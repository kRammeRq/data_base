#pragma once
#include<iostream>
//#include<stdexcept>
#include <iomanip>
using namespace std;
class Date {
public:
	Date();
	Date(unsigned int year_, unsigned int month_, unsigned int day_);
	const unsigned int& Year() const;
	const unsigned int& Month() const;
	const unsigned int& Day() const;
private:
	unsigned int year, month, day;
};

Date ParseDate(std::istream& is);

bool operator < (const Date& lhs, const Date& rhs);

bool operator > (const Date& lhs, const Date& rhs);

bool operator <= (const Date& lhs, const Date& rhs);

bool operator >= (const Date& lhs, const Date& rhs);

bool operator == (const Date& lhs, const Date& rhs);

bool operator != (const Date& lhs, const Date& rhs);

ostream& operator <<(ostream& os, const Date& date);