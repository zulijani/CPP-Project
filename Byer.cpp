/**
*   Definisjoner av funksjoner til Byer klassen
*
*   @file Byer.cpp
*   @author  ---------------
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>
#include <fstream>
#include "Byer.h"
#include "LesData3.h"
#include "Funksjoner.h"
#include "Attraksjon.h"
#include "MuseumGalleri.h"
#include "Kirke.h"
#include "Severdighet.h"
using namespace std;


/**
*   Handler valg
*
*   @param valg     -      F�rste karatker (B eller A)
*/
void Byer::handling(char valg){
    char andreValg;

    if(valg == 'B'){
        andreValg = lesChar("");
        switch(andreValg){
            case 'A': skrivAlleByene(); break;
            case '1': skrivEnBy(); break;
            case 'N': nyBy(); break;
            case 'F': slettBy(); break;
            default: skrivMeny(); break;
        }
    }else{
        andreValg = lesChar("");
        switch(andreValg){
            case 'F': fjernAttraksjon(); break;
            case 'N': nyAttraksjon(); break;
            default: skrivMeny(); break;
        }
    }
}

/**
*   Skriver ut litt info om alle byene
*
*   @see By::hentLand() && By::hentAntallAttraksjoner
*/
void Byer::skrivAlleByene(){
    if(!byene.empty()){ //Finnes det byer:
        cout << "\n\t\tF�LGENDE BYER FINNES: \n";
        for(const auto & city : byene){
            cout << "\n\t\t" << left << setw(20) << city.first << setw(20)
                 << left << setw(20) << city.second->hentLand()
                 << right << setw(20) << city.second->hentAntallAttraksjoner()
                 << " attraksjoner\n";
        }
    }else
        cout << "\n\n\tINGEN BYER ER LAGT TIL\n\n";

}

/**
*   Skriver en by
*
*   @see Byer::printByMedAttraksjoner()
*/
void Byer::skrivEnBy(){
    string navn;
    vector <string> matchendeNavn;

        //sp�r brukeren om navn og omdanner det til store bokstaver
    cout << "\n\tSkriv alt om byen/stedet: "; getline(cin, navn);
    transform(navn.begin(), navn.end(), navn.begin(), ::toupper);

    for(auto it = byene.begin(); it != byene.end(); it++)//g�r gjennom
        if(it->first.substr(0, navn.length()) == navn)  //datastruktur og sjekker om
            matchendeNavn.push_back(it->first);//navnet finnes

    if(matchendeNavn.empty())
        cout << "\n\tFANT IKKE BY/STED MED DETTE NAVNET\n";
    else if(matchendeNavn.size() == 1){ //navnet matcher og er entydig
        printByMedAttraksjoner(matchendeNavn.front());  //printer ut by
                                                        //med attraksjoner
    }else{
        cout << "\n\tNAVNET ER IKKE ENTYDIG\n";
        for(const auto & navn : matchendeNavn)
            cout << "\t" << navn;
    }
    matchendeNavn.clear();
}

/**
*   Printer ut by med alle attraksjonene
*
*   @param  byNavn  -   navn til by
*   @param  byNavn  -   navn til by
*   @see Byer::finnBy() By::hentAntallAttraksjoner() By::hentAttraksjoner()
*   @see Attraksjon::skrivData()
*/
void Byer::printByMedAttraksjoner(const std::string & byNavn){
    By* by = nullptr;   //lager by objekt
    int index = 1;
    by = finnBy(byNavn);    //setter peker til riktig by(navn)

        cout << "\n\t" << byNavn << ", " << by->hentLand()
             << "\thar folgende " << by->hentAntallAttraksjoner()
             << " attraksjoner:\n";

        for(const auto & attraksjon : by->hentAttraksjoner()){
            cout << "\t " <<index++ << ". ";    //g�r gjennom attraksjoner
            attraksjon->skrivData();            //og skriver data
        }
}



/**
*   Legger inn en ny By
*
*   @see    By::lesData();
*/
void Byer::nyBy(){
    By* newCity = new By;
    string navn;

    cout << "\n\tBy-navn: "; getline(cin, navn);
    transform(navn.begin(), navn.end(), navn.begin(), ::toupper);
            //leser inn navnet, og transformerer det til store bokstaver

    while(byene.find(navn) != byene.end()){      //s� lenge navnet finnes:
        cout << "\nNavnet finnes allerede. Velg et annet\n";
        cout << "\n\tBy-navn: "; getline(cin, navn);
        transform(navn.begin(), navn.end(), navn.begin(), ::toupper);
    }

    newCity->lesData(); //leser inn data
    byene.insert({navn, newCity});  //inserter inn i datastrukturen
}

/**
*   Fjerner en By, som er valgt av bruker
*/
void Byer::slettBy(){
    string navn;
    string outputNavn;
    vector <string> matchendeNavn;
    char bekreft;

        //sp�r brukeren om navn og omdanner det til store bokstaver
    cout << "\n\tHvilken By/Sted har du lyst � fjerne?: "; getline(cin,navn);
    transform(navn.begin(), navn.end(), navn.begin(), ::toupper);

    for(auto it = byene.begin(); it != byene.end(); it++)  //g�r gjennom
        if(it->first.substr(0, navn.length()) == navn)  //datastrukturen og sjekker om
            matchendeNavn.push_back(it->first);//substring av navnet finnes

    if(matchendeNavn.empty())
        cout << "\n\tINGEN byer/steder har et matchende navn\n";
    else if(matchendeNavn.size() == 1){ //navnet er entydig
        outputNavn = matchendeNavn.front();
        cout << "\n\t" << outputNavn << '\n';
        bekreft = lesChar("\tSikker at du vil � fjerne byen/stedet(J/n)?");

        if(bekreft == 'J'){ //bekrefter
            auto it = byene.find(outputNavn);   //finner byen
            delete it->second;  //sletter byen
            byene.erase(it);    //eraser
            cout << "\nBYEN/STEDET BLE FJERNET\n";
        } else
            cout << "\n\tFjerning av byen/stedet ble AVBRUTT!!\n";



    }else
        cout << "\n\tNAVNET ER IKKE ENTYDIG\n";


    matchendeNavn.clear();
}

/**
*   Legger inn en ny attraksjon
*
*   @see Byer::finnBy(const string & navn) && By::leggTilAttraksjon() &&
*        Attraksjon::lesData()
*/
void Byer::nyAttraksjon(){
    By* by = nullptr;
    Attraksjon* nyAtt = nullptr;
    vector <string> matchendeNavn;
    char type;
    string navn;
    list <Attraksjon*> attraksjonene;

        //sp�r brukeren om navn og omdanner det til store bokstaver
    cout << "\n\tNy attraksjon i byen/stedet: "; getline(cin, navn);
    transform(navn.begin(), navn.end(), navn.begin(), ::toupper);

    for(auto it = byene.begin(); it != byene.end(); it ++)
        if(it->first.substr(0, navn.length()) == navn)//g�r gjennom
            matchendeNavn.push_back(it->first);//datastrukturen og sjekker om
                                //substring av navnet finnes

    if(matchendeNavn.empty())
        cout << "\n\tFANT IKKE BY/STED MED DETTE NAVNET\n";
    else if(matchendeNavn.size() == 1){ //navnet er entydig
        by = finnBy(matchendeNavn.front());//setter peker til riktig by(navn)
        cout << "\n\t" << matchendeNavn.front();
        do{
            cout << "\n\tAttraksjonstype ";
            type = lesChar("S(everdighet),K(irke),M(useumGalleri):");
        }while(type != 'S' && type != 'K' && type != 'M');

        switch(type){
            case 'S': nyAtt = new Severdighet; break;
            case 'K': nyAtt = new Kirke; break;
            case 'M': nyAtt = new MuseumGalleri; break;
        }

        nyAtt->lesData();   //leser data
        by->leggTilAtraksjon(nyAtt); //legger til attraksjon i byen
    }else
        cout << "\n\tNAVNET ER IKKE ENTYDIG\n";

    matchendeNavn.clear();
}


/**
*   Fjerner bestemt attraksjon
*
*   @see By::hentAttraksjoner() && By::hentAntallAttraksjoner
*   @see Attraksjon::skrivData() && By::slettAttraksjon()
*/
void Byer::fjernAttraksjon(){
    By* by = nullptr;
    string navn;
    vector <string> matchendeNavn;
    int index = 1,
        valgtNr;

                //sp�r brukeren om navn og omdanner det til store bokstaver
    cout << "I hvilken by skal du fjerne attraksjoner?: "; getline(cin,navn);
    transform(navn.begin(), navn.end(), navn.begin(), ::toupper);

    for(auto it = byene.begin(); it != byene.end(); it++)
        if(it->first.substr(0, navn.length()) == navn)  //datastrukturen og sjekker om
            matchendeNavn.push_back(it->first);//substring av navnet finnes


    if(matchendeNavn.empty())
        cout << "\n\tINGEN byer/steder har et matchende navn\n";
    else if(matchendeNavn.size() == 1){ //navnet er entydig
        by = finnBy(matchendeNavn.front()); //setter peker til riktig by(navn)
        for(const auto & attraksjon : by->hentAttraksjoner()){ //g�r gjennom
            cout << "\t " <<index++ << ". ";        //attraksjoner og skriver
            attraksjon->skrivData();                //ut data
        }


        valgtNr = lesInt("Velg attraksjon som skal fjernes", 1,
                         by->hentAntallAttraksjoner());

        if(valgtNr > 0 && valgtNr <= by->hentAntallAttraksjoner()){
                            //hvis valgtNr er innenfor bestemt range:
            by->slettAttraksjon(valgtNr - 1);   //slett attraksjon
        }else
            cout << "\n\tUgyldig tall. Kan ikke fjerne attraksjon.\n";

    }else
        cout << "\n\tNAVNET ER IKKE ENTYDIG\n";


}


/**
 *  Leter etter (og evt. returnerer peker til) en gitt by.
 *
 *  @param   byNavn     -  by navnet det letes etter
 *  @return  Peker til funnet 'By' INNI EN AV CONTAINERNE,  evt. 'nullptr'
 */
By* Byer::finnBy(const std::string & byNavn){
    auto it = find_if(byene.begin(), byene.end(),
            [byNavn](const auto & val) {return val.first == byNavn;});

    if(it != byene.end()){
        return it->second;
    }
    return nullptr;
}


/**
 *  Leser inn fra fil
 *
 *  @see By::By(innfil) && Byer::finnBy() && By::leggTilAttraksjon()
 */
void Byer::lesFraFil() {
    ifstream innfil("byer.dta"); // Open file
    By* city = nullptr;
    char type;
    string navn;
    int antAttraksjon;

    if (innfil) { // Check if the file exists
        cout << "\n\tLeser dataene fra 'byer.dta'\n";

        while (getline(innfil, navn)) {  // Read city name
            if (navn.empty()) continue;  // Skip empty lines
            
            if (!(innfil >> antAttraksjon)) break;  // Read number of attractions
            innfil.ignore();  // Ignore newline after number
            
            // Create city and add it to the map
            byene.insert({navn, new By(innfil)});
            city = finnBy(navn);  // Get pointer to the correct city
            
            for (int i = 0; i < antAttraksjon; i++) {
                if (!(innfil >> type)) break;  // Read type (S, M, K)
                innfil.ignore();  // Ignore space after type
                
                switch (type) {
                    case 'S': city->leggTilAtraksjon(new Severdighet(innfil)); break;
                    case 'M': city->leggTilAtraksjon(new MuseumGalleri(innfil)); break;
                    case 'K': city->leggTilAtraksjon(new Kirke(innfil)); break;
                    default: cout << "\nULOVLIG type på filen!\n"; break;
                }
            }
            innfil.ignore();  // Ensure correct reading for the next line
        }

        innfil.close(); // Close the file
    } else { // If file is missing
        cout << "\n\nFINNER IKKE FILEN!!\n\n";
    }
}


/**
*   Skriver til fil
*
*   @see By::hentAntallAttraksjoner() && By::hentAttraksjoner &&
*        By::skrivTilFil()  &&  Attraksjon::skrivTilFil()
*/
void Byer::skrivTilFil(){
    ofstream utfil("byer.dta");
    int antAntall;

    if(utfil){
        cout << "\nSkriver til filen 'byer.dta' ...\n\n";

        for(const auto & by : byene){
            antAntall = by.second->hentAntallAttraksjoner();
            utfil << by.first << '\n' << antAntall << ' ';
            by.second->skrivTilFil(utfil);

            for(const auto & attraksjon : by.second->hentAttraksjoner()){
                attraksjon->skrivTilFil(utfil);
            }
        }

    }else
        cout << "\n\nFant ikke filen til � skrive til!!\n\n";
}
