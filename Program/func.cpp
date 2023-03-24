/**
 * Filen som inneholder alle globale funksjoner
 * 
 * @file func.cpp
 * @author Oliver, Mathilde og Ulrik
*/

#include <iostream>
#include "func.h"

void skrivMeny() {
	std::cout << "Velg type handling:" << std::endl
			  << "\t U - Kunder" << std::endl
			  << "\t A - Kategori" << std::endl
			  << "\t T - Kunder" << std::endl
			  << "\t K - Kjop" << std::endl;
}
