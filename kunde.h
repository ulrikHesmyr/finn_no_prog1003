/**
 *   Header fil for Kunde classen
 *
 *   @file     kunde.h
 *   @author   Mathilde, Oliver og Ulrik, NTNU
 */

#ifndef __KUNDE_H
#define __KUNDE_H


#include <string>
#include <fstream>

/**
 * Kunde (med kundens unike nummer, mobilnummer, postnummer, antall ting kjøpt, 
 * antall ting solgt, antall ting kunden har til salgs, navn og beskrivelse)
*/
class Kunde{
    private:
        int kundeNr, 
            mobilnummer,
            postnummer,
            antallTingKjopt,
            antallTingSolgt,
            antallTilSalgs;
        std::string navn,
            gateadresse,
            poststed,
            mailadresse;
            
    public:
        Kunde(int kNr); 
        void lesFraFil(std::ifstream & inn);
        void skrivTilFil(std::ofstream & ut);
        void lesData();
        void skrivData();
        bool finnKunde(int kNr);
        void skrivAllData();
        void kjop();
        void salg();
        void minkAntallTilSalgs();
        void okAntallTilSalgs();
};

#endif
