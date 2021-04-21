//
// Created by Mahmud Jego on 4/21/21.
//

#pragma once
#include <iomanip>
#include <iostream>

class Date {
public:
	Date(int year, int month, int day) : _year(year), _month(month), _day(day) {}

	int GetYear() const {
		return this->_year;
	}

	int GetMonth() const {
		return this->_month;
	}

	int GetDay() const {
		return this->_day;
	}

private:
	int _year;
	int _month;
	int _day;
};

std::ostream &operator<<(std::ostream &os, const Date &date) {
	os << std::setw(4) << std::setfill('0') << date.GetYear() << '-';
	os << std::setw(2) << std::setfill('0') << date.GetMonth() << '-';
	os << std::setw(2) << std::setfill('0') << date.GetDay();
	return os;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth())
			return lhs.GetDay() < rhs.GetDay();
	}
	return lhs.GetYear() < rhs.GetYear();
}