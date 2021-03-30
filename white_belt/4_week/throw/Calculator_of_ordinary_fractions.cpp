//
// Created by Mahmud Jego on 3/30/21.
//

#include <iostream>
#include <numeric>

class Rational {
public:
	Rational()
			: _num(0), _den(1) {}

	Rational(int numerator, int denominator) {
		if (denominator == 0)
			throw std::invalid_argument("Invalid argument");
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
		if (this->_den * other._num == 0)
			throw std::domain_error("Division by zero");
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
		if (is.fail() || c != '/')
			return is;
		rational = Rational(num, den);
	}
	return is;
}


int main() {
	try {
		Rational r1, r2;
		char operation;
		std::cin >> r1 >> operation >> r2;
		if (operation == '+')
			std::cout << r1 + r2;
		if (operation == '-')
			std::cout << r1 - r2;
		if (operation == '*')
			std::cout << r1 * r2;
		if (operation == '/')
			std::cout << r1 / r2;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}