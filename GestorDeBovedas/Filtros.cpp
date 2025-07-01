#include "Filtro.h"
#include "ui_filtros.h"
#include "ListadoOperaciones.h"
#include <QMessageBox>

Filtros::Filtros(SistemaGestor* sistema, QWidget *parent) :
    QDialog(parent), ui(new Ui::Filtros), sistema(sistema)
{
    ui->setupUi(this);
    setWindowTitle("Filtrar Operaciones");

    // Configurar fechas
    ui->dateEditInicio->setDate(QDate::currentDate().addMonths(-1));
    ui->dateEditFin->setDate(QDate::currentDate());

    // Cargar datos
    cargarTiposOperacion();
    cargarPlazas();
}

Filtros::~Filtros()
{
    delete ui;
}

void Filtros::on_btnFiltrar_clicked()
{
    try {
        TipoOperacion tipo = static_cast<TipoOperacion>(ui->comboTipo->currentData().toInt());
        string plaza = ui->comboPlaza->currentData().toString().toStdString();

        QString fechaInicio = ui->dateEditInicio->date().toString("yyyy-MM-dd");
        QString fechaFin = ui->dateEditFin->date().toString("yyyy-MM-dd");

        auto operaciones = sistema->filtrarOperaciones(
            tipo == TipoOperacion(-1) ? TipoOperacion(-1) : tipo,
            plaza == "Todas" ? "" : plaza,
            fechaInicio.toStdString(),
            fechaFin.toStdString()
            );

        if (operaciones.empty()) {
            QMessageBox::information(this, "Resultados", "No se encontraron operaciones con esos criterios");
            return;
        }

        ListadoOperaciones dialog(sistema, this);
        dialog.cargarOperaciones(operaciones);
        dialog.exec();

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("Error al filtrar: ") + e.what());
    }
}

void Filtros::on_btnCancelar_clicked()
{
    close();
}

void Filtros::cargarTiposOperacion()
{
    ui->comboTipo->clear();
    ui->comboTipo->addItem("Todas", -1);
    ui->comboTipo->addItem("Entrega", static_cast<int>(TipoOperacion::ENTREGA));
    ui->comboTipo->addItem("Recojo", static_cast<int>(TipoOperacion::RECOJO));
    ui->comboTipo->addItem("Traslado", static_cast<int>(TipoOperacion::TRASLADO));
    ui->comboTipo->addItem("Canje", static_cast<int>(TipoOperacion::CANJE));
    ui->comboTipo->addItem("Pago", static_cast<int>(TipoOperacion::PAGO));
    ui->comboTipo->addItem("Depósito", static_cast<int>(TipoOperacion::DEPOSITO));
    ui->comboTipo->addItem("Retiro", static_cast<int>(TipoOperacion::RETIRO));
}

void Filtros::cargarPlazas()
{
    ui->comboPlaza->clear();
    ui->comboPlaza->addItem("Todas", "Todas");
    // Implementar carga de plazas desde sistema
}
