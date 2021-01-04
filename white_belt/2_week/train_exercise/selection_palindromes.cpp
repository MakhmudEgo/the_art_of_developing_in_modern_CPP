//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>
#include <vector>

bool IsPalindrom(std::string szSrc)
{
	for (int i = 0; i <= szSrc.size() / 2; ++i)
	{
		if (szSrc[i] != szSrc[szSrc.size() - i - 1])
		{
			return (false);
		}
	}
	return (true);
}

std::vector<std::string> PalindromFilter(std::vector<std::string> vWords, int nMinLength)
{
	for (int i = 0; i < vWords.size(); ++i)
	{
		if (!(nMinLength <= vWords[i].size() && IsPalindrom(vWords[i])))
		{
			vWords.erase(vWords.begin() + i);
			i--;
		}
	}
	return (vWords);
}

int main()
{
	std::vector<std::string> vWords = PalindromFilter({"aba", "hello", "anna", "madam"}, 4);
	for (int i = 0; i < vWords.size(); ++i)
	{
		std::cout << vWords[i] << ' ';
	}
	std::cout << std::endl;
	return (0);
}