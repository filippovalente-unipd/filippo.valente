//Auto.h
#ifndef Auto_h
#define Auto_h

#include<string>
using std::string;

#include "Date_&_hour.h"

class Auto{
	public:
		//costruttore
		Auto(string targa_c, Date data, string in_out, string park1_2);
		Auto();

		//'get functions'
		string targa_code() const {return targa;} ;
		Date data_code() const {return d;} ;
		string stato_code() const {return stato;} ;
		string park_code() const {return parcheggio;} ;

	private:
		string targa;
		Date d;
		string stato, parcheggio;
};

//overload dell'operatore '<<' per poter inviare a schermo i dati dell'auto
std::ostream& operator<<(std::ostream& os, const Auto& d);

#endif