/**
 * Fil for innmaten av public funksjoner av classen NyTing
 *
 * @file nyting.cpp
 * @author Mathilde, Oliver og Ulrik, NTNU
 */

#include "nyting.h"
#include "const.h"
#include "kunder.h"
#include "kunde.h"

#include "LesData3.h"
#include <iostream>
#include <fstream>

using namespace std;

extern Kunder gKundebase;

/**
 * Constructor for klassen NyTing uten parameter som brukes ved opprettelse av ting
 * når data leses fra fil.
 * 
 * @param inn - Filstrømmen data leses fra
*/
NyTing::NyTing(ifstream & inn){
    int tingNr, selgerensNr, antallAvTingen, prisen;
    string navnet, beskrivelsen;

    inn >> tingNr; inn.ignore(1);
    inn >> selgerensNr; inn.ignore(1);
    inn >> antallAvTingen; inn.ignore(1);
    inn >> prisen; inn.ignore();

    getline(inn, navnet);
    getline(inn, beskrivelsen);

    navn = navnet;
    beskrivelse = beskrivelsen;

    nr = tingNr;
    selgerNr = selgerensNr;
    pris = prisen;
    antallTilSalgs = antallAvTingen;
}


/**
 * Skriver data for NyTing til fil
 * 
 * @param ut - Filstrømmen som data skrives til
*/
void NyTing::skrivTilFil(ofstream & ut){
    ut << nr << " " << selgerNr << " " << antallTilSalgs << " " << pris << "\n"
        << navn << "\n"
        << beskrivelse << "\n";
}

/**
 * Constructor for opprettelse av et objekt av klassen NyTing
 * 
 * @param tingNr - Tingens unike nummer
 * @param selgerensNr - Selgerens unike kundenummer
*/
NyTing::NyTing(int tingNr, int selgerensNr){
	nr = tingNr;
    selgerNr = selgerensNr;
};

/**
 * Leser data for objektet av klassen NyTing etter opprettelsen
*/
void NyTing::lesData(){
    cout << "\nNavn p\x8F gjenstand: "; getline(cin, navn);
    cout << "\nBeskrivelse av gjenstand: "; getline(cin, beskrivelse);
    pris = lesInt("\nPris p\x8F gjenstand", MINPRIS, MAKSPRIS);
    antallTilSalgs = lesInt("\nAntall til salgs", 1, MAKSANTALL);
}

/**
 * Skriver data om et objekt av klassen NyTing
*/
void NyTing::skrivData() const{
    cout << "Produkt nummer: " << nr << endl
        << "\tNavn: " << navn << endl
        << "\tPris: " << pris << endl
        << "\tAntall til salgs: " << antallTilSalgs << endl
        << "\tBeskrivelse: " << beskrivelse << endl;
};

/**
 * Skriver at tingen er ny
*/
void NyTing::skrivTilstand() const {
    cout << "NY ";
}

/**
 * Skriver tallet 1 til fil fordi gjenstanden er ny
 * 
 * @return int - Tallet som representerer at tingen er ny
*/
int NyTing::skrivNyEllerBrukt() const {
    return 1;
}

/**
 * Henter det unike nummeret til tingen
 * 
 * @return int - Det unike nummeret til gjenstanden
*/
int NyTing::hentNr(){
    return nr;
}

/**
 * Henter selgerens unike kundenummer
 * 
 * @return int - Selgerens unike kundenummer
*/
int NyTing::hentSelgerNr(){
    return selgerNr;
}

/**
 * Henter antall til salgs av tingen
 * 
 * @return int - antall av tingen som er til salgs
*/
int NyTing::hentAntallAvTing(){
    return antallTilSalgs;
}

/**
 *  hendelser:
 *          - Kjøperens antallTingKjopt økes med én
 *          - Selgerens antallTingSolgt økes med én
 *          
 *          - Antall av tingen minker med én (evt slettes helt hvis det er 0 igjen)
 *          - Dersom tingen slettes helt, så minker antallTingTilSalgs for selgeren også
 * 
 * Registrerer salget for kunde og selger
 * 
 * @param kjoperensNummer - Kjøperens unike kundenummer
 * @param selgerensNummer - Selgerens unike kundenummer
 * @see Kunder::salg(...)
*/
void NyTing::salg(int kjoperensNummer, int selgerensNummer){

    gKundebase.salg(kjoperensNummer, selgerensNummer, antallTilSalgs-1);
    antallTilSalgs--;

}
