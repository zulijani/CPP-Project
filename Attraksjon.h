/**
*   Deklarasjon av Attraksjon klassen og dens funksjoner
*
*   @file Attraksjon.h
*   @author  ---------------
*/

#ifndef __ATTRAKSJON_H
#define __ATTRAKSJON_H

#include <string>
#include <fstream>


/**
*   Klasse av attraksjon
*/
class Attraksjon{
    private:
        std::string ID; //ID (= unikt navn, sortert på denne)
        std::string beskrivelse;
        std::string adresse;
        std::string webside;
    public:
        Attraksjon();
        Attraksjon(std::ifstream & inn);

        std::string hentID() const{return ID;} //returnerer ID
        virtual void lesData();
        virtual void skrivData() const;
        virtual void skrivTilFil(std::ofstream & ut) const;
};

#endif // __ATTRAKSJON_H
