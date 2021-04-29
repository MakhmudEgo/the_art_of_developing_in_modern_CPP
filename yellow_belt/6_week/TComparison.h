//
// Created by Mahmud Jego on 4/29/21.
//

#pragma once

template<typename T>
bool TComparison(const T& lhs, const T& rhs, Comparison cmp) {
	switch (cmp) {
		case Comparison::Less:
			return lhs > rhs;
		case Comparison::LessOrEqual:
			return lhs > rhs || lhs == rhs;
		case Comparison::Greater:
			return lhs < rhs;
		case Comparison::GreaterOrEqual:
			return lhs < rhs || lhs == rhs;
		case Comparison::Equal:
			return lhs == rhs;
		case Comparison::NotEqual:
			return lhs != rhs;
	}
}
