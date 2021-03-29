//
// Created by Mahmud Jego on 3/29/21.
//

//
// Created by Mahmud Jego on 3/27/21.
//

#include <iostream>
#include <numeric>

class Rational {
public:
	Rational()
			: _num(0), _den(1) {}

	Rational(int numerator, int denominator) {
		int nod = std::gcd(numerator,denominator);
		this->_num = numerator / nod;
		this->_den = this->_num != 0 ? denominator / nod : 1;
		if (this->_den < 0)
		{
			this->_num = -this->_num;
			this->_den = -this->_den;
		}
	}

	int Numerator() const {
		return (this->_num);
	}
	int Denominator() const {
		return (this->_den);
	}

	bool operator==(const Rational& other) const {
		if (this->_num == other._num)
			return (this->_den == other._den);
		return (this->_num == other._num);
	}
	Rational operator+(const Rational& other) const {
		return Rational(this->_num * other._den + other._num * this->_den,
						this->_den * other._den);
	}
	Rational operator-(const Rational& other) const {
		return Rational(this->_num * other._den - other._num * this->_den,
						this->_den * other._den);
	}
	Rational operator*(const Rational& other) const {
		return Rational(this->_num * other._num,
						this->_den * other._den);
	}
	Rational operator/(const Rational& other) const {
		return Rational(this->_num * other._den,
						this->_den * other._num);
	}
	bool operator<(const Rational& other) const {
		return (this->_num * other._den < other._num * this->_den);
	}
	bool operator>(const Rational& other) const {
		return (this->_num * other._den > other._num * this->_den);
	}
private:
	int _num;
	int _den;
};

std::ostream &operator<<(std::ostream &os, const Rational &rational) {
	os << rational.Numerator() << '/' << rational.Denominator();
	return os;
}

std::istream  &operator>>(std::istream &is, Rational& rational)
{
	if (is) {
		int num, den;
		char c;
		is >> num;
		if (is.fail() || is.eof() || !is)
			return is;
		is >> c;
		if (is.fail() || c != '/' || is.eof() || !is)
			return is;
		is >> den;
		if (is.fail() || c != '/' || den <= 0)
			return is;
		rational = Rational(num, den);
	}
	return is;
}

#include <set>
#include <vector>
#include <map>

int main() {
	{
		const std::set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
		if (rs.size() != 3) {
			std::cout << "Wrong amount of items in the set" << std::endl;
			return 1;
		}

		std::vector<Rational> v;
		for (auto x : rs) {
			v.push_back(x);
		}
		if (v != std::vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
			std::cout << "Rationals comparison works incorrectly" << std::endl;
			return 2;
		}
	}

	{
		std::map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2) {
			std::cout << "Wrong amount of items in the map" << std::endl;
			return 3;
		}
	}

	std::cout << "OK" << std::endl;
	return 0;
}