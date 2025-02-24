/**
*   Definisjoner av funksjoner til MuseumGalleri klassen
*
*   @file MuseumGalleri.cpp
*   @author  ---------------
*/
#include <iostream>
#include <string>
#include <fstream>
#include "MuseumGalleri.h"
using namespace std;

MuseumGalleri::MuseumGalleri(){

}

/**
 *  Leser fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
MuseumGalleri::MuseumGalleri(std::ifstream & inn) : Attraksjon(inn){
    getline(inn, hoydepunkt);
}

/**
*   Leser inn data
*
*   @see Attraksjon::lesData()
*/
void MuseumGalleri::lesData(){
    Attraksjon::lesData();
    cout << "\tHoydepunkt:   "; getline(cin, hoydepunkt);
}

/**
*   Skriver ut data
*
*   @see Attraksjon::skrivdata()
*/
void MuseumGalleri::skrivData() const{
    cout << "MuseumGalleri";
    Attraksjon::skrivData();
    cout << hoydepunkt << "\n";
}

/**
 *  Skriver til fil.
 *
 *  @param   ut  - Filobjektet egne data skrives ut til
 *  @see     Attraksjon::skrivTilTil(...)
 */
void MuseumGalleri::skrivTilFil(ofstream & ut) const{
    ut << 'M' << ' ';
    Attraksjon::skrivTilFil(ut);
    ut << hoydepunkt << '\n';
}
