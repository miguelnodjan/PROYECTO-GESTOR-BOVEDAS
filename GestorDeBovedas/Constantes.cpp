#include "Constantes.h"

namespace Moneda {
double obtenerTasaCambio(const string& de, const string& a) {
    if (de == a) return 1.0;

    string clave = de + "-" + a;
    auto it = TASAS_CAMBIO.find(clave);
    if (it != TASAS_CAMBIO.end()) {
        return it->second;
    }
    throw runtime_error("Tasa de cambio no definida para " + clave);
}
}
