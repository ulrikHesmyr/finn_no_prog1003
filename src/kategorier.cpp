/**
 * Fil for alle public funksjoner i klassen Kunder
 *
 * @file class.cpp
 * @author Mathilde, Oliver og Ulrik
*/

#include "KATEGORIER.H"
#include "LESDATA3.H"
#include <iostream>     // cout
#include <fstream>      // ifstream, ofstream
using namespace std;


/**
 *
*/
Kategorier::Kategorier(){

}


/**
 *
*/
Kategorier::~Kategorier(){

}


/**
 * Leser data fra filen KATEGORIER.DTA
 *
*/
void Kategorier::lesFraFil(){

    ifstream innfil("KATEGORIER.DTA");  // Definerer og åpner ønsket fil

    int ant;

    if (innfil) {                       // Filen er funnet og kan åpnes

        cout << "\n\tLeser fra filen 'KATEGORIER.DTA' .....\n";
        innfil >>
    }

}


/**
 * Skriver data til filen KATEGORIER.DTA
 *
*/
void Kategorier::skrivTilFil() const{

}

/**
 *
*/
void Kategorier::handling(char valg){

}
