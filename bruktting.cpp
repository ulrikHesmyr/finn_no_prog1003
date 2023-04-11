/**
 * Fil for innmaten i public funksjoner i klassen BruktTing
 * 
 * @file bruktting.cpp
 * @author Mathilde, Oliver og Ulrik, NTNU
*/

#include "bruktting.h"
#include "nyting.h"
#include "const.h"

#include "LesData3.h"
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


/**
 * Constructor for opprettelse av et objekt av klassen BruktTing
 * 
 * @see NyTing::NyTing(...)
*/
BruktTing::BruktTing(int tingNr, int selgerensNr) : NyTing(tingNr, selgerensNr){
	
};

/**
 * Leser inn ekstra data for subklassen BruktTing
 * 
 * @see NyTing::lesData()
 * @see BruktTing::hentKvalitet(...)
*/
void BruktTing::lesData(){

    char kvalitet;

    //Leser inn data for baseklassen
    NyTing::lesData();

    //Les inn int alder og enum Kvalitet
    alder = lesInt("\nAlder p\x8F gjenstand (\x8fr)", 0, MAKSALDERTING);

    //Henter gyldig input fra bruker
    while(kvalitet != 'S' && kvalitet != 'P' && kvalitet != 'B' && kvalitet != 'G' && kvalitet != 'L'){
        kvalitet = lesChar("Kvalitet p\x8F gjenstand- (S)om ny, (P)ent brukt, (B)rukt, (G)odt brukt, s(L)iten");
    }
    kvaliteten = BruktTing::hentKvalitet(kvalitet);
}

/**
 * Skriver ut data om objekt av classen BruktTing
 * 
 * @see NyTing::skrivData()
*/
void BruktTing::skrivData() const{

    //Skriver all data for baseklassen før de resterende dataene
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

/**
 * Henter en char ut ifra en gitt kvalitet i form av enum Kvalitet
 * 
 * @param k - kvaliteten som skal omgjøres til en char
 * @return char - char som representerer kvaliteten til en brukt ting
*/
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
 * 
 * @return int - tallet 0 som representerer at gjenstanden er brukt for filposten
*/
int BruktTing::skrivNyEllerBrukt() const {
    return 0;
}