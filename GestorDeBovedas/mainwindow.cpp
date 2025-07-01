#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registrooperacion.h"
#include "listadooperaciones.h"
#include "Filtro.h"
#include "consultacapital.h"
#include <QMessageBox>

MainWindow::MainWindow(SistemaGestor* sistema, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), sistema(sistema)
{
    ui->setupUi(this);
    setWindowTitle("Sistema de Gestión de Bóvedas Multi-Moneda");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnRegistrarOperacion_clicked()
{
    RegistroOperacion dialog(sistema, this);
    dialog.exec();
}

void MainWindow::on_btnVerOperaciones_clicked()
{
    ListadoOperaciones dialog(sistema, this);
    dialog.exec();
}

void MainWindow::on_btnFiltrarOperaciones_clicked()
{
    Filtros dialog(sistema, this);
    dialog.exec();
}

void MainWindow::on_btnConsultarCapital_clicked()
{
    ConsultaCapital dialog(sistema, this);
    dialog.exec();
}

void MainWindow::on_btnSalir_clicked()
{
    close();
}
