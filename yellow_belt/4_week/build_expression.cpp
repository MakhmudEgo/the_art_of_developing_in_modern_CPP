//
// Created by Mahmud Jego on 4/18/21.
//

#include <iostream>

int main() {
	int n, arg;
	char sign;
	std::string res;
	std::cin >> res >> n;

	// * | - | +
	for (int i = 0; i < n; ++i) {
		res.insert(res.begin(), '(');
		res += ')';
		std::cin >> sign >> arg;
		res.push_back(' ');
		res.push_back(sign);
		res += " " + std::to_string(arg);
	}
	std::cout << res << std::endl;
}