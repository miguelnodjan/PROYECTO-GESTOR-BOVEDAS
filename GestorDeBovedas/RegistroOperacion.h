#ifndef REGISTROOPERACION_H
#define REGISTROOPERACION_H

#include <QDialog>
#include "SistemaGestor.h"

namespace Ui {
class RegistroOperacion;
}

class RegistroOperacion : public QDialog
{
    Q_OBJECT

public:
    explicit RegistroOperacion(SistemaGestor* sistema, QWidget *parent = nullptr);
    ~RegistroOperacion();

private slots:
    void on_comboTipo_currentIndexChanged(int index);
    void on_btnAgregarDenominacion_clicked();
    void on_btnRegistrar_clicked();
    void on_btnCancelar_clicked();

private:
    Ui::RegistroOperacion *ui;
    SistemaGestor* sistema;
    std::map<int, int> denominaciones;
    void cargarBancos();
    void cargarSedes();
    void cargarTransportadoras();
    void cargarPlazas();
    void actualizarTablaDenominaciones();
};

#endif // REGISTROOPERACION_H
