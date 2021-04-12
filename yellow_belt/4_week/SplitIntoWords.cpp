//
// Created by Mahmud Jego on 4/12/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> SplitIntoWords(const std::string& s) {
	std::vector<std::string> res;
	auto it = s.begin();
	auto prev = s.begin();

	while (*(it = std::find(it, s.end(), ' ')) != '\0') {
		res.push_back(std::string(prev, it));
		prev = ++it;
	}
	res.push_back(std::string(prev, it));
	return res;
}

int main() {
	std::string s = "C Cpp Java Python";

	std::vector<std::string> words = SplitIntoWords(s);
	std::cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			std::cout << "/";
		}
		std::cout << *it;
	}
	std::cout << std::endl;

	return 0;
}
