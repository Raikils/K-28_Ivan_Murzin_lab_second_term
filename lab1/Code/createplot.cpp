#include "createplot.h"
#include "ui_createplot.h"
#include <QColorDialog>

CreatePlot::CreatePlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePlot)
{
    ui->setupUi(this);
    connect(this,SIGNAL(CreateNewPlot(Plot)),parent,SLOT(CreateNewPlot(Plot)));
    connect(this,SIGNAL(DeleteCreatePlot()),parent,SLOT(DeleteCreatePlot()));
    ui->comboBox_backcolor->addItem("whiet");
    ui->comboBox_backcolor->addItem("red");
    ui->comboBox_backcolor->addItem("green");
    ui->comboBox_backcolor->addItem("blue");
    ui->comboBox_backcolor->addItem("yellow");
    ui->comboBox_backcolor->addItem("pink");
    ui->comboBox_backcolor->addItem("aqua");
    ui->comboBox_backcolor->addItem("black");
    ui->comboBox_backcolor->addItem("created");

    ui->comboBox_barcolor->addItem("red");
    ui->comboBox_barcolor->addItem("green");
    ui->comboBox_barcolor->addItem("blue");
    ui->comboBox_barcolor->addItem("yellow");
    ui->comboBox_barcolor->addItem("pink");
    ui->comboBox_barcolor->addItem("aqua");
    ui->comboBox_barcolor->addItem("whiet");
    ui->comboBox_barcolor->addItem("black");
    ui->comboBox_barcolor->addItem("created");
    ui->comboBox_cur_bar->addItem("1");

    num = 1;
    plot.setTicker({1,2,3});
    plot.setMain_x(true);
    plot.setBackground(QColor(255, 255, 255));
    plot.setColor_bars({QColor(255, 0, 0)});
    plot.setName_bars({""});
    plot.setNum(1);
    plot.setLegend(false);
    plot.setXAxis("x");
    plot.setYAxis("y");
    plot.setData({{2,5,9}});
    plot.setTicks_name({"1","2","3"});
    plot.build(ui->customPlot);
}

CreatePlot::~CreatePlot()
{
    delete ui;
}

void CreatePlot::on_OkButton_clicked()
{
    close();
    emit CreateNewPlot(plot);
}

void CreatePlot::on_CancelButton_clicked()
{
    emit DeleteCreatePlot();
}

void CreatePlot::on_comboBox_backcolor_currentIndexChanged(const QString &arg1)
{
    if (num == 0) return;
    if (arg1 == "red") {
        plot.setBackground(QColor(255,0,0));
    }
    if (arg1 == "green") {
        plot.setBackground(QColor(0,255,0));
    }
    if (arg1 == "blue") {
        plot.setBackground(QColor(0,0,255));
    }
    if (arg1 == "whiet") {
        plot.setBackground(QColor(255,255,255));
    }
    if (arg1 == "yellow") {
        plot.setBackground(QColor(255,255,0));
    }
    if (arg1 == "pink") {
        plot.setBackground(QColor(255,0,255));
    }
    if (arg1 == "aqua") {
        plot.setBackground(QColor(0,255,255));
    }
    if (arg1 == "black") {
        plot.setBackground(QColor(0,0,0));
    }
    if (arg1 == "created") {
        QColor col = QColorDialog::getColor(Qt::white,this,"choose color");
        plot.setBackground(col);
    }
    plot.build(ui->customPlot);
}

void CreatePlot::on_comboBox_barcolor_currentIndexChanged(const QString &arg1)
{
    if(num == 0) return;
    int i = ui->comboBox_cur_bar->currentIndex();
    if (arg1 == "red") {
        plot.setColor_bar(i, QColor(255, 0, 0));
    }
    if (arg1 == "green") {
        plot.setColor_bar(i, QColor(0, 255, 0));
    }
    if (arg1 == "blue") {
        plot.setColor_bar(i, QColor(0, 0, 255));
    }
    if (arg1 == "whiet") {
        plot.setColor_bar(i, QColor(255, 255, 255));
    }
    if (arg1 == "yellow") {
        plot.setColor_bar(i, QColor(255, 255, 0));
    }
    if (arg1 == "pink") {
        plot.setColor_bar(i, QColor(255, 0, 255));
    }
    if (arg1 == "aqua") {
        plot.setColor_bar(i, QColor(0, 255, 255));
    }
    if (arg1 == "black") {
        plot.setColor_bar(i, QColor(0, 0, 0));
    }
    if (arg1 == "created") {
        QColor col = QColorDialog::getColor(Qt::white,this,"choose color");
        plot.setColor_bar(i, col);
    }
    plot.build(ui->customPlot);
}

void CreatePlot::on_spinBox_num_bars_valueChanged(int arg1)
{
    if (num == 0) return;
    if (plot.num() == arg1) return;
    if (plot.num() > arg1) {
        QVector<QColor> x = plot.color_bars();
        x.resize(arg1);
        plot.setColor_bars(x);
        QVector<QString> y = plot.name_bars();
        y.resize(arg1);
        plot.setName_bars(y);
        int i = plot.num();
        plot.setNum(arg1);
        ui->comboBox_cur_bar->setCurrentIndex(0);
        while (i > arg1) {
            ui->comboBox_cur_bar->removeItem(i - 1);
            i--;
        }
        plot.build(ui->customPlot);
    }
    else {
        while (plot.num() < arg1) {
            plot.addName_bar("");
            plot.addColor_bar(QColor(0, 255, 0));
            plot.addData({2,5,9});
            ui->comboBox_cur_bar->addItem(QString::number(plot.num() + 1));
            plot.setNum(plot.num() + 1);
        }
    }
    plot.build(ui->customPlot);
}

void CreatePlot::on_lineEdit_xAxis_textChanged(const QString &arg1)
{
    plot.setXAxis(arg1);
    plot.build(ui->customPlot);
}

void CreatePlot::on_checkBox_legend_stateChanged(int arg1)
{
    plot.setLegend(arg1);
    plot.build(ui->customPlot);
}

void CreatePlot::on_lineEdit_bar_name_textChanged(const QString &arg1)
{
    plot.setName_bar(ui->comboBox_cur_bar->currentIndex(), arg1);
    plot.build(ui->customPlot);
}

void CreatePlot::on_comboBox_cur_bar_currentIndexChanged(int index)
{
    if (num == 0) return;
    if (plot.color_bars(index) == QColor(255,0,0)) {
        ui->comboBox_barcolor->setCurrentIndex(0);
    } else
    if (plot.color_bars(index) == QColor(0,255,0)) {
        ui->comboBox_barcolor->setCurrentIndex(1);
    } else
    if (plot.color_bars(index) == QColor(0,0,255)) {
        ui->comboBox_barcolor->setCurrentIndex(2);
    } else
    if (plot.color_bars(index) == QColor(255,255,0)) {
        ui->comboBox_barcolor->setCurrentIndex(3);
    } else
    if (plot.color_bars(index) == QColor(0,255,255)) {
        ui->comboBox_barcolor->setCurrentIndex(4);
    } else
    if (plot.color_bars(index) == QColor(255,0,255)) {
        ui->comboBox_barcolor->setCurrentIndex(5);
    } else
    if (plot.color_bars(index) == QColor(255,255,255)) {
        ui->comboBox_barcolor->setCurrentIndex(6);
    } else
    if (plot.color_bars(index) == QColor(0, 0, 0)) {
        ui->comboBox_barcolor->setCurrentIndex(7);
    } else {
        ui->comboBox_barcolor->setCurrentIndex(8);
    }
    ui->lineEdit_bar_name->setText(plot.name_bars(index));
    plot.build(ui->customPlot);
}

void CreatePlot::on_lineEdit_yAxis_textChanged(const QString &arg1)
{
    plot.setYAxis(arg1);
    plot.build(ui->customPlot);
}
