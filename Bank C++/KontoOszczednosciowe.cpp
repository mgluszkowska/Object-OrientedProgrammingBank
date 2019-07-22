#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "KontoOszczednosciowe.hpp"
using namespace std;

KontoOszczednosciowe::(Bank* b, Klient* k, string dane) :Konto(b,k)
{
    cout << endl << "Zakladam konto oszczednosciowe..." << endl;
    procent = 5;
    liczbaOszcz++;
    numer_konta = liczbaOszcz;
    cout << endl << "Utworzono nowe konto oszczednosciowe dla klienta " << dane << endl;
    cout << "Numer konta: " << numer_konta << endl;
}

int KontoOszczednosciowe::zwrocProcent()
{
    return procent;
}

virtual void KontoOszczednosciowe::naliczZyski()
{
    saldo = saldo + saldo*procent/100;
}

void KontoOszczednosciowe::wyplata(float m)
{
    cout.precision(2);
    cout << fixed;
    if(saldo>=m)
    {
        saldo = saldo - m;
        cout << endl << "Kwota " << m << " zl "
        << "zostala wyplacona z konta." << endl;
        cout << "Stan konta po wyplacie: " << saldo << " zl" << endl;
        wsk_na_bank->odejmijOdBudzetu(m);
    }
    else
        cout << "Brak wystarczajacych srodkow na koncie." << endl;
}
