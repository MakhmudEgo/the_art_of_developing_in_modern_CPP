//
// Created by Mahmud Jego on 1/6/21.
//

#include <iostream>
#include <map>

class Person {
public:
	void ChangeFirstName(int year, const std::string& first_name)
	{
		mHistFirstName[year] = first_name;
	}

	void ChangeLastName(int year, const std::string& last_name)
	{
		mHistLastName[year] = last_name;
	}
	std::string GetFullName(int year)
	{
		std::string szFirstName, szLastName;

		for (const auto& nItem : mHistFirstName)
		{
			if (nItem.first <= year)
			{
				szFirstName = nItem.second;
			}
			else
			{
				break ;
			}
		}
		for (const auto& nItem : mHistLastName)
		{
			if (nItem.first <= year)
			{
				szLastName = nItem.second;
			}
			else
			{
				break ;
			}
		}
		if (szFirstName.empty() && szLastName.empty())
		{
			szFirstName = "Incognito";
			return (szFirstName);
		}
		else if (szFirstName.empty())
		{
			return (szLastName + " with unknown first name");
		}
		else if (szLastName.empty())
		{
			return (szFirstName + " with unknown last name");
		}
		return (szFirstName + " " + szLastName);
	}

private:
	std::map<int, std::string> mHistFirstName;
	std::map<int, std::string> mHistLastName;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	return 0;
}
