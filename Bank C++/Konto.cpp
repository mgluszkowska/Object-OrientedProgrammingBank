#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Konto.hpp"
using namespace std;

class Klient;
class Bank;

Konto::Konto(Bank* b, Klient* k)
{
    saldo = 0;
    wsk_na_bank = b;
    wsk_na_klienta = k;
}

Konto::~Konto() {};

Konto::Klient* zwrocWskKlienta()
{
    return wsk_na_klienta;
}

int Konto::zwrocNumerKonta()
{
    return numer_konta;
}

float Konto::zwrocSaldo()
{
    return saldo;
}

Konto::Bank* zwrocBank()
{
    return wsk_na_bank;
}

void Konto::wplata(float m)
{
    saldo = saldo + m;
    cout.precision(2);
    cout << fixed;
    cout << endl << "Kwota " << m << " zl";
    cout << " zostala wplacona na konto." << endl;
    cout << "Stan konta po wplacie: " << saldo << " zl" << endl;
    wsk_na_bank->dodajDoBudzetu(m);
}
};
