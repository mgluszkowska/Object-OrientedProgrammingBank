#ifndef _KARTAPLATNICZA_HPP_
#define _KARTAPLATNICZA_HPP_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "KontoOsobiste.hpp"

class KartaPlatnicza
{
    KontoOsobiste* konto;
public:
    KartaPlatnicza(KontoOsobiste* k);
    void platnosc(float kwota);
    ~KartaPlatnicza();
};

#endif
