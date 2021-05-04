//
// Created by Mahmud Jego on 5/4/21.
//

#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>
//using namespace std;

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

bool operator<(const Time& lhs, const Time& rhs) {
	if (lhs.hours != rhs.hours) {
		return lhs.hours < rhs.hours;
	} else {
		return lhs.minutes < rhs.minutes;
	}
}

#define SORT_BY(field) [](const AirlineTicket& lhs, const AirlineTicket& rhs) { \
	return lhs.field < rhs.field;        \
}


/*void SortTickets(vector<AirlineTicket>& tixs) {
	stable_sort(std::begin(tixs), std::end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
		return lhs.to < rhs.to;
	});
	stable_sort(std::begin(tixs), std::end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
		return lhs.departure_time < rhs.departure_time;
	});
	stable_sort(std::begin(tixs), std::end(tixs), [](const AirlineTicket& lhs, const AirlineTicket& rhs) {
		return lhs.price < rhs.price;
	});
}*/

/*void SortTickets(vector<AirlineTicket>& tixs) {
	stable_sort(std::begin(tixs), std::end(tixs), SORT_BY(to));
	stable_sort(std::begin(tixs), std::end(tixs), SORT_BY(departure_time));
	stable_sort(std::begin(tixs), std::end(tixs), SORT_BY(price));
}*/
void TestSortBy() {
	std::vector<AirlineTicket> tixs = {
			{"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
			{"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
			{"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
			{"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
			{"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
	};

	std::sort(std::begin(tixs), std::end(tixs), SORT_BY(price));
	ASSERT_EQUAL(tixs.front().price, 1200);
	ASSERT_EQUAL(tixs.back().price, 9000);

	std::sort(std::begin(tixs), std::end(tixs), SORT_BY(from));
	ASSERT_EQUAL(tixs.front().from, "AER");
	ASSERT_EQUAL(tixs.back().from, "VKO");

	std::sort(std::begin(tixs), std::end(tixs), SORT_BY(arrival_date));
	ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
	ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestSortBy);
}