//
// Created by Mahmud Jego on 1/6/21.
//

#include <iostream>
#include <set>
#include <map>

void ifAdd(std::map<std::string, std::set<std::string>>& mSynonyms)
{
	std::string szWord1, szWord2;

	std::cin >> szWord1 >> szWord2;
	mSynonyms[szWord1].insert(szWord2);
	mSynonyms[szWord2].insert(szWord1);
}


void ifCount(std::map<std::string, std::set<std::string>>& mSynonyms)
{
	std::string szWord;

	std::cin >> szWord;
	std::cout << mSynonyms[szWord].size() << std::endl;
}

void ifCheck(std::map<std::string, std::set<std::string>>& mSynonyms)
{
	std::string szWord1, szWord2;

	std::cin >> szWord1 >> szWord2;
	if (mSynonyms[szWord1].count(szWord2))
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
	std::cout << std::endl;
}

int main()
{
	int nAmountCmd;
	std::string szCmd;
	std::map<std::string, std::set<std::string>> mSynonyms;

	std::cin >> nAmountCmd;
	for (int i = 0; i < nAmountCmd; ++i)
	{
		std::cin >> szCmd;
		if (szCmd == "ADD")
		{
			ifAdd(mSynonyms);
		}
		else if (szCmd == "COUNT")
		{
			ifCount(mSynonyms);
		}
		else if (szCmd == "CHECK")
		{
			ifCheck(mSynonyms);
		}
	}
	return (0);
}