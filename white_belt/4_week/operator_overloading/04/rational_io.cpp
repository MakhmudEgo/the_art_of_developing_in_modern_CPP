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

#include <sstream>

int main() {
	{
		std::ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			std::cout << "Rational(-6, 8) should be written as \"-3/4\"" << std::endl;
			return 1;
		}
	}
/*	{
		std::stringstream ss ("4/-6");
		Rational r (1, 5);
		ss >> r;
		std::cout << r;
	}*/

	{
		std::istringstream input("5  /   7  ");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			std::cout << "5/7 is incorrectly read as " << r << std::endl;
			return 2;
		}
	}

	{
		std::istringstream input("");
		Rational r;
		bool correct = !(input >> r);
		if (!correct) {
			std::cout << "Read from empty stream works incorrectly" << std::endl;
			return 3;
		}
	}

	{
		std::istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			std::cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << std::endl;
			return 4;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			std::cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
			return 5;
		}
	}

	{
		std::istringstream input1("1*2"), input2("1  /  d   1"), input3("/4");
		Rational r1, r2, r3;
		input1 >> r1;
		input2 >> r2;
		input3 >> r3;
		bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
		if (!correct) {
			std::cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
				 << r1 << " " << r2 << " " << r3 << std::endl;

			return 6;
		}
	}

	std::cout << "OK" << std::endl;
	return 0;
}