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

using namespace std;

extern Kunder gKundebase;

/**
 * Legger til ny ting i ???
*/

NyTing::NyTing(int tingNr){
	nr = tingNr;
	cout << "Tilgjengelige selgere:\n";
	gKundebase.skrivAlleKunder();
	lesInt("Oppgi selgerNr", 0, gKundebase.antall());

	
}
