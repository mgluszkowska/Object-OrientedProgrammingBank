#ifndef _KLIENT_HPP_
#define _KLIENT_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Bank.hpp"
#include "KontoOsobiste.hpp"

class Bank;
class KontoOsobiste;
class KontoOszczednosciowe;
class KontoJunior;
class KartaPlatnicza;

class Klient
{
    std::string imie, nazwisko;
    Bank* wsk_na_bank;
    KontoOsobiste* wsk_na_konto_osob =0;
    KontoOszczednosciowe* wsk_na_konto_oszcz =0;
    KontoJunior* wsk_na_konto_junior = 0;
    KartaPlatnicza* wsk_na_karte = 0;

public:

    Klient(std::string i, std::string n, Bank* b);
    ~Klient();
    std::string imieNazwisko();
    Bank* zwrocBank();
    KontoOsobiste* zwrocOsobiste();
    KontoOszczednosciowe* zwrocOszcz();
    KontoJunior* zwrocJunior();
    void noweKontoOsobiste(KontoOsobiste* k);
    void noweKontoOszczednosciowe(KontoOszczednosciowe* k);
    void noweKontoJunior(KontoJunior* k);
    void nowaKarta(KartaPlatnicza* k);
    KartaPlatnicza* zwrocKarte();
};

#endif
