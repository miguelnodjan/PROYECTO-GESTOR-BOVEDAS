#include "DetallesOperacion.h"
#include "ui_detallesoperacion.h"
#include <QMessageBox>

DetallesOperacion::DetallesOperacion(SistemaGestor* sistema, const QString& idOperacion, QWidget *parent) :
    QDialog(parent), ui(new Ui::DetallesOperacion), sistema(sistema)
{
    ui->setupUi(this);
    setWindowTitle("Detalles de Operación");

    try {
        // Buscar la operación por ID
        for (const auto& op : sistema->obtenerTodasOperaciones()) {
            if (op.getId() == idOperacion.toStdString()) {
                cargarDetalles(op);
                break;
            }
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("No se pudo cargar los detalles: ") + e.what());
        reject();
    }
}

DetallesOperacion::~DetallesOperacion()
{
    delete ui;
}

void DetallesOperacion::cargarDetalles(const Operacion& op)
{
    ui->labelId->setText(QString::fromStdString(op.getId()));
    ui->labelFecha->setText(QString::fromStdString(op.getFecha()));
    ui->labelTipo->setText(QString::fromStdString(op.tipoToString()));
    ui->labelOrigen->setText(QString::fromStdString(op.getOrigen()));
    ui->labelDestino->setText(QString::fromStdString(op.getDestino()));
    ui->labelPlaza->setText(QString::fromStdString(op.getPlaza()));
    ui->labelTransportadora->setText(QString::fromStdString(op.getTransportadora()));
    ui->labelMoneda->setText(QString::fromStdString(op.getMoneda()));

    if (op.getTipo() == TipoOperacion::CANJE) {
        ui->labelMonedaDestino->setText(QString::fromStdString(op.getMonedaDestino()));
        ui->labelMonedaDestinoLabel->setVisible(true);
        ui->labelMonedaDestino->setVisible(true);
    } else {
        ui->labelMonedaDestinoLabel->setVisible(false);
        ui->labelMonedaDestino->setVisible(false);
    }

    // Configurar tabla de denominaciones
    ui->tableDenominaciones->setColumnCount(3);
    ui->tableDenominaciones->setHorizontalHeaderLabels({"Valor", "Cantidad", "Subtotal"});
    ui->tableDenominaciones->setRowCount(0);

    double total = 0;
    for (const auto& par : op.getDenominaciones()) {
        int row = ui->tableDenominaciones->rowCount();
        ui->tableDenominaciones->insertRow(row);

        ui->tableDenominaciones->setItem(row, 0,
                                         new QTableWidgetItem(QString("%1 %2").arg(QString::fromStdString(op.getMoneda()))
                                                                  .arg(par.first)));
        ui->tableDenominaciones->setItem(row, 1, new QTableWidgetItem(QString::number(par.second)));

        double subtotal = par.first * par.second;
        total += subtotal;
        ui->tableDenominaciones->setItem(row, 2,
                                         new QTableWidgetItem(QString("%1 %2").arg(QString::fromStdString(op.getMoneda()))
                                                                  .arg(subtotal, 0, 'f', 2)));
    }

    ui->labelTotal->setText(QString("Total: %1 %2").arg(QString::fromStdString(op.getMoneda()))
                                .arg(total, 0, 'f', 2));
}
