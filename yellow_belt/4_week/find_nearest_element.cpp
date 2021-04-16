//
// Created by Mahmud Jego on 4/16/21.
//

#include <set>
#include <iostream>
#include <algorithm>

std::set<int>::const_iterator FindNearestElement(
		const std::set<int>& numbers,
		int border);

std::set<int>::const_iterator FindNearestElement(
		const std::set<int>& numbers,
		int border) {
	(std::lower_bound(numbers.begin(), numbers.end(), border)).first.;
	return res.fire;
}

// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {
	std::set<int> numbers = {1, 4, 6};
	std::cout <<
		 *FindNearestElement(numbers, 0) << " " <<
		 *FindNearestElement(numbers, 3) << " " <<
		 *FindNearestElement(numbers, 5) << " " <<
		 *FindNearestElement(numbers, 6) << " " <<
		 *FindNearestElement(numbers, 100) << std::endl;

	std::set<int> empty_set;

	std::cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << std::endl;
	return 0;
}