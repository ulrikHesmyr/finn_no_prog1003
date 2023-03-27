/**
 * Fil for alle public funksjoner i klassen Kunder
 * 
 * @file class.cpp
 * @author Mathilde, Oliver og Ulrik
*/

#include "KUNDER.H"
#include "KUNDE.H"
#include "LESDATA3.H"
#include <iostream>
//#include <iterator>


/**
 * 
*/
Kunder::Kunder(){
    sisteNr = 0;
}


/**
 * 
*/
Kunder::~Kunder(){
    
}

/**
 * Leser data fra filen KUNDER.DTA
 * 
*/
void Kunder::lesFraFil(){
    std::cout << "hihi";
}


/**
 * Skriver data til filen KUNDER.DTA
 * 
*/
void Kunder::skrivTilFil() const {
    
}

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

/**
 * Oppretter ny kunde og tildeler kunden automatisk et ID-nummer som er én
 * høyere enn forrige kundenummer. Kundens data leses inn og legges inn i 
 * listen for kundene  
 * 
 * @see Kunde::Kunde(...)
 * @see Kunde::lesData()
*/
void Kunder::nyKunde(){

    //Allokerer minne for kunde og initiserer med constructor
    Kunde* kunde = new Kunde(sisteNr + 1);

    //Leser data og legger inn i listen for kundene
    kunde->lesData();
    kundene.push_back(kunde);
}

/**
 * Skriver først ut siste kundenummer hittil brukt og antall kunder i 
 * datastrukturen og deretter skrives 20 kunder av gangen hvor brukeren
 * kan velge å skrive fler helt til alle brukere(kundene) er skrevet
 * ut på skjermen
 * 
 * 
*/
void Kunder::skrivAlleKunder() const {
    std::cout   << "\nSiste kundenummer: " << sisteNr  << std::endl
                << "Antall kunder: " << kundene.size() << std::endl;


    char skrivFlereKunder;
    int counter = 0;

    for(auto & k: kundene){
        k->skrivData();
        counter++;
        if(counter % 20 == 0){
            char gaaVidere = ' ';
            gaaVidere = lesChar("Trykk (Enter) for å lese videre");
        }
    }
}

void Kunder::skrivKunde() const {

}

void Kunder::fjernKunde(){

}
