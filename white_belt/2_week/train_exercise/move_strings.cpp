//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>
#include <vector>

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination)
{
	for (const auto& szItem : source)
	{
		destination.push_back(szItem);
	}
	source.clear();
}

int main()
{
	std::vector<std::string> source = {"a", "b", "c"};
	std::vector<std::string> destination = {"z"};

	MoveStrings(source, destination);
	for (auto &szItem : source)
	{
		std::cout << szItem << ' ';
	}
	for (auto &szItem : destination)
	{
		std::cout << szItem << ' ';
	}
	std::cout << std::endl;
}