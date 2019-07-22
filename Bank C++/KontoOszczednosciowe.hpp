#ifndef _KONTOOSZCZEDNOSCIOWE_HPP_
#define _KONTOOSZCZEDNOSCIOWE_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Bank.hpp"
#include "Konto.hpp"

class KontoOszczednosciowe :public Konto
{
    static int liczbaOszcz;
    int procent;
public:
    KontoOszczednosciowe(Bank* b, Klient* k, string dane) :Konto(b,k);
    int zwrocProcent();
    virtual void naliczZyski();
    void wyplata(float m);
};

#endif
