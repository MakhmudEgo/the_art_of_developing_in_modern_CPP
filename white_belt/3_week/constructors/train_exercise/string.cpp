//
// Created by Mahmud Jego on 1/7/21.
//

#include <iostream>
#include <algorithm>

class ReversibleString {
public:
	ReversibleString()
	{
		szString = """";
	}

	ReversibleString(const std::string& szSrc)
	{
		szString = szSrc;
	}

	void Reverse()
	{
		std::reverse(std::begin(szString), std::end(szString));
	}

	std::string ToString() const
	{
		return (szString);
	}
private:
	std::string szString;
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	std::cout << s.ToString() << std::endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	std::string tmp = s_ref.ToString();
	std::cout << tmp << std::endl;

	ReversibleString empty;
	std::cout << '"' << empty.ToString() << '"' << std::endl;

	return 0;
}