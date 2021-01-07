//
// Created by Mahmud Jego on 1/7/21.
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
		for (int i = (int)vName.size() - 2; i >= 0 ; i--)
		{
			if (szIsdupl != vName[i])
			{
				szRes += vName[i];
				if (i != 0)
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
	Person (const std::string& szNewFirstName, const std::string& szNewLastName, const int& nNewYear)
	{
		mHistFirstName[nNewYear] = szNewFirstName;
		mHistLastName[nNewYear] = szNewLastName;
		nAge = nNewYear;
	}

	void ChangeFirstName(int year, const std::string& first_name)
	{
		if (year >= nAge)
		{
			mHistFirstName[year] = first_name;
		}
	}

	void ChangeLastName(int year, const std::string& last_name)
	{
		if (year >= nAge)
		{
			mHistLastName[year] = last_name;
		}
	}

	std::string GetFullName(int year) const
	{
		if (year < nAge)
		{
			return ("No person");
		}
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
		return (szFirstName + " " + szLastName);
	}

	std::string GetFullNameWithHistory(int year) const
	{
		if (year < nAge)
		{
			return ("No person");
		}
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
		return (szFirstName + getHistName(vFirstName) + " "
				+ szLastName + getHistName(vLastName));
	}

private:
	std::map<int, std::string> mHistFirstName;
	std::map<int, std::string> mHistLastName;
	int nAge;
};

int main(){
	Person person ("-1_first","-1_last",-1);

	int year = 3;
	person.ChangeFirstName(year, std::to_string(year)+"_first");
	person.ChangeLastName(year, std::to_string(year)+"_last");

	year = 5;
	person.ChangeFirstName(year, std::to_string(year)+"_first");
	person.ChangeLastName(year, std::to_string(year)+"_last");

	year = 1;
	person.ChangeFirstName(year, std::to_string(3)+"_first");
	person.ChangeLastName(year, std::to_string(3)+"_last");

	year = 7;
	std::cout << "year: " << year << '\n';
	std::cout << person.GetFullNameWithHistory(year) << '\n';

	Person person1("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		std::cout << person1.GetFullNameWithHistory(year) << std::endl;
	}

	person1.ChangeFirstName(1965, "Appolinaria");
	person1.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		std::cout << year << std::endl;
		std::cout << person1.GetFullNameWithHistory(year) << std::endl;
	}
	return 0;
}