#include "Banco.h"
#include "Constantes.h"
#include <iostream>
#include <iomanip>

EntidadBancaria::EntidadBancaria(const string& nombre, const string& codigo)
    : nombre(nombre), codigo(codigo) {}

void EntidadBancaria::agregarSede(const string& codigo, const string& ubicacion, const string& moneda) {
    sedes.emplace_back(codigo, ubicacion, moneda);
}

Sede* EntidadBancaria::buscarSede(const string& codigo) {
    for (auto& sede : sedes) {
        if (sede.getCodigo() == codigo) {
            return &sede;
        }
    }
    return nullptr;
}

const vector<Sede>& EntidadBancaria::getSedes() const {
    return sedes;
}

string EntidadBancaria::getNombre() const {
    return nombre;
}

string EntidadBancaria::getCodigo() const {
    return codigo;
}

double EntidadBancaria::getCapitalTotal(const string& moneda) const {
    double total = 0;
    for (const auto& sede : sedes) {
        double capital = sede.getCapital();
        if (sede.getMoneda() != moneda) {
            capital *= Moneda::obtenerTasaCambio(sede.getMoneda(), moneda);
        }
        total += capital;
    }
    return total;
}

void EntidadBancaria::mostrarInfo() const {
    cout << "Banco: " << nombre << " (" << codigo << ")" << endl;
    cout << "Total de sedes: " << sedes.size() << endl;
    cout << "Capital total (USD): $" << fixed << setprecision(2) << getCapitalTotal() << endl;

    cout << "\nDetalle de sedes:" << endl;
    for (const auto& sede : sedes) {
        sede.mostrarInfo();
        cout << endl;
    }
}
