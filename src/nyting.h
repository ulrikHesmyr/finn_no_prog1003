/**
 *   Header fil for alle classess
 *
 *   @file     nyting.h
 *   @author   Ulrik, Oliver og Mathilde, NTNU
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
        NyTing();
        ~NyTing();
};

#endif
