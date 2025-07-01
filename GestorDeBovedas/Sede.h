#ifndef SEDE_H
#define SEDE_H

#include "Boveda.h"
#include <string>

using namespace std;

class Sede {
private:
    string codigo;
    string ubicacion;
    Boveda boveda;

public:
    Sede(const string& codigo, const string& ubicacion, const string& moneda);

    string getCodigo() const;
    string getUbicacion() const;
    Boveda& getBoveda();
    const Boveda& getBoveda() const;
    double getCapital() const;
    string getMoneda() const;
    void mostrarInfo() const;
};

#endif // SEDE_H
