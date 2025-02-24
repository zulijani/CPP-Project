/**
*   Definisjoner av funksjoner til Opplegg klassen
*
*   @file Opplegg.cpp
*   @author  ---------------
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include "Opplegg.h"
using namespace std;

/**
*   Constructor som legger til beskrivelse for opplegget
*
*   @param besk     -   beskrivelse til Opplegget
*/
Opplegg::Opplegg(const string & besk){beskrivelse = besk;}

/**
*   Legger til data i Opplegg
*
*   @param  dagNummer   -   Antall dager opplegget varer
*   @param  by          -   navnet til byen som skal legges til
*   @param  attraksjoner-   byen sine attraksjoner som skal legges til
*/
void Opplegg::leggTilIOpplegg(int dagNummer, const string & by, const vector <string> & attraksjoner){
    oppleggData[dagNummer].push_back({by,{attraksjoner}});
    //For opplegget sin dag, så pusher man bynavnet og attraksjoner bakerst
}


/**
*   Skriver ut opplegg
*/
void Opplegg::skrivOpplegg() const{
    cout << beskrivelse;    //skriver beskrivelsen til opplegget

    for(const auto & dag : oppleggData){             //går gjennom oppleggData (map)
        cout << "\n\tDag nr. " << dag.first << ": "; //og skriver ut dagNr/int
        for(const auto & by : dag.second){           //går gjennom vector av structen
            cout << "\n\t\t" << by.navn;             //skriver bynavnet i structen
            for(const auto & attraksjon : by.attraksjoner)  //går gjennom vector av attraksjoner i struct
                cout << "\n\t\t\t" << attraksjon;       //skriver ut attraksjonene
        }
    }
}

/**
*   Skriver opplegg til fil
*
*   @param  filnavn    -    filnavet til filen som skal skrives til
*/
void Opplegg::skrivTilFil(const string & filnavn){
    ofstream utfil(filnavn);    //definerer

    if(utfil){  //finnes filen
        cout << "\n\n\tSkrevet opplegg til filen:\t" << filnavn << "\n\n";


        utfil << beskrivelse;
        for(const auto & dag : oppleggData){  //går gjennom oppleggData (map)
            utfil << "\n\tDag nr. " << dag.first << ": ";//legger til dagNr
            for(const auto & by : dag.second){  //går gjennom vector av structen
                utfil << "\n\t\t" << by.navn;   //legger til bynavn i filen
                for(const auto & attraksjon : by.attraksjoner)//går gjennom vector av attraksjoner i struct
                    utfil << "\n\t\t\t" << attraksjon; //skriver ut attraksjonene
            }
        }

    }else   //filen finnes ikke
        cout << "\n\nFant ikke filen til å skrive til!!\n\n";
}
