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
        ~Kunde();
        void lesFraFil(std::ifstream & inn);
        void lesData();
        void skrivData();
};

#endif
