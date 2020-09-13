#include <string>
#include <iostream>
#include <cassert>
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
	// Реализуйте эту функцию
	string cmd;
	is >> cmd;
	if (cmd == "NEW_BUS") {
		q.type = QueryType::NewBus;
		is >> q.bus;
		int stop_count;
		is >> stop_count;
		q.stops.resize(stop_count);
		for (auto& now : q.stops) {
			is >> now;
		}
	}
	else if (cmd == "BUSES_FOR_STOP") {
		is >> q.stop;
		q.type = QueryType::BusesForStop;
	}
	else if (cmd == "STOPS_FOR_BUS") {
		is >> q.bus;
		q.type = QueryType::StopsForBus;
	}
	else if (cmd == "ALL_BUSES") {
		q.type = QueryType::AllBuses;
	}
	return is;
}

struct BusesForStopResponse {
	// Наполните полями эту структуру
	string stop;
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	// Реализуйте эту функцию
	if (r.stops_to_buses.count(r.stop) == 0) {
		os << "No stop";
	}
	else {
		for (const string& bus : r.stops_to_buses.at(r.stop)) {
			os << bus << " ";
		}
		os << endl;
	}
	return os;
}

struct StopsForBusResponse {
	// Наполните полями эту структуру
	string bus;
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	// Реализуйте эту функцию
	map<string, vector<string>> temp = r.stops_to_buses;
	if (r.buses_to_stops.count(r.bus) == 0) {
		os << "No bus";
	}
	else {
		for (const string& stop : r.buses_to_stops.at(r.bus)) {
			os << "Stop " << stop << ": ";
			if (temp[stop].size() == 1) {
				os << "no interchange";
			}
			else {
				for (const string& other_bus : temp[stop]) {
					if (r.bus != other_bus) {
						os << other_bus << " ";
					}
				}
			}
			cout << endl;
		}
	}
	return os;
}

struct AllBusesResponse {
	// Наполните полями эту структуру
	map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	// Реализуйте эту функцию
	if (r.buses_to_stops.empty()) {
		os << "No buses";
	}
	else {
		for (const auto& bus_item : r.buses_to_stops) {
			os << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				os << stop << " ";
			}
			os << endl;
		}
	}
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
		// Реализуйте этот метод
		buses_to_stops[bus] = stops;
		for (const string& stop : stops) {
			stops_to_buses[stop].push_back(bus);
		}
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
		// Реализуйте этот метод
		BusesForStopResponse result;
		result.stop = stop;
		result.buses_to_stops = buses_to_stops;
		result.stops_to_buses = stops_to_buses;
		return result;
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
		// Реализуйте этот метод
		StopsForBusResponse result;
		result.bus = bus;
		result.buses_to_stops = buses_to_stops;
		result.stops_to_buses = stops_to_buses;
		return result;
	}

	AllBusesResponse GetAllBuses() const {
		// Реализуйте этот метод
		AllBusesResponse result;
		result.buses_to_stops = buses_to_stops;
		return result;
	}
private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};

// Не меняя тела функции main, реализуйте функции и классы выше

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
