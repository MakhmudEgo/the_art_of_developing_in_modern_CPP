//
// Created by Mahmud Jego on 1/5/21.
//

#include <iostream>
#include <map>

std::map<char, int> BuildCharCounters(const std::string& szSrc)
{
	std::map<char, int> mRes;

	for (const auto& cItem: szSrc)
	{
		++mRes[cItem];
	}
	return (mRes);
}

bool isMapEqual(const std::map<char, int>& mSrc1, const std::map<char, int>& mSrc2)
{
	return (mSrc1 == mSrc2);
}

int main()
{
	std::string szInp1, szInp2;
	int nAmountCmd;

	std::cin >> nAmountCmd;
	for (int i = 0; i < nAmountCmd; ++i)
	{
		std::cin >> szInp1 >> szInp2;
		if (isMapEqual(BuildCharCounters(szInp1), BuildCharCounters(szInp2)))
		{
			std::cout << "YES";
		}
		else
		{
			std::cout << "NO";
		}
		std::cout << std::endl;
	}
	return (0);
}