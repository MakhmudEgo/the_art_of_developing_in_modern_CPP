//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>

bool IsPalindrom(std::string szSrc)
{
	for (int i = 0; i <= szSrc.size() / 2; ++i)
	{
		if (szSrc[i] != szSrc[szSrc.size() - i - 1])
		{
			return (false);
		}
	}
	return (true);
}

int main()
{
	std::string szStr;

	std::cout.setf(std::ostream::boolalpha);
	while (szStr != "exit")
	{
		std::cin >> szStr;
		std:: cout << IsPalindrom(szStr) << std::endl;
	}
	return (0);
}