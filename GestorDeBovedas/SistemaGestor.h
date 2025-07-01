#ifndef SISTEMA_GESTOR_H
#define SISTEMA_GESTOR_H

#include "Banco.h"
#include "Transportadora.h"
#include "Operacion.h"
#include "Constantes.h"
#include <vector>
#include <map>

using namespace std;

class SistemaGestor {
private:
    vector<EntidadBancaria> bancos;
    vector<Transportadora> transportadoras;
    vector<Operacion> historial;
    map<string, string> plazas;

    bool existeBanco(const string& codigo) const;
    bool existeTransportadora(const string& codigo) const;
    bool existePlaza(const string& codigo) const;
    string generarIdOperacion() const;
    map<int, int> calcularCanje(const map<int, int>& denominaciones,
                                const string& monedaOrigen,
                                const string& monedaDestino);

public:
    SistemaGestor();

    void agregarBanco(const string& nombre, const string& codigo);
    EntidadBancaria* buscarBanco(const string& codigo);
    void agregarSedeABanco(const string& codigoBanco, const string& codigoSede,
                           const string& ubicacion, const string& moneda);

    void agregarTransportadora(const string& nombre, const string& codigo);
    Transportadora* buscarTransportadora(const string& codigo);

    void agregarPlaza(const string& codigo, const string& nombre);

    void registrarOperacion(TipoOperacion tipo, const string& origen, const string& destino,
                            const string& plaza, const string& transportadora,
                            const map<int, int>& denominaciones, const string& moneda,
                            const string& monedaDestino = "");

    vector<Operacion> filtrarOperaciones(TipoOperacion tipo, const string& plaza,
                                         const string& fechaInicio, const string& fechaFin) const;
    double getCapitalBanco(const string& codigoBanco, const string& moneda = "USD") const;
    double getCapitalSede(const string& codigoBanco, const string& codigoSede,
                          const string& moneda = "USD") const;
    double getCapitalTransportadora(const string& codigoTransportadora,
                                    const string& moneda = "USD") const;

    void cargarDatosPrueba();
    const vector<EntidadBancaria>& getBancos() const;
    const vector<Transportadora>& getTransportadoras() const;
    const vector<Operacion>& obtenerTodasOperaciones() const;
    const std::map<std::string, std::string>& getPlazas() const;
};

#endif // SISTEMA_GESTOR_H
