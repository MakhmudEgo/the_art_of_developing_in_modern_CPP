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
			throw std::invalid_argument("знаменатель равен нулю.");
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
			throw std::domain_error("знаменатель равен нулю.");
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


int main() {
	try {
		Rational r(1, 0);
		std::cout << "Doesn't throw in case of zero denominator" << std::endl;
		return 1;
	} catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		std::cout << "Doesn't throw in case of division by zero" << std::endl;
		return 2;
	} catch (std::domain_error& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "OK" << std::endl;
	return 0;
}