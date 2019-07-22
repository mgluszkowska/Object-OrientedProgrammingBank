#ifndef _KONTOOSOBISTE_HPP_
#define _KONTOOSOBISTE_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Bank.hpp"
#include "Konto.hpp"

class KontoOsobiste :public Konto::Konto
{
    static int liczbaOsobistych;
public:

    KontoOsobiste(Bank* b, Klient* k, std::string dane);
    virtual int zwrocProcent();
    virtual void naliczZyski();
    void wyplata(float m);
};

#endif
