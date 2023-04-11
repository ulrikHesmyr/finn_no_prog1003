/**
 * Fil for alle public funksjoner i klassen Kategori
 * 
 * @file kategori.cpp
 * @author Oliver, Ulrik og Mathilde, NTNU
*/

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "LesData3.h"

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
 * Leser inn data fra filen KATEGORIER.DTA på posten:
 * kategori
 * ny/brukt nr selgerNr antallTilSalgs pris
 * navn
 * beskrivelse
 * hvis tingen er brukt: alder kvaliteten
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

    //Setter NyTing peker til ny ting eller brukt ting ut ifra int i fil
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
 * 
 * @see NyTing::skrivTilstand()
 * @see NyTing::skrivData()
*/
void Kategori::skrivData() const{
    cout << "Antall ting til salgs: " << nyeTing.size() << endl;
    for(auto & val: nyeTing){
        val->skrivTilstand();
        val->skrivData();
    }
}

/**
 * Endrer på en vilkårlig valgt ting ut ifra dets nummer
 * 
 * @param sisteNr - Siste mulige nummer en ting kan ha
 * @see Kategori::hentTilgjengeligeProduktNr()
 * @see Kategori::skrivData()
 * @see NyTing::hentNr()
 * @see NyTing::skrivData()
 * @see NyTing::lesData()
*/
void Kategori::endreTing(int sisteNr){
    int valgProdukt;
    char endreProdukt;
    vector <int> produktNummere = Kategori::hentTilgjengeligeProduktNr();

    Kategori::skrivData();

    while(find(produktNummere.begin(), produktNummere.end(), valgProdukt) == produktNummere.end()){
        valgProdukt = lesInt("\nProduktets nummer", 1, sisteNr);
    }

    for(auto & ting: nyeTing){
        if(ting->hentNr() == valgProdukt){
            ting->skrivData();
            endreProdukt = lesChar("\nVil du endre data for denne tingen? (J)a/(N)ei");
            if(endreProdukt == 'J'){
                ting->lesData();
                cout << "\n\tEndringer lagret!\n";
            }
        }
    }
}

/**
 * Kjøp av ting innenfor en vilkårlig kategori hvor brukeren velger 
 * mellom en av produktene som skrives ut på skjermen. Produktet skrives ut
 * og brukeren tar valget om å kjøpe tingen eller ikke. Dersom kunden kjøper 
 * tingen, så sjekkes det om det er samme kundenummer og selgernummer, hvis ikke
 * så selges tingen
 * 
 * @param sisteNr - Siste utdelte nummer for en ting
 * @param kjoperensNummer - kjøperens unike kundenummer
 * @see Kategori::hentTilgjengeligeProduktNr()
 * @see Kategori::skrivData()
 * @see NyTing::hentNr()
 * @see NyTing::hentSelgerNr()
 * @see NyTing::skrivData()
 * @see NyTing::salg()
 * @see NyTing::hentAntallAvTing()
*/
void Kategori::kjopTing(int sisteNr, int kjoperensNummer){
    int valgProdukt, selgerensNummer;
    char kjopProdukt;

    //vector med produkter innenfor kategorien som er tilgjengelig for salg
    vector <int> produktNummere = Kategori::hentTilgjengeligeProduktNr();

    Kategori::skrivData();

    //Sjekker om brukerens valgte produktnummer er et av de gyldige
    while(find(produktNummere.begin(), produktNummere.end(), valgProdukt) == produktNummere.end()){
        valgProdukt = lesInt("\nProduktets nummer", 1, sisteNr);
    }

    //Skriver ut data for gjeldende ting og deretter ber om brukeren vil kjøpe
    for(auto & ting: nyeTing){
        if(ting->hentNr() == valgProdukt){
            selgerensNummer = ting->hentSelgerNr();
            ting->skrivData();
            kjopProdukt = lesChar("\nVil du kjope denne tingen? (J)a/(N)ei");
            if(kjopProdukt == 'J'){

                //Sjekker om kjøper er samme person som selger
                if(selgerensNummer != kjoperensNummer){

                    //Registrerer salg for tingen
                    ting->salg(kjoperensNummer, selgerensNummer);

                    //Fjerner tingen dersom det er ikke er fler igjen
                    if(ting->hentAntallAvTing() == 0){
                        list <NyTing*>::iterator it = find(nyeTing.begin(), nyeTing.end(), ting);
                        if(it != nyeTing.end()){
                            nyeTing.erase(it);
                            delete ting;
                            cout << "\n\tKjopet er gjennomfort!\n";
                            break;
                        }

                    }
                } else {
                    cout << "\n\tKan ikke kjope ting av seg selv!\n";
                }
            }
        }
    }

}

/**
 * Henter en vector med nummeret til de tilgjengelige tingene i en gitt kategori
 * 
 * @see NyTing::hentNr()
 * @return vector <int> - vectoren med nummere til de tilgjengelige tingene
*/
vector <int> Kategori::hentTilgjengeligeProduktNr(){
    vector <int> produktNummere;
    for(auto & ting: nyeTing){
        produktNummere.push_back(ting->hentNr());
    }
    return produktNummere;
}

/**
 * Skriver navnet på kategorien for hver av tingene i en kategori
 * 
 * @param ut - Filstrømmen som data skrives til
 * @param k - Navnet på kategorien som skrives til filen
 * @see NyTing::skrivNyEllerBrukt(...)
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

/**
 * Oppretter ny ting (NyTing eller BruktTing) innenfor en vilkårlig kategori
 * 
 * @param nyttNr - unikt nummer som tildeles ny ting
 * @param selgerensNr - det unike nummeret til selgeren
 * @see NyTing::NyTing(...)
 * @see BruktTing::BruktTing(...)
 * @see NyTing::lesData(...)
*/
void Kategori::nyTing(int nyttNr, int selgerensNr){
    char nyEllerBrukt;
    NyTing* nyeTingen;

    while(nyEllerBrukt != 'N' && nyEllerBrukt != 'B'){
        nyEllerBrukt = lesChar("\n(N)y eller (B)rukt");
    }

    if(nyEllerBrukt == 'N'){
        nyeTingen = new NyTing(nyttNr, selgerensNr);
    } else {
        nyeTingen = new BruktTing(nyttNr, selgerensNr);
    }

    nyeTingen->lesData();

    nyeTing.push_back(nyeTingen);

    cout << "\n\tOpprettet ny ting!\n";
}