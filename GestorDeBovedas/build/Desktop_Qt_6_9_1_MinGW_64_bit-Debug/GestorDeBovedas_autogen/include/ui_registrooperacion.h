/********************************************************************************
** Form generated from reading UI file 'registrooperacion.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTROOPERACION_H
#define UI_REGISTROOPERACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegistroOperacion
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxDatos;
    QFormLayout *formLayout;
    QLabel *labelTipo;
    QComboBox *comboTipo;
    QLabel *labelOrigen;
    QComboBox *comboOrigen;
    QLabel *labelDestino;
    QComboBox *comboDestino;
    QLabel *labelPlaza;
    QComboBox *comboPlaza;
    QLabel *labelTransportadora;
    QComboBox *comboTransportadora;
    QLabel *labelMoneda;
    QComboBox *comboMoneda;
    QLabel *labelMonedaDestino;
    QComboBox *comboMonedaDestino;
    QGroupBox *groupBoxDenominaciones;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelValor;
    QSpinBox *spinValor;
    QLabel *labelCantidad;
    QSpinBox *spinCantidad;
    QPushButton *btnAgregarDenominacion;
    QTableWidget *tableDenominaciones;
    QLabel *labelTotal;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnCancelar;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRegistrar;

    void setupUi(QDialog *RegistroOperacion)
    {
        if (RegistroOperacion->objectName().isEmpty())
            RegistroOperacion->setObjectName("RegistroOperacion");
        RegistroOperacion->resize(600, 700);
        verticalLayout = new QVBoxLayout(RegistroOperacion);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxDatos = new QGroupBox(RegistroOperacion);
        groupBoxDatos->setObjectName("groupBoxDatos");
        formLayout = new QFormLayout(groupBoxDatos);
        formLayout->setObjectName("formLayout");
        labelTipo = new QLabel(groupBoxDatos);
        labelTipo->setObjectName("labelTipo");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelTipo);

        comboTipo = new QComboBox(groupBoxDatos);
        comboTipo->setObjectName("comboTipo");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboTipo);

        labelOrigen = new QLabel(groupBoxDatos);
        labelOrigen->setObjectName("labelOrigen");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelOrigen);

        comboOrigen = new QComboBox(groupBoxDatos);
        comboOrigen->setObjectName("comboOrigen");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboOrigen);

        labelDestino = new QLabel(groupBoxDatos);
        labelDestino->setObjectName("labelDestino");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelDestino);

        comboDestino = new QComboBox(groupBoxDatos);
        comboDestino->setObjectName("comboDestino");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboDestino);

        labelPlaza = new QLabel(groupBoxDatos);
        labelPlaza->setObjectName("labelPlaza");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelPlaza);

        comboPlaza = new QComboBox(groupBoxDatos);
        comboPlaza->setObjectName("comboPlaza");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, comboPlaza);

        labelTransportadora = new QLabel(groupBoxDatos);
        labelTransportadora->setObjectName("labelTransportadora");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelTransportadora);

        comboTransportadora = new QComboBox(groupBoxDatos);
        comboTransportadora->setObjectName("comboTransportadora");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, comboTransportadora);

        labelMoneda = new QLabel(groupBoxDatos);
        labelMoneda->setObjectName("labelMoneda");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, labelMoneda);

        comboMoneda = new QComboBox(groupBoxDatos);
        comboMoneda->setObjectName("comboMoneda");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, comboMoneda);

        labelMonedaDestino = new QLabel(groupBoxDatos);
        labelMonedaDestino->setObjectName("labelMonedaDestino");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, labelMonedaDestino);

        comboMonedaDestino = new QComboBox(groupBoxDatos);
        comboMonedaDestino->setObjectName("comboMonedaDestino");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, comboMonedaDestino);


        verticalLayout->addWidget(groupBoxDatos);

        groupBoxDenominaciones = new QGroupBox(RegistroOperacion);
        groupBoxDenominaciones->setObjectName("groupBoxDenominaciones");
        verticalLayout_2 = new QVBoxLayout(groupBoxDenominaciones);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labelValor = new QLabel(groupBoxDenominaciones);
        labelValor->setObjectName("labelValor");

        horizontalLayout->addWidget(labelValor);

        spinValor = new QSpinBox(groupBoxDenominaciones);
        spinValor->setObjectName("spinValor");
        spinValor->setMinimum(1);
        spinValor->setMaximum(100000);

        horizontalLayout->addWidget(spinValor);

        labelCantidad = new QLabel(groupBoxDenominaciones);
        labelCantidad->setObjectName("labelCantidad");

        horizontalLayout->addWidget(labelCantidad);

        spinCantidad = new QSpinBox(groupBoxDenominaciones);
        spinCantidad->setObjectName("spinCantidad");
        spinCantidad->setMinimum(1);

        horizontalLayout->addWidget(spinCantidad);

        btnAgregarDenominacion = new QPushButton(groupBoxDenominaciones);
        btnAgregarDenominacion->setObjectName("btnAgregarDenominacion");

        horizontalLayout->addWidget(btnAgregarDenominacion);


        verticalLayout_2->addLayout(horizontalLayout);

        tableDenominaciones = new QTableWidget(groupBoxDenominaciones);
        if (tableDenominaciones->columnCount() < 3)
            tableDenominaciones->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableDenominaciones->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableDenominaciones->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableDenominaciones->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableDenominaciones->setObjectName("tableDenominaciones");

        verticalLayout_2->addWidget(tableDenominaciones);


        verticalLayout->addWidget(groupBoxDenominaciones);

        labelTotal = new QLabel(RegistroOperacion);
        labelTotal->setObjectName("labelTotal");
        labelTotal->setAlignment(Qt::AlignRight);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        labelTotal->setFont(font);

        verticalLayout->addWidget(labelTotal);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnCancelar = new QPushButton(RegistroOperacion);
        btnCancelar->setObjectName("btnCancelar");

        horizontalLayout_2->addWidget(btnCancelar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnRegistrar = new QPushButton(RegistroOperacion);
        btnRegistrar->setObjectName("btnRegistrar");

        horizontalLayout_2->addWidget(btnRegistrar);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(RegistroOperacion);

        QMetaObject::connectSlotsByName(RegistroOperacion);
    } // setupUi

    void retranslateUi(QDialog *RegistroOperacion)
    {
        RegistroOperacion->setWindowTitle(QCoreApplication::translate("RegistroOperacion", "Registrar Nueva Operaci\303\263n", nullptr));
        groupBoxDatos->setTitle(QCoreApplication::translate("RegistroOperacion", "Datos de la Operaci\303\263n", nullptr));
        labelTipo->setText(QCoreApplication::translate("RegistroOperacion", "Tipo de Operaci\303\263n:", nullptr));
        labelOrigen->setText(QCoreApplication::translate("RegistroOperacion", "Origen:", nullptr));
        labelDestino->setText(QCoreApplication::translate("RegistroOperacion", "Destino:", nullptr));
        labelPlaza->setText(QCoreApplication::translate("RegistroOperacion", "Plaza:", nullptr));
        labelTransportadora->setText(QCoreApplication::translate("RegistroOperacion", "Transportadora:", nullptr));
        labelMoneda->setText(QCoreApplication::translate("RegistroOperacion", "Moneda:", nullptr));
        labelMonedaDestino->setText(QCoreApplication::translate("RegistroOperacion", "Moneda Destino (solo canje):", nullptr));
        groupBoxDenominaciones->setTitle(QCoreApplication::translate("RegistroOperacion", "Denominaciones", nullptr));
        labelValor->setText(QCoreApplication::translate("RegistroOperacion", "Valor:", nullptr));
        labelCantidad->setText(QCoreApplication::translate("RegistroOperacion", "Cantidad:", nullptr));
        btnAgregarDenominacion->setText(QCoreApplication::translate("RegistroOperacion", "Agregar", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableDenominaciones->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RegistroOperacion", "Valor", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableDenominaciones->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RegistroOperacion", "Cantidad", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableDenominaciones->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("RegistroOperacion", "Subtotal", nullptr));
        labelTotal->setText(QCoreApplication::translate("RegistroOperacion", "Total: $0.00", nullptr));
        btnCancelar->setText(QCoreApplication::translate("RegistroOperacion", "Cancelar", nullptr));
        btnRegistrar->setText(QCoreApplication::translate("RegistroOperacion", "Registrar Operaci\303\263n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegistroOperacion: public Ui_RegistroOperacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTROOPERACION_H
