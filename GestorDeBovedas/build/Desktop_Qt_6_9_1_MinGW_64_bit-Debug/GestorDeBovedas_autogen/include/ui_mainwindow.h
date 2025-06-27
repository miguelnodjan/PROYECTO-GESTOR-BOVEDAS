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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGuardar;
    QAction *actionCargar;
    QAction *actionSalir;
    QAction *actionAcerca_de;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitulo;
    QPushButton *btnRegistrarOperacion;
    QPushButton *btnVerOperaciones;
    QPushButton *btnFiltrarOperaciones;
    QPushButton *btnSalir;
    QMenuBar *menubar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName("actionGuardar");
        actionCargar = new QAction(MainWindow);
        actionCargar->setObjectName("actionCargar");
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName("actionSalir");
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName("actionAcerca_de");
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
        btnRegistrarOperacion->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btnRegistrarOperacion);

        btnVerOperaciones = new QPushButton(centralwidget);
        btnVerOperaciones->setObjectName("btnVerOperaciones");
        btnVerOperaciones->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btnVerOperaciones);

        btnFiltrarOperaciones = new QPushButton(centralwidget);
        btnFiltrarOperaciones->setObjectName("btnFiltrarOperaciones");
        btnFiltrarOperaciones->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btnFiltrarOperaciones);

        btnSalir = new QPushButton(centralwidget);
        btnSalir->setObjectName("btnSalir");
        btnSalir->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(btnSalir);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuArchivo = new QMenu(menubar);
        menuArchivo->setObjectName("menuArchivo");
        menuAyuda = new QMenu(menubar);
        menuAyuda->setObjectName("menuAyuda");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuArchivo->menuAction());
        menubar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionCargar);
        menuArchivo->addAction(actionSalir);
        menuAyuda->addAction(actionAcerca_de);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sistema de Gesti\303\263n de B\303\263vedas", nullptr));
        actionGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar datos", nullptr));
        actionCargar->setText(QCoreApplication::translate("MainWindow", "Cargar datos", nullptr));
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        actionAcerca_de->setText(QCoreApplication::translate("MainWindow", "Acerca de...", nullptr));
        labelTitulo->setText(QCoreApplication::translate("MainWindow", "<h1>Sistema de Gesti\303\263n de Operaciones entre B\303\263vedas</h1>", nullptr));
        btnRegistrarOperacion->setText(QCoreApplication::translate("MainWindow", "Registrar Nueva Operaci\303\263n", nullptr));
        btnVerOperaciones->setText(QCoreApplication::translate("MainWindow", "Ver Operaciones Registradas", nullptr));
        btnFiltrarOperaciones->setText(QCoreApplication::translate("MainWindow", "Filtrar Operaciones", nullptr));
        btnSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuAyuda->setTitle(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
