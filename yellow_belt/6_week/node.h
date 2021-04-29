//
// Created by Mahmud Jego on 4/21/21.
//

#pragma once

#include <memory>
#include "date.h"

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
	virtual bool Evaluate(const Date&, const std::string&) = 0;
};


class EmptyNode : public Node {
public:
	bool Evaluate(const Date &date, const std::string &string) override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison& cmp, const Date&);

	bool Evaluate(const Date &date, const std::string &string) override;

private:
	const Comparison _comparison;
	const Date _date;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison& cmp, const std::string &value);

	bool Evaluate(const Date &date, const std::string &string) override;

private:
	const Comparison _operation;
	const std::string _event;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation& log, const std::shared_ptr<Node>& left, const std::shared_ptr<Node>& right);

	bool Evaluate(const Date &date, const std::string &event) override;

private:
	const std::shared_ptr<Node> _left, _right;
	const LogicalOperation _operation;
};