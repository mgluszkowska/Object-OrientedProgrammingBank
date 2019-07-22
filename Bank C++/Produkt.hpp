#ifndef _PRODUKT_HPP_
#define _PRODUKT_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

class Produkt
{
    std::string nazwa;
    float cena;

public:

    Produkt(std::string n, float c);
    ~Produkt();
    void opisProduktu();
    std::string pokazNazwe();
    float pokazCene();
};

#endif
