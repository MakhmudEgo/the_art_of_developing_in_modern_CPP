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
	void Add(const Date& date, const std::string& event);

	void DeleteEvent(const Date& date, const std::string& event = "");

	std::string Last(const Date& date);

	void Find(const Date& date) const;

	void Print() const;

	void Print(std::ostream& os) const;

	int RemoveIf(const std::function<bool(const Date&, const std::string&)>&fn);

	std::vector<std::string> FindIf(const std::function<bool(const Date&, const std::string&)>&fn);


private:
	std::map<Date, std::set<std::string> > _data;
};