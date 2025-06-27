#ifndef ENTIDAD_BANCARIA_H
#define ENTIDAD_BANCARIA_H

#include <string>
#include <vector>

class EntidadBancaria {
private:
    std::string nombre;
    std::vector<std::string> bovedas;

public:
    EntidadBancaria(const std::string& nombre);
    void agregarBoveda(const std::string& nombreBoveda);
    bool contieneBoveda(const std::string& nombreBoveda) const;
    void mostrarBovedas() const;
};

#endif
