/**
*   Deklarasjon av Turoperatorer klassen og dens funksjoner
*
*   @file Turoperatorer.h
*   @author  ---------------
*/

#ifndef __TUROPERATORER_H
#define __TUROPERATORER_H

#include <string> //string
#include <map>    //map
#include "Turoperator.h"


/**
*   Klasse av Turoperatorer
*/
class Turoperatorer{
    private:
        std::map <std::string, Turoperator*> operatorer;
    public:

        void handling();
        void lesFraFil();
        void skrivTilFil();
        void skrivAlleTuroperatorer();
        void skrivEnTuroperator();
        void nyTuroperator();
        void endreEnTuroperator();
        void slettTuroperator();
        std::map<std::string, Turoperator*>& hentTuroperatorer() {return operatorer;}
        Turoperator* finnTuroperator(const std::string & navn);
};


#endif // __TUROPERATORER_H
