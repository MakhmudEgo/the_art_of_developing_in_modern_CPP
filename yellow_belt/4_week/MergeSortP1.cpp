//
// Created by Mahmud Jego on 4/15/21.
//

#include <iostream>
#include <vector>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if (range_end - range_begin < 2) {
		return ;
	}
	std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
	MergeSort(elements.begin(), elements.begin() + elements.size() / 2);
	MergeSort(elements.begin() + elements.size() / 2, elements.end());
	std::merge(elements.begin(), elements.begin() + elements.size() / 2,
			elements.begin() + elements.size() / 2, elements.end(), range_begin);
}

int main() {
	std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
	MergeSort(begin(v), end(v));
	for (int x : v) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

/*	std::vector<int> hello;
	std::vector<int> hello1 = {1,2,3,4,5};
	std::vector<int> t1 = {1,2,3,4,5, 6};
	std::vector<int> t2 = {1,2,3,4,5, 6};

	std::merge(t1.begin(), t1.end(), t2.begin(), t2.end(), std::back_inserter(hello));
	for (const auto &item : hello) {
		std::cout << item << ' ';
	}*/
	return 0;
}
