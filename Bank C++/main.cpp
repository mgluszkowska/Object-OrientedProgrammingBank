#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Bank.hpp"
#include "Konto.hpp"
#include "KontoOsobiste.hpp"
#include "KartaPlatnicza.hpp"
#include "KontoOszczednosciowe.hpp"
#include "KontoJunior.hpp"
#include "Klient.hpp"
#include "Bankomat.hpp"
#include "Produkt.hpp"
#include "Zakupy.hpp"
using namespace std;

ostream& operator<<(ostream& os, Bank& b)
{
    os << b.nazwa;
    return os;
}

int KontoOszczednosciowe::liczbaOszcz = 222111110;

int KontoJunior::liczbaJunior = 333111110;


int main()
{
    //TWORZE PRZYKLADOWE PRODUKTY, ZEBY BYLO CO KUPOWAC
    Produkt p1("maslo", 5.99);
    Produkt p2("jogurt", 3.49);
    Produkt p3("bulka", 0.39);
    Produkt p4("kurczak", 16.49);
    Produkt p5("mleko", 2.69);
    Produkt p6("czekolada", 2.99);
    Produkt p7("herbata", 5.29);
    Produkt p8("kawa", 24.49);
    Produkt p9("maka", 1.99);
    Produkt p10("cukier", 1.49);
    vector<Produkt*> lista_produktow;
    lista_produktow.push_back(&p1);
    lista_produktow.push_back(&p2);
    lista_produktow.push_back(&p3);
    lista_produktow.push_back(&p4);
    lista_produktow.push_back(&p5);
    lista_produktow.push_back(&p6);
    lista_produktow.push_back(&p7);
    lista_produktow.push_back(&p8);
    lista_produktow.push_back(&p9);
    lista_produktow.push_back(&p10);

    //TWORZE BANKI
    Bank b1("SuperBank", 1000.00);
    b1.daneBanku();
    Bank b2("Bank Polski", 10000);

    //TWORZE KLIENTOW
    Klient marta("Marta", "Gluszkowska", &b1);
    Klient jan("Jan", "Kowalski", &b2);

    //ZAKLADAM KONTA DLA KLIENTA MARTA
    KontoOsobiste osob1(&b1, &marta, marta.imieNazwisko());
    marta.noweKontoOsobiste(&osob1);
    KartaPlatnicza karta1(&osob1);
    marta.nowaKarta(&karta1);
    KontoOszczednosciowe oszcz1(&b1, &marta, marta.imieNazwisko());
    marta.noweKontoOszczednosciowe(&oszcz1);
    KontoJunior jun1(&b1, &marta, marta.imieNazwisko());
    marta.noweKontoJunior(&jun1);

    //ZAKLADAM KONTA DLA KLIENTA JAN
    KontoOsobiste osob2(&b2, &jan, jan.imieNazwisko());
    jan.noweKontoOsobiste(&osob2);
    KartaPlatnicza karta2(&osob2);
    jan.nowaKarta(&karta2);
    KontoOszczednosciowe oszcz2(&b2, &jan, jan.imieNazwisko());
    jan.noweKontoOszczednosciowe(&oszcz2);
    KontoJunior jun2(&b2, &jan, jan.imieNazwisko());
    jan.noweKontoJunior(&jun2);

    //MARTA WCHODZI DO BANKOMATU
    Bankomat b(&marta);
    b.stanKonta();
    b.stanOszczednosci();
    b.stanOszczednosciJunior();
    b.wplata(marta.zwrocOsobiste(),100.99);
    b.wplata(marta.zwrocOszcz(),500);
    b.wyplataOsob(marta.zwrocOsobiste(),20.50);
    b.przelewOszczJunior(marta.zwrocOszcz(),marta.zwrocJunior(),400);
    b.wyplataJunior(marta.zwrocJunior(),300);
    b.nowyRok();
    b.stanKonta();
    b.stanOszczednosci();
    b.stanOszczednosciJunior();

    //ZAKUPY
    Zakupy z(&marta,lista_produktow);
    z.pokazOferte();
    z.kasa(marta.zwrocKarte());

    //JAN WCHODZI DO BANKOMATU
    Bankomat ba(&jan);
    ba.stanKonta();
    ba.stanOszczednosci();
    ba.stanOszczednosciJunior();
    ba.wplata(jan.zwrocOsobiste(),200);
    ba.przelewOsobOsob(jan.zwrocOsobiste(), marta.zwrocOsobiste(), 100);

    //SPRAWDZENIE BUDZETU BANKOW
    b1.pokazBudzet();
    b1.listaKlientow();
    b2.pokazBudzet();
    b2.listaKlientow();
    return 0;
}
