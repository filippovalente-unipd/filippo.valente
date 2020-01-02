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

#include "Auto.h"
#include "Park.h"
#include "Date_&_hour.h" 
//#include "global_variables.h"

Park park1;
Park park2;

int ingresso(int id)  //controllare l'id nei casi che serve
{
   if(id == 1)
   {
      ifstream infile;
      infile.open("../../input_files/parcheggioUnoIngresso.txt");
   	
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
       
         Auto car(targa_, {anno_, mese_, giorno_, ora_, minuto_}, "IN", "PARK1" );
         park1.inserisci(car);
      }
      infile.close();
   } else 
   {
      ifstream infile;
      infile.open("../../input_files/parcheggioDueIngresso.txt");
   	
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
         park2.inserisci(car);
      }
      infile.close();
   }
   
   return 0;
}

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
         park1.rimuovi(car);
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
         park1.rimuovi(car);
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

   in_park1.join();
   out_park1.join();
   in_park2.join();
   out_park2.join();

}