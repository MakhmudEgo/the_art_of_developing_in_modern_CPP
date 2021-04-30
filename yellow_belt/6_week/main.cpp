//
// Created by Mahmud Jego on 4/21/21.
//

#include "test_runner.h"
#include "database.h"
#include "date.h"
#include "condition_parser.h"
#include <iostream>
#include <stdexcept>


std::string ParseEvent(std::istream& is) {
	std::string res;

	is >> std::ws;
	std::getline(is, res);
	return res;
}

void TestAll();

int main() {
	TestAll();

	Database db;

	for (std::string line; getline(std::cin, line); ) {
		std::istringstream is(line);

		std::string command;
		is >> command;
		if (command == "Add") {
			const auto date = ParseDate(is);
			const auto event = ParseEvent(is);
			db.Add(date, event);
		} else if (command == "Print") {
			db.Print(std::cout);
		} else if (command == "Del") {
			auto condition = ParseCondition(is);
			auto predicate = [condition](const Date& date, const string& event) {
				return condition->Evaluate(date, event);
			};
			int count = db.RemoveIf(predicate);
			cout << "Removed " << count << " entries" << endl;
		} else if (command == "Find") {
			auto condition = ParseCondition(is);
			auto predicate = [condition](const Date& date, const string& event) {
				return condition->Evaluate(date, event);
			};

			const auto entries = db.FindIf(predicate);
			for (const auto& entry : entries) {
				cout << entry << endl;
			}
			cout << "Found " << entries.size() << " entries" << endl;
		} else if (command == "Last") {
			try {
				cout << db.Last(ParseDate(is)) << endl;
			} catch (invalid_argument&) {
				cout << "No entries" << endl;
			}
		} else if (command.empty()) {
			continue;
		} else {
			throw logic_error("Unknown command: " + command);
		}
	}

	return 0;
}

void TestParseEvent() {
	{
		std::istringstream is("event");
		AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
	}
	{
		std::istringstream is("   sport event ");
		AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
	}
	{
		std::istringstream is("  first event  \n  second event");
		std::vector<std::string> events;
		events.push_back(ParseEvent(is));
		events.push_back(ParseEvent(is));
		AssertEqual(events, std::vector<std::string>{"first event  ", "second event"}, "Parse multiple events");
	}
}

void TestDbAdd() {
	{
		Database db;
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 7}, "xmas");
		ostringstream out;
		db.Print(out);
		AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n", out.str(), "straight ordering");
	}
	{
		Database db;
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 1}, "holiday");
		ostringstream out;
		db.Print(out);
		AssertEqual("2017-01-01 new year\n2017-01-01 holiday\n", out.str(), "several in one day");
	}
	{
		Database db;
		db.Add({2017, 1, 7}, "xmas");
		db.Add({2017, 1, 1}, "new year");
		ostringstream out;
		db.Print(out);
		AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n", out.str(), "reverse ordering");
	}
	{
		Database db;
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 1}, "xmas");
		db.Add({2017, 1, 1}, "new year");
		ostringstream out;
		db.Print(out);
		AssertEqual("2017-01-01 new year\n2017-01-01 xmas\n", out.str(), "uniq adding");
	}
}

int DoRemove (Database& db, const string& str) {
	istringstream is (str);
	auto condition = ParseCondition(is);
	auto predicate = [condition](const Date &date, const string &event) {
		return condition->Evaluate(date, event);
	};
	return db.RemoveIf(predicate);
}

void TestDbRemoveIf () {
	{
		Database db;
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 7}, "xmas");
		AssertEqual(0, DoRemove(db, R"(event == "something")"), "Remove nothing");
		AssertEqual(1, DoRemove(db, R"(date == "2017-01-01")"), "Remove by date");
		ostringstream out;
		db.Print(out);
		AssertEqual("2017-01-07 xmas\n", out.str(), "Remove by date, left");
	}
	{
		Database db;
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 7}, "xmas");
		AssertEqual(1, DoRemove(db, R"(event == "xmas")"), "Remove by event");
		ostringstream out;
		db.Print(out);
		AssertEqual("2017-01-01 new year\n", out.str(), "Remove by event, left");
	}
	{
		Database db;
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 7}, "xmas");
		db.Add({2017, 1, 7}, "new year");
		AssertEqual(2, DoRemove(db, R"(event == "new year")"), "Multiple remove by event");
		ostringstream out;
		db.Print(out);
		AssertEqual("2017-01-07 xmas\n", out.str(), "Multiple remove by event, left");
	}
}
string DoFind (Database& db, const string& str) {
	istringstream is (str);
	auto condition = ParseCondition(is);
	auto predicate = [condition](const Date &date, const string &event) {
		return condition->Evaluate(date, event);
	};
	const auto entries = db.FindIf(predicate);
	ostringstream os;
	for (const auto& entry : entries) {
		os << entry << endl;
	}
	os << entries.size();
	return os.str();
}
void TestDbFind() {
	{
		Database db;
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 7}, "xmas");
		AssertEqual("2017-01-01 new year\n1", DoFind(db, "date == 2017-01-01"), "simple find by date");
		AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n2", DoFind(db, "date < 2017-01-31"), "multiple find by date");
		AssertEqual("2017-01-01 new year\n1", DoFind(db, R"(event != "xmas")"), "multiple find by holiday");
	}
	{
		Database db;
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 1}, "new year2");
		db.Add({2017, 1, 7}, "xmas");
		AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n2", DoFind(db, R"(date == 2017-01-07 OR event == "new year")"),
					"complex find or");
		AssertEqual("2017-01-01 new year\n1", DoFind(db, R"(date == 2017-01-01 AND event == "new year")"),
					"complex find and");
		AssertEqual("0", DoFind(db, R"(date == 2017-01-09 AND event == "new year")"),
					"complex find and, nothing");
	}
}
void TestDbLast(){
	Database db;
	db.Add({2017, 1, 1}, "new year");
	db.Add({2017, 1, 7}, "xmas");
	{
		try {
			db.Last({2016, 12, 31});
			Assert(false, "last, found no entries");
		} catch (...){
			Assert(true, "last, found no entries");

		}
	}
	{
		ostringstream os;
		os << db.Last({2017, 1, 2});
		AssertEqual("2017-01-01 new year", os.str(), "greater than date");
	}
	{
		ostringstream os;
		os << db.Last({2017, 1, 1});
		AssertEqual("2017-01-01 new year", os.str(), "eq to date");
	}
	{
		ostringstream os;
		os << db.Last({2017, 1, 10});
		AssertEqual("2017-01-07 xmas", os.str(), "greater than max date");
	}
}
void TestInsertionOrder()
{
	{
		Database db;
		db.Add({2017, 1, 1}, "new year");
		db.Add({2017, 1, 7}, "xmas");
		db.Add({2017, 1, 7}, "party");
		db.Add({2017, 1, 7}, "pie");
		ostringstream out;
		db.Print(out);
		AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n2017-01-07 party\n2017-01-07 pie\n", out.str(), "Remove by date, left");
	}

}
void TestDatabase() {
	istringstream empty_is("");
	auto empty_condition = ParseCondition(empty_is);
	auto empty_predicate = [empty_condition](const Date& date, const string& event) {
		return empty_condition->Evaluate(date, event);
	};

	// Add 2 - Del 1 - Add deleted again
	{
		Database db;
		Date d(2019, 1, 1);
		db.Add(d, "e1");
		db.Add(d, "e2");
		istringstream is(R"(event == "e1")");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.RemoveIf(predicate), 1, "Db Add2-Del-Add 1");
		db.Add(d, "e1");
		AssertEqual(db.FindIf(empty_predicate).size(), 2, "Db Add2-Del-Add 2");
	}

	// Add
	{
		Database db;
		Date d(2019, 1, 1);
		db.Add(d, "e1");
		db.Add(d, "e1");
		istringstream is("date == 2019-01-01");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.FindIf(predicate).size(), 1, "Db Add Duplicates 1");
	}

	// Last


	// Del
	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		istringstream is("date == 2018-01-07");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.RemoveIf(predicate), 2, "Db Del 1");
	}
	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		istringstream is("date >= 2018-01-07 AND date <= 2020-01-01");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.RemoveIf(predicate), 4, "Db Del 2");
	}
	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		AssertEqual(db.RemoveIf(empty_predicate), 4, "Db Del 3");
	}
	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		istringstream is(R"(event == "e1")");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.RemoveIf(predicate), 1, "Db Del 4");
	}

	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		istringstream is(R"(event == "e1" OR date == 2019-01-01)");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.RemoveIf(predicate), 2, "Db Del 5");
	}

	// Find
	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		istringstream is("date == 2018-01-07");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.FindIf(predicate).size(), 2, "Db Find 1");
	}
	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		istringstream is("date >= 2018-01-07 AND date <= 2020-01-01");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.FindIf(predicate).size(), 4, "Db Find 2");
	}
	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		AssertEqual(db.FindIf(empty_predicate).size(), 4, "Db Find 3");
	}
	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		istringstream is(R"(event == "e1")");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.FindIf(predicate).size(), 1, "Db Find 4");
	}

	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		db.Add({2018, 1, 7}, "e3");
		db.Add({2018, 1, 7}, "e4");
		istringstream is(R"(event == "e1" OR date == 2019-01-01)");
		auto condition = ParseCondition(is);
		auto predicate = [condition](const Date& date, const string& event) {
			return condition->Evaluate(date, event);
		};
		AssertEqual(db.FindIf(predicate).size(), 2, "Db Find 5");
	}

	// Add - Del - Add - Del
	{
		Database db;
		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		AssertEqual(db.RemoveIf(empty_predicate), 2, "Db Add-Del-Add-Del 1");

		db.Add({2019, 1, 1}, "e1");
		db.Add({2019, 1, 1}, "e2");
		AssertEqual(db.RemoveIf(empty_predicate), 2, "Db Add-Del-Add-Del 1");
	}

	{
		Database db;
		db.Add({2017, 1, 1}, "first");
		db.Add({2017, 1, 1}, "second");
		db.Add({2017, 1, 1}, "third");
		db.Add({2017, 1, 1}, "fourth");
		db.Add({2017, 1, 1}, "five");
		AssertEqual(2, DoRemove(db, R"(event == "second" OR event == "fourth")"), "Remove several");
		ostringstream os;
		db.Print(os);
		AssertEqual("2017-01-01 first\n2017-01-01 third\n2017-01-01 five\n", os.str(), "Check print after remove several- 3");
	}
}
void TestDateComparisonNode() {
	{
		DateComparisonNode dcn(Comparison::Equal, {2017, 11, 18});
		Assert(dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparison 1");
		Assert(!dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparison 2");
	}
	{
		DateComparisonNode dcn(Comparison::NotEqual, {2017, 11, 18});
		Assert(dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparison 3");
		Assert(!dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparison 4");
	}
	{
		DateComparisonNode dcn(Comparison::Less, {2017, 11, 18});
		Assert(dcn.Evaluate(Date{2017, 11, 17}, ""), "DateComparison 5");
		Assert(!dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparison 6");
		Assert(!dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparison 7");
	}
	{
		DateComparisonNode dcn(Comparison::Greater, {2017, 11, 18});
		Assert(dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparison 8");
		Assert(!dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparison 9");
		Assert(!dcn.Evaluate(Date{2017, 11, 17}, ""), "DateComparison 10");
	}
	{
		DateComparisonNode dcn(Comparison::LessOrEqual, {2017, 11, 18});
		Assert(dcn.Evaluate(Date{2017, 11, 17}, ""), "DateComparison 11");
		Assert(dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparison 12");
		Assert(!dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparison 13");
	}
	{
		DateComparisonNode dcn(Comparison::GreaterOrEqual, {2017, 11, 18});
		Assert(dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparison 14");
		Assert(dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparison 15");
		Assert(!dcn.Evaluate(Date{2017, 11, 17}, ""), "DateComparison 16");
	}
}
void TestEventComparisonNode() {
	{
		EventComparisonNode ecn(Comparison::Equal, "abc");
		Assert(ecn.Evaluate(Date{0, 1, 1}, "abc"), "EventComparison 1");
		Assert(!ecn.Evaluate(Date{0, 1, 1}, "cbe"), "EventComparison 2");
	}
	{
		EventComparisonNode ecn(Comparison::NotEqual, "abc");
		Assert(ecn.Evaluate(Date{0, 1, 1}, "cde"), "EventComparison 3");
		Assert(!ecn.Evaluate(Date{0, 1, 1}, "abc"), "EventComparison 4");
	}
	{
		EventComparisonNode ecn(Comparison::Less, "abc");
		Assert(ecn.Evaluate(Date{0, 1, 1}, "abb"), "EventComparison 5");
		Assert(!ecn.Evaluate(Date{0, 1, 1}, "abc"), "EventComparison 6");
		Assert(!ecn.Evaluate(Date{0, 1, 1}, "abd"), "EventComparison 7");
	}
	{
		EventComparisonNode ecn(Comparison::Greater, "abc");
		Assert(ecn.Evaluate(Date{0, 1, 1}, "abd"), "EventComparison 8");
		Assert(!ecn.Evaluate(Date{0, 1, 1}, "abc"), "EventComparison 9");
		Assert(!ecn.Evaluate(Date{0, 1, 1}, "abb"), "EventComparison 10");
	}
	{
		EventComparisonNode ecn(Comparison::LessOrEqual, "abc");
		Assert(ecn.Evaluate(Date{0, 1, 1}, "abb"), "EventComparison 11");
		Assert(ecn.Evaluate(Date{0, 1, 1}, "abc"), "EventComparison 12");
		Assert(!ecn.Evaluate(Date{0, 1, 1}, "abd"), "EventComparison 13");
	}
	{
		EventComparisonNode ecn(Comparison::GreaterOrEqual, "abc");
		Assert(ecn.Evaluate(Date{0, 1, 1}, "abd"), "EventComparison 14");
		Assert(ecn.Evaluate(Date{0, 1, 1}, "abc"), "EventComparison 15");
		Assert(!ecn.Evaluate(Date{0, 1, 1}, "abb"), "EventComparison 16");
	}
}
void TestAll() {
	TestRunner tr;
	tr.RunTest(TestParseEvent, "TestParseEvent");
	tr.RunTest(TestParseCondition, "TestParseCondition");
	tr.RunTest(TestDbAdd, "TestDbAdd");
	tr.RunTest(TestDbRemoveIf, "TestDbRemoveIf");
	tr.RunTest(TestDbFind, "TestDbFind");
	tr.RunTest(TestDbLast, "TestDbLast");
	tr.RunTest(TestInsertionOrder, "TestInsertionOrder");
	tr.RunTest(TestDatabase, "TestDatabase");
	tr.RunTest(TestDateComparisonNode, "TestDateComparisonNode");
	tr.RunTest(TestEventComparisonNode, "TestEventComparisonNode");
}