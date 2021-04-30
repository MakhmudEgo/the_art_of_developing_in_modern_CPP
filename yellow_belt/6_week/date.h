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
	explicit InvalidData(const std::string& arg, int e);

	virtual const char *what() const throw();
private:
	std::string _arg;
};


class Date {
public:
	Date(int year, int month, int day);

	int GetYear() const;

	int GetMonth() const;

	int GetDay() const;

private:
	int _year;
	int _month;
	int _day;
};

std::ostream &operator<<(std::ostream &os, const Date &date);

bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);

Date ParseDate(std::istream &is);