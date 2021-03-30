//
// Created by Mahmud Jego on 3/30/21.
//

#include <iostream>
#include <algorithm>

class Date {
public:
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
};

bool operator<(const Date& lhs, const Date& rhs);

class Database {
public:
	void AddEvent(const Date& date, const std::string& event);
	bool DeleteEvent(const Date& date, const std::string& event);
	int  DeleteDate(const Date& date);

	/* ??? */ Find(const Date& date) const;

	void Print() const;
};

int main() {
	Database db;

	std::string command;
	while (getline(std::cin, command)) {

	}

	return 0;
}