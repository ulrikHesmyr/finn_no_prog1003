/**
 *   Header fil for klassen NyTing
 *
 *   @file    nyting.h
 *   @author  Mathilde, Oliver og Ulrik, NTNU
 */

#ifndef __NYTING_H
#define __NYTING_H

#include <string>
#include <fstream>

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
        NyTing(int tingNr);
        void endreTing();
        void lesFraFil(std::ifstream & inn);
        virtual void lesData();
        virtual void skrivData() const;

};

#endif

