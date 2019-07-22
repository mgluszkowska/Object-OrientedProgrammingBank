#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Zakupy.hpp"
using namespace std;

Zakupy::Zakupy(Klient* k, vector <Produkt*> lista)
{
    obecny_klient = k;
    cout << endl << "Witaj w sklepie, " << k->imieNazwisko() << "!" << endl;
    oferta = lista;
}

Zakupy::~Zakupy()
{
    oferta.clear();
}

void Zakupy::pokazOferte()
{
    cout << endl << "PRODUKTY DOSTEPNE W NASZYM SKLEPIE:" << endl;
    int licz = 1;
    for(element:oferta)
    {
        cout << licz << ". ";
        element->opisProduktu();
        licz++;
    }
}

int Zakupy::zliczCyfry(string &s)
{
    return count_if( s.begin(), s.end(), ptr_fun < int, int >( isdigit ) );
}

bool Zakupy::czySameCyfry(string &s)
{
    if(zliczCyfry(s)==s.size())
        return true;
    else
        return false;
}

void Zakupy::kasa(KartaPlatnicza* karta)
{
    cout.precision(2);
    cout << fixed;
    float suma = 0;
    cout << "Jakie produkty chcesz kupic?" << endl;
    cout << "(Podaj numer produktu i ilosc. Gdy dodasz juz wszystkie produkty, wcisnij 0)" << endl;
    stringstream koszyk;
    koszyk << "WYBRALES NASTEPUJACE PRODUKTY:\n";
    while(true)
    {
        string liczba1;
        string liczba2;
        cout << "Numer produktu: ";
        cin >>  liczba1;
        if(czySameCyfry(liczba1))
        {
            int prod;
            istringstream iss(liczba1);
            iss >> prod;
            if(prod>=oferta.size()+1)
                cout << "Nieprawidlowy numer produktu" << endl;
            else if (prod>0)
            {
                cout << "Ilosc: ";
                cin >> liczba2;
                if(czySameCyfry(liczba2))
                {
                    int ilosc;
                    istringstream is(liczba2);
                    is >> ilosc;
                    koszyk << oferta[prod-1]->pokazNazwe() << " - " << oferta[prod-1]->pokazCene() << " zl";
                    koszyk << " (" << ilosc << "szt.)\n";
                    suma=suma + oferta[prod-1]->pokazCene() * ilosc;
                }
                else
                    cout << "Nieprawidlowa ilosc produktu" << endl;
            }
            else
                break;
            }
        else
            cout << "Nieprawidlowy numer produktu" << endl;
    }
    cout << koszyk.str() << endl;
    cout << "Suma kosztow: " << suma << " zl" << endl;
    cout << "Czy na pewno chcesz kupic te produkty? (Wpisz tak lub nie) ";
    string wybor;
    cin >> wybor;
    if(wybor=="tak")
    {
        karta -> platnosc(suma);
        cout << "Rachunek uregulowany. Dziekujemy za zakupy!" << endl;
    }
    else
        cout << "Zakupy anulowane." << endl;
}
