#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Bank.hpp"
using namespace std;

Bank::Bank(string n, float b)
{
    nazwa = n;
    budzet = b;
    liczbaKlientow = 0;
    cout << "\nNOWY BANK - " << nazwa << endl;
}

Bank::~Bank()
{
    klienci.clear();
}

void Bank::daneBanku()
{
    cout.precision(2);
    cout << fixed;
    cout << endl << "Bank " << nazwa << " (budzet " << budzet << " zl)" << endl;
    cout << "Oferujemy nastepujace konta:" << endl;
    cout << " - Konto Osobiste (razem z bezplatna karta platnicza)" << endl;
    cout << " - Konto Oszczednosciowe (oprocentowane 5% w skali roku)" << endl;
    cout << " - Konto Junior (dla klientow w wieku 15-18 lat, oprocentowane 10% w skali roku, bez mozliwosci wyplaty)" << endl;
}

string Bank::zwrocNazwe()
{
    return nazwa;
}

//void Bank::dodajKlienta(Klient* k);

//void Bank::listaKlientow();

int Bank::liczbaKli()
{
    return liczbaKlientow;
}

void Bank::odejmijOdBudzetu(float kwota)
{
    budzet-=kwota;
}

void Bank::dodajDoBudzetu(float kwota)
{
    budzet+=kwota;
}

void Bank::pokazBudzet()
{
    cout.precision(2);
    cout << fixed;
    cout << "\nBudzet banku " << nazwa << ": " << budzet << " zl" << endl;
}

void  Bank::dodajKlienta(Klient* k)
{
    klienci.push_back(k);
    liczbaKlientow++;
}

void Bank::listaKlientow()
{
    cout << "LISTA KLIENTOW BANKU " << nazwa << ":" << endl;
    for (i : klienci)
        cout << i->imieNazwisko() << endl;
}
