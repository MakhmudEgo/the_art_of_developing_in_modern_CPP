//
// Created by Mahmud Jego on 1/5/21.
//

#include <iostream>
#include <map>

void ifChangeCapital(std::map<std::string, std::string>& mDirecCap)
{
	std::string szCountry, szNewCapital;

	std::cin >> szCountry >> szNewCapital;
	if (!mDirecCap.count(szCountry))
	{
		std::cout << "Introduce new country " <<
		szCountry << " with capital " << szNewCapital;
	}
	else if (mDirecCap[szCountry] == szNewCapital)
	{
		std::cout << "Country " << szCountry <<
		" hasn't changed its capital";
	}
	else if (mDirecCap[szCountry] != szNewCapital)
	{
		std::cout << "Country " << szCountry << " has changed its capital from "
		<< mDirecCap[szCountry] << " to " << szNewCapital;
	}
	std::cout << std::endl;
	mDirecCap[szCountry] = szNewCapital;
}

void ifRename(std::map<std::string, std::string>& mDirecCap)
{
	std::string szOldCountryName, szNewCountryName;

	std::cin >> szOldCountryName >> szNewCountryName;
	if (!mDirecCap.count(szOldCountryName)
	|| mDirecCap.count(szNewCountryName))
	{
		std::cout << "Incorrect rename, skip";
	}
	else
	{
		mDirecCap[szNewCountryName] = mDirecCap[szOldCountryName];
		mDirecCap.erase(szOldCountryName);
		std::cout << "Country " << szOldCountryName <<
		" with capital " << mDirecCap[szNewCountryName] <<
		" has been renamed to " << szNewCountryName;
	}
	std::cout << std::endl;
}

void ifAbout(std::map<std::string, std::string>& mDirecCap)
{
	std::string szCountry;

	std::cin >> szCountry;
	if (!mDirecCap.count(szCountry))
	{
		std::cout << "Country " <<
		szCountry << " doesn't exist";
	}
	else
	{
		std::cout << "Country " << szCountry <<
		" has capital " << mDirecCap[szCountry];
	}
	std::cout << std::endl;
}

void ifDump(const std::map<std::string, std::string>& mDirecCap)
{
	if (mDirecCap.empty())
	{
		std::cout << "There are no countries in the world";
	}
	else
	{
		for (const auto& mItem : mDirecCap)
		{
			std::cout << mItem.first << '/'
			<< mItem.second << ' ';
		}
	}
	std::cout << std::endl;
}

int main()
{
	int nAmountCmd;
	std::string szCmd;
	std::map<std::string, std::string> mDirecCap;

	std::cin >> nAmountCmd;
	for (int i = 0; i < nAmountCmd; ++i)
	{
		std::cin >> szCmd;
		if (szCmd == "CHANGE_CAPITAL")
		{
			ifChangeCapital(mDirecCap);
		}
		else if (szCmd == "RENAME")
		{
			ifRename(mDirecCap);
		}
		else if (szCmd == "ABOUT")
		{
			ifAbout(mDirecCap);
		}
		else if (szCmd == "DUMP")
		{
			ifDump(mDirecCap);
		}
	}
	return (0);
}