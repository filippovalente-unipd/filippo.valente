#include <ostream>
using std::ostream;
#include <iostream>
using std::cerr;
#include "Date_&_hour.h"

// helper functions

// check for valid date and initialise
Date::Date(int yy, int mm, int dd, int ora, int minuto)
	:y{yy}, m{mm}, d{dd}, hh{ora}, mm{minuto}
{}

const Date& default_date()
{
	static Date dd{2001,1,1,00,00};   // start of 21st century
	return dd;
}

Date::Date()
	:y{default_date().year()},
	m{default_date().month()},
	d{default_date().day()},
	hh{default_date().hour()},
	mm{default_date().minute()}
{
}

// return year
int Date::year() const
{
	return y;
}

// return month
int Date::month() const
{
	return m;
}

// return day of month
int Date::day() const
{
	return d;
}

// return hour 
int Date::hour() const
{
	return hh;
}

// return minute
int Date::minute() const
{
	return mm;
}

// operators
ostream& operator<<(ostream& os, const Date& d)
{
	return os << '{' << d.year()
			  << '/' << d.month()
			  << '/' << d.day() << ','
			  << ' ' << d.hour() 
			  << ':' << d.minute() << '}';
}

