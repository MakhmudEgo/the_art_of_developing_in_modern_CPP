//
// Created by Makhmud Ego on 05.04.2021.
//

#include <iostream>

int main() {
	uint64_t res = 0, tmp = 0;
	int n, m;
	uint16_t r;
	std::cin >> n >> r;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cin >> m;
			if (!j)
				tmp = m;
			else
				tmp *= m;
		}
		res += tmp * r;
	}
	std::cout << res;

	return 0;
}