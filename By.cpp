/**
*   Definisjoner av funksjoner til By klassen
*
*   @file By.cpp
*   @author  ---------------
*/

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "By.h"
using namespace std;


By::By(){

}

/**
 *  Leser ALLE egne datamedlemmer inn fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
By::By(ifstream & inn){
    getline(inn, land);
}

/**
*  Skriver ut navnet til fil.
*
*  @param   ut  - Filobjektet egne data skrives ut til
*/
void By::skrivTilFil(ofstream & ut) const{
    ut << land << '\n';
}

/**
*   Sletter en bestemt attraksjon
*
*   @param indeks   -   "indeksen" til attraksjonen
*/
void By::slettAttraksjon(int indeks){
    list <Attraksjon*>::iterator it = attraksjonene.begin();
    for(int i = 0; i < indeks; i++)
        it++;

    delete *it;
    attraksjonene.erase(it);
}

/**
*   @return peker til spesfikk attraksjon
*   @param indeks   -   "indeksen" til attraksjon
*/
Attraksjon* By::hentSpesifikkAttraksjon(int indeks) const{
    auto it = attraksjonene.begin();
    for(int i = 1; i < indeks; i++)
        it++;
    return *it;
}

/**
*   @return returnerer by sine attraksjoner
*/
const list <Attraksjon*> & By::hentAttraksjoner() const{
    return attraksjonene;
}

/**
*   Leser inn data
*/
void By::lesData(){
    cout << "\n\tLand: "; getline(cin, land);
}

/**
*   @return land
*/
string By::hentLand() { return land; }

/**
*   @return antallAttraksjoner
*/
int By::hentAntallAttraksjoner() const{ return attraksjonene.size(); }

/**
*   Legger til attraksjon i datastruktur
*/
void By::leggTilAtraksjon(Attraksjon* attraksjon){
    attraksjonene.push_back(attraksjon);
    attraksjon->skrivData();
}

