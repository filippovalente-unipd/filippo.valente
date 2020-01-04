#include <iostream>
using std::cout;
using std::endl;
#include <ostream>
using std::ostream;
#include<list>
using std::list;
#include <mutex>
using std::mutex;
using std::unique_lock;
#include <condition_variable>
using std::condition_variable;

#include "Park.h"

//initilize the list
Park::Park(std::list<Auto> macchine)
     :park{macchine}
{}

//default constructor
Park::Park()
     :park{Auto()}
{}

//search a car in the list, returning an iterator on the position of the car (if its found)
list<Auto>::iterator Park::cerca(Auto car)
{
     list<Auto>::iterator pos;
     for(pos = park.begin(); pos != park.end(); ++pos)
     {
          if( (*pos).targa_code()==car.targa_code() )
          {
               return pos;
          }
     } 

     return park.end();
}

//insert a car into the park
void Park::inserisci(Auto car)
{
     unique_lock<mutex> mlock(mutex_);
     if(i == cap)
     {
          cout << " PARK1 is full." << endl;
          OK_to_park.wait(mlock);
     } 
     
     //cout << car;   
     park.push_back(car);
     i++;
     mlock.unlock();
     New_car.notify_one();
}

//erase a car from the list, when it leaves the park
void Park::rimuovi(Auto car)
{
     unique_lock<mutex> mlock(mutex_);
    
     list<Auto>::iterator pos = cerca(car);

     if(pos == park.end() )
     {
          pos=park.begin();
          New_car.wait(mlock);
     }

     //cout << car;
     park.erase(pos);
     i--;
     mlock.unlock();
     OK_to_park.notify_one();
}