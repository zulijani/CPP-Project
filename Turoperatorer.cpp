/**
*   Definisjoner av funksjoner til klassen Turoperatorer
*
*   @file Turoperatorer.cpp
*   @author ---------------
*/

#include <iostream> //cout, cin, osv
#include <string>   //string
#include <map>      //map
#include <cctype>   //toupper
#include <algorithm>//transform
#include <iomanip>
#include <vector>   //vector
#include <fstream>
#include "Turoperatorer.h"
#include "LesData3.h"
#include "Funksjoner.h"
using namespace std;



/**
*   Handler valg
*/
void Turoperatorer::handling(){
    char andreValg;     //definerer

    andreValg = lesChar("");    //sp�r om andre karakter
    switch(andreValg){
        case 'A': skrivAlleTuroperatorer();   break;
        case '1': skrivEnTuroperator(); break;
        case 'N': nyTuroperator(); break;
        case 'E': endreEnTuroperator(); break;
        case 'F': slettTuroperator(); break;
        case 'O': lagEttOpplegg(); break;
        default: skrivMeny(); break;
    }
}


/**
*   Skriver ut litt info om alle turoperatorene
*
*   @see Turoperator::hentAntallTuropplegg() & Turoperator::hentWebside()
*/
void Turoperatorer::skrivAlleTuroperatorer(){
    if(!operatorer.empty()){ //finnes det turoperatorer i operatorer?
        cout << "\n\tF�LGENDE TUROPERATORER FINNES: \n";
        for(const auto & TurOp : operatorer){
            cout << "\n\t"  << left <<setw(15) << TurOp.first << "\t"
                 << TurOp.second->hentAntallTuropplegg() << " opplegg\t"
                 << TurOp.second->hentWebside();
        }
    }else
        cout << "\n\nINGEN TUROPERATORER FINNES\n\n";

}

/**
*   Skriver ut alt om en turoperator
*
*   @see    Turoperator::skrivData();
*/
void Turoperatorer::skrivEnTuroperator(){
    string navn;        //navnet vi f�r av bruker
    string outputNavn;  //Det egentlige navnet
    vector <string> matchendeNavn;  //vector av navn

    //sp�r brukeren om navn og omdanner det til store bokstaver
    cout << "\n\tSkriv alt om turoperatoren: "; getline(cin,navn);
    transform(navn.begin(), navn.end(), navn.begin(), ::toupper);


    for(auto it = operatorer.begin(); it != operatorer.end(); it++)
        if(it->first.substr(0, navn.length()) == navn)   //er navnet en substring av
            matchendeNavn.push_back(it->first);    //et navn i datastrukturen

    if(matchendeNavn.empty())   //navnet finnes ikke:
        cout << "\n\tINGEN turoperatorer har et matchende navn\n";
    else if(matchendeNavn.size() == 1){ //bare ett navn matcher
        outputNavn = matchendeNavn.front();
        cout << "\n\t" << outputNavn << "  ";
        operatorer[outputNavn]->skrivData();    //skriver data om turoperator
    }else
        cout << "\n\tNAVNET ER IKKE ENTYDIG\n";

    matchendeNavn.clear();
}

/**
*   Legger inn en ny Turoperator
*
*   @see    Turoperator::lesData();
*/
void Turoperatorer::nyTuroperator(){
    Turoperator* nyOp = new Turoperator;        //lager ny Turoperator
    string navn;

    cout << "\n\tNavn: "; getline(cin, navn);
                            //leser inn navn og lagrer det med store bokstaver
    transform(navn.begin(), navn.end(), navn.begin(), ::toupper);

    while(operatorer.find(navn) != operatorer.end()){ //Finnes navnet?
        cout << "\nNavnet finnes allerede. Velg et annet\n";
        cout << "\n\tNavn: "; getline(cin, navn);
        transform(navn.begin(), navn.end(), navn.begin(), ::toupper);
    }

    nyOp->lesData();    //leser data
    operatorer.insert({navn, nyOp}); //legger inn i "operatorer"
}

/**
*   Endrer en turoperators data - ut fra brukerens �nsker
*
*   @see Turoperator::endreData()
*/
void Turoperatorer::endreEnTuroperator(){
    string navn;
    string outputNavn;
    vector <string> matchendeNavn;

        //sp�r brukeren om navn og omdanner det til store bokstaver
    cout << "Hvilken turoperator har du lyst � endre?: "; getline(cin, navn);
    transform(navn.begin(), navn.end(), navn.begin(), ::toupper);

    for(auto it = operatorer.begin(); it != operatorer.end(); it++)
        if(it->first.substr(0, navn.length()) == navn)  //er navnet en substring av
            matchendeNavn.push_back(it->first); //et navn i datastrukturen

    if(matchendeNavn.empty())   //navnet finnes ikke
        cout << "\n\tINGEN turoperatorer har et matchende navn\n";
    else if(matchendeNavn.size() == 1){ //det finnes bare et matchende navn
        outputNavn = matchendeNavn.front();
        cout << "\n\tHva vil du endre for " << outputNavn << ": ";
        operatorer[outputNavn]->endreData();    //endrer data

    }else       //for mange navn som matcher
        cout << "\n\tNAVNET ER IKKE ENTYDIG\n";

}

/**
*   Fjerner en Turoperator, som er valgt av bruker
*/
void Turoperatorer::slettTuroperator(){
    string navn;
    string outputNavn;
    vector <string> matchendeNavn;
    char bekreft;

        //sp�r brukeren om navn og omdanner det til store bokstaver
    cout << "\n\tHvilken turoperator har du lyst � fjerne?: ";
                                                            getline(cin,navn);
    transform(navn.begin(), navn.end(), navn.begin(), ::toupper);

    for(auto it = operatorer.begin(); it != operatorer.end(); it++)
        if(it->first.substr(0, navn.length()) == navn)  //er starten av navnet
            matchendeNavn.push_back(it->first); //lignende med et navn
                                                //i datastrukturn

    if(matchendeNavn.empty())
        cout << "\n\tINGEN turoperatorer har et matchende navn\n";
    else if(matchendeNavn.size() == 1){ //navnet er entydig:
        outputNavn = matchendeNavn.front();
        cout << "\n\t" << outputNavn;
        bekreft = lesChar("\tSikker at du vil � fjerne turoperatoren(J/n)?");

        if(bekreft == 'J'){ //bekrefter at bruker vil fjerne navnet
            auto it = operatorer.find(outputNavn);  //finner navnet
            delete it->second;                      //sletter Turoperator
            operatorer.erase(it);                   //fjerner navnet
            cout << "\n\tTUROPERATOREN BLE FJERNET\n";
        } else
            cout << "\n\tFjerning av turoperator ble AVBRUTT!!\n";
    }else       //for mange navn som matcher
        cout << "\n\tNAVNET ER IKKE ENTYDIG\n";


    matchendeNavn.clear();
}


/**
 *  Leser inn fra fil
 *
 *  @see Turoperator::Turoperator(innfil)
 */
void Turoperatorer::lesFraFil(){
    ifstream innfil("turoperatorer.dta");
    string navn;

    if(innfil){ //finnes fil
        cout << "\n\n\tLeser fra filen 'turoperatorer.dta'...\n\n";

          //leser navn
        while(getline(innfil, navn)){   //s� lenge filen ikke er slutt
            if(navn.empty()) continue;
        // Make sure the file still has content before reading a new Turoperator
            if (!innfil.eof()) {
                operatorer.insert({navn, new Turoperator(innfil)});
            }
        }
        innfil.close(); //lukker
    }else   //finner ikke fil
        cout << "\n\nFant ikke filen 'turoperatorer.dta'!\n\n";
}

/**
*   Skriver til fil
*
*   @see Turoperator::skrivTilFil()
*/
void Turoperatorer::skrivTilFil(){
    ofstream utfil("turoperatorer.dta"); //definerer og �pner

    if(utfil){      //finnes og fant filen:
        cout << "\nSkriver til filen 'turoperatorer.dta' ....\n\n";

        for(const auto & [navn, turoperator] : operatorer){ //range-based loop som
            utfil << navn << '\n';                     //skriver til fil med nr
            turoperator->skrivTilFil(utfil);             //og data til person
        }

        utfil.close(); //lukker filen
    }else       //filen finnes ikke:
        cout << "\n\nFant ikke filen til � skrive til!!\n\n";
}

