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
 * Leser inn data fra filen KATEGORIER.DTA
 * 
 * @param inn - Filstrøm som data leses fra
 * @see NyTing::lesFraFil(...)
 * @see NyTing::NyTing()
 * @see BruktTing::BruktTing()
*/
void Kategori::lesFraFil(ifstream & inn){
    int nyEllerBrukt;
    inn >> nyEllerBrukt; inn.ignore(1);
    NyTing* nyeTingen;
    if(nyEllerBrukt == 1){
        nyeTingen = new NyTing(inn);
    } else {
        nyeTingen = new BruktTing(inn);
    }
    nyeTing.push_back(nyeTingen);
    
};

/**
 * Skriver all data om en kategori, inkludert data om hver av tingene til salgs
 * i den gjeldende kategorien
*/
void Kategori::skrivData() const{
    cout << "Antall ting til salgs: " << nyeTing.size() << endl;
    for(auto & val: nyeTing){
        val->skrivTilstand();
        val->skrivData();
    }
}

/**
 * Skriver navnet på kategorien for hver av tingene i en kategori
 * 
 * @param ut - Filstrømmen som data skrives til
 * @param k - Navnet på kategorien som skrives til filen
 * @see NyTing::skrivTilFil(...)
*/
void Kategori::skrivTilFil(std::ofstream & ut, string k){
    
    for(auto & ting: nyeTing){
        ut << k << "\n";
        ut << ting->skrivNyEllerBrukt() << " ";
        ting->skrivTilFil(ut);
    }
};

/**
 * Henter antall ting til salgs for vilkårlig kategori
 * 
 * @return int - antall ting til salgs
*/
int Kategori::antallTilSalgs(){
    return nyeTing.size();
}