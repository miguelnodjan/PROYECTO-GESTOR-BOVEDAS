/********************************************************************************
** Form generated from reading UI file 'detallesOperacion.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETALLESOPERACION_H
#define UI_DETALLESOPERACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DetallesOperacion
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *labelIdLabel;
    QLabel *labelId;
    QLabel *labelFechaLabel;
    QLabel *labelFecha;
    QLabel *labelTipoLabel;
    QLabel *labelTipo;
    QLabel *labelOrigenLabel;
    QLabel *labelOrigen;
    QLabel *labelDestinoLabel;
    QLabel *labelDestino;
    QLabel *labelPlazaLabel;
    QLabel *labelPlaza;
    QLabel *labelTransportadoraLabel;
    QLabel *labelTransportadora;
    QLabel *labelMonedaLabel;
    QLabel *labelMoneda;
    QLabel *labelMonedaDestinoLabel;
    QLabel *labelMonedaDestino;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableDenominaciones;
    QLabel *labelTotal;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DetallesOperacion)
    {
        if (DetallesOperacion->objectName().isEmpty())
            DetallesOperacion->setObjectName("DetallesOperacion");
        DetallesOperacion->resize(600, 500);
        verticalLayout = new QVBoxLayout(DetallesOperacion);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(DetallesOperacion);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        labelIdLabel = new QLabel(groupBox);
        labelIdLabel->setObjectName("labelIdLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelIdLabel);

        labelId = new QLabel(groupBox);
        labelId->setObjectName("labelId");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, labelId);

        labelFechaLabel = new QLabel(groupBox);
        labelFechaLabel->setObjectName("labelFechaLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelFechaLabel);

        labelFecha = new QLabel(groupBox);
        labelFecha->setObjectName("labelFecha");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, labelFecha);

        labelTipoLabel = new QLabel(groupBox);
        labelTipoLabel->setObjectName("labelTipoLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelTipoLabel);

        labelTipo = new QLabel(groupBox);
        labelTipo->setObjectName("labelTipo");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, labelTipo);

        labelOrigenLabel = new QLabel(groupBox);
        labelOrigenLabel->setObjectName("labelOrigenLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelOrigenLabel);

        labelOrigen = new QLabel(groupBox);
        labelOrigen->setObjectName("labelOrigen");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, labelOrigen);

        labelDestinoLabel = new QLabel(groupBox);
        labelDestinoLabel->setObjectName("labelDestinoLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, labelDestinoLabel);

        labelDestino = new QLabel(groupBox);
        labelDestino->setObjectName("labelDestino");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, labelDestino);

        labelPlazaLabel = new QLabel(groupBox);
        labelPlazaLabel->setObjectName("labelPlazaLabel");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, labelPlazaLabel);

        labelPlaza = new QLabel(groupBox);
        labelPlaza->setObjectName("labelPlaza");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, labelPlaza);

        labelTransportadoraLabel = new QLabel(groupBox);
        labelTransportadoraLabel->setObjectName("labelTransportadoraLabel");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, labelTransportadoraLabel);

        labelTransportadora = new QLabel(groupBox);
        labelTransportadora->setObjectName("labelTransportadora");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, labelTransportadora);

        labelMonedaLabel = new QLabel(groupBox);
        labelMonedaLabel->setObjectName("labelMonedaLabel");

        formLayout->setWidget(7, QFormLayout::ItemRole::LabelRole, labelMonedaLabel);

        labelMoneda = new QLabel(groupBox);
        labelMoneda->setObjectName("labelMoneda");

        formLayout->setWidget(7, QFormLayout::ItemRole::FieldRole, labelMoneda);

        labelMonedaDestinoLabel = new QLabel(groupBox);
        labelMonedaDestinoLabel->setObjectName("labelMonedaDestinoLabel");

        formLayout->setWidget(8, QFormLayout::ItemRole::LabelRole, labelMonedaDestinoLabel);

        labelMonedaDestino = new QLabel(groupBox);
        labelMonedaDestino->setObjectName("labelMonedaDestino");

        formLayout->setWidget(8, QFormLayout::ItemRole::FieldRole, labelMonedaDestino);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(DetallesOperacion);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableDenominaciones = new QTableWidget(groupBox_2);
        tableDenominaciones->setObjectName("tableDenominaciones");

        verticalLayout_2->addWidget(tableDenominaciones);

        labelTotal = new QLabel(groupBox_2);
        labelTotal->setObjectName("labelTotal");
        labelTotal->setAlignment(Qt::AlignRight);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        labelTotal->setFont(font);

        verticalLayout_2->addWidget(labelTotal);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(DetallesOperacion);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DetallesOperacion);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DetallesOperacion, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DetallesOperacion, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DetallesOperacion);
    } // setupUi

    void retranslateUi(QDialog *DetallesOperacion)
    {
        DetallesOperacion->setWindowTitle(QCoreApplication::translate("DetallesOperacion", "Detalles de Operaci\303\263n", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DetallesOperacion", "Informaci\303\263n General", nullptr));
        labelIdLabel->setText(QCoreApplication::translate("DetallesOperacion", "ID:", nullptr));
        labelFechaLabel->setText(QCoreApplication::translate("DetallesOperacion", "Fecha:", nullptr));
        labelTipoLabel->setText(QCoreApplication::translate("DetallesOperacion", "Tipo:", nullptr));
        labelOrigenLabel->setText(QCoreApplication::translate("DetallesOperacion", "Origen:", nullptr));
        labelDestinoLabel->setText(QCoreApplication::translate("DetallesOperacion", "Destino:", nullptr));
        labelPlazaLabel->setText(QCoreApplication::translate("DetallesOperacion", "Plaza:", nullptr));
        labelTransportadoraLabel->setText(QCoreApplication::translate("DetallesOperacion", "Transportadora:", nullptr));
        labelMonedaLabel->setText(QCoreApplication::translate("DetallesOperacion", "Moneda:", nullptr));
        labelMonedaDestinoLabel->setText(QCoreApplication::translate("DetallesOperacion", "Moneda Destino:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("DetallesOperacion", "Denominaciones", nullptr));
        labelTotal->setText(QCoreApplication::translate("DetallesOperacion", "Total: $0.00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DetallesOperacion: public Ui_DetallesOperacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETALLESOPERACION_H
