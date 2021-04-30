//
// Created by Mahmud Jego on 4/21/21.
//

#include "database.h"

void Database::Add(const Date &date, const std::string &event)  {
	this->_data[date].insert(event);
}

void Database::DeleteEvent(const Date &date, const std::string &event) {
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

std::string Database::Last(const Date &date) {
	return std::string();
}

void Database::Find(const Date &date) const {
	if (this->_data.count(date)) {
		for (const auto& item : this->_data.at(date)) {
			std::cout << item << std::endl;
		}
	}
}

void Database::Print() const {
	for (const auto &item : this->_data) {
		for (const auto &item1 : item.second) {
			std::cout << item.first << ' ' << item1 << std::endl;
		}
	}
}

void Database::Print(std::ostream &os) const {
	for (const auto &item : this->_data) {
		for (const auto &item1 : item.second) {
			os << item.first << ' ' << item1 << std::endl;
		}
	}
}
int Database::RemoveIf(const std::function<bool(const Date &, const std::string &)> &fn) {
	std::vector<std::pair<Date, std::string> > res;

	for (auto &[date, event] : _data) {
		for (auto &item : event) {
			if (fn(date, item)) {
				res.emplace_back(date, item);
			}
		}
	}
	for (const auto &[date, event] : res) {
		_data.at(date).erase(event);
		if (_data.at(date).empty()) {
			_data.erase(date);
		}
	}
	return static_cast<int>(res.size());
}

std::vector<std::string> Database::FindIf(
		const std::function<bool(const Date &, const std::string &)> &fn) {
	std::vector<std::string> res;
	std::ostringstream ss;

	for (auto &[date, event] : _data) {
		for (auto &item : event) {
			if (fn(date, item)) {
				ss << date << ' ' << item;
				res.emplace_back(ss.str());
				ss.str(std::string());
			}
		}
	}
	return res;
}

