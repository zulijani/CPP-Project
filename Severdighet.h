/**
*   Deklarasjon av Severdighet klassen og dens funksjoner
*
*   @file Severdighet.h
*   @author  ---------------
*/

#ifndef __SEVERDIGHET_H
#define __SEVERDIGHET_H

#include "Attraksjon.h"
#include <string>
#include <fstream>

class Severdighet : public Attraksjon{
    private:
        std::string spesielt;//spesielt å se/gjøre/oppleve ved/på dette stedet
    public:
        Severdighet();
        Severdighet(std::ifstream & inn);

        virtual void lesData();
        virtual void skrivData() const;
        virtual void skrivTilFil(std::ofstream & ut) const;
};

#endif // SEVERDIGHET_H
