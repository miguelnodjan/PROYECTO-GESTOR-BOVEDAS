/********************************************************************************
** Form generated from reading UI file 'filtros.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTROS_H
#define UI_FILTROS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Filtros
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxFiltros;
    QFormLayout *formLayout;
    QLabel *labelTipo;
    QComboBox *comboTipo;
    QLabel *labelFechaInicio;
    QDateEdit *dateEditInicio;
    QLabel *labelFechaFin;
    QDateEdit *dateEditFin;
    QLabel *labelPlaza;
    QComboBox *comboPlaza;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnFiltrar;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancelar;

    void setupUi(QDialog *Filtros)
    {
        if (Filtros->objectName().isEmpty())
            Filtros->setObjectName("Filtros");
        Filtros->resize(500, 400);
        verticalLayout = new QVBoxLayout(Filtros);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxFiltros = new QGroupBox(Filtros);
        groupBoxFiltros->setObjectName("groupBoxFiltros");
        formLayout = new QFormLayout(groupBoxFiltros);
        formLayout->setObjectName("formLayout");
        labelTipo = new QLabel(groupBoxFiltros);
        labelTipo->setObjectName("labelTipo");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelTipo);

        comboTipo = new QComboBox(groupBoxFiltros);
        comboTipo->setObjectName("comboTipo");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboTipo);

        labelFechaInicio = new QLabel(groupBoxFiltros);
        labelFechaInicio->setObjectName("labelFechaInicio");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelFechaInicio);

        dateEditInicio = new QDateEdit(groupBoxFiltros);
        dateEditInicio->setObjectName("dateEditInicio");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, dateEditInicio);

        labelFechaFin = new QLabel(groupBoxFiltros);
        labelFechaFin->setObjectName("labelFechaFin");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelFechaFin);

        dateEditFin = new QDateEdit(groupBoxFiltros);
        dateEditFin->setObjectName("dateEditFin");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, dateEditFin);

        labelPlaza = new QLabel(groupBoxFiltros);
        labelPlaza->setObjectName("labelPlaza");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelPlaza);

        comboPlaza = new QComboBox(groupBoxFiltros);
        comboPlaza->setObjectName("comboPlaza");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, comboPlaza);


        verticalLayout->addWidget(groupBoxFiltros);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnFiltrar = new QPushButton(Filtros);
        btnFiltrar->setObjectName("btnFiltrar");

        horizontalLayout->addWidget(btnFiltrar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancelar = new QPushButton(Filtros);
        btnCancelar->setObjectName("btnCancelar");

        horizontalLayout->addWidget(btnCancelar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Filtros);

        QMetaObject::connectSlotsByName(Filtros);
    } // setupUi

    void retranslateUi(QDialog *Filtros)
    {
        Filtros->setWindowTitle(QCoreApplication::translate("Filtros", "Filtrar Operaciones", nullptr));
        groupBoxFiltros->setTitle(QCoreApplication::translate("Filtros", "Criterios de Filtrado", nullptr));
        labelTipo->setText(QCoreApplication::translate("Filtros", "Tipo de Operaci\303\263n:", nullptr));
        labelFechaInicio->setText(QCoreApplication::translate("Filtros", "Fecha Inicio:", nullptr));
        labelFechaFin->setText(QCoreApplication::translate("Filtros", "Fecha Fin:", nullptr));
        labelPlaza->setText(QCoreApplication::translate("Filtros", "Plaza:", nullptr));
        btnFiltrar->setText(QCoreApplication::translate("Filtros", "Filtrar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("Filtros", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Filtros: public Ui_Filtros {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTROS_H
