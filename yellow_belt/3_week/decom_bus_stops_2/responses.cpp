//
// Created by Mahmud Jego on 4/11/21.
//

#include "responses.h"

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
	if (r.stop.empty()) {
		os << "No stop";
	} else {
		bool d = false;
		for (const auto &item : r.busses) {
			if (d) {
				os << ' ';
			}
			d = true;
			os << item;
		}
	}
	return os;
}

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
	if (r.stops.empty()) {
		os << "No bus";
	} else {
		size_t i = 0;
		for (const auto &stop : r.st) {
			os << "Stop " << stop << ": ";
			if (r.stops.at(stop).size() == 1) {
				os << "no interchange";
			} else {
				for (const std::string& other_bus : r.stops.at(stop)) {
					if (r.bus != other_bus) {
						os << other_bus << " ";
					}
				}
			}
			if (++i < r.stops.size()) {
				os << std::endl;
			}
		}
	}
	return os;
}

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
	if (r.buses_to_stops.empty()) {
		os << "No buses";
	} else {
		size_t i = 0;
		for (const auto& bus_item : r.buses_to_stops) {
			os << "Bus " << bus_item.first << ": ";
			for (const std::string& stop : bus_item.second) {
				os << stop << " ";
			}
			if (++i < r.buses_to_stops.size()) {
				os << std::endl;
			}
		}
	}
	return os;
}