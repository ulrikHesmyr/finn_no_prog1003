/**
 *   Header fil for alle classess
 *
 *   @file     class.h
 *   @author   Ulrik, Oliver og Mathilde, NTNU
 */

#ifndef __CLASS_H
#define __CLASS_H

//#include "enum.h"

#include <string>
#include <vector>
#include <iostream>
#include <list>
#include <map>

class Kunder{
    private:
        int sisteNr;
        list <Kunde*> kundene;
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

class Kunde{
    private:
        int kundeNr, 
            mobilnummer,
            postnummer,
            antallTingKjopt,
            antallTingSolgt,
            antallTilSalgs;
        string navn,
            gateadresse,
            poststed,
            mailadresse;
            
    public:
        Kunde();
        ~Kunde();
};

class Kategorier{
    private:
        int sisteNr;
        map <string, Kategori*> kategoriene; //Map med alle unikt navnede Kategori'er
    public:
        void lesFraFil();
        void handling(char valg);
        void skrivTilFil() const;
};

class Kategori{
    private:
        list <NyTing*> nyeTing; //Alle tingene som er til salgs i denne
                                //kategorien. Disse kan være en blanding av 
                                //NyTing og BruktTing
        
    public:


};

class NyTing{
    private:
        int uniktIDnummer,
            selgersKID,
            pris,
            antallTilSalgs; 
        string navn,
            beskrivelse;
    public:
        NyTing();
        ~NyTing();
};

class BruktTing : public NyTing {
    private:
        int alder;
        enum Kvalitet kvalitet;
    public:
        BruktTing();
        ~BruktTing();

};

#endif
