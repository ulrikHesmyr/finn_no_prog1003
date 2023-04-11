/**
 * Fil for alle public funksjoner i klassen Kunder
 * 
 * @file kunder.cpp
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
        cout << "\tLeser fra filen KUNDER.DTA..." << endl;
        int kundeNr;
        innFil >> kundeNr; innFil.ignore(1);
        sisteNr = kundeNr;
        while(!innFil.eof()){

            //Oppretter nytt objekt av classen Kunde og leser inn data fra filen
            Kunde* nykunde = new Kunde(kundeNr);
            nykunde->lesFraFil(innFil);

            //Legger til objektet i listen for alle kundene
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
        cout << "\n\tSkriver til Filen KUNDER.DTA...";

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
 * @see Kunder::nyKunde()
 * @see Kunder::skrivAlleKunder()
 * @see Kunder::skrivKunde()
 * @see Kunder::fjernKunde()
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
            default:   
                cout << "\n\tKommando ikke tillat!\n"; 
                Kunder::skrivMeny(); 
                break;
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
*/
void Kunder::skrivAlleKunder() const {

    char gaaVidere;
    int counter = 0;

    cout   << "\nSiste kundenummer: " << sisteNr  << endl
                << "Antall kunder: " << kundene.size() << endl;

    cout << "Nr        " << "Navn  " << "Tlf.  " << endl;

    //Stopper loopen for hver 20. kunde og venter på input før den går videre
    for(auto & k: kundene){
        k->skrivData();
        counter++;
        if(counter % 20 == 0){
            gaaVidere = lesChar("Skriv inn en bokstav for å lese videre");
        }
    }
}

/**
 * Skriver dataen til en gitt kunde ut ifra kundenummer, dersom kunde
 * med det gitte kundenummeret eksisterer
 * 
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

/**
 * Henter en kunde ut ifra kundenummeret til en vilkårlig kunde
 * 
 * @see Kunde::finnKunde(...)
 * @return int - selgerens kundenummer
*/
int Kunder::hentKunde(){
    bool gyldigFunn = false;
    int brukersNr;

    while(!gyldigFunn){
        brukersNr = lesInt("\nSelgerens kundenummer: ", 1, kundene.size());
        
        for(auto & k: kundene){
            if(k->finnKunde(brukersNr)){
                gyldigFunn = true;
            }
        }
    }
    
    return brukersNr;

}

/**
 * Registrerer salgsdata for kunde og selger ved et salg
 * 
 * @param kjoperensNummer - Kjøperens unike kundenummer
 * @param selgerensNummer - Selgerens unike kundenummer
 * @param antTilSalgs - Antall igjen til salgs
 * @see Kunde::finnKunde(...)
 * @see Kunde::kjop()
 * @see Kunde::minkAntallTilSalgs()
*/
void Kunder::salg(int kjoperensNummer, int selgerensNummer, int antTilSalgs){
    for(auto & k: kundene){
        if(k->finnKunde(kjoperensNummer)){
            k->kjop();
        }

        if(k->finnKunde(selgerensNummer)){
            k->salg();
            if(antTilSalgs == 0){
                k->minkAntallTilSalgs();
            }
        }
    }
}