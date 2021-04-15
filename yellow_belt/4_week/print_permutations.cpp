//
// Created by Mahmud Jego on 4/15/21.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>



int main() {
	int n = 3;

	#ifndef MY_TEST
	#define MY_TEST

	std::cin >> n;

	#endif

	std::vector<int> vector(n);

	std::iota(vector.rbegin(), vector.rend(), 1);
	do {
		for (const auto &item : vector) {
			std::cout << item << ' ';
		}
		std::cout << std::endl;
	} while (std::prev_permutation(vector.begin(), vector.end()));

}