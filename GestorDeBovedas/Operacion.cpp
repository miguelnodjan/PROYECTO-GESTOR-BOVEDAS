#include "Operacion.h"
#include <iomanip>
#include <sstream>

Operacion::Operacion(const string& id, TipoOperacion tipo, const string& origen,
                     const string& destino, const string& plaza, const string& transportadora,
                     const string& moneda, const string& monedaDestino)
    : id(id), tipo(tipo), origen(origen), destino(destino),
    plaza(plaza), transportadora(transportadora),
    moneda(moneda), monedaDestino(monedaDestino) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    ostringstream oss;
    oss << 1900 + ltm->tm_year << "-"
        << setw(2) << setfill('0') << 1 + ltm->tm_mon << "-"
        << setw(2) << setfill('0') << ltm->tm_mday;
    fecha = oss.str();
}

void Operacion::agregarDenominacion(int valor, int cantidad) {
    if (valor <= 0 || cantidad <= 0) {
        throw runtime_error("Denominación y cantidad deben ser positivas");
    }
    denominaciones[valor] += cantidad;
}

double Operacion::calcularMonto() const {
    double total = 0.0;
    for (const auto& par : denominaciones) {
        total += par.first * par.second;
    }
    return total;
}

string Operacion::tipoToString() const {
    switch (tipo) {
    case TipoOperacion::ENTREGA: return "Entrega";
    case TipoOperacion::RECOJO: return "Recojo";
    case TipoOperacion::TRASLADO: return "Traslado";
    case TipoOperacion::CANJE: return "Canje";
    case TipoOperacion::PAGO: return "Pago";
    case TipoOperacion::DEPOSITO: return "Depósito";
    case TipoOperacion::RETIRO: return "Retiro";
    default: return "Desconocido";
    }
}

string Operacion::getId() const { return id; }
string Operacion::getFecha() const { return fecha; }
TipoOperacion Operacion::getTipo() const { return tipo; }
string Operacion::getOrigen() const { return origen; }
string Operacion::getDestino() const { return destino; }
string Operacion::getPlaza() const { return plaza; }
string Operacion::getTransportadora() const { return transportadora; }
const map<int, int>& Operacion::getDenominaciones() const { return denominaciones; }
string Operacion::getMoneda() const { return moneda; }
string Operacion::getMonedaDestino() const { return monedaDestino; }
