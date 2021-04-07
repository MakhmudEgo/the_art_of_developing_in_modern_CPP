//
// Created by Mahmud Jego on 4/7/21.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	q.stops.clear();
	string query;
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
			cin >> q.bus >> n;
			for (int i = 0; i < n; ++i) {
				cin >> q.stop;
				q.stops.push_back(q.stop);
			}
			break;
		case QueryType::BusesForStop:
			cin >> q.stop;
			break;
		case QueryType::StopsForBus:
			cin >> q.bus;
			break;
		case QueryType::AllBuses:
			break;
	}
	return is;
}

struct BusesForStopResponse {
	string stop;
	vector<string> busses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
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

struct StopsForBusResponse {
	string bus;
	std::vector<string> st;
	map<string, vector<string> > stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.stops.empty()) {
		os << "No bus";
	} else {
		size_t i = 0;
		for (const auto &stop : r.st) {
			os << "Stop " << stop << ": ";
			if (r.stops.at(stop).size() == 1) {
				os << "no interchange";
			} else {
				for (const string& other_bus : r.stops.at(stop)) {
					if (r.bus != other_bus) {
						os << other_bus << " ";
					}
				}
			}
			if (++i < r.stops.size()) {
				os << endl;
			}
		}
	}
	return os;
}

struct AllBusesResponse {
	map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses_to_stops.empty()) {
		os << "No buses";
	} else {
		size_t i = 0;
		for (const auto& bus_item : r.buses_to_stops) {
			os << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				os << stop << " ";
			}
			if (++i < r.buses_to_stops.size()) {
				os << endl;
			}
		}
	}
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		this->buses_to_stops[bus] = stops;
		for (const auto &item : stops) {
			this->stops_to_buses[item].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		BusesForStopResponse response;
		try {
			response.busses = this->stops_to_buses.at(stop);
			response.stop = stop;

		} catch (...) {}
		return response;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		StopsForBusResponse response;
		try {
			response.bus = bus;
			for (const string &item : this->buses_to_stops.at(bus)) {
				response.stops[item] = this->stops_to_buses.at(item);
				response.st.push_back(item);
//				std::sort(response.stops[item].begin(), response.stops[item].end());
			}
		} catch (...) {}

		return response;
	}

	AllBusesResponse GetAllBuses() const {
		AllBusesResponse response;
		response.buses_to_stops = this->buses_to_stops;
		return response;
	}

private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};


int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
			case QueryType::NewBus:
				bm.AddBus(q.bus, q.stops);
				break;
			case QueryType::BusesForStop:
				cout << bm.GetBusesForStop(q.stop) << endl;
				break;
			case QueryType::StopsForBus:
				cout << bm.GetStopsForBus(q.bus) << endl;
				break;
			case QueryType::AllBuses:
				cout << bm.GetAllBuses() << endl;
				break;
		}
	}

	return 0;
}