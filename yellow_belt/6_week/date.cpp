//
// Created by Mahmud Jego on 4/21/21.
//

#include "date.h"

Date ParseDate(std::istringstream &is) {
	int year, month, day;
	std::stringstream date;
	std::string tmp;
	is >> tmp;
	date << tmp;
	char c;
	date >> year >> c;
	if (c != '-' || date.eof())
		throw InvalidData(date.str(), FULLDATE);
	date >> month >> c;
	if (c != '-' || date.eof())
		throw InvalidData(date.str(), FULLDATE);
	date >> day;
	if (date.fail())
		throw InvalidData(date.str(), FULLDATE);
	if (month > 12 || month < 1)
		throw InvalidData(std::to_string(month), MONTH);
	if (day > 31 || day < 1)
		throw InvalidData(std::to_string(day), DAY);
	if (!date.eof() && date.peek() != ' ')
		throw InvalidData(date.str(), FULLDATE);
	return {year, month, day};
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << std::setw(4) << std::setfill('0') << date.GetYear() << '-';
	os << std::setw(2) << std::setfill('0') << date.GetMonth() << '-';
	os << std::setw(2) << std::setfill('0') << date.GetDay();
	return os;
}

std::tuple<int,int,int> getTupleDate(const Date& date) {
	return std::make_tuple(date.GetYear(), date.GetMonth(), date.GetDay())
}

bool operator<(const Date& lhs, const Date& rhs) {
	return getTupleDate(lhs) < getTupleDate(rhs);
}

bool operator>(const Date& lhs, const Date& rhs) {
	return getTupleDate(lhs) > getTupleDate(rhs);
}

bool operator==(const Date& lhs, const Date& rhs) {
	return getTupleDate(lhs) == getTupleDate(rhs);
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return getTupleDate(lhs) != getTupleDate(rhs);
}