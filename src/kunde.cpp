/**
 *   Innmat til funksjonene i klassen Kunde
 *
 *   @file     kunde.cpp
 *   @author   Mathilde, Oliver og Ulrik, NTNU
 */

#include "kunde.h"
#include "LesData3.h"
#include <iostream>

Kunde::Kunde(int Knr){
    kundeNr = Knr;
    std::cout << "\n\tOpprettet ny kunde med kundenummer: " << kundeNr << std::endl;
    antallTilSalgs = antallTingKjopt = antallTingSolgt = 0;
}

Kunde::~Kunde(){
    
}

void Kunde::lesData(){ 
    std::cout << "\n\tNavn p\x8F kunde:"; getline(std::cin, navn);
    mobilnummer = lesInt("Kundens mobilnummer", 11111111, 99999999);
    std::cout << "\n\tE-post adresse:"; getline(std::cin, mailadresse);

    std::cout << "\n\tGateadresse (gatenavn og husnummer):"; 
    getline(std::cin, gateadresse);

    postnummer = lesInt("Postnummer", 0, 9999);
    std::cout << "\n\tPoststed:"; getline(std::cin, poststed); 
}

void Kunde::skrivData(){
    std::cout << "hihi" << std::endl;
}
