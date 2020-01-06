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

#include "Auto.h"
#include "Park.h"
#include "Date_&_hour.h" 

//I due parcheggi da gestire
Park park1;
Park park2;

//mutex per sincronizzare la scrittura a schermo (tramite cout)
mutex output;

//Funzione che, in base a quale parcheggio, apre il file con le entrate 
//e inserisce una per una le macchine nel parcheggio giusto.
//La lettura da file è stata presa dal file '../tests/reading_from_file.cpp'
//fornito dalla docente
int ingresso(int id) 
{
   if(id == 1)                                                    //se il parcheggio è 'park1'...
   {
      ifstream infile;
      infile.open("../../input_files/parcheggioUnoIngresso.txt"); //... apre il file 'parcheggioUnoIngresso.txt'
   	
      if (!infile.is_open()) 
      {
         cout << "error opening the input file\n";
         exit(EXIT_FAILURE);
      }

      string line;
      while (getline(infile, line))
      {
         istringstream iss(line);
         int anno_, mese_, giorno_, ora_, minuto_;
         string targa_;
         if (!(iss >> targa_ >> anno_ >> mese_ >> giorno_ >> ora_ >> minuto_)) { break; } // error


         Auto car(targa_, {anno_, mese_, giorno_, ora_, minuto_}, "IN", "PARK1" );
         park1.inserisci(car, 1);
         output.lock();
         cout << car;
         output.unlock();
      }
      infile.close();
   } else                                                         //invece, se il parcheggio è 'park2'...
   {
      ifstream infile;
      infile.open("../../input_files/parcheggioDueIngresso.txt");//... apre il file 'parcheggioDueIngresso.txt'
   	
      if (!infile.is_open()) {
         cout << "Error opening the input file\n";
         exit(EXIT_FAILURE);
      }

      string line;
      while (getline(infile, line))
      {
         istringstream iss(line);
         int anno_, mese_, giorno_, ora_, minuto_;
         string targa_;
         if (!(iss >> targa_ >> anno_ >> mese_ >> giorno_ >> ora_ >> minuto_)) { break; } // error
       
         Auto car(targa_, {anno_, mese_, giorno_, ora_, minuto_}, "IN", "PARK2" );
         park2.inserisci(car, 2);
         output.lock();
         cout << car;
         output.unlock();
      }
      infile.close();
   }
   
   return 0;
}

//stesso procedimento della funzione 'entrata', solo che i due file da leggere sono 'parcheggioUnoUscita.txt' e 'parcheggioDueUscita.txt'
int uscita(int id)
{  
   if(id == 1)
   {
      ifstream infile;
      infile.open("../../input_files/parcheggioUnoUscita.txt");
   	
      if (!infile.is_open()) 
      {
         cout << "error opening the input file\n";
         exit(EXIT_FAILURE);
      }

      string line;
      while (getline(infile, line))
      {
         istringstream iss(line);
         int anno_, mese_, giorno_, ora_, minuto_;
         string targa_;
      
         if (!(iss >> targa_ >> anno_ >> mese_ >> giorno_ >> ora_ >> minuto_)) { break; } // error
         Auto car{targa_, {anno_, mese_, giorno_, ora_, minuto_}, "OUT", "PARK1"};
         park1.rimuovi_da1(car, 1);
         output.lock();
         cout << car;
         output.unlock();
      }

      infile.close();
   } else 
   {
      ifstream infile;
      infile.open("../../input_files/parcheggioDueUscita.txt");
   	
      if (!infile.is_open()) {
         cout << "error opening the input file\n";
         exit(EXIT_FAILURE);
      }

      string line;
      while (getline(infile, line))
      {
         istringstream iss(line);
         int anno_, mese_, giorno_, ora_, minuto_;
         string targa_;
      
         if (!(iss >> targa_ >> anno_ >> mese_ >> giorno_ >> ora_ >> minuto_)) { break; } // error
         Auto car{targa_, {anno_, mese_, giorno_, ora_, minuto_}, "OUT", "PARK2"};
         park2.rimuovi_da2(car, 2);
         output.lock();
         cout << car;
         output.unlock();
      }

      infile.close();
   }

   return 0;
}


int main()
{
   thread in_park1(ingresso, 1);
   thread out_park1(uscita, 1);
   thread in_park2{ingresso, 2};
   thread out_park2{uscita, 2};
   std::this_thread::sleep_for(std::chrono::milliseconds(500));

   in_park1.join();
   out_park1.join();
   in_park2.join();
   out_park2.join();

   return 0;
}