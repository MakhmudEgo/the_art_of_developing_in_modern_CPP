//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;
	if (!b)
	{
		std::cout << "Impossible";
	}
	else
	{
		std::cout << a / b;
	}
	return (0);
}