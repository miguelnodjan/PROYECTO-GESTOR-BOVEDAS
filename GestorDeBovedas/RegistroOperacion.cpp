#include "RegistroOperacion.h"
#include "ui_registrooperacion.h"
#include <QMessageBox>
#include <QComboBox>

RegistroOperacion::RegistroOperacion(SistemaGestor* sistema, QWidget *parent) :
    QDialog(parent), ui(new Ui::RegistroOperacion), sistema(sistema)
{
    ui->setupUi(this);

    // Configurar combobox
    ui->comboTipo->addItem("Entrega", static_cast<int>(TipoOperacion::ENTREGA));
    ui->comboTipo->addItem("Recojo", static_cast<int>(TipoOperacion::RECOJO));
    ui->comboTipo->addItem("Traslado", static_cast<int>(TipoOperacion::TRASLADO));
    ui->comboTipo->addItem("Canje", static_cast<int>(TipoOperacion::CANJE));
    ui->comboTipo->addItem("Pago", static_cast<int>(TipoOperacion::PAGO));
    ui->comboTipo->addItem("Depósito", static_cast<int>(TipoOperacion::DEPOSITO));
    ui->comboTipo->addItem("Retiro", static_cast<int>(TipoOperacion::RETIRO));

    // Configurar monedas
    ui->comboMoneda->addItem("USD");
    ui->comboMoneda->addItem("EUR");
    ui->comboMoneda->addItem("PEN");

    ui->comboMonedaDestino->addItem("N/A");
    ui->comboMonedaDestino->addItem("USD");
    ui->comboMonedaDestino->addItem("EUR");
    ui->comboMonedaDestino->addItem("PEN");

    // Cargar datos
    cargarBancos();
    cargarTransportadoras();
    cargarPlazas();

    // Configurar tabla
    ui->tableDenominaciones->setColumnCount(3);
    ui->tableDenominaciones->setHorizontalHeaderLabels({"Valor", "Cantidad", "Subtotal"});

    // Conectar señales
    connect(ui->comboTipo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &RegistroOperacion::on_comboTipo_currentIndexChanged);
}

RegistroOperacion::~RegistroOperacion()
{
    delete ui;
}

void RegistroOperacion::on_comboTipo_currentIndexChanged(int index)
{
    bool esCanje = (ui->comboTipo->currentData().toInt() == static_cast<int>(TipoOperacion::CANJE));
    ui->labelMonedaDestino->setVisible(esCanje);
    ui->comboMonedaDestino->setVisible(esCanje);

    cargarSedes(); // Recargar sedes según el tipo de operación
}

void RegistroOperacion::on_btnAgregarDenominacion_clicked()
{
    int valor = ui->spinValor->value();
    int cantidad = ui->spinCantidad->value();

    if (valor <= 0 || cantidad <= 0) {
        QMessageBox::warning(this, "Error", "Valor y cantidad deben ser positivos");
        return;
    }

    denominaciones[valor] += cantidad;
    actualizarTablaDenominaciones();

    // Limpiar controles
    ui->spinValor->setValue(0);
    ui->spinCantidad->setValue(0);
}

void RegistroOperacion::on_btnRegistrar_clicked()
{
    try {
        if (denominaciones.empty()) {
            QMessageBox::warning(this, "Error", "Debe agregar al menos una denominación");
            return;
        }

        TipoOperacion tipo = static_cast<TipoOperacion>(ui->comboTipo->currentData().toInt());
        string origen = ui->comboOrigen->currentData().toString().toStdString();
        string destino = ui->comboDestino->currentData().toString().toStdString();
        string plaza = ui->comboPlaza->currentData().toString().toStdString();
        string transportadora = ui->comboTransportadora->currentData().toString().toStdString();
        string moneda = ui->comboMoneda->currentText().toStdString();
        string monedaDestino = "";

        if (tipo == TipoOperacion::CANJE) {
            monedaDestino = ui->comboMonedaDestino->currentText().toStdString();
            if (monedaDestino == "N/A") {
                QMessageBox::warning(this, "Error", "Debe seleccionar moneda destino para canje");
                return;
            }
        }

        sistema->registrarOperacion(tipo, origen, destino, plaza, transportadora, denominaciones, moneda, monedaDestino);

        QMessageBox::information(this, "Éxito", "Operación registrada correctamente");
        accept();

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("No se pudo registrar la operación: ") + e.what());
    }
}

void RegistroOperacion::on_btnCancelar_clicked()
{
    reject();
}

void RegistroOperacion::cargarBancos()
{
    ui->comboOrigen->clear();
    ui->comboDestino->clear();

    for (const auto& banco : sistema->getBancos()) {
        for (const auto& sede : banco.getSedes()) {
            QString itemText = QString("%1 - %2").arg(QString::fromStdString(banco.getNombre()),
                                                      QString::fromStdString(sede.getUbicacion()));

            ui->comboOrigen->addItem(itemText, QString::fromStdString(sede.getCodigo()));
            ui->comboDestino->addItem(itemText, QString::fromStdString(sede.getCodigo()));
        }
    }
}

void RegistroOperacion::cargarSedes()
{
    // Implementación similar a cargarBancos pero con filtros según tipo de operación
}

void RegistroOperacion::cargarTransportadoras()
{
    ui->comboTransportadora->clear();
    for (const auto& trans : sistema->getTransportadoras()) {
        ui->comboTransportadora->addItem(QString::fromStdString(trans.getNombre()),
                                         QString::fromStdString(trans.getCodigo()));
    }
}

void RegistroOperacion::cargarPlazas()
{
    ui->comboPlaza->clear();
    const auto& plazas = sistema->getPlazas();

    for (const auto& plaza : plazas) {
        ui->comboPlaza->addItem(QString::fromStdString(plaza.second),
                                QString::fromStdString(plaza.first));
    }

    if (plazas.empty()) {
        qDebug() << "Advertencia: No hay plazas cargadas en el sistema";
    }
}

void RegistroOperacion::actualizarTablaDenominaciones()
{
    ui->tableDenominaciones->setRowCount(0);

    double total = 0;
    for (const auto& par : denominaciones) {
        int row = ui->tableDenominaciones->rowCount();
        ui->tableDenominaciones->insertRow(row);

        ui->tableDenominaciones->setItem(row, 0, new QTableWidgetItem(QString::number(par.first)));
        ui->tableDenominaciones->setItem(row, 1, new QTableWidgetItem(QString::number(par.second)));

        double subtotal = par.first * par.second;
        total += subtotal;
        ui->tableDenominaciones->setItem(row, 2, new QTableWidgetItem(QString::number(subtotal)));
    }

    ui->labelTotal->setText(QString("Total: %1 %2")
                                .arg(ui->comboMoneda->currentText())
                                .arg(total, 0, 'f', 2));
}
