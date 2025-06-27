#ifndef OPERACION_H
#define OPERACION_H

#include <string>
#include <map>
#include "TipoOperacion.h"

class Operacion {
private:
    std::string fecha;
    TipoOperacion tipo;
    std::string origen;
    std::string destino;
    std::string plaza;
    std::string transportadora;
    std::map<int, int> denominaciones;

public:
    Operacion(const std::string& fecha, TipoOperacion tipo,
              const std::string& origen, const std::string& destino,
              const std::string& plaza, const std::string& transportadora);

    void agregarDenominacion(int valor, int cantidad);
    double calcularMonto() const;
    void mostrarResumen() const;
};

#endif
