#ifndef TRANSPORTADORA_H
#define TRANSPORTADORA_H

#include <string>
#include <vector>
#include "Operacion.h"

class Transportadora {
private:
    std::string nombre;
    std::vector<Operacion> operaciones;

public:
    Transportadora(const std::string& nombre);
    void registrarOperacion(const Operacion& op);
    void listarOperaciones() const;
};

#endif
