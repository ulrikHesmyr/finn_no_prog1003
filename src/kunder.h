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
        void lesFraFil();
        void handling();
        void skrivTilFil();
        void skrivMeny();
        void nyKunde();
        void skrivAlleKunder() const;
        void skrivKunde() const; 
        void fjernKunde();
        int antall();

};

#endif
