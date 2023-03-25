/**
 * Filen som inneholder alle globale funksjoner
 * 
 * @file func.cpp
 * @author Mathilde, Oliver og Ulrik, NTNU
*/

#include "FUNC.H"
#include <iostream>

void skrivMeny() {
	std::cout << "Velg type handling:" << std::endl
			  << "\t U - Kunder" << std::endl
			  << "\t A - Kategori" << std::endl
			  << "\t T - Ting" << std::endl
			  << "\t K - Kjop" << std::endl;
}
