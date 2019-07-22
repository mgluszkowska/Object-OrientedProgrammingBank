#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "KartaPlatnicza.hpp"
using namespace std;

KartaPlatnicza::KartaPlatnicza(KontoOsobiste* k)
{
    konto = k;
    cout << "Do konta zostala dolaczona karta platnicza" << endl;
}

void KartaPlatnicza::platnosc(float kwota)
{
    konto->wyplata(kwota);
}

KartaPlatnicza::~KartaPlatnicza() {}
