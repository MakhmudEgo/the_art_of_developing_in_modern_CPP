//
// Created by Mahmud Jego on 1/6/21.
//

#include <iostream>
#include <map>
#include <set>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m)
{
	std::set<std::string> sRes;
	for (const auto& mItem : m)
	{
		sRes.insert(mItem.second);
	}
	return (sRes);
}

int main()
{
	std::set<std::string> values = BuildMapValuesSet({
		{1, "odd"},
		{2, "even"},
		{3, "odd"},
		{4, "even"},
		{5, "odd"}
		});

	for (const std::string& value : values)
	{
		std::cout << value << std::endl;
	}
	return (0);
}