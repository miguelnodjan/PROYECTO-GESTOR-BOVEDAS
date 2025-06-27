#ifndef SISTEMA_GESTOR_OPERACIONES_H
#define SISTEMA_GESTOR_OPERACIONES_H

#include <vector>
//#include <string>
#include "Banco.h"
#include "Transportadora.h"
#include "Plaza.h"
#include "Operacion.h"

class SistemaGestorOperaciones {
private:
    std::vector<EntidadBancaria> bancos;
    std::vector<Transportadora> transportadoras;
    std::vector<Plaza> plazas;
    std::vector<Operacion> historial;

public:
    SistemaGestorOperaciones();

    void mostrarMenu();
    void registrarNuevaOperacion();
    void listarOperacionesPorTipo();
    void filtrarPorPlaza();
    void verHistorialCompleto();
};

#endif


