/**
 *   Header fil for Kunder classen
 *
 *   @file     kunder.h
 *   @author   Ulrik, Oliver og Mathilde, NTNU
 */

#ifndef __KUNDER_H
#define __KUNDER_H

#include "kunde.h"
#include <list>

class Kunder{
    private:
        int sisteNr;
        std::list <Kunde*> kundene;
    public:
        Kunder();
        ~Kunder();
        void lesFraFil();
        void handling();
        void skrivTilFil() const;
        void skrivMeny();
        void nyKunde();
        void skrivAlleKunder() const;
        void skrivKunde() const; 
        void fjernKunde();

};

#endif
