/********************************************************************************
** Form generated from reading UI file 'listadooperaciones.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTADOOPERACIONES_H
#define UI_LISTADOOPERACIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ListadoOperaciones
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableOperaciones;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnDetalles;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCerrar;

    void setupUi(QDialog *ListadoOperaciones)
    {
        if (ListadoOperaciones->objectName().isEmpty())
            ListadoOperaciones->setObjectName("ListadoOperaciones");
        ListadoOperaciones->resize(900, 600);
        verticalLayout = new QVBoxLayout(ListadoOperaciones);
        verticalLayout->setObjectName("verticalLayout");
        tableOperaciones = new QTableWidget(ListadoOperaciones);
        tableOperaciones->setObjectName("tableOperaciones");
        tableOperaciones->setSelectionMode(QAbstractItemView::SingleSelection);
        tableOperaciones->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(tableOperaciones);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnDetalles = new QPushButton(ListadoOperaciones);
        btnDetalles->setObjectName("btnDetalles");

        horizontalLayout->addWidget(btnDetalles);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCerrar = new QPushButton(ListadoOperaciones);
        btnCerrar->setObjectName("btnCerrar");

        horizontalLayout->addWidget(btnCerrar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ListadoOperaciones);

        QMetaObject::connectSlotsByName(ListadoOperaciones);
    } // setupUi

    void retranslateUi(QDialog *ListadoOperaciones)
    {
        ListadoOperaciones->setWindowTitle(QCoreApplication::translate("ListadoOperaciones", "Operaciones Registradas", nullptr));
        btnDetalles->setText(QCoreApplication::translate("ListadoOperaciones", "Ver Detalles", nullptr));
        btnCerrar->setText(QCoreApplication::translate("ListadoOperaciones", "Cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ListadoOperaciones: public Ui_ListadoOperaciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTADOOPERACIONES_H
