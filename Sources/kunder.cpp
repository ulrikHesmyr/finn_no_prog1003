/**
 * Fil for alle public voids i klassene
 * 
 * @file class.cpp
 * @author Mathilde, Oliver og Ulrik
*/

#include "class.h"
#include "LesData3.h"


/**
 * Håndterer brukerens kommando-valg for kundebasen
 * 
 * @see Kunder::skrivMeny()
 * 
*/
void Kunder::handling(){
    Kunder::skrivMeny();
    char valgHandlingKunde;
    valgHandlingKunde = lesChar("\nKommando");

    while (valgHandlingKunde != 'Q')  {
        switch(valgHandlingKunde)  {
            case 'N':  Kunder::nyKunde();               break;
            case 'A':  Kunder::skrivAlleKunder();       break;
            case 'S':  Kunder::skrivKunde();            break;
            case 'F':  Kunder::fjernKunde();            break;
            default:   skrivMeny();                         break;
        }
        valgHandlingKunde = lesChar("\nKommando");
    }
}

/**
 * Skriver menyen for handlinger som er tilgjengelig i kundebasen
*/
void Kunder::skrivMeny(){
    std::cout << "\nVelg handling:\n"
        << "N - Ny kunde\n"
        << "A - Skriv alle kunder\n"
        << "S - Skriv en gitt kunde\n"
        << "F - Fjern en gitt kunde\n";
}

void Kunder::nyKunde(){

}

void Kunder::skrivAlleKunder() const {

}

void Kunder::skrivKunde() const {

}

void Kunder::fjernKunde(){

}