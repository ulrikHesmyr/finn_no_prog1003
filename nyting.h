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

/**
 * NyTing (med tingens unike nummer, selgerens unike kundenummer, pris og antall til salgs av tingen)
*/
class NyTing{
    private:
        int nr,
            selgerNr,
            pris,
            antallTilSalgs;
        std::string navn,
            beskrivelse;
    public:
        NyTing(std::ifstream & inn);
        NyTing(int tingNr, int selgerensNr);
        void endreTing();
        void salg(int kjoperensNummer, int selgerensNummer);
        virtual void skrivTilFil(std::ofstream & ut);
        virtual void lesData();
        virtual void skrivData() const;
        virtual void skrivTilstand() const;
        virtual int skrivNyEllerBrukt() const;
        int hentNr();
        int hentSelgerNr();
        int hentAntallAvTing();

};

#endif

