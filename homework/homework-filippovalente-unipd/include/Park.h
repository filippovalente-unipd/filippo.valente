//Park.h
#ifndef Park_h
#define Park_h

#include<list> 
#include<mutex>
#include<condition_variable>

#include "Auto.h"

class Park{
    public:
        //costruttore
        Park(std::list<Auto> macchina);
        Park();
        
        //funzioni per l'inserimento e la cancellazione
        //delle auto dal parcheggio
        list<Auto>::iterator cerca(const Auto& car);
        void inserisci(const Auto& car, int id);
        void rimuovi_da1(const Auto& car, int id);
        void rimuovi_da2(const Auto& car, int id);

    private:
        //dati membro
        //variabili che tengono conto delle macchine nel parcheggio
        int m_in1=0;
        int m_in2=0;

        //capacità del parcheggio (10 posti di default)
        const int cap=10;

        //container usato: lista
        std::list<Auto> park;

        //mutex per la protezione delle risorse condivise
        std::mutex mutex_;

        //varibili condizione
        //varibili per bloccare l'inserimento in caso di parcheggio pieno
        std::condition_variable OK_to_park_in1;
        std::condition_variable OK_to_park_in2;

        //variabili per bloccare l'uscita, in caso di parcheggio vuoto
        std::condition_variable New_car_in1;
        std::condition_variable New_car_in2;
};

#endif