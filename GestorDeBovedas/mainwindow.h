#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SistemaGestor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(SistemaGestor* sistema, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnRegistrarOperacion_clicked();
    void on_btnVerOperaciones_clicked();
    void on_btnFiltrarOperaciones_clicked();
    void on_btnConsultarCapital_clicked();
    void on_btnSalir_clicked();

private:
    Ui::MainWindow *ui;
    SistemaGestor* sistema;
};

#endif // MAINWINDOW_H
