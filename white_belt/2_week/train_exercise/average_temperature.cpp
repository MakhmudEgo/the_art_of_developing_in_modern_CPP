//
// Created by Mahmud Jego on 1/5/21.
//

#include <iostream>
#include <vector>

int main()
{
	int nSize, nAveTemp(0);
	std::cin >> nSize;
	std::vector<int> vTemp(nSize), vAveTemp;

	for (auto& nItem : vTemp)
	{
		std::cin >> nItem;
		nAveTemp += nItem;
	}
	nAveTemp /= nSize;
	for (int i = 0; i < vTemp.size(); ++i)
	{
		if (vTemp[i] > nAveTemp)
		{
			vAveTemp.push_back(i);
		}
	}
	std::cout << vAveTemp.size() << std::endl;
	for (const auto& nItem : vAveTemp)
	{
		std::cout << nItem << ' ';
	}
	return (0);
}