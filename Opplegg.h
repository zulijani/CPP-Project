/**
*   Deklarasjon av Opplegg klassen og dens funksjoner
*
*   @file Opplegg.h
*   @author  ---------------
*/

#ifndef __OPPLEGG_H
#define __OPPLEGG_H

#include <string>
#include <vector>
#include <map>

/**
*   En struct av by( med navn og attraksjoner)
*/
struct Byen{
    std::string navn;
    std::vector <std::string> attraksjoner;
};


class Opplegg{
    private:
        std::string beskrivelse; //beskrivelse
        std::map <int, std::vector <Byen>> oppleggData;
        //En map av dagNummer, med vector av structen "Byen"
    public:
        Opplegg(const std::string & besk);

        void leggTilIOpplegg(int dagNummer, const std::string & by, const std::vector<std::string> & attraksjoner);
        void skrivOpplegg() const;
        void skrivTilFil(const std::string & filnavn);
};

#endif // __OPPLEGG_H
