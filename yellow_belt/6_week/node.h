//
// Created by Mahmud Jego on 4/21/21.
//

#pragma once

#include <memory>
#include <date.h>

enum class LogicalOperation {
	And,
	Or
};

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

class Node {
public:
	Node() {

	}
	bool Evaluate(const Date&, const std::string&) {
		return true;
	}
};


class EmptyNode : public Node {

};
class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date&) {

	}
};
class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const std::string &value) {

	}
};
class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& log, const std::shared_ptr<Node>& left, const std::shared_ptr<Node>& right) {

	}
};