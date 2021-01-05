//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>

int Factorial(int nI)
{
	int nRes(1), nJ(1);

	if (nI < 2)
	{
		return (1);
	}
	while (nJ++ < nI)
	{
		nRes *= nJ;
	}
	return (nRes);
}

int main()
{
	int i = 0;

	while (i != 77)
	{
		std::cin >> i;
		std::cout << Factorial(i) << std::endl;
	}
	return (0);
}