//
// Created by Mahmud Jego on 1/5/21.
//

#include <iostream>
#include <vector>
#include <map>

int main()
{
	int nNumBus = 1, nAmountCmd, nAmountStops;
	std::map<std::vector<std::string>, int> mStopsBus;
	std::vector<std::string> vStops;
	std::string szStop;

	std::cin >> nAmountCmd;
	for (int i = 0; i < nAmountCmd; ++i)
	{
		std::cin >> nAmountStops;
		for (int j = 0; j < nAmountStops; ++j)
		{
			std::cin >> szStop;
			vStops.push_back(szStop);
		}
		if (mStopsBus.count(vStops))
		{
			std::cout << "Already exists for " << mStopsBus[vStops];
		}
		else
		{
			std::cout << "New bus " << nNumBus;
			mStopsBus[vStops] = nNumBus++;
		}
		std::cout << std::endl;
		vStops.clear();
	}
	return (0);
}