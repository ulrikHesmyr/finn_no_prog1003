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

class BruktTing : public NyTing{
    private:
        int alder;
        enum Kvalitet;
    public:
        BruktTing();
        virtual void lesData();
        virtual void skrivData();
};

#endif
