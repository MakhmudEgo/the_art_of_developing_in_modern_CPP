//
// Created by Mahmud Jego on 1/6/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int nAmountWords;
	std::string szWord;
	std::cin >> nAmountWords;
	std::vector<std::string> vWords(nAmountWords);

	for (auto& szItem : vWords)
	{
		std::cin >> szItem;
	}
	std::sort(std::begin(vWords), std::end(vWords), [](std::string szW1, std::string szW2)
	{
		for (auto& cItem : szW1)
		{
			cItem = tolower(cItem);
		}
		for (auto& cItem : szW2)
		{
			cItem = tolower(cItem);
		}
		return (szW1 < szW2);
	});
	for (const auto& szItem : vWords)
	{
		std::cout << szItem << ' ';
	}
	std::cout << std::endl;
	return (0);
}