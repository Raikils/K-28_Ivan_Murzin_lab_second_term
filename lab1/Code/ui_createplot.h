/********************************************************************************
** Form generated from reading UI file 'createplot.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPLOT_H
#define UI_CREATEPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_CreatePlot
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QCustomPlot *customPlot;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEdit_name;
    QCheckBox *checkBox_legend;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_backcolor;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpinBox *spinBox_num_bars;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBox_cur_bar;
    QLabel *label_2;
    QComboBox *comboBox_barcolor;
    QLabel *label_6;
    QLineEdit *lineEdit_bar_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit_xAxis;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEdit_yAxis;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *OkButton;
    QPushButton *CancelButton;

    void setupUi(QDialog *CreatePlot)
    {
        if (CreatePlot->objectName().isEmpty())
            CreatePlot->setObjectName(QString::fromUtf8("CreatePlot"));
        CreatePlot->resize(914, 423);
        verticalLayout_2 = new QVBoxLayout(CreatePlot);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        customPlot = new QCustomPlot(CreatePlot);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setMinimumSize(QSize(301, 241));
        customPlot->setMaximumSize(QSize(301, 241));

        horizontalLayout_7->addWidget(customPlot);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEdit_name = new QLineEdit(CreatePlot);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setMaxLength(20);

        horizontalLayout_6->addWidget(lineEdit_name);

        checkBox_legend = new QCheckBox(CreatePlot);
        checkBox_legend->setObjectName(QString::fromUtf8("checkBox_legend"));

        horizontalLayout_6->addWidget(checkBox_legend);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CreatePlot);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox_backcolor = new QComboBox(CreatePlot);
        comboBox_backcolor->setObjectName(QString::fromUtf8("comboBox_backcolor"));

        horizontalLayout->addWidget(comboBox_backcolor);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(CreatePlot);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        spinBox_num_bars = new QSpinBox(CreatePlot);
        spinBox_num_bars->setObjectName(QString::fromUtf8("spinBox_num_bars"));
        spinBox_num_bars->setMinimum(1);
        spinBox_num_bars->setMaximum(8);

        horizontalLayout_2->addWidget(spinBox_num_bars);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboBox_cur_bar = new QComboBox(CreatePlot);
        comboBox_cur_bar->setObjectName(QString::fromUtf8("comboBox_cur_bar"));

        horizontalLayout_3->addWidget(comboBox_cur_bar);

        label_2 = new QLabel(CreatePlot);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        comboBox_barcolor = new QComboBox(CreatePlot);
        comboBox_barcolor->setObjectName(QString::fromUtf8("comboBox_barcolor"));

        horizontalLayout_3->addWidget(comboBox_barcolor);

        label_6 = new QLabel(CreatePlot);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_3->addWidget(label_6);

        lineEdit_bar_name = new QLineEdit(CreatePlot);
        lineEdit_bar_name->setObjectName(QString::fromUtf8("lineEdit_bar_name"));
        lineEdit_bar_name->setMinimumSize(QSize(0, 0));
        lineEdit_bar_name->setMaxLength(20);

        horizontalLayout_3->addWidget(lineEdit_bar_name);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(CreatePlot);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        lineEdit_xAxis = new QLineEdit(CreatePlot);
        lineEdit_xAxis->setObjectName(QString::fromUtf8("lineEdit_xAxis"));
        lineEdit_xAxis->setMaxLength(20);

        horizontalLayout_4->addWidget(lineEdit_xAxis);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(CreatePlot);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        lineEdit_yAxis = new QLineEdit(CreatePlot);
        lineEdit_yAxis->setObjectName(QString::fromUtf8("lineEdit_yAxis"));
        lineEdit_yAxis->setMaxLength(20);

        horizontalLayout_5->addWidget(lineEdit_yAxis);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_7->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        OkButton = new QPushButton(CreatePlot);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        OkButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(OkButton);

        CancelButton = new QPushButton(CreatePlot);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(CancelButton);


        verticalLayout_2->addLayout(horizontalLayout_8);


        retranslateUi(CreatePlot);

        QMetaObject::connectSlotsByName(CreatePlot);
    } // setupUi

    void retranslateUi(QDialog *CreatePlot)
    {
        CreatePlot->setWindowTitle(QCoreApplication::translate("CreatePlot", "Dialog", nullptr));
        checkBox_legend->setText(QCoreApplication::translate("CreatePlot", "Legend", nullptr));
        label->setText(QCoreApplication::translate("CreatePlot", "Background color:", nullptr));
        label_5->setText(QCoreApplication::translate("CreatePlot", "Number of bars", nullptr));
        label_2->setText(QCoreApplication::translate("CreatePlot", "Bar color:", nullptr));
        label_6->setText(QCoreApplication::translate("CreatePlot", "Bar name:", nullptr));
        label_3->setText(QCoreApplication::translate("CreatePlot", "xAxis", nullptr));
        lineEdit_xAxis->setText(QCoreApplication::translate("CreatePlot", "x", nullptr));
        label_4->setText(QCoreApplication::translate("CreatePlot", "yAxis", nullptr));
        lineEdit_yAxis->setText(QCoreApplication::translate("CreatePlot", "y", nullptr));
        OkButton->setText(QCoreApplication::translate("CreatePlot", "Ok", nullptr));
        CancelButton->setText(QCoreApplication::translate("CreatePlot", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreatePlot: public Ui_CreatePlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPLOT_H
