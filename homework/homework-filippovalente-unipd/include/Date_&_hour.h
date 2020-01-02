#ifndef DATE_COMPLETE_H
#define DATE_COMPLETE_H

#include <ostream>

// simple Date (use Month type)
class Date {
public:
	Date(int y, int m, int d, int hh, int mm);   
	Date();                        

	int year() const;
	int month() const;
	int day() const;
	int hour() const;
	int minute() const;

private:
	int y;      // year
	int m;		// month
	int d;      // day of month
	int hh;     //hour
	int mm;		//minute
};

// operators
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
