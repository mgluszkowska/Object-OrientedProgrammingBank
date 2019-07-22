#ifndef _BANKOMAT_HPP_
#define _BANKOMAT_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Klient.hpp"

class Bankomat
{
    Klient* obecny_klient;
    Konto* osobiste_klienta;
    Konto* oszczednosciowe_klienta;
    Konto* junior_klienta;
public:

    Bankomat(Klient* kli);
    ~Bankomat();
    void stanKonta();
    void stanOszczednosci();
    void stanOszczednosciJunior();
    void wplata(Konto* k, float kwota);
    void wyplataOsob(KontoOsobiste* k, float kwota);
    void wyplataOszcz(KontoOszczednosciowe* k, float kwota);
    void wyplataJunior(KontoJunior* k, float kwota);
    void przelewOsobOsob(KontoOsobiste* z, KontoOsobiste* na, float kwota);
    void przelewOsobOszcz(KontoOsobiste* z, KontoOszczednosciowe* na, float kwota);
    void przelewOsobJunior(KontoOsobiste* z, KontoJunior* na, float kwota);
    void przelewOszczOsob(KontoOszczednosciowe* z, KontoOsobiste* na, float kwota);
    void przelewOszczJunior(KontoOszczednosciowe* z, KontoJunior* na, float kwota);
    void nowyRok();
};

#endif
