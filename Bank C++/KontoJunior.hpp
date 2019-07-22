#ifndef _KONTOJUNIOR_HPP_
#define _KONTOJUNIOR_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Bank.hpp"
#include "Konto.hpp"

class KontoJunior :public Konto
{
    static int liczbaJunior;
    int procent;
public:
    KontoJunior(Bank* b, Klient* k, std::string dane);
    int zwrocProcent();
    virtual void naliczZyski();
    void wyplata(float m);
};

#endif
