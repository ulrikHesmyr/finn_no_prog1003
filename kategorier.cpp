/**
 *  Fil for public funksjoner i klassen Kategorier
 *
 *  @file   kategorier.cpp
 *  @author Mathilde, Oliver og Ulrik, NTNU
*/


#include "kategorier.h"
#include "kategori.h"
#include "kunder.h"
#include "kunde.h"

#include "LesData3.h"
#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

extern Kunder gKundebase;

/**
 * Constructor for klassen Kategorier
*/
Kategorier::Kategorier(){
    sisteNr = 0;
}


/**
 * Funksjon for å håndtere valg av handling
 * 
 * @param valg - Char som presenterer valg av handling
 * @see Kategorier::skrivMeny(...)
 * @see lesChar(...)
 * @see Kategorier::nyKategori()
 * @see Kategorier::skrivAlleKategorier()
 * @see Kategorier::skrivKategori()
 * @see Kategorier::nyTing()
 * @see Kategorier::endreTing()
 * @see Kategorier::kjopTing()
*/
void Kategorier::handling(char valg){

    char v;
    Kategorier::skrivMeny(valg);
    switch(valg){
        case 'A':
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

              v = lesChar("\nKommando");
            }

            cout << "\n\tDu er n\x8F i hovedmenyen\n";
            break;
        case 'T':
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
              v = lesChar("\nKommando");
            }
            cout << "\n\tDu er n\x8F i hovedmenyen\n";
            break;
        case 'K':
            Kategorier::kjopTing();
            break;
        default: break;
    }
}

/**
 * Skriver menyen for handlingene til et gikk valg
 * 
 * @param valg - Char som representerer valg av handling
*/
void Kategorier::skrivMeny(char valg){
    switch(valg){
        case 'A':
            cout << "\nVelg handling:\n"
                << "\tN - Ny kategori \n"
                << "\tA - Skriv alle kategorier\n"
                << "\tS - Skriv en gitt kategori\n"
                << "\tQ - G\x8F til hovedmenyen\n";
            break;
        case 'T':
             cout << "\nVelg handling:\n"
                << "\tN - Ny ting\n"
                << "\tE - Endre ting\n"
                << "\tQ - G\x8F til hovedmenyen\n";
            break;
        case 'K':
            break;
        default: 
            cout << "\n\tKommando ikke tillat!\n";
            break;
    }
}

/**
 * Oppretter en ny kategori dersom det ikke eksisterer en kategori med samme navn
 * 
 * @see Kategori::Kategori()
*/
void Kategorier::nyKategori(){

    //Leser inn navn på ny kategori fra bruker og gjør første bokstaven til uppercase
    string navnNyKategori;
    cout << "\nNavn p\x8F ny kategori: "; getline(cin, navnNyKategori);
    navnNyKategori[0] = toupper(navnNyKategori[0]);

    //Sjekker om kategorien finner fra før, hvis ikke så opprettes den nye kategorien og legges i "kategoriene"
    bool eksistererFraFor = Kategorier::finnKategori(navnNyKategori);
    if(!eksistererFraFor){
        Kategori* nyeKategorien = new Kategori();
        kategoriene.insert(pair <string, Kategori*> (navnNyKategori, nyeKategorien));
        if(nyeKategorien){
            cout << "\n\tOpprettet ny kategori: " << navnNyKategori << endl;
        }
    }
}

/**
 * Leser data fra filen KATEGORIER.DTA
 * 
 * @see Kategorier::finnKategori(...)
 * @see Kategori::Kategori()
 * @see Kategori::lesFraFil()
*/
void Kategorier::lesFraFil(){
    ifstream innFil;
    innFil.open("KATEGORIER.DTA");

    if(innFil){
        cout << "\tLeser fra filen KATEGORIER.DTA..." << endl;
        string kategori;
        getline(innFil, kategori);
        while(!innFil.eof()){
            bool kategoriEksisterer = Kategorier::finnKategori(kategori);
            
            if(!kategoriEksisterer){
                Kategori* nyeKategorien = new Kategori();
                kategoriene.insert(pair <string, Kategori*> (kategori, nyeKategorien));
                nyeKategorien->lesFraFil(innFil);
            } else {
                for(auto & kat: kategoriene){
                    if(kat.first == kategori){
                        kat.second->lesFraFil(innFil);
                    }
                }
            }
            sisteNr++;
            getline(innFil, kategori);
        }
    }
}

/**
 * Skriver alle kategorier og tingene i kategoriene til filen
 * 
 * @see Kategori::skrivTilFil(...)
*/
void Kategorier::skrivTilFil(){

    ofstream utFil;
    utFil.open("KATEGORIER.DTA");

    if(utFil){
        cout << "\n\tSkriver til Filen KATEGORIER.DTA...\n";

        //Skriver ut for hver kategori
        for(auto & kat: kategoriene){
            kat.second->skrivTilFil(utFil, kat.first);
        }
    } else {
        cout << "\n\tKunne ikke åpne fil\n";
    }

}

/**
 * Spør etter kjøperens nummer og leser inn entydig kategori navn og 
 * skriver deretter hele navnet på kategorien, antall ting til salgs i den og data.
 * Etter det, velger kjøperen hvilket produkt som skal kjøpes.
 * 
 * @see Kunder::antall()
 * @see Kategorier::skrivAlleKategorier()
 * @see Kategorier::hentEntydigKategori()
 * @see Kategori::kjopTing(...)
*/
void Kategorier::kjopTing(){
    int kjoperensNummer = lesInt("\nKjoperens nummer", 1, gKundebase.antall());
    Kategorier::skrivAlleKategorier();

    string onsketKategori = Kategorier::hentEntydigKategori();

    //Skriver data om den valgte kategorien
    for(auto & val: kategoriene){
        if(val.first == onsketKategori){
            cout << val.first << endl;
            val.second->kjopTing(sisteNr, kjoperensNummer);
        }
    }

};

/**
 * Skriver alle ting for en vilkårlig og entydig kategori og henter deretter en vilkårlig 
 * og entydig kategori fra brukeren. Dette gjøres slik at brukeren kan endre på en av tingene
 * under denne valgte kategorien
 * 
 * @see Kategorier::skrivAlleKategorier()
 * @see Kategorier::hentEntydigKategori()
 * @see Kategori::endreTing(...)
*/
void Kategorier::endreTing(){
    Kategorier::skrivAlleKategorier();
    string onsketKategori = Kategorier::hentEntydigKategori();

    for(auto & kat: kategoriene){
        if(kat.first == onsketKategori){
            cout << "\n" << onsketKategori << endl;
            kat.second->endreTing(sisteNr);
        }
    }
};

/**
 * Oppretter en ny eller en brukt ting innenfor en eksisterende og vilkårlig kategori
 * og legges inn i tingene for denne kategorien
 * 
 * Entydig kategori
 * Henter selgerens kundenummer
 * Sjekk om dette kundenummeret eksisterer
 * Spør om tingen er brukt eller ny
 * Les inn data
 * Legg inn i nyeTing for den gjeldende kategorien
 * 
 * @see Kategorier::skrivAlleKategorier()
 * @see Kategorier::hentEntydigKategori()
 * @see Kunder::hentKunde()
 * @see Kategori::nyTing(...)
*/
void Kategorier::nyTing(){

    Kategorier::skrivAlleKategorier();
    string onsketKategori = Kategorier::hentEntydigKategori();

    int selgerNr = gKundebase.hentKunde();

    for(auto & val: kategoriene){
        if(val.first == onsketKategori){
            cout << "\n" << onsketKategori << endl;
            val.second->nyTing(sisteNr+1, selgerNr);
            sisteNr++; 
        }
    }

};

/**
 * Skriver data om en gitt kategori dersom det er funn for en entydig navngitt kategori.
 * 
 * @see Kategorier::skrivAlleKategorier()
 * @see Kategorier::hentEntydigKategori()
 * @see Kategori::skrivData()
*/
void Kategorier::skrivKategori(){

    //Skriver ut alle kategorier og initierer lokale variable
    Kategorier::skrivAlleKategorier();

    string onsketKategori = Kategorier::hentEntydigKategori();

    //Skriver data om den valgte kategorien
    for(auto & val: kategoriene){
        if(val.first == onsketKategori){
            cout << val.first << endl;
            val.second->skrivData();
        }
    }
};

/**
 * Henter navnet på en entydig kategori ut ifra brukerens input ved å sammenligne input
 * som en substring av det originale navnet til en kategori. Dersom det kan være flere muligheter
 * så startes prosessen med å finne en entydig kategori, på nytt
 * 
 * @return string - navnet på entydig kategori
*/
string Kategorier::hentEntydigKategori(){
    
    bool gyldigFunn = false;
    string onsketKategori;

    //Henter kategori fra bruker og ser etter funn
    while(!gyldigFunn){
        cout << "\nSkriv inn kategori: "; getline(cin, onsketKategori);

        //Gjør om string fra input til lowercase
        for(int i = 0; i < onsketKategori.size(); i++){
            onsketKategori[i] = tolower(onsketKategori[i]);
        }
        
        vector <string> potensielleKategorier;

        //Dersom det er treff for en substring, så legges kategorien i potensielle matcher
        for(auto & val: kategoriene){

            //Gjør om hele kategorien til lowercase
            string kategoriNavn = val.first;
            for(int i = 0; i < onsketKategori.size(); i++){
                kategoriNavn[i] = tolower(kategoriNavn[i]);
            }

            //Ser om det er en match for en substring fra input stringen
            if(kategoriNavn.find(onsketKategori) == 0){
                gyldigFunn = true;
                potensielleKategorier.push_back(val.first);
            }
        }

        //Dersom det ikke er entydig, så må brukeren skrive inn på ny om ønsket
        if(potensielleKategorier.size() != 1){
            gyldigFunn = false;
            potensielleKategorier.clear();
        } else if(potensielleKategorier.size() == 1) {
            onsketKategori = potensielleKategorier[0];
            gyldigFunn = true;
            return onsketKategori;
        }

        if(!gyldigFunn){
            cout << "\n\tIngen funn p\x8F \"" << onsketKategori << "\"\n";
        }
        
    }
}

/**
 * Skriver ut navn på alle kategoriene og antall ting til salgs for denne kategorien
 * 
 * @see Kategori::antallTilSalgs()
*/
void Kategorier::skrivAlleKategorier(){

    if(kategoriene.size() > 0){
        cout << "\nSkriver ut alle kategoriene" << endl;
        cout << "\nNavn:    Antall gjenstander til salgs:\n";

        //Går igjennom alle kategoriene og skriver ut navn og antall til salgs
        for(auto & kat: kategoriene){
            cout << "\n" << kat.first << right<< setw(10) << right << setw(6) <<
            kat.second->antallTilSalgs();
        }
    } else {
        cout << "\n\tEksisterer ingen kategorier ennå..." << endl;
    }

};


/**
 * Finner ut om innlest kategori er entydig og gyldig
 * 
 * @param k - Navn på kategori for sammenligning
 * @return true/false - om kategorien eksisterer fra før av
*/
bool Kategorier::finnKategori(string k){
    bool eksistererFraFor = false;
    
    for(auto & val: kategoriene){
        if(val.first == k){
            eksistererFraFor = true;
        }
    }
    return eksistererFraFor;
};


