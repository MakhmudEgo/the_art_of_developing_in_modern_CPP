//
// Created by Mahmud Jego on 1/5/21.
//

#include <iostream>
#include <vector>
#include <map>

void ifNewBus(std::map<std::string, std::vector<std::string>>& mBusStops,
		std::map<std::string, std::vector<std::string>>& mStops)
{
	std::string szBus, szStop;
	int nStopCount;

	std::cin >> szBus >> nStopCount;
	for (int i = 0; i < nStopCount; ++i)
	{
		std::cin >> szStop;
		mBusStops[szBus].push_back(szStop);
	}
	for (const auto& vItem : mBusStops[szBus])
	{
		mStops[vItem].push_back(szBus);
	}
}

void ifBusForStop(std::map<std::string, std::vector<std::string>>& mStops)
{
	std::string szStop;

	std::cin >> szStop;
	if (!mStops.count(szStop))
	{
		std::cout << "No stop";
	}
	else
	{
		for (const auto& szItem : mStops[szStop])
		{
			std::cout << szItem << ' ';
		}
	}
	std::cout << std::endl;
}

void ifStopsForBus(std::map<std::string, std::vector<std::string>>& mBusStops,
		std::map<std::string, std::vector<std::string>>& mStops)
{
	std::string szBus;

	std::cin >> szBus;
	if (!mBusStops.count(szBus))
	{
		std::cout << "No bus" << std::endl;
	}
	else
	{
		for (const auto& szItem : mBusStops[szBus])
		{
			std::cout << "Stop " << szItem << ':';
			if (mStops[szItem].size() == 1)
			{
				std::cout << " no interchange";
			}
			else
			{
				for (const auto& szItem1 : mStops[szItem])
				{
					if (szBus != szItem1)
					{
						std::cout << ' ' << szItem1;
					}
				}
			}
			std::cout << std::endl;
		}
	}
}

void ifAllBuses(std::map<std::string, std::vector<std::string>>& mBusStops)
{
	if (mBusStops.empty())
	{
		std::cout << "No buses" << std::endl;
	}
	else
	{
		for (const auto& mItem : mBusStops)
		{
			std::cout << "Bus " << mItem.first << ':';
			for (const auto& szItem : mItem.second)
			{
				std::cout << ' ' << szItem;
			}
			std::cout << std::endl;
		}
	}
}

int main()
{
	std::map<std::string, std::vector<std::string>> mBusStops;
	std::map<std::string, std::vector<std::string>> mStops;
	int nAmountCmd;
	std::string szCmd;

	std::cin >> nAmountCmd;
	for (int i = 0; i < nAmountCmd; ++i)
	{
		std::cin >> szCmd;
		if (szCmd == "NEW_BUS")
		{
			ifNewBus(mBusStops, mStops);
		}
		else if (szCmd == "BUSES_FOR_STOP")
		{
			ifBusForStop(mStops);
		}
		else if (szCmd == "STOPS_FOR_BUS")
		{
			ifStopsForBus(mBusStops, mStops);
		}
		else if (szCmd == "ALL_BUSES")
		{
			ifAllBuses(mBusStops);
		}
	}
	return (0);
}