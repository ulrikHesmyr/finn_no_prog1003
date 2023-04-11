/**
 * Filen som inneholder alle globale funksjoner
 *
 * @file func.cpp
 * @author Mathilde, Oliver og Ulrik, NTNU
*/

#include "func.h"
#include "kunder.h"
#include <iostream>

using namespace std;


extern Kunder gKundebase;

/**
 * Skriver hovedmenyen ut på skjermen
*/
void skrivMeny() {

	cout << "Velg handling:" << endl
			  << "\t U - Kunder" << endl
			  << "\t A - Kategori" << endl
			  << "\t T - Ting" << endl
			  << "\t K - Kjop" << endl
			  << "\t Q - Avslutt program og skriv data til filer" << endl;
}