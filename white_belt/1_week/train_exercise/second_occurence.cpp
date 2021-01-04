//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>

int main()
{
	std::string szStr;
	int nFlag(0);

	std::cin >> szStr;
	for (int i = 0; i < szStr.size(); ++i)
	{
		if (szStr[i] == 'f')
		{
			nFlag++;
		}
		if (nFlag == 2)
		{
			std::cout << i << std::endl;
			return (0);
		}
	}
	if (nFlag)
	{
		std::cout << -1 << std::endl;
	}
	else
	{
		std::cout << -2 << std::endl;
	}
	return (0);
}