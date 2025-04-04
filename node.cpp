#include "node.h"
#include <memory>
#include "date.h"
using namespace std;
bool EmptyNode::Evaluate(const Date& date_, const string& event) const {
		return true;
}

bool DateComparisonNode::Evaluate(const Date& date_, const string& event) const {
	if (type == Comparison::Less) {
		return date_ < date;
	}
	else if (type == Comparison::LessOrEqual) {
		return date_ <= date;
	}
	else if (type == Comparison::Greater) {
		return date_ > date;
	}
	else if (type == Comparison::GreaterOrEqual) {
		return date_ >= date;
	}
	else if (type == Comparison::Equal) {
		return date_ == date;
	}
	else if (type == Comparison::NotEqual) {
		return date_ != date;
	}
	else {
		//throw invalid_argument("");
		return true;
	}
}

bool EventComparisonNode::Evaluate(const Date& date_, const string& event) const {
	if (type == Comparison::Less) {
		return value > event;
	}
	else if (type == Comparison::LessOrEqual) {
		return value >= event;
	}
	else if (type == Comparison::Greater) {
		return value < event;
	}
	else if (type == Comparison::GreaterOrEqual) {
		return value <= event;
	}
	else if (type == Comparison::Equal) {
		return value == event;
	}
	else if (type == Comparison::NotEqual) {
		return value != event;
	}
	else {
		//throw invalid_argument("");
		return true;
	}
}

bool LogicalOperationNode::Evaluate(const Date& date_, const string& event) const {
	if (operation == LogicalOperation::And) {
		return (lhs->Evaluate(date_, event) && rhs->Evaluate(date_, event));
	}
	else if (operation == LogicalOperation::Or) {
		return (lhs->Evaluate(date_, event) || rhs->Evaluate(date_, event));
	}
	else {
		//throw invalid_argument("");
		return true;
	}
}