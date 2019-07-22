#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Klient.hpp"
#include "Bank.hpp"
using namespace std;

class Bank;
class KontoOsobiste;

Klient::Klient(string i, string n, Bank* b)
{
    wsk_na_bank = b;
    imie = i;
    nazwisko = n;
    cout << endl << "NOWY KLIENT W BANKU " << b->zwrocNazwe() << " - "
    << imie << " " << nazwisko << endl;
    b->dodajKlienta(this);
}

Klient::~Klient() {}

string Klient::imieNazwisko()
{
    stringstream s;
    s << imie << " " << nazwisko;
    return s.str();
}

Klient::Bank* zwrocBank()
{
    return wsk_na_bank;
}

Klient::KontoOsobiste* zwrocOsobiste()
{
    return wsk_na_konto_osob;
}

Klient::KontoOszczednosciowe* zwrocOszcz()
{
    return wsk_na_konto_oszcz;
}

Klient::KontoJunior* zwrocJunior()
{
    return wsk_na_konto_junior;
}

void Klient::noweKontoOsobiste(KontoOsobiste* k)
{
    wsk_na_konto_osob = k;
}

void Klient::noweKontoOszczednosciowe(KontoOszczednosciowe* k)
{
    wsk_na_konto_oszcz = k;
}

void Klient::noweKontoJunior(KontoJunior* k)
{
    wsk_na_konto_junior = k;
}

void Klient::nowaKarta(KartaPlatnicza* k)
{
    wsk_na_karte = k;
}

Klient::KartaPlatnicza* zwrocKarte()
{
    return wsk_na_karte;
}
