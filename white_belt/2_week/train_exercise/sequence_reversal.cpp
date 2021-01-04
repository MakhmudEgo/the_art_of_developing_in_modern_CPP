//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>
#include <vector>

void Reverse(std::vector<int>& v)
{
	int nTmp;

	for (int i = 0; i < v.size() / 2; ++i)
	{
		nTmp = v[i];
		v[i] = v[v.size() - i - 1];
		v[v.size() - i - 1] = nTmp;
	}
}

int main()
{
	std::vector<int> numbers = {1, 5, 3, 4, 2};

	Reverse(numbers);
	for (auto& item : numbers)
	{
		std::cout << item << ' ';
	}
	std::cout << std::endl;
	return (0);
}