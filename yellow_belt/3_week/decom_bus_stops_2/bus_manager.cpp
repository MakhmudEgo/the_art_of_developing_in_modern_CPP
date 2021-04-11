//
// Created by Mahmud Jego on 4/11/21.
//

#include "bus_manager.h"

void BusManager::AddBus(const std::string& bus, const std::vector<std::string>& stops) {
	this->buses_to_stops[bus] = stops;
	for (const auto &item : stops) {
		this->stops_to_buses[item].push_back(bus);
	}
}

BusesForStopResponse BusManager::GetBusesForStop(const std::string& stop) const {
	BusesForStopResponse response;
	try {
		response.busses = this->stops_to_buses.at(stop);
		response.stop = stop;

	} catch (...) {}
	return response;
}

StopsForBusResponse BusManager::GetStopsForBus(const std::string& bus) const {
	StopsForBusResponse response;
	try {
		response.bus = bus;
		for (const std::string &item : this->buses_to_stops.at(bus)) {
			response.stops[item] = this->stops_to_buses.at(item);
			response.st.push_back(item);
		}
	} catch (...) {}

	return response;
}

AllBusesResponse BusManager::GetAllBuses() const {
	AllBusesResponse response;
	response.buses_to_stops = this->buses_to_stops;
	return response;
}