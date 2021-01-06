//
// Created by Mahmud Jego on 1/6/21.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int nAmountInt;
	std::cin >> nAmountInt;
	std::vector<int> vInt(nAmountInt);

	for (auto& nItem : vInt)
	{
		std::cin >> nItem;
	}
	std::sort(std::begin(vInt), std::end(vInt), [](int nA, int nB)
	{
		return (abs(nA) < abs(nB));
	});
	for (const auto& nItem : vInt)
	{
		std::cout << nItem << ' ';
	}
	std::cout << std::endl;
	return (0);
}
