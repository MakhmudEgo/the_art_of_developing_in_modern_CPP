//
// Created by Mahmud Jego on 1/5/21.
//

#include <iostream>
#include <vector>

void ifNext(int& nCurrentMonth, std::vector<std::vector<std::string>>& vCurrentMonthAff)
{
	std::vector<int> vMonthDay = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::vector<std::string> vszPrevMonthRemainsAff;
	int nNextMonth = nCurrentMonth == 11 ? 0 : nCurrentMonth + 1;

	int nMonthDays = vMonthDay[nNextMonth];
	for (; nMonthDays < vMonthDay[nCurrentMonth]; ++nMonthDays)
	{
		for (const auto& szItem : vCurrentMonthAff[nMonthDays])
		{
			vszPrevMonthRemainsAff.push_back(szItem);
		}
	}
	// resize on next month vCurrentMonth
	vCurrentMonthAff.resize(vMonthDay[nNextMonth]);
	if (vMonthDay[nCurrentMonth] > vMonthDay[nNextMonth])
	{
		vCurrentMonthAff[vCurrentMonthAff.size() - 1].insert(vCurrentMonthAff[vCurrentMonthAff.size() - 1].end(),
		vszPrevMonthRemainsAff.begin(), vszPrevMonthRemainsAff.end());
	}
	nCurrentMonth = nNextMonth;
}

int main()
{
	int nCurrentMonth(0), nAmountCmd, nDayCmd;
	std::vector<std::vector<std::string>> vCurrentMonthAff(31);
	std::string szCmd;

	std::cin >> nAmountCmd;
	for (int i = 0; i < nAmountCmd; ++i)
	{
		std::cin >> szCmd;
		if (szCmd == "NEXT")
		{
			ifNext(nCurrentMonth, vCurrentMonthAff);
		}
		else if (szCmd == "ADD")
		{
			std::cin >> nDayCmd >> szCmd;
			vCurrentMonthAff[nDayCmd - 1].push_back(szCmd);
		}
		else if (szCmd == "DUMP")
		{
			std::cin >> nDayCmd;
			std::cout << vCurrentMonthAff[nDayCmd - 1].size();
			for (const auto& szItem : vCurrentMonthAff[nDayCmd - 1])
			{
				std::cout  << ' ' << szItem;
			}
			std::cout << std::endl;
		}
	}
	return (0);
}
