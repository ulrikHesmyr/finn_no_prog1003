/**
 *   Header fil for klassen NyTing
 *
 *   @file    nyting.h
 *   @author  Mathilde, Oliver og Ulrik, NTNU
 */

#ifndef __KATEGORIER_H
#define __KATEGORIER_H

#include "kategori.h"
#include <string>
#include <map>
#include <fstream>


class Kategorier{
    private:
        int sisteNr;
        std::map <std::string, Kategori*> kategoriene; 
    public:
        Kategorier();
        void handling(char valg);
        void lesFraFil();
        void skrivTilFil();
        void skrivMeny(char valg);
        void kjopTing();
        void endreTing();
        void nyTing();
        void skrivKategori();
        void skrivAlleKategorier();
        void nyKategori();
        bool finnKategori(std::string k);
        
        
};

#endif
