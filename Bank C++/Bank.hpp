#ifndef _BANK_HPP_
#define _BANK_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Klient.hpp"

class Klient;

class Bank
{
    float budzet;
    std::vector<Klient*> klienci;
    int liczbaKlientow;

public:
    std::string nazwa;

    Bank(std::string n, float b);
    ~Bank();
    void daneBanku();
    std::string zwrocNazwe();
    void dodajKlienta(Klient* k);
    void listaKlientow();
    friend std::ostream& operator<<(std::ostream& os, Bank& b);
    int liczbaKli();
    void odejmijOdBudzetu(float kwota);
    void dodajDoBudzetu(float kwota);
    void pokazBudzet();
};


#endif
