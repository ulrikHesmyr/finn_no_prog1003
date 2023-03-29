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

using namespace std;


Kunde::Kunde(int Knr){
    kundeNr = Knr;
    cout << "\n\tOpprettet ny kunde med kundenummer: " << kundeNr << endl;
    antallTilSalgs = antallTingKjopt = antallTingSolgt = 0;
}

Kunde::~Kunde(){
    
}

void Kunde::lesFraFil(ifstream & inn){
    inn >> antallTilSalgs; 
    inn >> antallTingKjopt; 
    inn >> antallTingSolgt; 
    inn >> mobilnummer; 
    inn >> postnummer;
    getline(inn, navn);
    getline(inn, gateadresse);
    getline(inn, poststed);
    getline(inn, mailadresse);
}

void Kunde::lesData(){ 
    cout << "\n\tNavn p\x8F kunde:"; getline(cin, navn);
    mobilnummer = lesInt("Kundens mobilnummer", 11111111, 99999999);
    cout << "\n\tE-post adresse:"; getline(cin, mailadresse);

    cout << "\n\tGateadresse (gatenavn og husnummer):"; 
    getline(cin, gateadresse);

    postnummer = lesInt("Postnummer", 0, 9999);
    cout << "\n\tPoststed:"; getline(cin, poststed); 
}

void Kunde::skrivData(){
    cout << "hihi" << endl;
}
