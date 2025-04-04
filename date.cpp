#include "date.h"
#include <tuple>
//#include <iomanip>
using namespace std;

//нужно дописывать методы класса
Date::Date() {
	int k = 0;
}

Date::Date(unsigned int year_, unsigned int month_, unsigned int day_) :
	year(year_), month(month_), day(day_) {}
const unsigned int& Date:: Year() const {
	return this->year;
}
const unsigned int& Date:: Month() const {
	return this->month;
}
const unsigned int& Date:: Day() const {
	return this->day;
}


Date ParseDate(std::istream& is) {
	int year, month, day;
	bool ok = true;
	ok = ok && (is >> year);
	ok = ok && (is.peek() == '-');
	is.ignore(1);
	ok = ok && (is >> month);
	ok = ok && (is.peek() == '-');
	is.ignore(1);
	ok = ok && (is >> day);
	ok = ok && is.eof();
	/*if (!ok) {
		throw std::invalid_argument("Wrong date format: ");
	}*/
	return Date(year, month, day);
}

bool operator < (const Date& lhs, const Date& rhs) {
	return tie(lhs.Year(), lhs.Month(), lhs.Day()) < tie(rhs.Year(), rhs.Month(), rhs.Day());
}

bool operator > (const Date& lhs, const Date& rhs) {
	return tie(lhs.Year(), lhs.Month(), lhs.Day()) > tie(rhs.Year(), rhs.Month(), rhs.Day());
}

bool operator <= (const Date& lhs, const Date& rhs) {
	return tie(lhs.Year(), lhs.Month(), lhs.Day()) <= tie(rhs.Year(), rhs.Month(), rhs.Day());
}

bool operator >= (const Date& lhs, const Date& rhs) {
	return tie(lhs.Year(), lhs.Month(), lhs.Day()) >= tie(rhs.Year(), rhs.Month(), rhs.Day());
}

bool operator == (const Date& lhs, const Date& rhs) {
	return tie(lhs.Year(), lhs.Month(), lhs.Day()) == tie(rhs.Year(), rhs.Month(), rhs.Day());
}

bool operator != (const Date& lhs, const Date& rhs) {
	return tie(lhs.Year(), lhs.Month(), lhs.Day()) != tie(rhs.Year(), rhs.Month(), rhs.Day());
}

ostream& operator <<(ostream& os, const Date& date) {
	os << setw(4) << setfill('0') << date.Year() << "-" <<
		setw(2) << setfill('0') << date.Month() << "-" <<
		setw(2) << setfill('0') << date.Day();
	return os;
}