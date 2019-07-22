#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Bankomat.hpp"
using namespace std;

Bankomat::Bankomat(Klient* kli)
{
    cout << endl << "Witaj w bankomacie " << kli->imieNazwisko() << "!" << endl;
    obecny_klient = kli;
    osobiste_klienta = kli->zwrocOsobiste();
    oszczednosciowe_klienta = kli->zwrocOszcz();
    junior_klienta = kli->zwrocJunior();
}

Bankomat::~Bankomat() {};

void Bankomat::stanKonta()
{
    cout.precision(2);
    cout << fixed;
    if(osobiste_klienta!=0)
        cout << "Stan konta: " << osobiste_klienta->zwrocSaldo() << " zl" << endl;
    else
        cout << "Nie mozna sprawdzic stanu konta osobistego, bo nie zalozyles takiego konta." << endl;
}

void Bankomat::stanOszczednosci()
{
    cout.precision(2);
    cout << fixed;
    if(oszczednosciowe_klienta!=0)
        cout << "Stan oszczednosci: " << oszczednosciowe_klienta->zwrocSaldo() << " zl" << endl;
    else
        cout << "Nie da sie sprawdzic stanu konta oszczednosciowego, bo nie zalozyles sobie takiego konta." << endl;
}

void Bankomat::stanOszczednosciJunior()
{
    cout.precision(2);
    cout << fixed;
    if(junior_klienta!=0)
        cout << "Stan oszczednosci na koncie junior: " << junior_klienta->zwrocSaldo() << " zl" << endl;
    else
        cout << "Nie da sie sprawdzic stanu konta junior, bo nie zalozyles sobie takiego konta." << endl;
}

void Bankomat::wplata(Konto* k, float kwota)
{
    cout << endl << "Robie wplate na konto o numerze " << k->zwrocNumerKonta() << "..." << endl;
    k->wplata(kwota);
}

void Bankomat::wyplataOsob(KontoOsobiste* k, float kwota)
{
    cout << endl << "Robie wplate na konto o numerze " << k->zwrocNumerKonta() << "..." << endl;
    k->wyplata(kwota);
}

void Bankomat::wyplataOszcz(KontoOszczednosciowe* k, float kwota)
{
    cout << endl << "Robie wplate na konto o numerze " << k->zwrocNumerKonta() << "..." << endl;
    k->wyplata(kwota);
}

void Bankomat::wyplataJunior(KontoJunior* k, float kwota)
{
    cout << endl << "Robie wplate na konto o numerze " << k->zwrocNumerKonta() << "..." << endl;
    k->wyplata(kwota);
}

void Bankomat::przelewOsobOsob(KontoOsobiste* z, KontoOsobiste* na, float kwota)
{
    cout << endl << "Robie przelew z konta o numerze " << z->zwrocNumerKonta() <<
    " na konto o numerze " << na->zwrocNumerKonta() << "..." << endl;
    if(z->zwrocSaldo()>=kwota)
    {
        z->wyplata(kwota);
        na->wplata(kwota);
    }
    else
        cout << "Brak wystarczajacych srodkow na koncie." << endl;
}

void Bankomat::przelewOsobOszcz(KontoOsobiste* z, KontoOszczednosciowe* na, float kwota)
{
    cout << endl << "Robie przelew z konta o numerze " << z->zwrocNumerKonta() <<
    " na konto o numerze " << na->zwrocNumerKonta() << "..." << endl;
    if(z->zwrocSaldo()>=kwota)
    {
        z->wyplata(kwota);
        na->wplata(kwota);
    }
    else
        cout << "Brak wystarczajacych srodkow na koncie." << endl;
}

void Bankomat::przelewOsobJunior(KontoOsobiste* z, KontoJunior* na, float kwota)
{
    cout << endl << "Robie przelew z konta o numerze " << z->zwrocNumerKonta() <<
    " na konto o numerze " << na->zwrocNumerKonta() << "..." << endl;
    if(z->zwrocSaldo()>=kwota)
    {
        z->wyplata(kwota);
        na->wplata(kwota);
    }
    else
        cout << "Brak wystarczajacych srodkow na koncie." << endl;
}

void Bankomat::przelewOszczOsob(KontoOszczednosciowe* z, KontoOsobiste* na, float kwota)
{
    cout << endl << "Robie przelew z konta o numerze " << z->zwrocNumerKonta() <<
    " na konto o numerze " << na->zwrocNumerKonta() << "..." << endl;
    if(z->zwrocSaldo()>=kwota)
    {
        z->wyplata(kwota);
        na->wplata(kwota);
    }
    else
        cout << "Brak wystarczajacych srodkow na koncie." << endl;
}

void Bankomat::przelewOszczJunior(KontoOszczednosciowe* z, KontoJunior* na, float kwota)
{
    cout << endl << "Robie przelew z konta o numerze " << z->zwrocNumerKonta() <<
    " na konto o numerze " << na->zwrocNumerKonta() << "..." << endl;
    if(z->zwrocSaldo()>=kwota)
    {
        z->wyplata(kwota);
        na->wplata(kwota);
    }
    else
        cout << "Brak wystarczajacych srodkow na koncie." << endl;
}

void Bankomat::nowyRok()
{
    if(oszczednosciowe_klienta!=0)
    {
        oszczednosciowe_klienta->naliczZyski();
        cout << "\nMinal rok i naliczono odsetki. ";
        stanOszczednosci();
    }
    if(junior_klienta!=0)
    {
        junior_klienta->naliczZyski();
        cout.precision(2);
        cout << fixed;
        cout << "Stan konta junior po naliczeniu odsetek: " << junior_klienta->zwrocSaldo() << " zl" << endl;
    }
    if(oszczednosciowe_klienta==0 && junior_klienta==0)
        cout << "\nNie ma konta, dla ktorego mozna naliczyc odsetki." << endl;
}
