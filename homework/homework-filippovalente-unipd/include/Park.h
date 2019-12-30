//Park.h
#ifndef Park_h
#define Park_h

#include <list> 

#include "Auto.h"
//#include "global_variables.h"

class Park{
    public:
        Park(std::list<Auto> macchina);
        Park();
        
        void inserisci(Auto car);
        void rimuovi(Park park, Auto car);

    private:
        std::list<Auto> park;

};

// operators
std::ostream& operator<<(std::ostream& os, const Park& d);

#endif