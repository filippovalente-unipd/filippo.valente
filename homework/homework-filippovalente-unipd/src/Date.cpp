#include <ostream>
using std::ostream;
#include <iostream>
using std::cerr;
#include "Date.h"

// helper functions

// check for valid date and initialise
Date::Date(int yy, Month mm, int dd)
	:y{yy}, m{mm}, d{dd}
{
	if (m<Date::jan || m>Date::dec || d<1 || d>31)  {
		cerr << "invalid date\n";
		exit(1);
	}

}

const Date& default_date()
{
	static Date dd{2001,Date::jan,1};   // start of 21st century
	return dd;
}

Date::Date()
	:y{default_date().year()},
	m{default_date().month()},
	d{default_date().day()}
{
}

// return year
int Date::year() const
{
	return y;
}

// return month
Date::Month Date::month() const
{
	return m;
}

// return day of month
int Date::day() const
{
	return d;
}

// operators
ostream& operator<<(ostream& os, const Date& d)
{
	return os << '(' << d.year()
		<< ',' << d.month()
		<< ',' << d.day() << ')';
}
