/**
*   Definisjoner av funksjoner
*
*   @file funksjoner.cpp
*   @author  ---------------
*/


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "Turoperatorer.h"
#include "Byer.h"
#include "By.h"
#include "Funksjoner.h"
#include "LesData3.h"
#include "Const.h"
#include "Attraksjon.h"
#include "MuseumGalleri.h"
#include "Kirke.h"
#include "Severdighet.h"
#include "Opplegg.h"
//#include <bits.h>   //to_string
using namespace std;

extern Turoperatorer gOperatorBase;
extern Byer gByerBase;

/**
 *  Skriver programmets menyvalg/muligheter p� skjermen.
 */
void skrivMeny(){
    cout << "\n\n\n\n\tF�LGENDE KOMMANDOER ER TILGJENGELIGE:\n\n\n";
    cout << "\t   T  A  \t   - skriv alle turoeprat�rer\n";
    cout << "\t   T  1  \t   - skriv alt om en turoperat�r\n";
    cout << "\t   T  N  \t   - ny turoperat�r\n";
    cout << "\t   T  E* \t   - endre noe om en turoperat�r\n";
    cout << "\t   T  O  \t   - lag opplegg for en turoperat�r\n";
    cout << "\t   T  F  \t   - fjern/slett en turoperat�r\n\n\n";

    cout << "\t   B  A  \t   - skriv alle byer\n";
    cout << "\t   B  1  \t   - skriv alt om en by\n";
    cout << "\t   B  N  \t   - ny by\n";
    cout << "\t   B  F  \t   - fjern/slett en by\n\n\n";

    cout << "\t   A  N  \t   - ny attraksjon i en by\n";
    cout << "\t   A  F  \t   - fjern/slett attraksjon i en by\n\n\n";

    cout << "\t   Q     \t   - Quit / avslutt\n\n\n";

}


/**
*   Lager ett opplegg for en bestemt turoperator
*
*   @see Byer::printByMedAttraksjoner() && Byer::finnBy()
*   @see By::hentAntallOpplegg() && hentSpesifikkAttraksjon
*   @see Attraksjon::hentID()
*   @see Opplegg::leggTilIOpplegg() && Opplegg::skrivOpplegg()
*   @see Turoperator::hentAntallTuropplegg() && Turoperator::okeAntallTuropplegg()
*/
void lagEttOpplegg(){
    vector <string> matchendeToNavn; //Navn som matcher for toNavn
    vector <string> matchendeByNavn; //navn som matcher for byNavn
    vector <string> attraksjonerForBy;
    map <string, Turoperator*> operatorer;  //datastruktur for Turoperatorer
    map <string, By*> byene; //datastruktur for Byer
    string toNavn,  //navn for turoperator
           byNavn;   //navn for by
    string beskrivelse; //beskrivelse av turopplegget
    string filnavn;     // filnavnet til filen som bruker kan lagre
    int antDager; //Opplegg for antall dager
    int dagNummer = 1; //N�v�rende dag for opplegget
    int attraksjonNr; //nummer til attraksjon bruker velger
    char fortsett = 'S'; //Fortsett med � legge til attraksjoner
    By* by = nullptr;
    Attraksjon* valgtAttraksjon = nullptr;
    char svar;
    int antOpplegg;

    cout << "\tLag ett opplegg for turoperatoren: "; getline(cin, toNavn);
    transform(toNavn.begin(), toNavn.end(), toNavn.begin(), ::toupper);
    //sp�r om navn og setter navn til store bokstaver

    operatorer = gOperatorBase.hentTuroperatorer(); //henter datastruktur
    for(auto it = operatorer.begin(); it != operatorer.end(); it++)//g�r gjennom datastruktur
        if(it->first.substr(0, toNavn.length()) == toNavn)    //Finnes det et navn som starter p� det brukeren skrev
            matchendeToNavn.push_back(it->first);  //pusher navn inn i en vector

    if(matchendeToNavn.size() == 1){    //er navnet entydig?
        cout << "\n\t" << matchendeToNavn.front();
        cout << "\n\tBeskrivelse av opplegget: "; getline(cin, beskrivelse);
        antDager = lesInt("\tOpplegg for antall dager",1, MAXOPPLEGGDAGER);


        Opplegg opplegg(beskrivelse);   //lager et opplegg-objekt med beskrivelse
        while(dagNummer <= antDager && fortsett != 'Q'){  //er dagnummer mindre enn antall dager og brukeren valgt � fortsette?
            fortsett = 'S';         //setter fortsett til 'S'
            while(fortsett == 'S'){ //brukeren har valgt � fortsette
                matchendeByNavn.clear();
                cout << "\n\tDag nr. " << dagNummer << ':';
                cout << "\n\tLag opplegg for byen/stedet: "; getline(cin,byNavn);
                transform(byNavn.begin(), byNavn.end(), byNavn.begin(), ::toupper);
                //sp�r om navn og endrer det til store bokstaver

                byene = gByerBase.hentByene();  //henter map av byene
                for(auto it2 = byene.begin(); it2 != byene.end(); it2++)  //g�r gjennom datastruktur
                    if(it2->first.substr(0, byNavn.length()) == byNavn) //Finnes det et navn som starter p� det brukeren skrev
                        matchendeByNavn.push_back(it2->first);  //pusher navnet inn i vectoren

                if(matchendeByNavn.size() == 1){ //er navnet entydig?
                    attraksjonerForBy.clear();  //clearer vectoren med attraksjonene
                    gByerBase.printByMedAttraksjoner(matchendeByNavn.front()); //skriver by med alle attraksjoner

                    by = gByerBase.finnBy(matchendeByNavn.front()); //setter 'by-objekt' til � v�re en by fra 'byene' som har samme navn

                    attraksjonNr = lesInt("\n\tLegg til attraksjon nr ",0 , by->hentAntallAttraksjoner());//leser tall
                    while(attraksjonNr != 0){   //imens bruker ikke velger "0"
                        valgtAttraksjon = by->hentSpesifikkAttraksjon(attraksjonNr);    //definerer
                        cout << "\t\tLegger til attraksjon: "
                             << valgtAttraksjon->hentID() << '\n';
                        attraksjonerForBy.push_back(valgtAttraksjon->hentID()); //legger til valgt attraksjonNavn i en vector
                        attraksjonNr = lesInt("\n\tLegg til attraksjon nr ",0 , by->hentAntallAttraksjoner());
                                                            //leser tall p� nytt
                    }
                    opplegg.leggTilIOpplegg(dagNummer, matchendeByNavn.front(), attraksjonerForBy);
                                                    //Legger til data i opplegg(dagnr, bynavn, vector med attrakjonsnavn)

                    //sp�r om Samme dag eller neste dag basert p� om dagnummer er
                    //enn antDager eller ikke
                    if(dagNummer < antDager){
                        do{
                            fortsett = lesChar("\n\tS(amme dag), N(este dag), Q(uit):");
                        }while(fortsett != 'S' && fortsett != 'N' && fortsett != 'Q');
                    }else{
                        do{
                            fortsett = lesChar("\n\tS(amme dag), Q(uit):");
                        }while(fortsett != 'S' && fortsett != 'Q');
                    }

                    if(fortsett == 'N')  //fortsett er 'N'
                        dagNummer++;        //�ker dagNummer

                }else //navnet er ikke entydig eller finnes ikke
                    cout << "\nBy-navnet er ikke entydig!\n";
                }
            }

            opplegg.skrivOpplegg(); //skriver opplegget p� skjerm
            operatorer[matchendeToNavn.front()]->okeAntallTuropplegg(); //�ker antall turopplegg
            antOpplegg = operatorer[matchendeToNavn.front()]->hentAntallTuropplegg();

            svar = lesChar("\nVil du lagre opplegget til fil? (J/n):");
            if(svar == 'J'){
                filnavn = lagFilnavn(matchendeToNavn.front(), antOpplegg, dagNummer); //lager filnavn
                opplegg.skrivTilFil(filnavn);   //skriver til fil(med filnavn)
            }

        }else //navnet er ikke entydig eller finnes ikke
        cout << "\n\tTuroperatornavnet er ikke entydig!\n\n";


    matchendeToNavn.clear();    //clearer vectoren
}

/**
*   lager filnavn
*
*   @return filnavn
*/
string lagFilnavn(const string & navn,int antOpp, int antDag){
    string filnavn = navn + "-"; //lager starten av filnavnet

            //lager fortsettelsen basert p� antallOpplegg
    if(antOpp >= 100)
        filnavn += std::to_string(antOpp);          //bruker std::to_string
    if(antOpp >= 10)                                //for � omdanne int til string.
        filnavn += "0" + std::to_string(antOpp);    //Kunnet kanskje ha g�tt gjennom v�r
    else                                            //karakter i tallet og omdannet den, men
        filnavn += "00" + std::to_string(antOpp);   //det blir litt dr�yt, s� jeg brukte internett.


    filnavn += "-" + to_string(antDag) + "dg.dta";  //Lager slutten p� filnavnet

    for(int i = 0; i < filnavn.size(); i++) //sjekker om det er mellomrom i navnet
        if(filnavn[i] == ' ')               //p� turoperat�ren, og omdanner ' ' til '-'
            filnavn[i] = '-';


    return filnavn;     //returnerer filnavn
}
