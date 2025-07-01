#ifndef TRANSPORTADORA_H
#define TRANSPORTADORA_H

#include <string>
#include <vector>
#include <map>
#include "Constantes.h"

using namespace std;

class Transportadora {
private:
    string nombre;
    string codigo;
    map<string, map<int, int>> efectivoTransportado; // moneda -> (valor -> cantidad)
    vector<string> operacionesRealizadas;

public:
    Transportadora(const string& nombre, const string& codigo);

    void registrarTransporte(const string& operacionId, const map<int, int>& denominaciones, const string& moneda);
    double getCapitalTransportado(const string& moneda = "USD") const;
    string getNombre() const;
    string getCodigo() const;
    void mostrarInfo() const;
};

#endif // TRANSPORTADORA_H
