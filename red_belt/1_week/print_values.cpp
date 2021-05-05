//
// Created by Mahmud Jego on 5/5/21.
//

#include "test_runner.h"

#include <sstream>

template<typename X, typename Y>
std::ostream& print_values(std::ostream& os, const X& x, const Y& y) {
	os << x << std::endl; os << y << std::endl;
	return os;
}

#define PRINT_VALUES(out, x, y) print_values(out, x, y)

int main() {
	TestRunner tr;
	tr.RunTest([] {
		ostringstream output;
		PRINT_VALUES(output, 5, "red belt");
		ASSERT_EQUAL(output.str(), "5\nred belt\n");
	}, "PRINT_VALUES usage example");
}