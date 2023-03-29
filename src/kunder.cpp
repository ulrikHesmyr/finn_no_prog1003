/**
 * Fil for alle public funksjoner i klassen Kunder
 * 
 * @file class.cpp
 * @author Mathilde, Oliver og Ulrik
*/

#include "kunder.h"
#include "kunde.h"
#include "LesData3.H"
#include <iostream>
#include <fstream>

using namespace std;
/**
 * 
*/
Kunder::Kunder(){
    sisteNr = 0;
}


/**
 * 
*/
Kunder::~Kunder(){
    
}

/**
 * Leser data fra filen KUNDER.DTA
 * 
*/
void Kunder::lesFraFil(){
    ifstream innFil;
    innFil.open("KUNDER.DTA");

    if(innFil){
        cout << "Leser fra KUNDER.DTA" << endl;
        int kundeNr;
        innFil >> kundeNr; innFil.ignore(1);
        sisteNr = kundeNr;
            cout << "kunde nummer !!!!" << kundeNr << endl;
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
*/
void Kunder::skrivTilFil() const {
    
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
        << "N - Ny kunde\n"
        << "A - Skriv alle kunder\n"
        << "S - Skriv en gitt kunde\n"
        << "F - Fjern en gitt kunde\n"
        << "Q - G\x8F til hovedmeny\n";
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
}

/**
 * Skriver først ut siste kundenummer hittil brukt og antall kunder i 
 * datastrukturen og deretter skrives 20 kunder av gangen hvor brukeren
 * kan velge å skrive fler helt til alle brukere(kundene) er skrevet
 * ut på skjermen
 * 
 * 
*/
void Kunder::skrivAlleKunder() const {
    cout   << "\nSiste kundenummer: " << sisteNr  << endl
                << "Antall kunder: " << kundene.size() << endl;


    char skrivFlereKunder;
    int counter = 0;

    cout << "Nr  " << "Navn  " << "Tlf.  " << endl;
    for(auto & k: kundene){
        k->skrivData();
        counter++;
        if(counter % 20 == 0){
            char gaaVidere = ' ';
            gaaVidere = lesChar("Trykk (Enter) for å lese videre");
        }
    }
}

void Kunder::skrivKunde() const {

}

void Kunder::fjernKunde(){

}
