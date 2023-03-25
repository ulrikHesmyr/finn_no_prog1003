/**
 *   Header fil for Kunde classen
 *
 *   @file     kunde.h
 *   @author   Ulrik, Oliver og Mathilde, NTNU
 */

#ifndef __KUNDE_H
#define __KUNDE_H


#include <string>


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
        Kunde();
        ~Kunde();
};

#endif
