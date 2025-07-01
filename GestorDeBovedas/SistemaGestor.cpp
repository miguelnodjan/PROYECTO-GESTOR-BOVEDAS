#include "SistemaGestor.h"
#include <ctime>
#include <sstream>
#include <iomanip>
#include <stdexcept>

SistemaGestor::SistemaGestor() {
    cargarDatosPrueba();
}

bool SistemaGestor::existeBanco(const string& codigo) const {
    for (const auto& banco : bancos) {
        if (banco.getCodigo() == codigo) {
            return true;
        }
    }
    return false;
}

bool SistemaGestor::existeTransportadora(const string& codigo) const {
    for (const auto& trans : transportadoras) {
        if (trans.getCodigo() == codigo) {
            return true;
        }
    }
    return false;
}

bool SistemaGestor::existePlaza(const string& codigo) const {
    return plazas.find(codigo) != plazas.end();
}

string SistemaGestor::generarIdOperacion() const {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    ostringstream ss;
    ss << "OP-" << 1900 + ltm->tm_year
       << setw(2) << setfill('0') << 1 + ltm->tm_mon
       << setw(2) << setfill('0') << ltm->tm_mday << "-"
       << setw(2) << setfill('0') << ltm->tm_hour
       << setw(2) << setfill('0') << ltm->tm_min
       << setw(2) << setfill('0') << ltm->tm_sec;

    return ss.str();
}

map<int, int> SistemaGestor::calcularCanje(const map<int, int>& denominaciones,
                                           const string& monedaOrigen,
                                           const string& monedaDestino) {
    // Calcular monto total en moneda origen
    double montoOrigen = 0;
    for (const auto& par : denominaciones) {
        montoOrigen += par.first * par.second;
    }

    // Convertir a moneda destino
    double tasa = Moneda::obtenerTasaCambio(monedaOrigen, monedaDestino);
    double montoDestino = montoOrigen * tasa;

    // Simplificación: usar denominaciones estándar para cada moneda
    map<int, int> resultado;
    int resto = static_cast<int>(montoDestino);

    if (monedaDestino == "USD") {
        const int denominacionesUSD[] = {100, 50, 20, 10, 5, 1};
        for (int denom : denominacionesUSD) {
            if (resto >= denom) {
                resultado[denom] = resto / denom;
                resto %= denom;
            }
        }
    }
    else if (monedaDestino == "EUR") {
        const int denominacionesEUR[] = {200, 100, 50, 20, 10, 5};
        for (int denom : denominacionesEUR) {
            if (resto >= denom) {
                resultado[denom] = resto / denom;
                resto %= denom;
            }
        }
    }
    else if (monedaDestino == "PEN") {
        const int denominacionesPEN[] = {200, 100, 50, 20, 10, 5, 2, 1};
        for (int denom : denominacionesPEN) {
            if (resto >= denom) {
                resultado[denom] = resto / denom;
                resto %= denom;
            }
        }
    }

    return resultado;
}

void SistemaGestor::agregarBanco(const string& nombre, const string& codigo) {
    if (existeBanco(codigo)) {
        throw runtime_error("El banco con este código ya existe");
    }
    bancos.emplace_back(nombre, codigo);
}

EntidadBancaria* SistemaGestor::buscarBanco(const string& codigo) {
    for (auto& banco : bancos) {
        if (banco.getCodigo() == codigo) {
            return &banco;
        }
    }
    return nullptr;
}

void SistemaGestor::agregarSedeABanco(const string& codigoBanco, const string& codigoSede,
                                      const string& ubicacion, const string& moneda) {
    auto banco = buscarBanco(codigoBanco);
    if (!banco) {
        throw runtime_error("Banco no encontrado");
    }
    banco->agregarSede(codigoSede, ubicacion, moneda);
}

void SistemaGestor::agregarTransportadora(const string& nombre, const string& codigo) {
    if (existeTransportadora(codigo)) {
        throw runtime_error("La transportadora con este código ya existe");
    }
    transportadoras.emplace_back(nombre, codigo);
}

Transportadora* SistemaGestor::buscarTransportadora(const string& codigo) {
    for (auto& trans : transportadoras) {
        if (trans.getCodigo() == codigo) {
            return &trans;
        }
    }
    return nullptr;
}

void SistemaGestor::agregarPlaza(const string& codigo, const string& nombre) {
    if (existePlaza(codigo)) {
        throw runtime_error("La plaza con este código ya existe");
    }
    plazas[codigo] = nombre;
}

void SistemaGestor::registrarOperacion(TipoOperacion tipo, const string& origen,
                                       const string& destino, const string& plaza,
                                       const string& transportadora,
                                       const map<int, int>& denominaciones,
                                       const string& moneda,
                                       const string& monedaDestino) {
    // Validar plaza
    if (!existePlaza(plaza)) {
        throw runtime_error("Plaza no válida");
    }

    // Validar transportadora
    auto trans = buscarTransportadora(transportadora);
    if (!trans) {
        throw runtime_error("Transportadora no válida");
    }

    // Buscar sedes
    Sede* sedeOrigen = nullptr;
    Sede* sedeDestino = nullptr;

    for (auto& banco : bancos) {
        if (!sedeOrigen) sedeOrigen = banco.buscarSede(origen);
        if (!sedeDestino) sedeDestino = banco.buscarSede(destino);
    }

    if (!sedeOrigen && tipo != TipoOperacion::DEPOSITO) {
        throw runtime_error("Sede origen no válida");
    }

    if (!sedeDestino && tipo != TipoOperacion::RETIRO) {
        throw runtime_error("Sede destino no válida");
    }

    // Validar monedas
    if (sedeOrigen && sedeOrigen->getMoneda() != moneda) {
        throw runtime_error("La moneda no coincide con la bóveda de origen");
    }

    if (tipo != TipoOperacion::CANJE && sedeDestino && sedeDestino->getMoneda() != moneda) {
        throw runtime_error("La moneda no coincide con la bóveda de destino");
    }

    // Generar operación
    string id = generarIdOperacion();
    Operacion op(id, tipo, origen, destino, plaza, transportadora, moneda, monedaDestino);
    for (const auto& par : denominaciones) {
        op.agregarDenominacion(par.first, par.second);
    }

    // Procesar según tipo de operación
    if (tipo == TipoOperacion::CANJE) {
        if (monedaDestino.empty()) {
            throw runtime_error("Se requiere moneda destino para canje");
        }

        map<int, int> denominacionesDestino = calcularCanje(denominaciones, moneda, monedaDestino);

        // Retirar de origen
        for (const auto& par : denominaciones) {
            sedeOrigen->getBoveda().retirarDinero(par.first, par.second);
        }

        // Depositar en destino
        for (const auto& par : denominacionesDestino) {
            sedeDestino->getBoveda().agregarDinero(par.first, par.second);
        }
    }
    else if (tipo == TipoOperacion::ENTREGA || tipo == TipoOperacion::TRASLADO ||
             tipo == TipoOperacion::PAGO || tipo == TipoOperacion::RETIRO) {
        // Retirar de origen
        for (const auto& par : denominaciones) {
            sedeOrigen->getBoveda().retirarDinero(par.first, par.second);
        }
    }
    else if (tipo == TipoOperacion::RECOJO || tipo == TipoOperacion::DEPOSITO) {
        // Depositar en destino
        for (const auto& par : denominaciones) {
            sedeDestino->getBoveda().agregarDinero(par.first, par.second);
        }
    }

    // Registrar en transportadora
    trans->registrarTransporte(id, denominaciones, moneda);

    // Guardar en historial
    historial.push_back(op);
}

vector<Operacion> SistemaGestor::filtrarOperaciones(TipoOperacion tipo, const string& plaza,
                                                    const string& fechaInicio, const string& fechaFin) const {
    vector<Operacion> resultado;
    for (const auto& op : historial) {
        if ((tipo == TipoOperacion(-1) || op.getTipo() == tipo) &&
            (plaza.empty() || op.getPlaza() == plaza) &&
            (fechaInicio.empty() || op.getFecha() >= fechaInicio) &&
            (fechaFin.empty() || op.getFecha() <= fechaFin)) {
            resultado.push_back(op);
        }
    }
    return resultado;
}

double SistemaGestor::getCapitalBanco(const string& codigoBanco, const string& moneda) const {
    for (const auto& banco : bancos) {
        if (banco.getCodigo() == codigoBanco) {
            return banco.getCapitalTotal(moneda);
        }
    }
    throw runtime_error("Banco no encontrado");
}

double SistemaGestor::getCapitalSede(const string& codigoBanco, const string& codigoSede,
                                     const string& moneda) const {
    for (const auto& banco : bancos) {
        if (banco.getCodigo() == codigoBanco) {
            for (const auto& sede : banco.getSedes()) {
                if (sede.getCodigo() == codigoSede) {
                    double capital = sede.getCapital();
                    if (sede.getMoneda() != moneda) {
                        capital *= Moneda::obtenerTasaCambio(sede.getMoneda(), moneda);
                    }
                    return capital;
                }
            }
            throw runtime_error("Sede no encontrada");
        }
    }
    throw runtime_error("Banco no encontrado");
}

double SistemaGestor::getCapitalTransportadora(const string& codigoTransportadora,
                                               const string& moneda) const {
    for (const auto& trans : transportadoras) {
        if (trans.getCodigo() == codigoTransportadora) {
            return trans.getCapitalTransportado(moneda);
        }
    }
    throw runtime_error("Transportadora no encontrada");
}

void SistemaGestor::cargarDatosPrueba() {
    // Agregar bancos
    agregarBanco("Banco Central", "BCR");
    agregarBanco("Banco Nacional", "BN");
    agregarBanco("Banco de Costa Rica", "BAC");

    // Agregar sedes con diferentes monedas
    agregarSedeABanco("BCR", "BCR-SJ", "San José, Av. Central", "USD");
    agregarSedeABanco("BCR", "BCR-AL", "Alajuela, Parque Central", "USD");
    agregarSedeABanco("BN", "BN-SJ", "San José, Calle 5", "EUR");
    agregarSedeABanco("BN", "BN-HD", "Heredia, Centro", "EUR");
    agregarSedeABanco("BAC", "BAC-SJ", "San José, Sabana", "PEN");

    // Agregar transportadoras
    agregarTransportadora("Hermes", "HER");
    agregarTransportadora("Prosegur", "PRO");
    agregarTransportadora("Brinks", "BRI");

    // Agregar plazas
    plazas["SJ"] = "San José";
    plazas["AL"] = "Alajuela";
    plazas["HD"] = "Heredia";
    plazas["CT"] = "Cartago";

    // Cargar dinero inicial en bóvedas
    auto bcrSj = buscarBanco("BCR")->buscarSede("BCR-SJ");
    if (bcrSj) {
        bcrSj->getBoveda().agregarDinero(100, 50);
        bcrSj->getBoveda().agregarDinero(50, 100);
        bcrSj->getBoveda().agregarDinero(20, 200);
    }

    auto bnHd = buscarBanco("BN")->buscarSede("BN-HD");
    if (bnHd) {
        bnHd->getBoveda().agregarDinero(100, 30);
        bnHd->getBoveda().agregarDinero(50, 60);
        bnHd->getBoveda().agregarDinero(20, 120);
    }

    auto bacSj = buscarBanco("BAC")->buscarSede("BAC-SJ");
    if (bacSj) {
        bacSj->getBoveda().agregarDinero(100, 40);
        bacSj->getBoveda().agregarDinero(50, 80);
        bacSj->getBoveda().agregarDinero(20, 160);
    }
}

const vector<EntidadBancaria>& SistemaGestor::getBancos() const {
    return bancos;
}

const vector<Transportadora>& SistemaGestor::getTransportadoras() const {
    return transportadoras;
}
const vector<Operacion>& SistemaGestor::obtenerTodasOperaciones() const {
    return historial;
}
const std::map<std::string, std::string>& SistemaGestor::getPlazas() const {
    return plazas;
}

