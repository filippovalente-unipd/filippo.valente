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

//insert a car into the park
void Park::inserisci(Auto car)
{
     unique_lock<mutex> mlock(mutex_);
     if(i != cap)
     {
          park.push_back(car);
          i++;
          New_car.notify_one();
          cout << car;
     } else
     {
          cout << "PARK1 is full." << endl;
          OK_to_park.wait(mlock);
     } 
}

//erase a car from the list, when it leaves the park
void Park::rimuovi(Auto car)
{
     unique_lock<mutex> mlock(mutex_);
     list<Auto>::iterator pos;
     if(i == 0)
          New_car.wait(mlock);
     else
     {
          for(pos = park.begin(); pos != park.end(); ++pos)
          {
               if( (*pos).targa_code()==car.targa_code() )
               {
                    list<Auto>::iterator v = park.erase(pos);
                    i--;
                    cout << car;
                    OK_to_park.notify_one();
                    break;
               }   
          }
     } 
}

