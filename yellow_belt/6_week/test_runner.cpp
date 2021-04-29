//
// Created by Makhmud Ego on 26.04.2021.
//

#include "test_runner.h"

void Assert(bool b, const std::string& hint) {
	AssertEqual(b, true, hint);
}