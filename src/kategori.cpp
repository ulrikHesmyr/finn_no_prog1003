/**
 * Fil for alle public funksjoner i klassen Kategori
 * 
 * @file kategori.cpp
 * @author Oliver, Ulrik og Mathilde, NTNU
*/

#include <string>
#include <iostream>
#include <fstream>
#include "kategori.h"
#include "nyting.h"
#include "bruktting.h"

using namespace std;


/**
 * Constructor for klassen Kategori
*/
Kategori::Kategori(){

}

/**
 * 
*/
void Kategori::lesFraFil(ifstream & inn){
    int nyEllerBrukt;
    inn >> nyEllerBrukt; inn.ignore(1);
    NyTing* nyeTingen;
    if(nyEllerBrukt == 1){
        nyeTingen = new NyTing();
    } else {
        nyeTingen = new BruktTing();
    }
    nyeTingen->lesFraFil(inn);
    nyeTing.push_back(nyeTingen);
    

};

/**
 * Skriver all data om en kategori, inkludert data om hver av tingene til salgs
 * i den gjeldende kategorien
*/
void Kategori::skrivData() const{
    cout << "Antall ting til salgs: " << nyeTing.size() << endl;
    for(auto & val: nyeTing){
        val->skrivData();
    }
}

/**
 * 
*/
void Kategori::skrivTilFil(std::ofstream & ut){

};

/**
 * Henter antall ting til salgs for vilkårlig kategori
 * 
 * @return int - antall ting til salgs
*/
int Kategori::antallTilSalgs(){
    return nyeTing.size();
}