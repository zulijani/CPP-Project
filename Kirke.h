/**
*   Deklarasjon av Kirke klassen og dens funksjoner
*
*   @file Kirke.h
*   @author  ---------------
*/

#ifndef __KIRKE_H
#define __KIRKE_H

#include <fstream>
#include "Attraksjon.h"
#include "Enum.h"

class Kirke : public Attraksjon{
    private:
        int byggeAar,   //ca.byggeår
            kapasitet;  //ca.plass til antall personer (kapasitet)
        KirkeType type; //type kirke;
    public:
        Kirke();
        Kirke(std::ifstream & inn);

        virtual void lesData();
        virtual void skrivData() const;
        virtual void skrivTilFil(std::ofstream & ut) const;
};

#endif // __KIRKE_H
