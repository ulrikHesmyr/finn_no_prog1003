/**
 * Funksjon for aa lage ny kunde
 *
 * @file nyting.cpp
 * @author Mathilde, Oliver og Ulrik, NTNU
 */

#include "nyting.h"
#include "kunder.h"
#include "list"
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
*/
NyTing::NyTing(int tingNr){
	nr = tingNr;
};

/**
 * Leser data for objektet av klassen NyTing etter opprettelsen
 * 
 * @see Kunder::skrivAlleKunder()
 * @see Kunder::antall()
 * @see lesInt()
*/
void NyTing::lesData(){
	cout << "Tilgjengelige selgere:\n";
	gKundebase.skrivAlleKunder();
	selgerNr = lesInt("\nOppgi selgerNr: ", 1, gKundebase.antall());
}


/**
 *  Skriver ut alle tingene i en entydig og gyldig valgt kategori, og
 *  gir mulighet til å endre på de forskjellige elementene p ting som velges.
 *
 *  @param  tingListe - Peker til hele listen med ting
 *  @param  tingPeker - Peker til �n ting
 * ? @param  tingSkrivData() - Skriver ut all data for en ting
 *  @param  i - int som teller opp antall ting i listen
 *
 *  @see    Kategori::finnKategori(...)
*/
void NyTing::endreTing()    {
    
}

    /**
    *   Kategori::finnKategori(string k);
    *       - finner ut om innlest kategori er entydig og gyldig
    *       - if(true), return k
    *       - else, return melding om at den ikke er entydig/gyldig
    */

    /**
    *   tingPeker = tingListe;  // Peker til �n ting og til hele listen.
    *                           // Legge til disse i main f�rst? @see eks_33.c
    *                           // Initierer til listens begynnelse
    *
    *   while (tingPeker != NULL)   {       // S� lenge slutten ikke er n�dd
    *       tingSkrivData(tingPeker);       // Tingen skrives
    *       tingPeker = tingPeker->neste;   // Videre til neste ting
    *   }
    *
    *
    *
    }*/

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
*/
int NyTing::skrivNyEllerBrukt() const {
    return 1;
}
