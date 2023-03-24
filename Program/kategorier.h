/**
 *   Header fil for Kategorier classen
 *
 *   @file     kategorier.h
 *   @author   Ulrik, Oliver og Mathilde, NTNU
 */

#ifndef __KATEGORIER_H
#define __KATEGORIER_H

#include "kategori.h"
#include <iostream>
#include <map>
#include <string>

class Kategorier{
    private:
        int sisteNr;
        std::map <std::string, Kategori*> kategoriene; //Map med alle unikt navnede Kategori'er
    public:
        Kategorier();
        ~Kategorier();
        void lesFraFil();
        void handling(char valg);
        void skrivTilFil() const;
};

#endif
