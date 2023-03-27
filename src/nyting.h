/**
 *   Header fil for klassen NyTing
 *
 *   @file    nyting.h
 *   @author  Mathilde, Oliver og Ulrik, NTNU
 */

#ifndef __NYTING_H
#define __NYTING_H

#include <string>

class NyTing{
    private:
        int nr,
            selgerNr,
            pris,
            antallTilSalgs; 
        std::string navn,
            beskrivelse;
    public:
        NyTing(int tingNr);
        ~NyTing();
};

#endif
