#ifndef BOVEDA_H
#define BOVEDA_H

#include <map>
#include <string>
#include "Constantes.h"

using namespace std;

class Boveda {
private:
    string codigo;
    string moneda;
    map<int, int> denominaciones; // valor -> cantidad

public:
    Boveda(const string& codigo, const string& moneda);

    void agregarDinero(int valor, int cantidad);
    void retirarDinero(int valor, int cantidad);
    double getCapital() const;
    const map<int, int>& getDenominaciones() const;
    string getCodigo() const;
    string getMoneda() const;
    void mostrarEstado() const;
    bool tieneSuficiente(const map<int, int>& denominaciones) const;
};

#endif // BOVEDA_H
