//
// Created by Makhmud Ego on 04.04.2021.
//

#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> data(n);

	int64_t avg = 0;
	for (auto &item : data) {
		std::cin >> item;
		avg += item;
	}

	avg /= n;
	n = 0;
	for (const auto &item : data) {
		if (item > avg) {
			n++;
		}
	}

	std::cout << n << std::endl;
	for (size_t i = 0; i < data.size(); ++i) {
		if (data[i] > avg) {
			std::cout << i << ' ';
		}
	}

	return 0;
}