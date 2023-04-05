/**
 * Funksjon for aa lage ny kunde
 *
 * @file nyting.cpp
 * @author Mathilde, Oliver og Ulrik, NTNU
 */

#include "nyting.h"
#include "kunder.h"
#include <iostream>

using namespace std;

extern Kunder     gKundebase;


NyTing::NyTing(int tingNr){
	nr = tingNr;
	cout << "Tilgjengelige selgere:\n";
	gKundebase.skrivAlleKunder();
	cout << "Oppgi selgerNr: ";
};


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

