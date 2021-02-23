#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include <QListWidgetItem>
#include <QWinTaskbarButton>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    group = NULL;
    cur = -1;
    width << 0.3 << 0.3 << 0.15 << 0.15 << 0.1 << 0.1 << 0.06 << 0.06;
    QFile f("plots.dat");
    f.open(QIODevice::ReadOnly);
    QDataStream in(&f);
    while(!in.atEnd()) {
         Plot k;
         in >> k;
         k.setListWidgetItem(new QListWidgetItem(ui->listWidget));
         k.listWidgetItem()->setText(k.name());
         plots.push_back(k);
    }
    ui->customPlot->xAxis->setRange(0, 4);
    ui->customPlot->yAxis->setRange(0, 4);
    QWinTaskbarButton *button = new QWinTaskbarButton(this);
    button->setWindow(this->windowHandle());
    button->setOverlayIcon(QIcon(":/img/market-fluctuation.png"));

    mydelegate = new TableDelagate(this);

    model = new QStandardItemModel(this);

    ui->tableView->setModel(model);

    ui->tableView->setItemDelegate(mydelegate);
    connect(model,SIGNAL(itemChanged(QStandardItem*)),this,SLOT(TableItemChange(QStandardItem*)));
    tt = true;
    table_change_data = true;
}

MainWindow::~MainWindow()
{
    QFile f("plots.dat");
    f.open(QIODevice::WriteOnly);
    QDataStream out(&f);
    for (const auto &k : plots) {
        out << Plot(k);
    }
    delete ui;
}


void MainWindow::on_CreateButton_clicked()
{
    crpl = new CreatePlot(this);
    crpl->exec();
}

void MainWindow::CreateNewPlot(Plot p)
{
    delete crpl;

    p.setListWidgetItem(new QListWidgetItem(ui->listWidget));
    p.listWidgetItem()->setText(p.name());

    QVector<QVector<double>> data;
    for (int i = 0; i < p.num(); i++) {
        data.push_back({0});
    }
    p.setData(data);
    p.setTicker({1});
    p.setLast(0);
    p.setTicks_name({"1"});
    plots.push_back(p);
}

void MainWindow::DeleteCreatePlot()
{
    delete crpl;
}

void MainWindow::TableItemChange(QStandardItem *item)
{
    if(cur >= 0 && tt) { QVector<QVector<double>> data = plots[cur].data();
    data[item->column()][item->row()] = item->text().toDouble();
    plots[cur].setData(data);
    if (ui->comboBox_cur_bar->currentIndex() == item->column() && ui->spinBox_cur_tick->value() == item->row() + 1) {
        table_change_data = false;
        ui->doubleSpinBox_cur_data->setValue(item->text().toDouble());
    }
    if (plots[cur].last() == item->row()) {
        plots[cur].setLast(plots[cur].last() + 1);
        ui->spinBox_cur_tick->setMaximum(ui->spinBox_cur_tick->maximum() + 1);
        QVector<QVector<double>> data1 = plots[cur].data();
        for (auto &k : data1) k << 0;
        plots[cur].setData(data1);
        QVector<double> tick = plots[cur].ticker();
        tick << plots[cur].last() + 1;
        plots[cur].setTicker(tick);
        QVector<QString> labels = plots[cur].ticks_name();
        labels << QString::number(plots[cur].last() + 1);
        plots[cur].setTicks_name(labels);
    }
    plots[cur].build(ui->customPlot);
    }
    tt = true;
}

void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    int i = 0;
    for (i = 0; i < plots.size(); i++) {
        if(plots[i].listWidgetItem() == current) {
            cur = i;
            plots[cur].build(ui->customPlot);
            rebuild_table(plots[cur]);
            ui->spinBox_cur_tick->setValue(1);
            ui->spinBox_cur_tick->setMaximum(plots[i].last() + 1);
            ui->lineEdit_tick_name->setText(plots[i].ticks_name()[0]);
            ui->comboBox_cur_bar->setCurrentIndex(0);
            if (ui->comboBox_cur_bar->count() > plots[i].num())
            for (int j = 7; j >= plots[i].num(); j--) {
                ui->comboBox_cur_bar->removeItem(j);
            }
            else
            for (int l = ui->comboBox_cur_bar->count() + 1; l <= plots[i].num(); l++) {
                ui->comboBox_cur_bar->addItem(QString::number(l));
            }
            ui->doubleSpinBox_cur_data->setValue(plots[i].data()[0][0]);
            ui->customPlot->update();
            ui->customPlot->replot();
            return;
        }
    }
}

void MainWindow::rebuild_table(Plot p)
{
    tt = false;
    model->clear();
    model->setColumnCount(p.num());
    model->setRowCount(p.last() + 1);
    QStringList lab;
    for(int i = 0; i < p.num(); i++) {
        lab << p.name_bars()[i];
    }
    model->setHorizontalHeaderLabels(lab);
    lab.clear();
    for(int i = 0; i < p.last() + 1; i++) {
        lab << p.ticks_name()[i];
    }
    model->setVerticalHeaderLabels(lab);
    for(int i = 0; i < p.num(); i++) {
        for(int j = 0; j < p.last() + 1; j++) {
            tt = false;
            model->setItem(j, i, new QStandardItem(QString::number(p.data()[i][j])));
        }
    }
}

void MainWindow::on_spinBox_cur_tick_valueChanged(int arg1)
{
    ui->comboBox_cur_bar->setCurrentIndex(0);
    ui->lineEdit_tick_name->setText(plots[cur].ticks_name()[arg1 - 1]);
    if(cur >= 0) ui->doubleSpinBox_cur_data->setValue(plots[cur].data()[0][arg1 - 1]);
}

void MainWindow::on_comboBox_cur_bar_currentIndexChanged(int index)
{
    if(cur >= 0) ui->doubleSpinBox_cur_data->setValue(plots[cur].data()[index][ui->spinBox_cur_tick->value() - 1]);
}

void MainWindow::on_doubleSpinBox_cur_data_valueChanged(double arg1)
{
    if(cur >= 0 && table_change_data) { QVector<QVector<double>> data = plots[cur].data();
    data[ui->comboBox_cur_bar->currentIndex()][ui->spinBox_cur_tick->value() - 1] = arg1;
    plots[cur].setData(data);
    if (plots[cur].last() == ui->spinBox_cur_tick->value() - 1) {
        plots[cur].setLast(plots[cur].last() + 1);
        ui->spinBox_cur_tick->setMaximum(plots[cur].last() + 1);
        QVector<QVector<double>> data1 = plots[cur].data();
        for (auto &k : data1) k << 0;
        plots[cur].setData(data1);
        QVector<double> tick = plots[cur].ticker();
        tick << plots[cur].last() + 1;
        plots[cur].setTicker(tick);
        QVector<QString> labels = plots[cur].ticks_name();
        labels << QString::number(plots[cur].last() + 1);
        plots[cur].setTicks_name(labels);
    }
    plots[cur].build(ui->customPlot);
    rebuild_table(plots[cur]);
    }
    table_change_data = true;
}

void MainWindow::on_pushButton_Delete_clicked()
{
    QVector<QVector<double>> data = plots[cur].data();
    for ( auto &k : data) {
        k[ui->spinBox_cur_tick->value() - 1] = 0;
    }
    plots[cur].setData(data);
    ui->doubleSpinBox_cur_data->setValue(0);
    plots[cur].build(ui->customPlot);
    rebuild_table(plots[cur]);
}

void MainWindow::on_lineEdit_tick_name_textChanged(const QString &arg1)
{
    QVector<QString> labels = plots[cur].ticks_name();
    labels[ui->spinBox_cur_tick->value() - 1] = arg1;
    plots[cur].setTicks_name(labels);
    plots[cur].build(ui->customPlot);
    rebuild_table(plots[cur]);
}

void MainWindow::on_pushButton_save_png_clicked()
{
    if(cur >= 0) ui->customPlot->savePng(plots[cur].name() + ".png",531,401);
}

void MainWindow::on_pushButton_save_jpg_clicked()
{
    if(cur >= 0) ui->customPlot->saveJpg(plots[cur].name() + ".jpg",531,401);
}

void MainWindow::on_pushButton_save_pdf_clicked()
{
    if(cur >= 0) ui->customPlot->savePdf(plots[cur].name() + ".pdf",531,401);
}

void MainWindow::on_pushButton_delete_plot_clicked()
{
    if (cur < 0) return;
    ui->customPlot->clearPlottables();
    ui->customPlot->clearGraphs();
    ui->customPlot->clearItems();
    ui->customPlot->update();
    ui->customPlot->replot();
    int c = cur;
    delete plots[cur].listWidgetItem();
    plots.erase(plots.begin() + c);
}
