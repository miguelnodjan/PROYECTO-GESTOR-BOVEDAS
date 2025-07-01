#include "ListadoOperaciones.h"
#include "ui_listadooperaciones.h"
#include "detallesoperacion.h"
#include <QMessageBox>

ListadoOperaciones::ListadoOperaciones(SistemaGestor* sistema, QWidget *parent) :
    QDialog(parent), ui(new Ui::ListadoOperaciones), sistema(sistema)
{
    ui->setupUi(this);
    setWindowTitle("Listado de Operaciones");

    // Configurar tabla
    ui->tableOperaciones->setColumnCount(8);
    ui->tableOperaciones->setHorizontalHeaderLabels(
        {"ID", "Fecha", "Tipo", "Origen", "Destino", "Plaza", "Transportadora", "Monto"});

    cargarOperaciones();
}

ListadoOperaciones::~ListadoOperaciones()
{
    delete ui;
}

void ListadoOperaciones::on_btnDetalles_clicked()
{
    int row = ui->tableOperaciones->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Error", "Seleccione una operación");
        return;
    }

    QString id = ui->tableOperaciones->item(row, 0)->text();
    DetallesOperacion dialog(sistema, id, this);
    dialog.exec();
}

void ListadoOperaciones::on_btnCerrar_clicked()
{
    close();
}

void ListadoOperaciones::cargarOperaciones(const std::vector<Operacion>& operaciones)
{
        ui->tableOperaciones->setRowCount(0);

        // Si no se pasan operaciones, usar todas del sistema
        const std::vector<Operacion>& ops = operaciones.empty() ?
                                                sistema->obtenerTodasOperaciones() :
                                                operaciones;

        for (const auto& op : ops) {
        int row = ui->tableOperaciones->rowCount();
        ui->tableOperaciones->insertRow(row);

        ui->tableOperaciones->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(op.getId())));
        ui->tableOperaciones->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(op.getFecha())));
        ui->tableOperaciones->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(op.tipoToString())));

        ui->tableOperaciones->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(op.getId())));
        ui->tableOperaciones->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(op.getFecha())));

        ui->tableOperaciones->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(op.getId())));
        ui->tableOperaciones->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(op.getFecha())));
        ui->tableOperaciones->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(op.tipoToString())));
        ui->tableOperaciones->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(op.getOrigen())));
        ui->tableOperaciones->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(op.getDestino())));
        ui->tableOperaciones->setItem(row, 5, new QTableWidgetItem(QString::fromStdString(op.getPlaza())));
        ui->tableOperaciones->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(op.getTransportadora())));

        QString monto = QString("%1 %2").arg(QString::fromStdString(op.getMoneda()))
                            .arg(op.calcularMonto(), 0, 'f', 2);
        ui->tableOperaciones->setItem(row, 7, new QTableWidgetItem(monto));
    }

    ui->tableOperaciones->resizeColumnsToContents();
}
