/**
*   Definisjoner av funksjoner til klassen Turoperator
*
*   @file Turoperator.cpp
*   @author  ---------------
*/

#include <iostream>
#include <string>
#include "LesData3.h"
#include "Turoperator.h"
using namespace std;

Turoperator::Turoperator(){}

/**
 *  Leser ALLE egne datamedlemmer inn fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
 Turoperator::Turoperator(ifstream & inn){
    inn >> antallTuropplegg; inn.ignore();
    getline(inn, gateadresse);
    getline(inn, postnrOgSted);
    getline(inn, kontaktpersonsNavn);
    inn >> tlfNummer; inn.ignore();
    getline(inn, email);
    getline(inn, webside);
 }

/**
*  Skriver ut navnet til fil.
*
*  @param   ut  - Filobjektet egne data skrives ut til
*/
void Turoperator::skrivTilFil(ofstream & ut) const{
    ut << antallTuropplegg << '\n' << gateadresse << '\n'
       << postnrOgSted << '\n' << kontaktpersonsNavn << '\n' << tlfNummer << ' '
       << email << '\n' << webside << '\n';
}

/**
*   @return antallTuropplegg
*/
int Turoperator::hentAntallTuropplegg() const { return antallTuropplegg; }

/**
*   @return webside
*/
string Turoperator::hentWebside() const { return webside; }

/**
*   Leser inn data
*/
void Turoperator::lesData(){
    cout << "\tGateadresse: "; getline(cin, gateadresse);
    cout << "\tPostNr og Sted: "; getline(cin, postnrOgSted);
    cout << "\tKontaktperson: "; getline(cin, kontaktpersonsNavn);
    cout << "\tMailadresse: "; getline(cin, email);
    cout << "\tWebside: "; getline(cin, webside);
    tlfNummer = lesInt("\tTelefonNr",10000, 99999999);
}

/**
*   Skriver ut data
*/
void Turoperator::skrivData() const {
    cout << antallTuropplegg << " opplegg\t" << webside << "\n\t\t"
         << gateadresse << ", " << postnrOgSted << "\n\t\t"
         << kontaktpersonsNavn << ", " << tlfNummer << ", " << email;
}

/**
*   Endrer data
*/
void Turoperator::endreData(){
    char hva;
    char ferdig;

    do{
        do{
            hva = lesChar("\t\tG(ate),P(ost/Std),K(ontaktpers),M(ail),W(eb),T(lf):");
        } while(hva != 'G' && hva != 'P' && hva != 'K' &&
                hva != 'M' && hva != 'W' && hva != 'T');
                //leser tegn av bruker
        switch(hva){ //gjør noe basert på brukerens valg
            case 'G':cout << "\t\tGateadresse: "; getline(cin, gateadresse);
                break;
            case 'P':
                cout << "\t\tPostNr og Sted: "; getline(cin, postnrOgSted);
                break;
            case 'K':
                cout << "\t\tKontaktperson: "; getline(cin, kontaktpersonsNavn);
                break;
            case 'M':
                cout << "\t\tMailadresse: "; getline(cin, email); break;
            case 'W':  cout << "Webside: "; getline(cin, webside); break;
            case 'T':  tlfNummer = lesInt("\t\tTelefonNr",10000, 99999999);
                break;
        }

        ferdig = lesChar("\t\tVil du forsette å endre (J/n):");
                            //Er brukeren ferdig med å endre på data?
    }while(ferdig == 'J');
}
