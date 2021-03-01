/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_6;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spinBox_cur_tick;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_tick_name;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_cur_bar;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_cur_data;
    QPushButton *pushButton_Delete;
    QVBoxLayout *verticalLayout_5;
    QListWidget *listWidget;
    QPushButton *CreateButton;
    QPushButton *pushButton_save_png;
    QPushButton *pushButton_save_jpg;
    QPushButton *pushButton_save_pdf;
    QPushButton *pushButton_delete_plot;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(964, 535);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMinimumSize(QSize(300, 0));

        horizontalLayout_2->addWidget(tableView);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setMinimumSize(QSize(531, 401));
        customPlot->setMaximumSize(QSize(531, 401));

        verticalLayout_6->addWidget(customPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        spinBox_cur_tick = new QSpinBox(centralwidget);
        spinBox_cur_tick->setObjectName(QString::fromUtf8("spinBox_cur_tick"));
        spinBox_cur_tick->setMinimum(1);

        verticalLayout->addWidget(spinBox_cur_tick);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        lineEdit_tick_name = new QLineEdit(centralwidget);
        lineEdit_tick_name->setObjectName(QString::fromUtf8("lineEdit_tick_name"));
        lineEdit_tick_name->setMaxLength(20);

        verticalLayout_2->addWidget(lineEdit_tick_name);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        comboBox_cur_bar = new QComboBox(centralwidget);
        comboBox_cur_bar->setObjectName(QString::fromUtf8("comboBox_cur_bar"));

        verticalLayout_3->addWidget(comboBox_cur_bar);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout_4->addWidget(label_4);

        doubleSpinBox_cur_data = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_cur_data->setObjectName(QString::fromUtf8("doubleSpinBox_cur_data"));
        doubleSpinBox_cur_data->setMinimum(-100.000000000000000);
        doubleSpinBox_cur_data->setMaximum(100.000000000000000);

        verticalLayout_4->addWidget(doubleSpinBox_cur_data);


        horizontalLayout->addLayout(verticalLayout_4);

        pushButton_Delete = new QPushButton(centralwidget);
        pushButton_Delete->setObjectName(QString::fromUtf8("pushButton_Delete"));

        horizontalLayout->addWidget(pushButton_Delete);


        verticalLayout_6->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(125, 0));

        verticalLayout_5->addWidget(listWidget);

        CreateButton = new QPushButton(centralwidget);
        CreateButton->setObjectName(QString::fromUtf8("CreateButton"));

        verticalLayout_5->addWidget(CreateButton);

        pushButton_save_png = new QPushButton(centralwidget);
        pushButton_save_png->setObjectName(QString::fromUtf8("pushButton_save_png"));

        verticalLayout_5->addWidget(pushButton_save_png);

        pushButton_save_jpg = new QPushButton(centralwidget);
        pushButton_save_jpg->setObjectName(QString::fromUtf8("pushButton_save_jpg"));

        verticalLayout_5->addWidget(pushButton_save_jpg);

        pushButton_save_pdf = new QPushButton(centralwidget);
        pushButton_save_pdf->setObjectName(QString::fromUtf8("pushButton_save_pdf"));

        verticalLayout_5->addWidget(pushButton_save_pdf);

        pushButton_delete_plot = new QPushButton(centralwidget);
        pushButton_delete_plot->setObjectName(QString::fromUtf8("pushButton_delete_plot"));

        verticalLayout_5->addWidget(pushButton_delete_plot);


        horizontalLayout_2->addLayout(verticalLayout_5);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 964, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ChartCreater", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Cur. group:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Group name:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Cur. bar:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Data:", nullptr));
        pushButton_Delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        CreateButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        pushButton_save_png->setText(QCoreApplication::translate("MainWindow", "Save(png)", nullptr));
        pushButton_save_jpg->setText(QCoreApplication::translate("MainWindow", "Save(jpg)", nullptr));
        pushButton_save_pdf->setText(QCoreApplication::translate("MainWindow", "Save(pdf)", nullptr));
        pushButton_delete_plot->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
