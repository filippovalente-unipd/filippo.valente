#include <ostream>
using std::ostream;

#include "Auto.h"
#include "Date_&_hour.h"


Auto::Auto(string targa_c, Date data, string in_out, string park1_2)
	 :targa{targa_c}, d{data}, stato{in_out}, parcheggio{park1_2}
{}

Auto::Auto()
     :targa{"XX---YY"}, d{Date()}, stato{"--"}, parcheggio{"PARK-"}
{}


ostream& operator<<(ostream& os, const Auto& p)
{
	return os << ' ' << p.data_code()
               << ' ' << p.targa_code()
               << ' ' << p.stato_code()
               << ' ' << p.park_code() << std::endl;
}
