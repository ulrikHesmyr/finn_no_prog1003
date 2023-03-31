/**
 *   Innmat til funksjonene i klassen Kunde
 *
 *   @file     kunde.cpp
 *   @author   Mathilde, Oliver og Ulrik, NTNU
 */

#include "kunde.h"
#include "LesData3.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

/**
 * Kunde constructor hvor nytt objekt av classen initieres med et unikt 
 * kundenummer
 * 
*/
Kunde::Kunde(int kNr){
    kundeNr = kNr;
    antallTilSalgs = antallTingKjopt = antallTingSolgt = 0;
}


/**
 * Leser data om kunde fra fil. Dataen leses fra post på følgende format:
 * antallTilSalgs antallTingKjopt antallTingSolgt mobilnummer postnummer
 * navn
 * gateadresse
 * poststed
 * mailadresse
 * 
 * @param inn - Original filstrøm som dataen leses fra
*/
void Kunde::lesFraFil(ifstream & inn){

    //Initierer midlertidige/lokale variable for å indikere datatype
    int antSalgs, antKjopt, antSolgt, mobilNr, postNr;
    string nvn, gateAddr, postStd, epostAddr;

    //Leser data av typen int
    inn >> antSalgs; inn.ignore(1);
    inn >> antKjopt; inn.ignore(1);
    inn >> antSolgt; inn.ignore(1);
    inn >> mobilNr; inn.ignore(1);
    inn >> postNr; inn.ignore();

    //Leser alle strings
    getline(inn, nvn);
    getline(inn, gateAddr);
    getline(inn, postStd);
    getline(inn, epostAddr);

    antallTilSalgs = antSalgs;
    antallTingKjopt = antKjopt;
    antallTingSolgt = antSolgt;
    mobilnummer = mobilNr;
    postnummer = postNr;

    navn = nvn;
    gateadresse = gateAddr;
    poststed = postStd;
    mailadresse = epostAddr;
}

/**
 * Skriver data til vilkårllig kunde til fil på formatet (posten):
 * antallTilSalgs antallTingKjopt antallTingSolgt mobilnummer postnummer
 * navn
 * gateadresse
 * poststed
 * mailadresse
 * 
 * @param ut - Original filstrøm som data skrives til
*/
void Kunde::skrivTilFil(std::ofstream & ut){
    ut << kundeNr << " "
       << antallTilSalgs << " " << antallTingKjopt << " " << antallTingSolgt
       << " " << mobilnummer << " " << postnummer << "\n"
       << navn << "\n" << gateadresse << "\n" << poststed << "\n" << mailadresse
       << "\n"; 
}

/**
 * Leser data for opprettelse av ny kunde
 * 
 * @see lesInt(...)
*/
void Kunde::lesData(){ 
    cout << "\n\tNavn p\x8F kunde:"; getline(cin, navn);
    mobilnummer = lesInt("\tKundens mobilnummer", 11111111, 99999999);
    cout << "\tE-post adresse:"; getline(cin, mailadresse);

    cout << "\tGateadresse (gatenavn og husnummer):"; 
    getline(cin, gateadresse);

    postnummer = lesInt("\tPostnummer", 0, 9999);
    cout << "\tPoststed:"; getline(cin, poststed); 
}

/**
 * Skriver kundens ID-nummer (kundeNr), navn og mobilnummer ut på skjermen på
 * én linje
*/
void Kunde::skrivData(){
    cout << kundeNr << right << setw(10) << navn << right << setw(10) << mobilnummer << endl; 
}

/**
 * Skriver ut all data til en vilkårlig kunde
 * 
 * @see Kunde::skrivData()
*/
void Kunde::skrivAllData(){
    Kunde::skrivData();
    cout << "\n\t" << "E-post: "  << mailadresse 
        << "\n\t" << "Adresse: "  << gateadresse << ", " << postnummer 
        << "\n\t" << "Poststed: " << poststed 
        << "\n\t" << "Antall kjopt: "     << setw(6) << left << antallTingKjopt
        << "\n\t" << "Antall solgt: "     << setw(6) << left << antallTingSolgt
        << "\n\t" << "Antall til salgs: " << setw(6) << left << antallTilSalgs 
        << endl;
}

/**
 * Ser om det eksisterer en kunde med et vilkårlig kundenummer
 * 
 * @param kNr - Vilkårlig kundenummer
 * @return true/false - true dersom det er treff, false hvis ikke
*/
bool Kunde::finnKunde(int kNr){
    if(kNr == kundeNr){
        return true;
    } else {
        return false;
    }
}
