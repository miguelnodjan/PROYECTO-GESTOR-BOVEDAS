#include "Boveda.h"
#include <iostream>
#include <iomanip>

Boveda::Boveda(const string& codigo, const string& moneda)
    : codigo(codigo), moneda(moneda) {}

void Boveda::agregarDinero(int valor, int cantidad) {
    if (valor <= 0 || cantidad <= 0) {
        throw runtime_error("Valor y cantidad deben ser positivos");
    }
    denominaciones[valor] += cantidad;
}

void Boveda::retirarDinero(int valor, int cantidad) {
    if (denominaciones[valor] < cantidad) {
        throw runtime_error("No hay suficiente dinero en la bóveda");
    }
    denominaciones[valor] -= cantidad;
}

double Boveda::getCapital() const {
    double total = 0.0;
    for (const auto& par : denominaciones) {
        total += par.first * par.second;
    }
    return total;
}

const map<int, int>& Boveda::getDenominaciones() const {
    return denominaciones;
}

string Boveda::getCodigo() const {
    return codigo;
}

string Boveda::getMoneda() const {
    return moneda;
}

void Boveda::mostrarEstado() const {
    cout << "Bóveda " << codigo << " (" << moneda << ") - Capital: "
         << moneda << " " << fixed << setprecision(2) << getCapital() << endl;
    cout << "Denominaciones disponibles:" << endl;
    for (const auto& par : denominaciones) {
        if (par.second > 0) {
            cout << "  " << moneda << " " << par.first << ": " << par.second << " billetes" << endl;
        }
    }
}

bool Boveda::tieneSuficiente(const map<int, int>& denominacionesRequeridas) const {
    for (const auto& par : denominacionesRequeridas) {
        if (denominaciones.at(par.first) < par.second) {
            return false;
        }
    }
    return true;
}
