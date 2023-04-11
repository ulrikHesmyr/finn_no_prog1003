/**
 *  Header fil for klassen BruktTing
 *  
 *  @file bruktting.h
 *  @author  Mathilde, Oliver og Ulrik, NTNU
*/

#ifndef __BRUKTTING_H
#define __BRUKTTING_H

#include "nyting.h"
#include "enum.h"
#include <fstream>

/**
 * BruktTing (med alder og kvaliteten på tingen)
*/
class BruktTing : public NyTing{
    private:
        int alder;
        enum Kvalitet kvaliteten;
    public:
        BruktTing(int tingNr, int selgerensNr);
        BruktTing(std::ifstream & inn);
        enum Kvalitet hentKvalitet(char k);
        char hentChar(enum Kvalitet k);
        virtual void skrivTilFil(std::ofstream & ut);
        virtual void lesData();
        virtual void skrivData() const;
        virtual void skrivTilstand() const;
        virtual int skrivNyEllerBrukt() const;
};

#endif
