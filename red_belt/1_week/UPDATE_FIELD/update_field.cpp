//
// Created by Mahmud Jego on 5/5/21.
//

#include "airline_ticket.h"
#include "test_runner.h"
#include <istream>

using namespace std;

bool operator<(const Date& lhs, const Date& rhs) {
	return std::make_tuple(lhs.year, lhs.month, lhs.day) <
		   std::make_tuple(rhs.year, rhs.month, rhs.day);
}

bool operator==(const Date& lhs, const Date& rhs) {
	return std::make_tuple(lhs.year, lhs.month, lhs.day) ==
		   std::make_tuple(rhs.year, rhs.month, rhs.day);
}
std::ostream &operator<<(std::ostream& os, const Date& d) {
	os << d.year << '-' << d.month << '-' << d.day;
	return os;
}

std::istream &operator>>(std::istream& is, Date& d) {
	is >> d.year;
	is.ignore(1);
	is >> d.month;
	is.ignore(1);
	is >> d.day;
	return is;
}

bool operator<(const Time& lhs, const Time& rhs) {
	if (lhs.hours != rhs.hours) {
		return lhs.hours < rhs.hours;
	} else {
		return lhs.minutes < rhs.minutes;
	}
}

bool operator==(const Time& lhs, const Time& rhs) {
	if (lhs.hours != rhs.hours) {
		return lhs.hours == rhs.hours;
	} else {
		return lhs.minutes == rhs.minutes;
	}
}

std::ostream &operator<<(std::ostream& os, const Time& t) {
	os << t.hours << ':' << t.minutes;
	return os;
}

std::istream &operator>>(std::istream& is, Time& t) {
	is >> t.hours;
	is.ignore(1);
	is >> t.minutes;
	return is;
}

#define UPDATE_FIELD(ticket, field, values) { \
	std::map<std::string, std::string>::const_iterator it; \
	it = values.find(#field); \
	if (it != values.end()) { \
		std::istringstream is(it->second); \
		is >> ticket.field; \
	} \
}

/*
void UpdateTicket(AirlineTicket& ticket, const map<string, string>& updates) {
	UPDATE_FIELD(ticket, to, updates);
	UPDATE_FIELD(ticket, from, updates);
	UPDATE_FIELD(ticket, price, updates);
	UPDATE_FIELD(ticket, airline, updates);
//	...
}

void UpdateTicketExample() {
	AirlineTicket t;
	t.price = 5000;
	t.from = "DME";
	t.to = "AER";

	const map<string, string> updates = {
			{"price", "3500"},
			{"from", "VKO"}
	};
	UpdateTicket(t, updates);
	ASSERT_EQUAL(t.from, "VKO");
	ASSERT_EQUAL(t.to, "AER");
	ASSERT_EQUAL(t.price, 3500);
}

void TestUpdate() {
	AirlineTicket t;
	t.price = 0;

	const map<string, string> updates1 = {
			{"departure_date", "2018-2-28"},
			{"departure_time", "17:40"},
	};
	UPDATE_FIELD(t, departure_date, updates1);
	UPDATE_FIELD(t, departure_time, updates1);
	UPDATE_FIELD(t, price, updates1);

	ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
	ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
	ASSERT_EQUAL(t.price, 0);

	const map<string, string> updates2 = {
			{"price", "12550"},
			{"arrival_time", "20:33"},
	};
	UPDATE_FIELD(t, departure_date, updates2);
	UPDATE_FIELD(t, departure_time, updates2);
	UPDATE_FIELD(t, arrival_time, updates2);
	UPDATE_FIELD(t, price, updates2);

	// updates2 Ð½Ðµ ÑÐ¾Ð´ÐµÑ€Ð¶Ð¸Ñ‚ ÐºÐ»ÑŽÑ‡ÐµÐ¹ "departure_date" Ð¸ "departure_time", Ð¿Ð¾ÑÑ‚Ð¾Ð¼Ñƒ
	// Ð·Ð½Ð°Ñ‡ÐµÐ½Ð¸Ñ ÑÑ‚Ð¸Ñ… Ð¿Ð¾Ð»ÐµÐ¹ Ð½Ðµ Ð´Ð¾Ð»Ð¶Ð½Ñ‹ Ð¸Ð·Ð¼ÐµÐ½Ð¸Ñ‚ÑŒÑÑ
	ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
	ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
	ASSERT_EQUAL(t.price, 12550);
	ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestUpdate);
}*/
