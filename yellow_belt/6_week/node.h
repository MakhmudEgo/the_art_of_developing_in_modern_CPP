//
// Created by Mahmud Jego on 4/21/21.
//

#pragma once
#include <memory>
#include <date.h>

class Node {
public:
	Node();
	bool Evaluate(const Date&, const std::string&) {
		return true;
	}
};


class EmptyNode : public Node {

};
class DateComparisonNode : public Node {

};
class EventComparisonNode : public Node {

};
class LogicalOperationNode : public Node {

};