#ifndef DATE_H
#define DATE_H

#include <ostream>

// simple Date (use Month type)
class Date {
public:
	enum Month {
		jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	
	Date(int y, Month m, int d);   
	Date();                        

	int year() const;
	Month month() const;
	int day() const;

private:
	int y;      // year
	Month m;
	int d;      // day of month
};

// operators
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
