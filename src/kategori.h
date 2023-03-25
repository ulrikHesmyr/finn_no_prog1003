/**
 *   Header fil classen Kategori
 *
 *   @file     kategori.h
 *   @author   Mathilde, Oliver og Ulrik, NTNU
 */

#ifndef __KATEGORI_H
#define __KATEGORI_H

#include "NYTING.H"
#include <list>

class Kategori{
    private:
        std::list <NyTing*> nyeTing; //Alle tingene som er til salgs i denne
                                //kategorien. Disse kan være en blanding av 
                                //NyTing og BruktTing
        
    public:


};

#endif
