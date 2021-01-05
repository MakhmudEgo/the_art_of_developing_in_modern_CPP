//
// Created by Mahmud Jego on 1/6/21.
//

#include <iostream>
#include <set>


int main()
{
	int nAmountWords;
	std::string szWord;
	std::set<std::string> sWords;

	std::cin >> nAmountWords;
	for (int i = 0; i < nAmountWords; ++i)
	{
		std::cin >> szWord;
		sWords.insert(szWord);
	}
	std::cout << sWords.size() << std::endl;
	return (0);
}