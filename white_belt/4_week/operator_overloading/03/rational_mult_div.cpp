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

int main() {
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			std::cout << "2/3 * 4/3 != 8/9" << std::endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			std::cout << "5/4 / 15/8 != 2/3" << std::endl;
			return 2;
		}
	}

	std::cout << "OK" << std::endl;
	return 0;
}