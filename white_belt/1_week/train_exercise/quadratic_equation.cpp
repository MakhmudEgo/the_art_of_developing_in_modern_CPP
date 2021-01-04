//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>
#include <cmath>

int main()
{
	float a, b, c, d;

	std::cin >> a >> b >> c;
	d = b * b - (4 * a * c);
	if ((a == 0 && c == a) || (b == 0 && b == c))
	{
		std::cout << 0;
	}
	else if (a == 0 && a != b)
	{
		std::cout << (-c) / b;
	}
	else if (d == 0 && a != d && b != d)
	{
		std::cout << (-b) / (2 * a);
	}
	else if (d > 0)
	{
		std::cout << (-b + sqrt(d)) / (2 * a) << " "
		<< ((-b) - sqrt(d)) / (2 * a);
	}
	return 0;
}