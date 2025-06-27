#ifndef PLAZA_H
#define PLAZA_H

#include <string>
#include <vector>
#include "Operacion.h"

class Plaza {
private:
    std::string nombre;
    std::vector<Operacion> operaciones;

public:
    Plaza(const std::string& nombre);
    void agregarOperacion(const Operacion& op);
    void mostrarResumen() const;
};

#endif

