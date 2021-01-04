//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>

int main()
{
	int nA, nB, nTmp;

	std::cin >> nA >> nB;
	while (nB)
	{
		nTmp = nA % nB;
		nA = nB;
		nB = nTmp;
	}
	std::cout << nA << std::endl;
	return (0);
}