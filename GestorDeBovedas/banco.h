#ifndef ENTIDAD_BANCARIA_H
#define ENTIDAD_BANCARIA_H

#include "Sede.h"
#include <string>
#include <vector>

using namespace std;

class EntidadBancaria {
private:
    string nombre;
    string codigo;
    vector<Sede> sedes;

public:
    EntidadBancaria(const string& nombre, const string& codigo);

    void agregarSede(const string& codigo, const string& ubicacion, const string& moneda);
    Sede* buscarSede(const string& codigo);
    const vector<Sede>& getSedes() const;
    string getNombre() const;
    string getCodigo() const;
    double getCapitalTotal(const string& moneda = "USD") const;
    void mostrarInfo() const;
};

#endif // ENTIDAD_BANCARIA_H
