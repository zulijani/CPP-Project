/**
*   Deklarasjon av MuseumGalleri klassen og dens funksjoner
*
*   @file MuseumGalleri.h
*   @author  ---------------
*/

#ifndef __MUSEUMGALLERI_H
#define __MUSEUMGALLERI_H

#include <string>
#include <fstream>
#include "Attraksjon.h"

/**
*   MuseumGalleri (med hoydepunkt)
*/
class MuseumGalleri : public Attraksjon{
    private:
        std::string hoydepunkt; //høydepunkt(er) på museumet/galleriet
    public:
        MuseumGalleri();
        MuseumGalleri(std::ifstream & inn);

        virtual void lesData();
        virtual void skrivData() const;
        virtual void skrivTilFil(std::ofstream & ut) const;

};

#endif // __MUSEUMGALLERI_H
