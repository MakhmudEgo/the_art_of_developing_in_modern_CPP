//
// Created by Mahmud Jego on 1/5/21.
//

#include <iostream>
#include <vector>

int getWorryCust(const std::vector<bool>& vCust)
{
	int nWorry(0);

	for (const auto& nItem : vCust)
	{
		if (nItem)
		{
			nWorry++;
		}
	}
	return (nWorry);
}

int main()
{
	int nAmountCmd, nAmountCust;
	std::string szCmd;
	std::vector<bool> vCust(0, false);

	std::cin >> nAmountCmd;
	for (int i = 0; i < nAmountCmd; ++i)
	{
		std::cin >> szCmd;
		if (szCmd == "COME")
		{
			std::cin >> nAmountCust;
			vCust.resize(vCust.size() + nAmountCust);
		}
		else if (szCmd == "WORRY" || szCmd == "QUIET")
		{
			std::cin >> nAmountCust;
			if (szCmd == "WORRY")
			{
				vCust[nAmountCust] = true;
			}
			else
			{
				vCust[nAmountCust] = false;
			}
		}
		else if (szCmd == "WORRY_COUNT")
		{
			std::cout << getWorryCust(vCust) << std::endl;
		}
	}
	return (0);
}