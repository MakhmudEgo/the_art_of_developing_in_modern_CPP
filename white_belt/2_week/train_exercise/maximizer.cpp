//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>

void UpdateIfGreater(const int& nA, int& nB)
{
	if (nA > nB)
	{
		nB = nA;
	}
}

int main()
{
	int nA(5), nB(1);

	UpdateIfGreater(nA, nB);
	std::cout << nB << std::endl;
	return (0);
}