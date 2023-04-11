/**
 *   Header fil classen Kategori
 *
 *   @file     kategori.h
 *   @author   Mathilde, Oliver og Ulrik, NTNU
 */

#ifndef __KATEGORI_H
#define __KATEGORI_H

#include "nyting.h"
#include <list>
#include <vector>

/**
 * Kategori (med alle tingene som er til salgs i vedkommende kategori,
 * disse kan være en blanding av NyTing og BruktTing)
*/
class Kategori{
    private:
        std::list <NyTing*> nyeTing; 
        
    public:
		Kategori();
        void skrivData() const;
        void endreTing(int sisteNr);
        void kjopTing(int sisteNr, int kjoperensNummer);
        void lesFraFil(std::ifstream & inn);
        void skrivTilFil(std::ofstream & ut, std::string k);
        void nyTing(int nyttNr, int selgerensNr);
        int antallTilSalgs();
        std::vector <int> hentTilgjengeligeProduktNr();
		

};

#endif
