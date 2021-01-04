//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vRes;
	int nI;

	std::cin >> nI;
	do
	{
		vRes.push_back(nI % 2);
	}
	while (nI /= 2);
	for (int i = (int)vRes.size() - 1; i > -1; --i)
	{
		std::cout << vRes[i];
	}
	return (0);
}