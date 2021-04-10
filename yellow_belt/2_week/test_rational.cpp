//
// Created by Mahmud Jego on 4/10/21.
//

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <numeric>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		} catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		} catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

/*class Rational {
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
};*/

void DefaultRational() {
	{
		Rational rational;
		AssertEqual(rational.Numerator(), 0);
		AssertEqual(rational.Denominator(), 1);
	}

	{
		Rational rational(0, 1);
		AssertEqual(rational.Numerator(), 0);
		AssertEqual(rational.Denominator(), 1);
	}

}

void WhereNegativeNuAndDen() {
	Rational rational(-2, -3);
	AssertEqual(rational.Numerator(), 2);
	AssertEqual(rational.Denominator(), 3);
}

void WhereNegativeDen() {
	Rational rational(2, -3);
	AssertEqual(rational.Numerator(), -2);
	AssertEqual(rational.Denominator(), 3);
}

void WhereReduction() {
	{
		Rational rational(4, 16);
		AssertEqual(rational.Numerator(), 1);
		AssertEqual(rational.Denominator(), 4);
	}

	{
		Rational rational(3, 27);
		AssertEqual(rational.Numerator(), 1);
		AssertEqual(rational.Denominator(), 9);
	}

	{
		Rational rational(7, 63);
		AssertEqual(rational.Numerator(), 1);
		AssertEqual(rational.Denominator(), 9);
	}

	{
		Rational rational(6, 34);
		AssertEqual(rational.Numerator(), 3);
		AssertEqual(rational.Denominator(), 17);
	}
}


void WhereDenOne() {
	for (int i = 1; i < 333; ++i) {
		Rational rational(0, i);
		AssertEqual(rational.Numerator(), 0);
		AssertEqual(rational.Denominator(), 1);
	}
}


int main() {
	TestRunner runner;
	runner.RunTest(DefaultRational, "MyHeroTest");
	runner.RunTest(WhereNegativeNuAndDen, "WhereNegativeNuAndDen");
	runner.RunTest(WhereNegativeDen, "WhereNegativeDen");
	runner.RunTest(WhereReduction, "WhereReduction");
	runner.RunTest(WhereDenOne, "WhereDenOne");

	return 0;
}