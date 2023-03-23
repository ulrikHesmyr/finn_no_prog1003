#ifndef __CLASS_H
#define __CLASS_H

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
        void nyKunde();//?

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
        void nyKunde();//?
};

class Kategorier{
    private:
        int sisteNr;
        map <string, Kategori*> kategoriene; //Map med alle unikt navnede Kategori'er
    public:
};

class Kategori{
    private:

    public:
        

};

#endif