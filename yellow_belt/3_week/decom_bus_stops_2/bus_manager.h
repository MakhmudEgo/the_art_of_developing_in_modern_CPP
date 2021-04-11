//
// Created by Mahmud Jego on 4/11/21.
//

#pragma once

#include "responses.h"


class BusManager {
public:
	void AddBus(const std::string& bus, const std::vector<std::string>& stops);

	BusesForStopResponse GetBusesForStop(const std::string& stop) const;

	StopsForBusResponse GetStopsForBus(const std::string& bus) const;

	AllBusesResponse GetAllBuses() const;

private:
	std::map<std::string, std::vector<std::string>> buses_to_stops;
	std::map<std::string, std::vector<std::string>> stops_to_buses;
};