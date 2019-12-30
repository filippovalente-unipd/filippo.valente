//Auto.h
#ifndef Auto_h
#define Auto_h

#include<string>
using std::string;

#include "Date.h"

class Auto{
public:

	Auto(string targa_c, int ora, int minuto, Date data);
	
	void inserisci(Auto car);
	string targa_code() const {return targa;} ;
	int ora_code() const {return hh;} ;
	int minuto_code() const {return min;} ;
	Date data_code() const {return d;} ;

private:
	string targa;
    int hh, min;
	Date d;
};

// operators
std::ostream& operator<<(std::ostream& os, const Auto& d);

#endif