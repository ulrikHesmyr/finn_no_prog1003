#ifndef __KUNDER_H
#define __KUNDER_H

#include "KUNDE.H"
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
