//
// Created by Mahmud Jego on 4/21/21.
//

#pragma once

#include <functional>
#include "date.h"
#include <map>
#include <set>
#include <vector>
/*class Database {
public:
	int RemoveIf(const std::function<bool(const Date&, const std::string&)>&fn) { return 1; }
//	int RemoveIf(const std::function<bool(const Date& date, const std::string& event)> &fn) { return 1; }
};*/

class Database {
public:
	void Add(const Date& date, const std::string& event) {
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

	std::string Last(const Date& date) {
		return std::string();
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
	void Print(std::ostream& os) const {
		for (const auto &item : this->_data) {
			for (const auto &item1 : item.second) {
				os << item.first << ' ' << item1 << std::endl;
			}
		}
	}

	int RemoveIf(const std::function<bool(const Date&, const std::string&)>&fn) { return 1; }
	std::vector<std::string> FindIf(const std::function<bool(const Date&, const std::string&)>&fn) { return std::vector<std::string>(1); }
//	 RemoveIf(const std::function<bool(const Date&, const std::string&)>&fn) { return 1; }


private:
	std::map<Date, std::set<std::string> > _data;
};