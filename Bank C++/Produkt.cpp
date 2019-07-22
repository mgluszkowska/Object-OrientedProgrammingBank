#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Produkt.hpp"
using namespace std;

Produkt::Produkt(string n, float c)
{
    nazwa=n;
    cena=c;
}

Produkt::~Produkt() {}

void Produkt::opisProduktu()
{
    cout.precision(2);
    cout << fixed;
    cout<<nazwa<<" - "<<cena<<" zl"<<endl;
}

string Produkt::pokazNazwe()
{
    return nazwa;
}

float Produkt::pokazCene()
{
    return cena;
}
