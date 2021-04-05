//
// Created by Mahmud Jego on 4/5/21.
//

#include <iostream>
#include <tuple>
#include <map>
#include <vector>
enum class Lang {
  DE, FR, IT
};
struct Region {
	std::string std_name;
	std::string parent_std_name;
	std::map<Lang, std::string> names;
	int64_t population;
};

bool operator<(const Region& l, const Region& r) {
	return std::tie(l.std_name, l.parent_std_name, l.names, l.population) < std::tie(r.std_name, r.parent_std_name, r.names, r.population);
}

int FindMaxRepetitionCount(const std::vector<Region>& regions) {
	std::map<Region, size_t> res;
	size_t n = 0;
	for (const auto &item : regions) {
		n = std::max(n, ++res[item]);
	}
	return n;
}


int main() {
	std::cout << FindMaxRepetitionCount({
	{
					"Moscow",
					"Russia",
					{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
					89
	}, {
			"Russia",
			"Eurasia",
			{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
			89
			}, {
					"Moscow",
					"Russia",
					{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
					89
			}, {
					"Moscow",
					"Russia",
					{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
					89
			}, {
					"Russia",
					"Eurasia",
					{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
					89
			},
		}) << std::endl;

	std::cout << FindMaxRepetitionCount({
	{
					"Moscow",
					"Russia",
					{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
					89
	}, {
					"Russia",
					"Eurasia",
					{{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
					89
			}, {
					"Moscow",
					"Russia",
					{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
					89
			}, {
					"Moscow",
					"Toulouse",
					{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
					89
			}, {
					"Moscow",
					"Russia",
					{{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
					31
			},
		}) << std::endl;

	return 0;
}
