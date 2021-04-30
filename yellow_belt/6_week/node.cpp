//
// Created by Mahmud Jego on 4/21/21.
//

#include "node.h"
#include "TComparison.h"

DateComparisonNode::DateComparisonNode(const Comparison &cmp, const Date &date)
: _comparison(cmp), _date(date) {}

bool DateComparisonNode::Evaluate(const Date &date, const std::string &string) {
	return TComparison(_date, date, _comparison);
}

bool EmptyNode::Evaluate(const Date &date, const std::string &string) {
	return true;
}

bool EventComparisonNode::Evaluate(const Date &date, const std::string &event) {
	return TComparison(_event, event, _operation);
}

EventComparisonNode::EventComparisonNode(const Comparison &cmp, const std::string &value)
: _operation(cmp), _event(value) {}

bool LogicalOperationNode::Evaluate(const Date &date, const std::string &event) {
	if(_operation == LogicalOperation::And){
		return _left->Evaluate(date, event) && _right->Evaluate(date, event);
	}
	if(_operation == LogicalOperation::Or){
		return _left->Evaluate(date, event) || _right->Evaluate(date, event);
	}
	return false;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation &log, const std::shared_ptr<Node> &left,
										   const std::shared_ptr<Node> &right)
: _left(left), _right(right), _operation(log) {}

