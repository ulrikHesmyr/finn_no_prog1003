/**
 *  Fil for alle public funksjoner i classen NyTing
 *
 *  @file   nyting.cpp
 *  @author Mathilde, Oliver og Ulrik, NTNU
*/

#include "nyting.h"
#include "kunder.h"
#include <iostream>


/**
 *  Skriver ut alle tingene i en entydig og gyldig valgt kategori, og
 *  gir mulighet til å endre på de forskjellige elementene på ting som velges.
 *
 *  @param  tingListe - Peker til hele listen med ting
 *  @param  tingPeker - Peker til én ting
 * ? @param  tingSkrivData() - Skriver ut all data for en ting
 *  @param  i - int som teller opp antall ting i listen
 *
 *  @see    Kategori::finnKategori(...)
*/
NyTing::endreTing()    {

    /**
    *   Kategori::finnKategori(string k);
    *       - finner ut om innlest kategori er entydig og gyldig
    *       - if(true), return k
    *       - else, return melding om at den ikke er entydig/gyldig
    */

    /**
    *   tingPeker = tingListe;  // Peker til én ting og til hele listen.
    *                           // Legge til disse i main først? @see eks_33.c
    *                           // Initierer til listens begynnelse
    *
    *   while (tingPeker != NULL)   {       // Så lenge slutten ikke er nådd
    *       tingSkrivData(tingPeker);       // Tingen skrives
    *       tingPeker = tingPeker->neste;   // Videre til neste ting
    *   }
    *
    *
    *
    }*/


/**
 * Funksjon for aa lage ny kunde
 *
 */

NyTing::NyTing(int tingNr){
	nr = tingNr;
	std::cout << "Tilgjengelige selgere:\n";
	Kunder::skrivAlleKunder();
	std::cout << "Oppgi selgerNr: ";
	std::cin <<
}

