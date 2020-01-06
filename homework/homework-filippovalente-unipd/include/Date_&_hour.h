#ifndef DATE_COMPLETE_H
#define DATE_COMPLETE_H

#include <ostream>

//Classe presa dal file 'Date05' mostrato in classe e
//modificata aggiungendo ora e minuto
class Date {
	public:
		//costruttore
		Date(int y, int m, int d, int hh, int mm);   
		Date();                        

		//'get functions'
		int year() const {return y;};
		int month() const {return m;};
		int day() const {return d;};
		int hour() const {return hh;};
		int minute() const {return mm;};

	private:
		int y;      //anno
		int m;		//mese
		int d;      //giorno
		int hh;     //ora
		int mm;		//minuto
};

//overload dell'operatore '<<' per poter stampare la data
std::ostream& operator<<(std::ostream& os, const Date& d);

#endif
