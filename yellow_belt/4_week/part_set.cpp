//
// Created by Mahmud Jego on 4/12/21.
//

#include <iostream>
#include <vector>
#include <set>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border) {
	std::vector<T> res;

	auto it = elements.begin();
	while (it != elements.end()) {
		if (*it > border) {
			res.push_back(*it);
		}
		it++;
	}
	return res;
}

int main() {
	for (int x : FindGreaterElements(std::set<int>{1, 5, 7, 8}, 5)) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::string to_find = "Python";
	std::cout << FindGreaterElements(std::set<std::string>{"C", "C++"}, to_find).size() << std::endl;
	return 0;
}

/*
 * 7 8
 * 0
*/