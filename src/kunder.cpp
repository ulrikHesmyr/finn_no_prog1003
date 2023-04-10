/**
 * Fil for alle public funksjoner i klassen Kunder
 * 
 * @file class.cpp
 * @author Mathilde, Oliver og Ulrik
*/

#include "kunder.h"
#include "kunde.h"
#include "LesData3.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Kunder constructor hvor nytt objekt av classen initieres
*/
Kunder::Kunder(){
    sisteNr = 0;
}

/**
 * Leser data fra filen KUNDER.DTA
 * 
 * @see Kunde::Kunde(...)
 * @see Kunde::lesFraFil(...)
*/
void Kunder::lesFraFil(){
    ifstream innFil;
    innFil.open("KUNDER.DTA");

    if(innFil){
        cout << "Leser fra KUNDER.DTA" << endl;
        int kundeNr;
        innFil >> kundeNr; innFil.ignore(1);
        sisteNr = kundeNr;
        while(!innFil.eof()){
            Kunde* nykunde = new Kunde(kundeNr);
            nykunde->lesFraFil(innFil);
            kundene.push_back(nykunde);
            innFil >> kundeNr; innFil.ignore(1);
            sisteNr = kundeNr;
        }
        innFil.close();
    }
}


/**
 * Skriver data til filen KUNDER.DTA
 * 
 * @see Kunde::skrivTilFil(...)
*/
void Kunder::skrivTilFil() {
    ofstream utFil;
    utFil.open("KUNDER.DTA");

    if(utFil){
        cout << "\n\tSkriver til Filen KUNDER.DTA";

        for(auto & k: kundene){
            k->skrivTilFil(utFil);
            delete k;
        }
        kundene.clear();

    } else {
        cout << "\n\tProblemer med å skrive til filen KUNDER.DTA";
    }
}

/**
 * Håndterer brukerens kommando-valg for kundebasen
 * 
 * @see Kunder::skrivMeny()
 * 
*/
void Kunder::handling(){
    Kunder::skrivMeny();
    char valgHandlingKunde;
    valgHandlingKunde = lesChar("\nKommando");

    while (valgHandlingKunde != 'Q')  {
        switch(valgHandlingKunde)  {
            case 'N':  Kunder::nyKunde();               break;
            case 'A':  Kunder::skrivAlleKunder();       break;
            case 'S':  Kunder::skrivKunde();            break;
            case 'F':  Kunder::fjernKunde();            break;
            default:   skrivMeny();                     break;
        }
        valgHandlingKunde = lesChar("\nKommando");
    }
    cout << "\n\tDu er n\x8F i hovedmenyen\n";
}

/**
 * Skriver menyen for handlinger som er tilgjengelig i kundebasen
*/
void Kunder::skrivMeny(){
    cout << "\nVelg handling:\n"
        << "\tN - Ny kunde\n"
        << "\tA - Skriv alle kunder\n"
        << "\tS - Skriv en gitt kunde\n"
        << "\tF - Fjern en gitt kunde\n"
        << "\tQ - G\x8F til hovedmeny\n";
}

/**
 * Oppretter ny kunde og tildeler kunden automatisk et ID-nummer som er én
 * høyere enn forrige kundenummer. Kundens data leses inn og legges inn i 
 * listen for kundene  
 * 
 * @see Kunde::Kunde(...)
 * @see Kunde::lesData()
*/
void Kunder::nyKunde(){

    //Allokerer minne for kunde og initiserer med constructor
    Kunde* kunde = new Kunde(sisteNr + 1);

    //Leser data og legger inn i listen for kundene
    kunde->lesData();
    kundene.push_back(kunde);
    sisteNr++;
}

/**
 * Skriver først ut siste kundenummer hittil brukt og antall kunder i 
 * datastrukturen og deretter skrives 20 kunder av gangen hvor brukeren
 * kan velge å skrive fler helt til alle brukere(kundene) er skrevet
 * ut på skjermen
 * 
 * @see Kunde::skrivData()
 * @see lesChar(...)
*/
void Kunder::skrivAlleKunder() const {
    cout   << "\nSiste kundenummer: " << sisteNr  << endl
                << "Antall kunder: " << kundene.size() << endl;


    char skrivFlereKunder;
    int counter = 0;

    cout << "Nr        " << "Navn  " << "Tlf.  " << endl;
    for(auto & k: kundene){
        k->skrivData();
        counter++;
        if(counter % 20 == 0){
            char gaaVidere = ' ';
            gaaVidere = lesChar("Trykk (Enter) for å lese videre");
        }
    }
}

/**
 * Skriver dataen til en gitt kunde ut ifra kundenummer, dersom kunde
 * med det gitte kundenummeret eksisterer
 * 
 * @see lesInt(...)
 * @see Kunde::finnKunde()
 * @see Kunde::skrivAllData()
*/
void Kunder::skrivKunde() const {
    int hKundeNr = lesInt("\nKundenummer", 1, sisteNr);
    bool funn = false;

    //Sjekker om det eksisterer en kunde med det gitte kundenummeret
    for(auto & k: kundene){
        if(k->finnKunde(hKundeNr)){

            //Skriver ut all data om kunden dersom det var et funn
            funn = true;
            k->skrivAllData();
        }
    }
    if(!funn){
        cout << "\n\tFant ingen kunde med dette kundenummeret\n";
    }
}

/**
 * Fjerner en valgt kunde fra kundene, dersom gitt kunde eksisterer
 * 
 * @see lesInt(...)
 * @see Kunde::finnKunde(...)
 * @see Kunde::skrivAllData()
*/
void Kunder::fjernKunde() {
    //Leser inn kundens nummer fra brukeren
    int kNr = lesInt("Kundens nummer", 1, sisteNr);
    bool funn = false;

    // Går igjennom alle kundene og sjekker om kunde med kundenummer eksisterer
    for (auto it = kundene.begin(); it != kundene.end(); ++it) {
        Kunde* k = *it;

        //Dersom kunden eksisterer så skrives all data om kunden ut
        if (k->finnKunde(kNr)) {
            funn = true;
            k->skrivAllData();

            //Fjerner kunde dersom brukeren ønsker det
            char valgFjerneKunde = lesChar("\n\tVil du fjerne denne kunden? (J)a/(N)ei");
            if (valgFjerneKunde == 'J') {
                it = kundene.erase(it);
                delete k;
                cout << "\n\tKunden er n\x8F fjernet.\n";
            } else {
                cout << "\n\tKunden ble ikke fjernet.\n";
            }
        }
    }

    if (!funn) {
        cout << "\n\tFant ingen kunde med dette nummeret.\n";
    }
}


/**
 * Returnerer antall kunder i Kunder.kundene
*/
int Kunder::antall() {
    return kundene.size();
}