//
// Created by Mahmud Jego on 4/11/21.
//

#pragma once

#include <iostream>
#include <vector>
#include <map>

struct BusesForStopResponse {
	std::string stop;
	std::vector<std::string> busses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	std::string bus;
	std::vector<std::string> st;
	std::map<std::string, std::vector<std::string> > stops;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	std::map<std::string, std::vector<std::string>> buses_to_stops;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);