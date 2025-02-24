/**
*   Definisjoner av funksjoner til Attraksjon klassen
*
*   @file Attraksjon.cpp
*   @author  ---------------
*/

#include <string>
#include <iostream>
#include <fstream>
#include "Attraksjon.h"
using namespace std;

Attraksjon::Attraksjon(){

}

/**
 *  Leser ALLE egne datamedlemmer inn fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Attraksjon::Attraksjon(ifstream & inn){
    getline(inn, ID);
    getline(inn, beskrivelse);
    getline(inn, adresse);
    getline(inn, webside);
}

/**
*   Leser data
*/
void Attraksjon::lesData(){
    cout << "\tNavn:         "; getline(cin, ID);
    cout << "\tBeskrivelse:  "; getline(cin, beskrivelse);
    cout << "\tAdresse:      "; getline(cin, adresse);
    cout << "\tWebside:      "; getline(cin, webside);
}

/**
*   Skriver data
*/
void Attraksjon::skrivData() const{
    cout << "\t " << ID << ",\t" << adresse
         << "\n\t\t" << beskrivelse << "\n\t\t" << webside << "\n\t\t";
}

/**
*   Skriver data til fil
*
*   @param ut   -   Filobjektet egne data skrives til fil
*/
void Attraksjon::skrivTilFil(ofstream & ut) const{
    ut << ID << '\n' << beskrivelse << '\n' << adresse << '\n'
       << webside << '\n';
}
