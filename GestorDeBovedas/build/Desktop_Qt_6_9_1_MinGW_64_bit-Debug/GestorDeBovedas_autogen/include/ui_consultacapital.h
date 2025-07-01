/********************************************************************************
** Form generated from reading UI file 'consultacapital.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSULTACAPITAL_H
#define UI_CONSULTACAPITAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConsultaCapital
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *labelTipo;
    QComboBox *comboTipo;
    QLabel *labelEntidad;
    QComboBox *comboEntidad;
    QLabel *labelMoneda;
    QComboBox *comboMoneda;
    QLabel *labelResultado;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConsultar;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCerrar;

    void setupUi(QDialog *ConsultaCapital)
    {
        if (ConsultaCapital->objectName().isEmpty())
            ConsultaCapital->setObjectName("ConsultaCapital");
        ConsultaCapital->resize(500, 300);
        verticalLayout = new QVBoxLayout(ConsultaCapital);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(ConsultaCapital);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        labelTipo = new QLabel(groupBox);
        labelTipo->setObjectName("labelTipo");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelTipo);

        comboTipo = new QComboBox(groupBox);
        comboTipo->setObjectName("comboTipo");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboTipo);

        labelEntidad = new QLabel(groupBox);
        labelEntidad->setObjectName("labelEntidad");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelEntidad);

        comboEntidad = new QComboBox(groupBox);
        comboEntidad->setObjectName("comboEntidad");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboEntidad);

        labelMoneda = new QLabel(groupBox);
        labelMoneda->setObjectName("labelMoneda");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelMoneda);

        comboMoneda = new QComboBox(groupBox);
        comboMoneda->setObjectName("comboMoneda");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboMoneda);


        verticalLayout->addWidget(groupBox);

        labelResultado = new QLabel(ConsultaCapital);
        labelResultado->setObjectName("labelResultado");
        labelResultado->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        labelResultado->setFont(font);

        verticalLayout->addWidget(labelResultado);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnConsultar = new QPushButton(ConsultaCapital);
        btnConsultar->setObjectName("btnConsultar");

        horizontalLayout->addWidget(btnConsultar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCerrar = new QPushButton(ConsultaCapital);
        btnCerrar->setObjectName("btnCerrar");

        horizontalLayout->addWidget(btnCerrar);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ConsultaCapital);

        QMetaObject::connectSlotsByName(ConsultaCapital);
    } // setupUi

    void retranslateUi(QDialog *ConsultaCapital)
    {
        ConsultaCapital->setWindowTitle(QCoreApplication::translate("ConsultaCapital", "Consultar Capital", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ConsultaCapital", "Consulta", nullptr));
        labelTipo->setText(QCoreApplication::translate("ConsultaCapital", "Tipo:", nullptr));
        labelEntidad->setText(QCoreApplication::translate("ConsultaCapital", "Entidad:", nullptr));
        labelMoneda->setText(QCoreApplication::translate("ConsultaCapital", "Moneda:", nullptr));
        labelResultado->setText(QCoreApplication::translate("ConsultaCapital", "Resultado:", nullptr));
        btnConsultar->setText(QCoreApplication::translate("ConsultaCapital", "Consultar", nullptr));
        btnCerrar->setText(QCoreApplication::translate("ConsultaCapital", "Cerrar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConsultaCapital: public Ui_ConsultaCapital {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSULTACAPITAL_H
