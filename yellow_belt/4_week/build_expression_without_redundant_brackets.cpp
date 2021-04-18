//
// Created by Mahmud Jego on 4/18/21.
//

#include <iostream>
#include <queue>

int main() {
	int n;
	std::string arg;
	char sign, prev_sign = '$';
	std::deque<std::string> res;
	std::cin >> arg >> n;
	res.emplace_back(arg);
	// * | - | +
	for (int i = 0; i < n; ++i) {
		std::cin >> sign >> arg;
		if ((sign == '*' || sign == '/') &&
		(prev_sign == '+' || prev_sign == '-')) {
			res.emplace_front(std::string(1, '('));
			res.emplace_back(std::string(1, ')'));
		}
		res.emplace_back(" ");
		res.emplace_back(std::string(1, sign));
		res.emplace_back(" ");
		res.push_back(arg);
		prev_sign = sign;
	}
	for (const auto &item : res) {
		std::cout << item;
	}
}
