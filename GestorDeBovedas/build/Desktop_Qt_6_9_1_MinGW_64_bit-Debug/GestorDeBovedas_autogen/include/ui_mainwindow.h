/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitulo;
    QPushButton *btnRegistrarOperacion;
    QPushButton *btnVerOperaciones;
    QPushButton *btnFiltrarOperaciones;
    QPushButton *btnConsultarCapital;
    QPushButton *btnSalir;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        labelTitulo = new QLabel(centralwidget);
        labelTitulo->setObjectName("labelTitulo");
        labelTitulo->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTitulo);

        btnRegistrarOperacion = new QPushButton(centralwidget);
        btnRegistrarOperacion->setObjectName("btnRegistrarOperacion");
        btnRegistrarOperacion->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnRegistrarOperacion);

        btnVerOperaciones = new QPushButton(centralwidget);
        btnVerOperaciones->setObjectName("btnVerOperaciones");
        btnVerOperaciones->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnVerOperaciones);

        btnFiltrarOperaciones = new QPushButton(centralwidget);
        btnFiltrarOperaciones->setObjectName("btnFiltrarOperaciones");
        btnFiltrarOperaciones->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnFiltrarOperaciones);

        btnConsultarCapital = new QPushButton(centralwidget);
        btnConsultarCapital->setObjectName("btnConsultarCapital");
        btnConsultarCapital->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnConsultarCapital);

        btnSalir = new QPushButton(centralwidget);
        btnSalir->setObjectName("btnSalir");
        btnSalir->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnSalir);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sistema de Gesti\303\263n de B\303\263vedas", nullptr));
        labelTitulo->setText(QCoreApplication::translate("MainWindow", "<h1>Sistema de Gesti\303\263n de B\303\263vedas</h1>", nullptr));
        btnRegistrarOperacion->setText(QCoreApplication::translate("MainWindow", "Registrar Nueva Operaci\303\263n", nullptr));
        btnVerOperaciones->setText(QCoreApplication::translate("MainWindow", "Ver Operaciones Registradas", nullptr));
        btnFiltrarOperaciones->setText(QCoreApplication::translate("MainWindow", "Filtrar Operaciones", nullptr));
        btnConsultarCapital->setText(QCoreApplication::translate("MainWindow", "Consultar Capital", nullptr));
        btnSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
