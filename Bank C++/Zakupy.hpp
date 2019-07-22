#ifndef _ZAKUPY_HPP_
#define _ZAKUPY_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "KartaPlatnicza.hpp"

class Zakupy
{
    Klient* obecny_klient;
    std::vector <Produkt*> oferta;
public:
    Zakupy(Klient* k, std::vector <Produkt*> lista);
    ~Zakupy();
    void pokazOferte();
    int zliczCyfry(std::string &s);
    bool czySameCyfry(std::string &s);
    void kasa(KartaPlatnicza* karta);
};

#endif
