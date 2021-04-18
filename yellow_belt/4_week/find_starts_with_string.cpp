//
// Created by Mahmud Jego on 4/17/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(
		RandomIt range_begin, RandomIt range_end,
		const std::string& prefix) {
	std::string hello1 = prefix;
	hello1.back() = ++(hello1.back());
	auto it_start = std::lower_bound(range_begin, range_end, prefix);
	auto it_end = std::lower_bound(range_begin, range_end, hello1);
	return std::make_pair(it_start, it_end != range_end && *std::prev(it_end) == hello1 ? std::prev(it_end) : it_end);
}

int main() {
	const std::vector<std::string> sorted_strings = {"moscow", "motovilikha", "mp", "murmansk"};

	const auto mo_result =
			FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	const auto mt_result =
			FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	std::cout << (mt_result.first - begin(sorted_strings)) << " " <<
		 (mt_result.second - begin(sorted_strings)) << std::endl;

	const auto na_result =
			FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
	std::cout << (na_result.first - begin(sorted_strings)) << " " <<
		 (na_result.second - begin(sorted_strings)) << std::endl;

	return 0;
}
