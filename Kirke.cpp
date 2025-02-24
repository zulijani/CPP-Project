/**
*   Definisjoner av funksjoner til Kirke klassen
*
*   @file Kirke.cpp
*   @author  ---------------
*/
#include <iostream>
#include <fstream>
#include "LesData3.h"
#include "Kirke.h"
#include "Const.h"
using namespace std;

Kirke::Kirke(){

}

/**
 *  Leser årslønn og rom/kontor fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Kirke::Kirke(ifstream & inn) : Attraksjon(inn){
    char hva;
    inn >> byggeAar; inn.ignore();
    inn >> kapasitet; inn.ignore();
    inn >> hva; inn.ignore();
    switch(hva){
        case 'K': type = KirkeType::Katedral; break;
        case 'E': type = KirkeType::Kirkee; break;
        case 'L': type = KirkeType::Kapell; break;
    }
}


/**
*   Leser inn data
*
*   @see Attraksjon::lesData()
*/
void Kirke::lesData(){
    char valg;

    Attraksjon::lesData();
    byggeAar = lesInt("\tBygge aar", 1, MAXBYGGEAAR);
    kapasitet = lesInt("\tKapaistet", 1, MAXKAPASITET);

    do{
        cout << "\tKirketype K(atedral), (kirke)E, (kapel)L: ";
        valg = lesChar("");
    }while(valg != 'K' && valg != 'E' && valg != 'L');

    switch(valg){
        case 'K': type = KirkeType::Katedral; break;
        case 'E': type = KirkeType::Kirkee; break;
        case 'L': type = KirkeType::Kapell; break;
    }
}

/**
*   Skriver ut data
*
*   @see Attraksjon::skrivdata()
*/
void Kirke::skrivData() const{
    cout << "Kirke\t";
    Attraksjon::skrivData();
    cout << "Bygger ca. aar: " << byggeAar << "   Kapasitet: " << kapasitet;

    switch(type){
        case KirkeType::Katedral: cout << "   Type: Katedral\n"; break;
        case KirkeType::Kirkee: cout << "   Type: Kirke\n"; break;
        case KirkeType::Kapell: cout << "   Type: Kapell\n"; break;
    }
}

/**
 *  Skriver til fil.
 *
 *  @param   ut  - Filobjektet egne data skrives ut til
 *  @see     Attraksjon::skrivTilTil(...)
 */
void Kirke::skrivTilFil(ofstream & ut) const{
    ut << 'K' << ' ';
    Attraksjon::skrivTilFil(ut);
    ut << byggeAar << ' ' << kapasitet << ' ';
    switch(type){
        case KirkeType::Katedral: ut << 'K'; break;
        case KirkeType::Kirkee: ut << 'E'; break;
        case KirkeType::Kapell: ut << 'L'; break;
    }
    ut << '\n';
}
