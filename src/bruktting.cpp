/**
 * Fil for innmaten i public funksjoner i klassen BruktTing
 * 
 * @file bruktting.cpp
 * @author Mathilde, Oliver og Ulrik, NTNU
*/

#include "bruktting.h"
#include "nyting.h"
#include "func.h"
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector <string> kvaliteter ={"Som ny", "Pent brukt", "Brukt", "Godt brukt", "Sliten"};

/**
 * Constructor for classen BruktTing ved opprettelse av et objekt ved lesing fra fil
 * 
 * @see BruktTing::hentKvalitet(...)
*/
BruktTing::BruktTing(ifstream & inn) : NyTing(inn) {
    int alderen;
    char k;
    inn >> alderen; inn.ignore(1);
    inn >> k; inn.ignore();


    alder = alderen;
    kvaliteten = BruktTing::hentKvalitet(k);
}


void BruktTing::lesData(){
    NyTing::lesData();

    //Les inn int alder og enum Kvalitet
}

/**
 * Skriver ut data om objekt av classen BruktTing
 * 
 * @see NyTing::skrivData()
*/
void BruktTing::skrivData() const{

    NyTing::skrivData();
    
    cout << "\tAlder: " << alder
        << "\tKvalitet: " << kvaliteter[kvaliteten] << endl;
}

/**
 * Skriver at tingen er brukt
*/
void BruktTing::skrivTilstand() const{
    cout << "BRUKT ";
};

/**
 * Henter kvaliteten på en gjenstand ut ifra char
 * 
 * @param k - Char som indikerer kvaliteten for en brukt gjenstand
 * @return enum Kvalitet
*/
enum Kvalitet BruktTing::hentKvalitet(char k){
	switch (k)
	{
	case 'S':
		return SomNy;
		break;
	case 'P':
		return PentBrukt;
		break;
	case 'B':
		return Brukt;
		break;
	case 'G':
		return GodtBrukt;
		break;
	case 'L':
		return Sliten;
		break;
	
	default:
		break;
	}
}

char BruktTing::hentChar(enum Kvalitet k){
    switch(k){
        case SomNy:
            return 'S';
            break;
        case PentBrukt:
            return 'P';
            break;
        case Brukt:
            return 'B';
            break;
        case GodtBrukt:
            return 'G';
            break;
        case Sliten:
            return 'S';
            break;
        default:
            break;

    }
}

/**
 * Skriver data til fil for objekter av classen BruktTing
 * 
 * @param ut - Filstrøm som data skrives til
 * @see NyTing::skrivTilFil(...)
 * @see BruktTing::hentChar(...)
*/
void BruktTing::skrivTilFil(ofstream & ut){
    NyTing::skrivTilFil(ut);
    ut << alder << " " << BruktTing::hentChar(kvaliteten) << "\n";
}


/**
 * Skriver tallet 0 til fil fordi gjenstanden er brukt
*/
int BruktTing::skrivNyEllerBrukt() const {
    return 0;
}