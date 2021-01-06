//
// Created by Mahmud Jego on 1/6/21.
//

#include <iostream>
#include <vector>

class SortedStrings {
public:
	void AddString(const std::string& s)
	{
		vStrings.push_back(s);
	}

	std::vector<std::string> GetSortedStrings()
	{
		std::sort(std::begin(vStrings), std::end(vStrings));
		return (vStrings);
	}
private:
	std::vector<std::string> vStrings;
};


void PrintSortedStrings(SortedStrings& strings)
{
	for (const std::string& s : strings.GetSortedStrings())
	{
		std::cout << s << " ";
	}
	std::cout << std::endl;
}

int main()
{
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}