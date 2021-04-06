//
// Created by Mahmud Jego on 4/6/21.
//

#include <iostream>
#include <map>
#include <vector>

template<typename T> std::vector<T> operator*(const std::vector<T>& l, const std::vector<T>& r);
template<typename F, typename S> std::pair<F, S> operator*(const std::pair<F, S>& l, const std::pair<F, S>& r);
template<typename F, typename S> std::map<F, S> operator*(const std::map<F, S>& l, const std::map<F, S>& r);
template<typename T> T Sqr(const T& t);


template<typename T>
std::vector<T> operator*(const std::vector<T>& l, const std::vector<T>& r) {
	std::vector<T> res = l;
	r.size();
	for (size_t i = 0; i < res.size(); ++i) {
		res[i] = res[i] * res[i];
	}
	return res;
}

template<typename F, typename S>
std::pair<F, S> operator*(const std::pair<F, S>& l, const std::pair<F, S>& r) {
	return {l.first * r.first, l.second * r.second};
}

template<typename F, typename S>
std::map<F, S> operator*(const std::map<F, S>& l, const std::map<F, S>& r) {
	std::map<F, S> res = l;
	r.size();
	for (auto &item : res) {
		item.second = item.second * item.second;
	}
	return res ;
}

template<typename T>
T Sqr(const T& t) {
	T res = t * t;
	return res;
}

int main() {
	// Пример вызова функции
	std::vector<int> v = {1, 2, 3};
	std::cout << "vector:";
	for (int x : Sqr(v)) {
		std::cout << ' ' << x;
	}
	std::cout << std::endl;

	std::map<int, std::pair<int, int>> map_of_pairs = {
			{4, {2, 2}},
			{7, {4, 3}}
	};
	std::cout << "map of pairs:" << std::endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		std::cout << x.first << ' ' << x.second.first << ' ' << x.second.second << std::endl;
	}
}