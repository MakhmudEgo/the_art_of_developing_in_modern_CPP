//
// Created by Mahmud Jego on 4/11/21.
//

#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y) {
	return x + y;
}
std::string Reverse(std::string s) {
	std::reverse(s.begin(), s.end());
	return s;
}
void Sort(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
}

