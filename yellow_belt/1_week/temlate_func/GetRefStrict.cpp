//
// Created by Mahmud Jego on 4/6/21.
//
#include <iostream>
#include <map>

template<typename T, typename S>
S& GetRefStrict(std::map<T, S>& m, const T& key) {
	try {
		return m.at(key);
	} catch (...) {
		throw std::runtime_error("kek");
	}
}

int main() {
	std::map<int, std::string> m = {{3, "value"}};
	std::string& item = GetRefStrict(m, 0);
	item = "newvalue";
	std::cout << m[0] << std::endl; // выведет newvalue
}