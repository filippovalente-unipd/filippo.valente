// main.cpp
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <list>
using std::list;
#include <thread>
using std::thread;
#include <sstream>
using std::istringstream;
#include <mutex>
using std::mutex;
using std::unique_lock;
#include <condition_variable>
using std::condition_variable;
#include "Auto.h"
#include "Park.h"
#include "Date.h" 
//#include "global_variables.h"

const int cap{10};
list<Auto> park1;
mutex m;
int i{0};

int ingressoUno()
{
   // open a file in read mode
   ifstream infile;
   infile.open("../../input_files/parcheggioUnoIngresso.txt");
   	
   if (!infile.is_open()) {
      cout << "error opening the input file\n";
      exit(EXIT_FAILURE);
   }

   string line;
   while (getline(infile, line))
   {
      
      unique_lock<mutex> mlock(m);
      istringstream iss(line);
      int anno_, mese_, giorno_, ora_, minuto_;
      string targa_;
      
      if (!(iss >> targa_ >> anno_ >> mese_ >> giorno_ >> ora_ >> minuto_)) { break; } // error
      Auto car(targa_, ora_, minuto_, {anno_, static_cast<Date::Month>(mese_), giorno_} );
      park1.push_back(car);
      cout << car << " IN" << " PARK1" << endl;
      mlock.unlock();
   }

   // close the opened file.
   infile.close();

   return 0;
}

int uscitaUno()
{  
   // open a file in read mode
   ifstream infile;
   infile.open("../../input_files/parcheggioUnoUscita.txt");
   	
   if (!infile.is_open()) {
      cout << "error opening the input file\n";
      exit(EXIT_FAILURE);
   }

   string line;
   while (getline(infile, line))
   {
      unique_lock<mutex> mlock(m);
      istringstream iss(line);
      int anno_, mese_, giorno_, ora_, minuto_;
      string targa_;
      
      if (!(iss >> targa_ >> anno_ >> mese_ >> giorno_ >> ora_ >> minuto_)) { break; } // error
      Auto car{targa_, ora_, minuto_, Date{anno_, static_cast<Date::Month>(mese_), giorno_} };
     // cout << car << " OUT" << " PARK1" << endl;
      mlock.unlock();
   }

   // close the opened file.
   infile.close();

   return 0;
}


int main()
{
    
    thread in_park1(ingressoUno);
    thread out_park1(uscitaUno);

    in_park1.join();
    out_park1.join();

}