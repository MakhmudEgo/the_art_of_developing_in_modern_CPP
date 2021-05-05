//
// Created by Makhmud Ego on 05.05.2021.
//

#include "test_runner.h"

#include <iostream>
#include <algorithm>

template<class T>
class Table {
public:
	Table(const size_t y, const size_t x) {
		Resize(y, x);
	}
	std::pair<size_t , size_t> Size() const {
		if (tab.empty()) {
			return {0, 0};
		}
		return {tab.size(), tab[0].size()};
	}
	void Resize(const size_t y, const size_t x) {
		if (y && x) {
			tab.resize(y);
			std::for_each(tab.begin(), tab.end(), [x](std::vector<T>& v) {v.resize(x);});
		}
	}
	std::vector<T>& operator[](size_t x) {
		return tab[x];
	}

	const std::vector<T>& operator[](size_t x) const {
		return tab[x];
	}

private:
	std::vector<std::vector<T> > tab;
};

void TestTable() {
	Table<int> t(1, 1);
	ASSERT_EQUAL(t.Size().first, 1u);
	ASSERT_EQUAL(t.Size().second, 1u);
	t[0][0] = 42;
	ASSERT_EQUAL(t[0][0], 42);
	t.Resize(3, 4);
	ASSERT_EQUAL(t.Size().first, 3u);
	ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestTable);
	return 0;
}