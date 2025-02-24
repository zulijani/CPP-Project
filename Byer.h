/**
*   Deklarasjon av Byer klassen og dens funksjoner
*
*   @file Byer.h
*   @author  ---------------jeg
*/

#ifndef __BYER_H
#define __BYER_H

#include <map>
#include <string>
#include "By.h"

/**
*   Klasse av Byer
*/
class Byer{
    private:
        std::map <std::string, By*> byene;
    public:

        void handling(char valg);
        void skrivAlleByene();
        void skrivEnBy();
        void printByMedAttraksjoner(const std::string & byNavn);
        void nyBy();
        void nyAttraksjon();
        void slettBy();
        void fjernAttraksjon();
        void lesFraFil();
        void skrivTilFil();
        By* finnBy(const std::string & byNavn);
        std::map<std::string, By*>& hentByene() {return byene;}
};

#endif // BYER_H
