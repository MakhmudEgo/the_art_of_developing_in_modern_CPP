//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>
#include <vector>

std::vector<int> Reversed(const std::vector<int>& v)
{
	std::vector<int> vRes;

	for (int i = 0; i < v.size(); ++i)
	{
		vRes.push_back(v[v.size() - i - 1]);
	}
	return (vRes);
}

int main()
{
	std::vector<int> vInt = {1, 2, 4, 56, 7, 8, 34, 4};

	std::vector<int> vIntReverse = Reversed(vInt);
	for (const auto& nItem : vInt)
	{
		std::cout << nItem << ' ';
	}
	std::cout << std::endl;
	for (const auto& nItem : vIntReverse)
	{
		std::cout << nItem << ' ';
	}
	std::cout << std::endl;
	return (0);
}