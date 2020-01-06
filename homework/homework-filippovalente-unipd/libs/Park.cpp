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

//Per inizializzare la lista:
Park::Park(std::list<Auto> macchine)
     :park{macchine}
{}

//Costruttore di default: 
Park::Park()
     :park{Auto()}
{}

//Funzione che cerca una macchina nel parcheggio tramite la targa, 
//e restituisce un iteratore che punta alla macchina:
list<Auto>::iterator Park::cerca(const Auto& car)
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

//Funzione che inserisce una macchina nel parcheggio:
void Park::inserisci(const Auto& car, int id)
{
     unique_lock<mutex> mlock(mutex_);
     if(id == 1)
     {
          if(m_in1 == cap)
          {
               cout << "park1 è pieno." << endl;
               OK_to_park_in1.wait(mlock);
          } 

          if(m_in1 < cap) {
          park.push_back(car);
          ++m_in1;
          mlock.unlock();
          New_car_in1.notify_one();
          }
     } else
     {
          if(m_in2 == cap)
          {
               cout << "park2 è pieno." << endl;
               OK_to_park_in2.wait(mlock);
          } 
          
          if(m_in2 < cap) {
          park.push_back(car);
          ++m_in2;
          mlock.unlock();
          New_car_in2.notify_one();
          }
     }

}

//funzione che rimuove una macchina dal parcheggio: 
void Park::rimuovi_da1(const Auto& car, int id)
{
     unique_lock<mutex> mlock(mutex_);
          if(m_in1 == 0) 
               New_car_in1.wait(mlock); 

          list<Auto>::iterator pos = cerca(car);

          if(pos == park.end() )
          {
               pos=park.begin();
               New_car_in1.wait(mlock);
          } else {
          park.erase(pos);
          --m_in1;
          mlock.unlock();
          OK_to_park_in1.notify_one();
          }
     
}

//funzione che rimuove una macchina dal parcheggio: 
void Park::rimuovi_da2(const Auto& car, int id)
{
     unique_lock<mutex> mlock(mutex_);
          if(m_in2 == 0)
               New_car_in2.wait(mlock);

          list<Auto>::iterator pos = cerca(car);

          if(pos == park.end() )
          {
               pos=park.begin();
               New_car_in2.wait(mlock);
          } else {
          park.erase(pos);
          --m_in2;
          mlock.unlock();
          OK_to_park_in2.notify_one();
          }
     
}