#ifndef OPERACION_H
#define OPERACION_H

#include <string>
#include <map>
#include <ctime>
#include "Constantes.h"

using namespace std;

enum class TipoOperacion {
    ENTREGA,
    RECOJO,
    TRASLADO,
    CANJE,
    PAGO,
    DEPOSITO,
    RETIRO
};

class Operacion {
private:
    string id;
    string fecha;
    TipoOperacion tipo;
    string origen;
    string destino;
    string plaza;
    string transportadora;
    map<int, int> denominaciones;
    string moneda;
    string monedaDestino;

public:
    Operacion(const string& id, TipoOperacion tipo, const string& origen,
              const string& destino, const string& plaza, const string& transportadora,
              const string& moneda, const string& monedaDestino = "");

    void agregarDenominacion(int valor, int cantidad);
    double calcularMonto() const;
    string tipoToString() const;

    // Getters
    string getId() const;
    string getFecha() const;
    TipoOperacion getTipo() const;
    string getOrigen() const;
    string getDestino() const;
    string getPlaza() const;
    string getTransportadora() const;
    const map<int, int>& getDenominaciones() const;
    string getMoneda() const;
    string getMonedaDestino() const;
};

#endif // OPERACION_H
