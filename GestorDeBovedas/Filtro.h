#ifndef FILTROS_H
#define FILTROS_H

#include <QDialog>
#include "SistemaGestor.h"

namespace Ui {
class Filtros;
}

class Filtros : public QDialog
{
    Q_OBJECT

public:
    explicit Filtros(SistemaGestor* sistema, QWidget *parent = nullptr);
    ~Filtros();

private slots:
    void on_btnFiltrar_clicked();
    void on_btnCancelar_clicked();

private:
    Ui::Filtros *ui;
    SistemaGestor* sistema;
    void cargarTiposOperacion();
    void cargarPlazas();
};

#endif // FILTROS_H
