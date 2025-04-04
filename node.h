#pragma once
#include "token.h"
#include "date.h"
#include <memory>
using namespace std;

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation {
	And,
	Or
};

class Node {
public:
	virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
	bool Evaluate(const Date& date_, const string& event) const override;
	//EmptyNode() : Node(){}
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(Comparison cmp,const Date& date_) : type(cmp), date(date_) {}
	bool Evaluate(const Date& date_, const string& event) const override;
private:
	const Comparison type;
	const Date date;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(Comparison cmp, const string val) : type(cmp), value(val){}
	bool Evaluate(const Date& date_, const string& event) const override;
private:
	const Comparison type;
	const string value;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> ptr) :
		operation(op), lhs(left), rhs(ptr){}
	bool Evaluate(const Date& date_, const string& event) const override;
private:
	const LogicalOperation operation;
	const shared_ptr<Node> lhs, rhs;
};