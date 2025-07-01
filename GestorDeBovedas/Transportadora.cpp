#include "Transportadora.h"
#include "Constantes.h"
#include <iostream>
#include <iomanip>

Transportadora::Transportadora(const string& nombre, const string& codigo)
    : nombre(nombre), codigo(codigo) {}

void Transportadora::registrarTransporte(const string& operacionId, const map<int, int>& denominaciones, const string& moneda) {
    operacionesRealizadas.push_back(operacionId);
    for (const auto& par : denominaciones) {
        efectivoTransportado[moneda][par.first] += par.second;
    }
}

double Transportadora::getCapitalTransportado(const string& moneda) const {
    double total = 0;
    for (const auto& monedaEfectivo : efectivoTransportado) {
        double subtotal = 0;
        for (const auto& par : monedaEfectivo.second) {
            subtotal += par.first * par.second;
        }
        if (monedaEfectivo.first != moneda) {
            subtotal *= Moneda::obtenerTasaCambio(monedaEfectivo.first, moneda);
        }
        total += subtotal;
    }
    return total;
}

string Transportadora::getNombre() const {
    return nombre;
}

string Transportadora::getCodigo() const {
    return codigo;
}

void Transportadora::mostrarInfo() const {
    cout << "Transportadora: " << nombre << " (" << codigo << ")" << endl;
    cout << "Total operaciones realizadas: " << operacionesRealizadas.size() << endl;
    cout << "Efectivo transportado actual (USD): $" << fixed << setprecision(2) << getCapitalTransportado() << endl;

    cout << "Detalle por moneda:" << endl;
    for (const auto& monedaEfectivo : efectivoTransportado) {
        if (!monedaEfectivo.second.empty()) {
            double subtotal = 0;
            for (const auto& par : monedaEfectivo.second) {
                subtotal += par.first * par.second;
            }
            cout << "  " << monedaEfectivo.first << ": " << subtotal << endl;
        }
    }
}
