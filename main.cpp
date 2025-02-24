/**
 *   Hovedprogrammet for OOP-prosjektet V24 med turoperatører, byer,
 *   attraksjoner i byene og N dagers ulike reiseopplegg for turoperatørene.
 *
 *   @file     main.cpp
 *   @author   Frode Haug, NTNU
 */


#include <iostream>
#include "Turoperatorer.h"
#include "Byer.h"
#include "Opplegg.h"
#include "Funksjoner.h"
#include "LesData3.h"
using namespace std;


Turoperatorer gOperatorBase; ///<  Globalt container-objekt med ALLE turoperatørene.
Byer gByerBase;              ///<  Globalt container-objekt med ALLE byene.

//  Kode som legges innledningsvis i de .cpp-filene som trenger å bruke
//  en eller begge det to globale objektene definert ovenfor:
//         extern Turoperatorer gOperatorBase;
//         extern Byer gByerBase;


/**
 *  Hovedprogram.
 */
int main()  {
    char valg;


    gOperatorBase.lesFraFil();
    gByerBase.lesFraFil();

    skrivMeny();
    valg = lesChar2("\nKommando");

    while (valg != 'Q')  {
        switch(valg)  {
        case 'T':               gOperatorBase.handling();      break;
        case 'B':  case 'A':    gByerBase.handling(valg);          break;
        default:                skrivMeny();                       break;
        }
        valg = lesChar2("\nKommando");
    }

    gOperatorBase.skrivTilFil();
    gByerBase.skrivTilFil();

    cout << "\n\n";
    return 0;
}
