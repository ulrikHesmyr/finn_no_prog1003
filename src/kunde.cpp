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

using namespace std;


Kunde::Kunde(int kNr){
    cout << kNr << endl;
    kundeNr = kNr;
    cout << kundeNr << endl;
    cout << "\n\tOpprettet ny kunde med kundenummer: " << kundeNr << endl;
    antallTilSalgs = antallTingKjopt = antallTingSolgt = 0;
}

Kunde::~Kunde(){
    
}

void Kunde::lesFraFil(ifstream & inn){
    int antSalgs, antKjopt, antSolgt, mobilNr, postNr;
    string nvn, gateAddr, postStd, epostAddr;

    inn >> antSalgs; inn.ignore(1);
    inn >> antKjopt; inn.ignore(1);
    inn >> antSolgt; inn.ignore(1);
    inn >> mobilNr; inn.ignore(1);
    inn >> postNr; inn.ignore();

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
    cout << kundeNr << navn << mobilnummer << antallTilSalgs << antallTingKjopt << antallTingSolgt << endl; 
}
