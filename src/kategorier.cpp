/**
 *  Fil for public funksjoner i klassen Kategorier
 *
 *  @file   kategorier.cpp
 *  @author Mathilde, Oliver og Ulrik, NTNU
*/


#include "kategorier.h"
#include "LesData3.h"
#include <iostream>


using namespace std;

/**
 * Constructor for klassen Kategorier
*/
Kategorier::Kategorier(){
    sisteNr = 0;
}

void Kategorier::handling(char valg){
    Kategorier::skrivMeny(valg);
    switch(valg){
        case 'A':
            char v;
            v = lesChar("\nKommando");
            while (v != 'Q')  {
              switch(v)  {
                    case 'N':
                        Kategorier::nyKategori();
                        break;
                    case 'A':
                        Kategorier::skrivAlleKategorier();
                        break;
                    case 'S':
                        Kategorier::skrivKategori();
                        break;
                default:   Kategorier::skrivMeny(valg); break;
              }

              valg = lesChar("\nKommando");
            }
            break;
        case 'T':
            char v;
            v = lesChar("\nKommando");
            while (v != 'Q')  {
              switch(v)  {
                    case 'N':
                        Kategorier::nyTing();
                        break;
                    case 'E':
                        Kategorier::endreTing();
                        break;
                default:   Kategorier::skrivMeny(valg); break;
              }
              valg = lesChar("\nKommando");
            }
            break;
        case 'K':
            Kategorier::kjopTing();
            break;
        default: break;
    }
}

/**
 * 
*/
void Kategorier::skrivMeny(char valg){
    switch(valg){
        case 'A':
            cout << "\nVelg handling:\n"
                << "N - Ny kategori \n"
                << "A - Skriv alle kategorier\n"
                << "S - Skriv en gitt kategori\n"
                << "Q - Avslutt/(Q)uit\n";
            break;
        case 'T':
             cout << "\nVelg handling:\n"
                << "N - Ny ting\n"
                << "E - Endre ting\n"
                << "Q - Avslutt/(Q)uit\n";
            break;
        default: break;
    }
}




