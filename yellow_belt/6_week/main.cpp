//
// Created by Mahmud Jego on 4/21/21.
//

#include "database.h"
#include "date.h"
#include "condition_parser.h"
#include "node.h"
#include "test_runner.h"

#include <iostream>
#include <stdexcept>
#include <sstream>

// TODO:: create new enam class for ...
#define CMD 0
#define DATE 1
#define MONTH 2
#define DAY 3

class InvalidData : public std::exception {
public:
	explicit InvalidData(const std::string& arg, int e) {
		switch (e) {
			case CMD:
				this->_arg = "Unknown command: "; break;
			case DATE:
				this->_arg = "Wrong date format: "; break;
			case MONTH:
				this->_arg = "Month value is invalid: "; break;
			case DAY:
				this->_arg = "Day value is invalid: "; break;
			default:
				this->_arg = "wtf";
		}
		this->_arg += arg;

	}
	const char *what() const throw() {
		return this->_arg.c_str();
	}
private:
	std::string _arg;
};


std::string ParseEvent(std::istream& is) {
	// TODO:: ?
	static int i;
	return std::string(std::to_string(++i) + " event");
}

void TestAll();

Date ParseDate(istringstream &is) {
	int year, month, day;
	std::stringstream date;
	std::string tmp;
	is >> tmp;
	date << tmp;
	char c;
	date >> year >> c;
	if (c != '-' || date.eof())
		throw InvalidData(date.str(), DATE);
	date >> month >> c;
	if (c != '-' || date.eof())
		throw InvalidData(date.str(), DATE);
	date >> day;
	if (date.fail())
		throw InvalidData(date.str(), DATE);
	if (month > 12 || month < 1)
		throw InvalidData(std::to_string(month), MONTH);
	if (day > 31 || day < 1)
		throw InvalidData(std::to_string(day), DAY);
	if (!date.eof() && date.peek() != ' ')
		throw InvalidData(date.str(), DATE);
	return {year, month, day};
}

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

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestParseEvent, "TestParseEvent");
	tr.RunTest(TestParseCondition, "TestParseCondition");
}