//
// Created by Mahmud Jego on 4/10/21.
//

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

bool IsPalindrom(std::string szSrc)
{
	for (size_t i = 0; i <= szSrc.size() / 2; ++i)
	{
		if (szSrc[i] != szSrc[szSrc.size() - i - 1])
		{
			return (false);
		}
	}
	return (true);
}

void MyHeroTestsForPal() {
	AssertEqual(IsPalindrom("hello"), false);
	AssertEqual(IsPalindrom("helleh"), true);
	AssertEqual(IsPalindrom("mama"), false);
	AssertEqual(IsPalindrom("helle"), false);
	AssertEqual(IsPalindrom("elleh"), false);
	AssertEqual(IsPalindrom("helloafasdfasdfolleh"), false);
	AssertEqual(IsPalindrom("dannaf"), false);
	AssertEqual(IsPalindrom("danna"), false);
	AssertEqual(IsPalindrom("dannadd"), false);
	AssertEqual(IsPalindrom("dannad       "), false);
	AssertEqual(IsPalindrom("         dannad"), false);
	AssertEqual(IsPalindrom("         adannad"), false);
	AssertEqual(IsPalindrom(""), true);
	AssertEqual(IsPalindrom("1"), true);
	AssertEqual(IsPalindrom("1111111111111111111111111"), true);
	AssertEqual(IsPalindrom("2211111111111dgetgdffxzgfsdg11111111111122"), false);
	AssertEqual(IsPalindrom("1                       1"), true);
	AssertEqual(IsPalindrom("1                       anna                       1"), true);
	AssertEqual(IsPalindrom("1                       anna                      1"), false);
	AssertEqual(IsPalindrom("                       anna                       "), true);
	AssertEqual(IsPalindrom("                       an   na                       "), true);
	AssertEqual(IsPalindrom("dddanna"), false);
	AssertEqual(IsPalindrom("annadddd"), false);
	AssertEqual(IsPalindrom("hellodfolleh"), false);
	AssertEqual(IsPalindrom("helloddolleh"), true);	


}
int main() {
	TestRunner runner;
	runner.RunTest(MyHeroTestsForPal, "MyHeroTestsForPal");
	return 0;
}