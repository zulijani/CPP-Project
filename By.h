/**
*   Deklarasjon av By klassen og dens funksjoner
*
*   @file By.h
*   @author  ---------------
*/

#ifndef __BY_H
#define __BY_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "Attraksjon.h"

class By{
    private:
        std::string land;
        std::list <Attraksjon*> attraksjonene;
    public:
        By();
        By(std::ifstream & inn);

        std::string hentLand();
        int hentAntallAttraksjoner() const;
        void lesData();
        void leggTilAtraksjon(Attraksjon* attraksjon);
        const std::list <Attraksjon*> & hentAttraksjoner() const;
        void slettAttraksjon(int indeks);
        void skrivTilFil(std::ofstream & ut) const;
        Attraksjon* hentSpesifikkAttraksjon(int indeks) const;
};

#endif // __BY_H
