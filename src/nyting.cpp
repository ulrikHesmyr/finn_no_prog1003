/**
 * Funksjon for aa lage ny kunde
 *
 * @file nyting.cpp
 * @author Mathilde, Oliver og Ulrik, NTNU
 */

#include "nyting.h"
#include "kunder.h"
#include <iostream>


NyTing::NyTing(int tingNr){
	nr = tingNr;
	std::cout << "Tilgjengelige selgere:\n";
	Kunder::skrivAlleKunder();	
	std::cout << "Oppgi selgerNr: ";
	std::cin << 
}

