/**
 *   Fil for innmat i all public funksjoner for classen Kunder
 * 
 *   @file     kunder.h
 *   @author   Mathilde, Oliver og Ulrik
 */

#ifndef __KUNDER_H
#define __KUNDER_H

#include "kunde.h"
#include <list>

/**
 * Kunder (med fortløpende økende automatisk nummerering av alle nye kunder og liste med de unikt nummererte kundene)
*/
class Kunder{
    private:
        int sisteNr;
        std::list <Kunde*> kundene;
    public:
        Kunder();
        void lesFraFil();
        void handling();
        void skrivTilFil();
        void skrivMeny();
        void nyKunde();
        void skrivAlleKunder() const;
        void skrivKunde() const; 
        void fjernKunde();
        void salg(int kjoperensNummer, int selgerensNummer, int antTilSalgs); 
        int antall();
        int hentKunde();

};

#endif
