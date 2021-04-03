//
// Created by Mahmud Jego on 3/30/21.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <exception>
#include <iomanip>

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

class Database {
public:
	void AddEvent(const Date& date, const std::string& event) {
		this->_data[date].insert(event);
	}

	void DeleteEvent(const Date& date, const std::string& event = "") {
		if (event.empty()) {
			std::cout << "Deleted " << this->_data[date].size() << " events" << std::endl;
			this->_data[date].clear();
		} else {
			if (this->_data[date].count(event)) {
				auto it = this->_data[date].begin();
				for (; it != this->_data[date].end(); ++it) {
					if (*it == event) {
						this->_data[date].erase(it);
						break;
					}
				}
				std::cout << "Deleted successfully" << std::endl;
			} else
				std::cout << "Event not found" << std::endl;
		}
	}

	void Find(const Date& date) const {
		if (this->_data.count(date)) {
			for (const auto& item : this->_data.at(date)) {
				std::cout << item << std::endl;
			}
		}
	}

	void Print() const {
		for (const auto &item : this->_data) {
			for (const auto &item1 : item.second) {
				std::cout << item.first << ' ' << item1 << std::endl;
			}
		}
	}

private:
	std::map<Date, std::set<std::string> > _data;
};

void checkCmd(const std::string& cmd) {
	if (cmd != "Add" && cmd != "Del"
	&& cmd != "Find" && cmd != "Print" && !cmd.empty())
		throw InvalidData(cmd, CMD);
}

Date getDate(std::stringstream& ss) {
	int year, month, day;
	std::stringstream date;
	std::string tmp;
	ss >> tmp;
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

std::string getEvent(std::stringstream& ss)
{
	std::string res;
	ss >> res;
	return res;
}

int main() {
	Database db;
	std::string cmd, command;

	while (getline(std::cin, command)) {
		std::stringstream ss;
		ss << command;
		ss >> cmd;
		try {
			checkCmd(cmd);
			if (cmd == "Add")
				db.AddEvent(getDate(ss), getEvent(ss));
			else if (cmd == "Find")
				db.Find(getDate(ss));
			else if (cmd == "Del")
				db.DeleteEvent(getDate(ss), getEvent(ss));
			else if (cmd == "Print")
				db.Print();
		} catch (InvalidData& e) {
			std::cout << e.what() << std::endl;
			return 1;
		}
		cmd.clear();
	}
	return 0;
}
