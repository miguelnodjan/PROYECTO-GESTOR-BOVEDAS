#ifndef CONSULTACAPITAL_H
#define CONSULTACAPITAL_H

#include <QDialog>
#include "SistemaGestor.h"

namespace Ui {
class ConsultaCapital;
}

class ConsultaCapital : public QDialog
{
    Q_OBJECT

public:
    explicit ConsultaCapital(SistemaGestor* sistema, QWidget *parent = nullptr);
    ~ConsultaCapital();

private slots:
    void on_comboTipo_currentIndexChanged(int index);
    void on_btnConsultar_clicked();
    void on_btnCerrar_clicked();

private:
    Ui::ConsultaCapital *ui;
    SistemaGestor* sistema;
    void cargarBancos();
    void cargarSedes();
    void cargarTransportadoras();
    void cargarMonedas();
};

#endif // CONSULTACAPITAL_H
