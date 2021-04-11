//
// Created by Mahmud Jego on 4/11/21.
//

#pragma once
#include <iostream>
#include <vector>

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	std::string bus;
	std::string stop;
	std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q);