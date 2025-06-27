#ifndef TIPO_OPERACION_H
#define TIPO_OPERACION_H

#include <string>

enum class TipoOperacion {
    ENTREGA,
    RECOJO,
    TRASLADO,
    DEPOSITO,
    RETIRO,
    CANJE,
    PAGO
};

std::string tipoToString(TipoOperacion tipo);
TipoOperacion tipoDesdeString(const std::string& texto);

#endif
