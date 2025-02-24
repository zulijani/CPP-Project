/**
*   Deklarasjon av Turoperator klassen og dens funksjoner
*
*   @file Turoperator.h
*   @author  ---------------
*/

#ifndef __TUROPERATOR_H
#define __TUROPERATOR_H

#include <string>
#include <fstream>

/**
*   Klasse av Turoperator
*/
class Turoperator{
    private:
        std::string gateadresse;
        std::string postnrOgSted;
        std::string kontaktpersonsNavn;
        std::string email;
        std::string webside;
        int tlfNummer;
        int antallTuropplegg = 0;
    public:
        Turoperator();
        Turoperator(std::ifstream & inn);

        void lesData();
        void skrivData() const;
        void endreData();
        int hentAntallTuropplegg() const;
        std::string hentWebside() const;
        void skrivTilFil(std::ofstream & ut) const;
        void okeAntallTuropplegg() {antallTuropplegg++;}
};

#endif // TUROPERATOR_H
