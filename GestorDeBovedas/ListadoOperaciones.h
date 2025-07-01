#ifndef LISTADOOPERACIONES_H
#define LISTADOOPERACIONES_H

#include <QDialog>
#include "SistemaGestor.h"

namespace Ui {
class ListadoOperaciones;
}

class ListadoOperaciones : public QDialog
{
    Q_OBJECT

public:
    explicit ListadoOperaciones(SistemaGestor* sistema, QWidget *parent = nullptr);
    ~ListadoOperaciones();
    void cargarOperaciones(const std::vector<Operacion>& operaciones = {});
private slots:
    void on_btnDetalles_clicked();
    void on_btnCerrar_clicked();

private:
    Ui::ListadoOperaciones *ui;
    SistemaGestor* sistema;

};

#endif // LISTADOOPERACIONES_H
