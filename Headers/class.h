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

using namespace std;

class Kunder{
    private:
        int sisteNr;
        list <Kunde*> kundene;
    public:
        Kunder();
        ~Kunder();
        void lesFraFil();
        void handling();
        void skrivTilFil();

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
        void skrivTilFil();
};

class Kategori{
    private:
        list <NyTing*> nyeTing; //Alle tingene som er til salgs i denne
                                //kategorien. Disse kan være en blanding av 
                                //NyTing og BruktTing
        
    public:


};

<<<<<<< HEAD
#endif
=======
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
>>>>>>> origin
