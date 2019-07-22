#ifndef _KONTO_HPP_
#define _KONTO_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Bank.hpp"
#include "Klient.hpp"

class Klient;
class Bank;
class Konto
{
public:
    int numer_konta;
    float saldo;
    Bank* wsk_na_bank;
    Klient* wsk_na_klienta;

    Konto(Bank* b, Klient* k);
    ~Konto();
    Klient* zwrocWskKlienta();
    int zwrocNumerKonta();
    float zwrocSaldo();
    Bank* zwrocBank();
    void wplata(float m);
    virtual int zwrocProcent() = 0;
    virtual void naliczZyski() = 0;
};

#endif
