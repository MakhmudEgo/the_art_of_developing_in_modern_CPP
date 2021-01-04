//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>

int main()
{
	float n, a, b, x, y;

	std::cin >> n >> a >> b >> x >> y;
	if (n > b && a < b)
	{
		std::cout << n - (n * y / 100);
	}
	else if (n > a)
	{
		std::cout << n - (n * x / 100);
	}
	else
	{
		std::cout << n;
	}
}