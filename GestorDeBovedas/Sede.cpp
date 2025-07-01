#include "Sede.h"
#include <iostream>
#include <iomanip>
Sede::Sede(const string& codigo, const string& ubicacion, const string& moneda)
    : codigo(codigo), ubicacion(ubicacion), boveda(codigo, moneda) {}

string Sede::getCodigo() const {
    return codigo;
}

string Sede::getUbicacion() const {
    return ubicacion;
}

Boveda& Sede::getBoveda() {
    return boveda;
}

const Boveda& Sede::getBoveda() const {
    return boveda;
}

double Sede::getCapital() const {
    return boveda.getCapital();
}

string Sede::getMoneda() const {
    return boveda.getMoneda();
}

void Sede::mostrarInfo() const {
    cout << "Sede " << codigo << " - Ubicación: " << ubicacion << endl;
    cout << "Moneda: " << getMoneda() << endl;
    cout << "Capital disponible: " << getMoneda() << " " << fixed << setprecision(2) << getCapital() << endl;
    boveda.mostrarEstado();
}
