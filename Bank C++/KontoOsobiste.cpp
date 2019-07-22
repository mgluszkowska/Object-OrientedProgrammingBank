#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "KontoOsobiste.hpp"
using namespace std;

KontoOsobiste::(Bank* b, Klient* k, string dane) :Konto(b, k)
{
    cout << endl << "Zakladam konto osobiste..." << endl;
    liczbaOsobistych++;
    numer_konta = liczbaOsobistych;
    cout << endl << "Utworzono nowe konto osobiste dla klienta " << dane << endl;
    cout << "Numer konta: " << numer_konta << endl;
}

virtual int KontoOsobiste::zwrocProcent()
{
    return -1;
}

virtual void KontoOsobiste::naliczZyski()
{
    cout << "Na koncie osobistym nie ma zyskow." << endl;
}

void KontoOsobiste::wyplata(float m)
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
