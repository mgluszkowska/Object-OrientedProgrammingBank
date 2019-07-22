#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "KontoJunior.hpp"
using namespace std;

KontoJunior::KontoJunior(Bank* b, Klient* k, string dane) :Konto(b,k)
{
    cout << endl << "Zakladam konto junior..." << endl;
    procent = 10;
    liczbaJunior++;
    numer_konta = liczbaJunior;
    cout << endl << "Utworzono nowe konto junior dla klienta " << dane << endl;
    cout << "Numer konta: " << numer_konta << endl;
}

int KontoJunior::zwrocProcent()
{
    return procent;
}

void KontoJunior::naliczZyski()
{
    saldo = saldo + saldo*procent/100;
}

void KontoJunior::wyplata(float m)
{
    cout << "Wyplacanie pieniedzy jest niemozliwe na koncie junior." << endl;
}
