//
// Created by Mahmud Jego on 1/6/21.
//

#include <iostream>
#include <map>
#include <vector>

std::string getHistName(const std::vector<std::string>& vName)
{
	std::string szRes, szIsdupl = vName[(int)vName.size() - 1];

	if (vName.size() <= 1)
	{
		return (szRes);
	}
	else
	{
		szRes = " (";
		for (int i = (int)vName.size() - 2; i >= 0 ; --i)
		{
			if (szIsdupl != vName[i])
			{
				szRes += vName[i];
				if (i != 0 && vName[i] != vName[i - 1])
				{
					szRes += ", ";
				}
			}
			szIsdupl = vName[i];
		}
	}
	szRes += ")";
	if (szRes == " ()")
		szRes.clear();
	return (szRes);
}

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

	std::string GetFullNameWithHistory(int year)
	{
		std::string szFirstName, szLastName;
		std::vector<std::string> vFirstName, vLastName;

		for (const auto& nItem : mHistFirstName)
		{
			if (nItem.first <= year)
			{
				szFirstName = nItem.second;
				vFirstName.push_back(szFirstName);
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
				vLastName.push_back(szLastName);
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
			return (szLastName + getHistName(vLastName) + " with unknown first name");
		}
		else if (szLastName.empty())
		{
			return (szFirstName + getHistName(vFirstName) + " with unknown last name");
		}
		return (szFirstName + getHistName(vFirstName) + " "
		+ szLastName + getHistName(vLastName));
	}

private:
	std::map<int, std::string> mHistFirstName;
	std::map<int, std::string> mHistLastName;
};

using namespace std;
int main() {
	Person person;

	person.ChangeFirstName(1900, "Eugene");
	person.ChangeLastName(1900, "Sokolov");
	person.ChangeLastName(1910, "Sokolov");
	person.ChangeFirstName(1920, "Evgeny");
	person.ChangeLastName(1930, "Sokolov");
	cout << person.GetFullNameWithHistory(1940) << endl;
	cout << endl;

	Person person2;

	person2.ChangeFirstName(1965, "Polina");
	person2.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person2.GetFullNameWithHistory(year) << endl;
	}

	person2.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person2.GetFullNameWithHistory(year) << endl;
	}

	person2.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person2.GetFullNameWithHistory(year) << endl;
	}

	person2.ChangeFirstName(1990, "Polina");
	person2.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person2.GetFullNameWithHistory(1990) << endl;

	person2.ChangeFirstName(1966, "Pauline");
	cout << person2.GetFullNameWithHistory(1966) << endl;

	person2.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person2.GetFullNameWithHistory(year) << endl;
	}

	person2.ChangeLastName(1961, "Ivanova");
	cout << person2.GetFullNameWithHistory(1967) << endl;

	cout << endl;

	Person person1;

	person1.ChangeFirstName(1965, "Polina");
	person1.ChangeFirstName(1965, "Appolinaria");

	person1.ChangeLastName(1965, "Sergeeva");
	person1.ChangeLastName(1965, "Volkova");
	person1.ChangeLastName(1965, "Volkova-Sergeeva");

	for (int year : {1964, 1965, 1966}) {
		cout << person1.GetFullNameWithHistory(year) << endl;
	}
	cout << endl;

	Person person4;

	int year = 1;
	person4.ChangeFirstName(year, std::to_string(year)+"_first");
	person4.ChangeLastName(year, std::to_string(year)+"_last");
	std::cout << "year: " << year << '\n';
	std::cout << person4.GetFullNameWithHistory(year) << '\n';

	year = 2;
	person4.ChangeFirstName(year, std::to_string(year)+"_first");
	person4.ChangeLastName(year, std::to_string(year)+"_last");
	std::cout << "year: " << year << '\n';
	std::cout << person4.GetFullNameWithHistory(year) << '\n';

	year = 3;
	person4.ChangeFirstName(year, std::to_string(2)+"_first");
	person4.ChangeLastName(year, std::to_string(2)+"_last");
	std::cout << "year: " << year << '\n';
	std::cout << person4.GetFullNameWithHistory(year) << '\n';
	return 0;
}