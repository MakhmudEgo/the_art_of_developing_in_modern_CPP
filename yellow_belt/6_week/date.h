//
// Created by Mahmud Jego on 4/21/21.
//

#pragma once
#include <iomanip>
#include <iostream>
#include <sstream>

#define CMD 0
#define FULLDATE 1
#define MONTH 2
#define DAY 3

class InvalidData : public std::exception {
public:
	explicit InvalidData(const std::string& arg, int e) {
		switch (e) {
			case CMD:
				this->_arg = "Unknown command: "; break;
			case FULLDATE:
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

std::ostream &operator<<(std::ostream &os, const Date &date);

bool operator<(const Date& lhs, const Date& rhs);

Date ParseDate(std::istringstream &is);