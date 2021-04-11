//
// Created by Mahmud Jego on 4/11/21.
//

#include "query.h"

std::istream& operator >> (std::istream& is, Query& q) {
	q.stops.clear();
	std::string query;
	int n;
	is >> query;
	if (query == "NEW_BUS") {
		q.type = QueryType::NewBus;
	} else if (query == "BUSES_FOR_STOP") {
		q.type = QueryType::BusesForStop;
	} else if (query == "STOPS_FOR_BUS") {
		q.type = QueryType::StopsForBus;
	} else if (query == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	switch (q.type) {
		case QueryType::NewBus:
			std::cin >> q.bus >> n;
			for (int i = 0; i < n; ++i) {
				std::cin >> q.stop;
				q.stops.push_back(q.stop);
			}
			break;
		case QueryType::BusesForStop:
			std::cin >> q.stop;
			break;
		case QueryType::StopsForBus:
			std::cin >> q.bus;
			break;
		case QueryType::AllBuses:
			break;
	}
	return is;
}