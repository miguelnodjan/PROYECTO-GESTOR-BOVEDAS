#ifndef CONSTANTES_H
#define CONSTANTES_H

#include <map>
#include <string>
#include <stdexcept>

using namespace std;

namespace Moneda {
const string USD = "USD";
const string EUR = "EUR";
const string PEN = "PEN";

const map<string, double> TASAS_CAMBIO = {
    {"USD-EUR", 0.85},
    {"USD-PEN", 3.96},
    {"EUR-USD", 1.18},
    {"EUR-PEN", 4.68},
    {"PEN-USD", 0.25},
    {"PEN-EUR", 0.21}
};

double obtenerTasaCambio(const string& de, const string& a);
}

#endif // CONSTANTES_H
