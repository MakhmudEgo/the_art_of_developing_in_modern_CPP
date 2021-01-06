//
// Created by Mahmud Jego on 1/6/21.
//

#include <iostream>
#include <set>
#include <map>

int main()
{
	int nAmountCmd, nAmountStops, nBus = 1;
	std::string szStop;
	std::map<std::set<std::string>, int> mBus;
	std::set<std::string> sBus;

	std::cin >> nAmountCmd;
	for (int i = 0; i < nAmountCmd; ++i)
	{
		std::cin >> nAmountStops;
		for (int j = 0; j < nAmountStops; ++j)
		{
			std::cin >> szStop;
			sBus.insert(szStop);
		}
		if (mBus.count(sBus))
		{
			std::cout << "Already exists for " << mBus[sBus];
		}
		else
		{
			std::cout << "New bus " << nBus;
			mBus[sBus] = nBus++;
		}
		std::cout << std::endl;
		sBus.clear();
	}
	return (0);
}