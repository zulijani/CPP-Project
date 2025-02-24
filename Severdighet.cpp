/**
*   Definisjoner av funksjoner til Severdighet klassen
*
*   @file Severdighet.cpp
*   @author  ---------------
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Severdighet.h"
using namespace std;

Severdighet::Severdighet(){

}

/**
 *  Leser årslønn og rom/kontor fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Severdighet::Severdighet(ifstream & inn) : Attraksjon(inn){
    getline(inn, spesielt);
}

/**
*   Leser inn data
*
*   @see Attraksjon::lesData()
*/
void Severdighet::lesData(){
    Attraksjon::lesData();
    cout << "\tSpesielt:     "; getline(cin, spesielt);
}

/**
*   Skriver ut data
*
*   @see Attraksjon::skrivdata()
*/
void Severdighet::skrivData() const{
    cout << "Severdighet";
    Attraksjon::skrivData();
    cout << spesielt << "\n";

}

/**
 *  Skriver til fil.
 *
 *  @param   ut  - Filobjektet egne data skrives ut til
 *  @see     Attraksjon::skrivTilTil(...)
 */
void Severdighet::skrivTilFil(ofstream & ut) const{
    ut << 'S' << ' ';
    Attraksjon::skrivTilFil(ut);
    ut << spesielt << '\n';
}
