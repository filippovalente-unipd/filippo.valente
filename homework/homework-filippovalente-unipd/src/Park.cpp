#include <ostream>
using std::ostream;
#include<list>
using std::list;

#include "Park.h"

Park::Park(std::list<Auto> macchine)
     :park{macchine}
{}

void Park::inserisci(Auto car)
{
     park.push_back(car);
}

void Park::rimuovi(Park park, Auto car)
{
    
}