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