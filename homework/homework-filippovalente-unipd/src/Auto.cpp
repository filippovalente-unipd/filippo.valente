#include <ostream>
using std::ostream;

#include "Auto.h"
#include "Date.h"


Auto::Auto(string targa_c, int ora, int minuto, Date data)
	 :targa{targa_c}, hh{ora}, min{minuto}, d{Date()}
{}

void Auto::inserisci(Auto car)
{
     
}

// operators
ostream& operator<<(ostream& os, const Auto& p)
{
	return os << ' ' << p.data_code()
              << ' ' << p.ora_code()
              << ' ' << p.minuto_code()
              << ' ' << p.targa_code();
}


