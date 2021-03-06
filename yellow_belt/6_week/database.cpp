//
// Created by Mahmud Jego on 4/21/21.
//

#include "database.h"

void Database::Add(const Date &date, const std::string &event)  {
	size_t n = this->_data[date].size();
	this->_data[date].insert(event);
	/*std::stringstream ss;
	ss << "Add " << date << ' ' << event << std::endl;
	_LOG += ss.str();*/

	if (n != this->_data[date].size())
		this->_lastEvent[date].push_back(event);
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

std::string Database::Last(const Date &date) const {
	try {
		auto it = _lastEvent.lower_bound(date);
		if ((it->first > date && it == _lastEvent.begin())
			|| (it == _lastEvent.end() && _lastEvent.empty())) {
			throw std::invalid_argument(std::string());
		} else if (it != _lastEvent.end() && it->first == date) {
			std::stringstream ss;
			ss << date << ' ' << _lastEvent.at(date).back();
			return ss.str();
		} else {
			std::stringstream ss;
			ss << (--it)->first << ' ' << it->second.back();
			return ss.str();
		}
	}
	catch (...) {
		std::stringstream ss;
		ss << date;
		throw std::invalid_argument(_LOG + ss.str());
	}
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
	for (const auto &item : this->_lastEvent) {
		for (const auto &item1 : item.second) {
			os << item.first << ' ' << item1 << std::endl;
		}
	}
/*	std::ostringstream ss;
	ss << os.rdbuf();
	_LOG += ss.str();*/
}

int Database::RemoveIf(const std::function<bool(const Date &, const std::string &)> &fn) {
	std::vector<std::pair<Date, std::string> > res;

	for (auto &[date, event] : _data) {
		for (auto &item : event) {
			if (fn(date, item)) {
				/*std::stringstream ss;
				ss << "Del " << date << ' ' << item << std::endl;
				_LOG += ss.str();*/
				res.emplace_back(date, item);
			}
		}
	}
	for (const auto &[date, event] : res) {
		_data.at(date).erase(event);

		if (_data.at(date).empty()) {
			_data.erase(date);
		}
		try {
			/*for (auto it = _lastEvent.at(date).begin(); it != _lastEvent.at(date).end(); ++it) {
				if (*it == event) {
					_lastEvent.at(date).erase(it);
					if (_lastEvent.at(date).empty()) {
						_lastEvent.erase(date);
					}
					break;
				}
			}*/
			auto it = std::find(_lastEvent.at(date).begin(), _lastEvent.at(date).end(), event);
			if (it != _lastEvent.at(date).end()) {
				_lastEvent.at(date).erase(it);
				if (_lastEvent.at(date).empty()) {
					_lastEvent.erase(date);
				}
			}
		} catch (...) {}
	}
	return static_cast<int>(res.size());
}

std::vector<std::string> Database::FindIf(
		const std::function<bool(const Date &, const std::string &)> &fn) const {
	std::vector<std::string> res;
	std::ostringstream ss;

	for (auto &[date, event] : _lastEvent) {
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

void Database::setLog(const std::string &log) {
	_LOG += log;
}

