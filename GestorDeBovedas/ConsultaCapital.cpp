#include "consultacapital.h"
#include "ui_consultacapital.h"
#include <QMessageBox>

ConsultaCapital::ConsultaCapital(SistemaGestor* sistema, QWidget *parent) :
    QDialog(parent), ui(new Ui::ConsultaCapital), sistema(sistema)
{
    ui->setupUi(this);
    setWindowTitle("Consultar Capital");

    // Configurar combobox
    ui->comboTipo->addItem("Banco");
    ui->comboTipo->addItem("Sede Bancaria");
    ui->comboTipo->addItem("Transportadora");

    cargarMonedas();
    cargarBancos();
}

ConsultaCapital::~ConsultaCapital()
{
    delete ui;
}

void ConsultaCapital::on_comboTipo_currentIndexChanged(int index)
{
    ui->comboEntidad->clear();

    switch(index) {
    case 0: // Banco
        cargarBancos();
        break;
    case 1: // Sede Bancaria
        cargarSedes();
        break;
    case 2: // Transportadora
        cargarTransportadoras();
        break;
    }
}

void ConsultaCapital::on_btnConsultar_clicked()
{
    try {
        QString moneda = ui->comboMoneda->currentText();
        double capital = 0;
        QString mensaje;

        switch(ui->comboTipo->currentIndex()) {
        case 0: { // Banco
            QString codigoBanco = ui->comboEntidad->currentData().toString();
            capital = sistema->getCapitalBanco(codigoBanco.toStdString(), moneda.toStdString());
            mensaje = QString("Capital total del banco en %1: ").arg(moneda);
            break;
        }
        case 1: { // Sede Bancaria
            QString codigoSede = ui->comboEntidad->currentData().toString();
            // Buscar el banco al que pertenece la sede
            for (const auto& banco : sistema->getBancos()) {
                for (const auto& sede : banco.getSedes()) {
                    if (sede.getCodigo() == codigoSede.toStdString()) {
                        capital = sistema->getCapitalSede(banco.getCodigo(), sede.getCodigo(), moneda.toStdString());
                        mensaje = QString("Capital de la sede en %1: ").arg(moneda);
                        break;
                    }
                }
            }
            break;
        }
        case 2: { // Transportadora
            QString codigoTrans = ui->comboEntidad->currentData().toString();
            capital = sistema->getCapitalTransportadora(codigoTrans.toStdString(), moneda.toStdString());
            mensaje = QString("Capital transportado en %1: ").arg(moneda);
            break;
        }
        }

        ui->labelResultado->setText(mensaje + QString("%1").arg(capital, 0, 'f', 2));

    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("No se pudo obtener el capital: ") + e.what());
    }
}

void ConsultaCapital::on_btnCerrar_clicked()
{
    close();
}

void ConsultaCapital::cargarBancos()
{
    ui->comboEntidad->clear();
    for (const auto& banco : sistema->getBancos()) {
        ui->comboEntidad->addItem(QString::fromStdString(banco.getNombre()),
                                  QString::fromStdString(banco.getCodigo()));
    }
}

void ConsultaCapital::cargarSedes()
{
    ui->comboEntidad->clear();
    for (const auto& banco : sistema->getBancos()) {
        for (const auto& sede : banco.getSedes()) {
            QString item = QString("%1 - %2").arg(QString::fromStdString(banco.getNombre()),
                                                  QString::fromStdString(sede.getUbicacion()));
            ui->comboEntidad->addItem(item, QString::fromStdString(sede.getCodigo()));
        }
    }
}

void ConsultaCapital::cargarTransportadoras()
{
    ui->comboEntidad->clear();
    for (const auto& trans : sistema->getTransportadoras()) {
        ui->comboEntidad->addItem(QString::fromStdString(trans.getNombre()),
                                  QString::fromStdString(trans.getCodigo()));
    }
}

void ConsultaCapital::cargarMonedas()
{
    ui->comboMoneda->clear();
    ui->comboMoneda->addItem("USD");
    ui->comboMoneda->addItem("EUR");
    ui->comboMoneda->addItem("PEN");
}
