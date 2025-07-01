#ifndef DETALLESOPERACION_H
#define DETALLESOPERACION_H

#include <QDialog>
#include "SistemaGestor.h"

namespace Ui {
class DetallesOperacion;
}

class DetallesOperacion : public QDialog
{
    Q_OBJECT

public:
    explicit DetallesOperacion(SistemaGestor* sistema, const QString& idOperacion, QWidget *parent = nullptr);
    ~DetallesOperacion();

private:
    Ui::DetallesOperacion *ui;
    SistemaGestor* sistema;
    void cargarDetalles(const Operacion& op);
};

#endif // DETALLESOPERACION_H
