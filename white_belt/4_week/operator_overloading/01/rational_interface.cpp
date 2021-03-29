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

private:
	int _num;
	int _den;
};

int main() {
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			std::cout << "Rational(3, 10) != 3/10" << std::endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			std::cout << "Rational(8, 12) != 2/3" << std::endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			std::cout << "Rational(-4, 6) != -2/3" << std::endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			std::cout << "Rational(4, -6) != -2/3" << std::endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			std::cout << "Rational(0, 15) != 0/1" << std::endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			std::cout << "Rational() != 0/1" << std::endl;
			return 5;
		}
	}

	{
		const Rational r(-2, -3);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			std::cout << "Rational(0, 15) != 0/1" << std::endl;
			return 4;
		}
	}

	std::cout << "OK" << std::endl;
	return 0;
}