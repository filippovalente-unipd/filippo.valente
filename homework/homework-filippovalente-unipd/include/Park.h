//Park.h
#ifndef Park_h
#define Park_h

#include<list> 
#include<mutex>
#include<condition_variable>

#include "Auto.h"
//#include "global_variables.h"

class Park{
    public:
        Park(std::list<Auto> macchina);
        Park();
        
        void inserisci(Auto car);
        void rimuovi(Auto car);

    private:
        int i;
        const int cap{10};
        std::list<Auto> park;
        std::mutex mutex_;
        std::condition_variable OK_to_park;
        std::condition_variable New_car;
};

#endif