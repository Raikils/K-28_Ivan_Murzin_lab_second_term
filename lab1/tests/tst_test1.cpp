#include <QtTest>
#include <QCoreApplication>

#include "plot.h"
#include "qcustomplot.h"
#include "createplot.h"
#include "mainwindow.h"

class Test1 : public QObject
{
    Q_OBJECT

public:
    Test1();
    ~Test1();

private slots:
    void test_plot();
    void test_createplot();

private:
    Plot p;
    CreatePlot *crpl;

};

Test1::Test1()
{

}

Test1::~Test1()
{

}

void Test1::test_plot()
{
    p.setName("chart");
    p.setBackground(QColor(0,0,0));
    p.setColor_bars({QColor(0,0,255),QColor(0,0,255),QColor(0,0,255)});
    p.setData({{0,1,2},{3,4,5},{6,7,8}});
    p.setLast(2);
    p.setLegend(true);
    p.setListWidgetItem(NULL);
    p.setMain_x(true);
    p.setName_bars({"one","two","three"});
    p.setNum(3);
    p.setTicker({1,2,3});
    p.setTicks_name({"1","2","3"});
    p.setXAxis("x");
    p.setYAxis("y");

    QCustomPlot *chart = new QCustomPlot;
    p.build(chart);
    QVERIFY(chart->xAxis->label() == "x");
    QVERIFY(chart->yAxis->label() == "y");
    QVERIFY(p._bars.size() == 3);
    QVERIFY(p._bars[0]->width() == 0.15);
    QVERIFY(p._bars[1]->width() == 0.15);
    QVERIFY(p._bars[2]->width() == 0.15);
    QVERIFY(p._bars[0]->name() == "one");
    QVERIFY(p._bars[1]->name() == "two");
    QVERIFY(p._bars[2]->name() == "three");
    QVERIFY(p._bars[0]->parentPlot() == chart);
    QVERIFY(p._bars[1]->parentPlot() == chart);
    QVERIFY(p._bars[2]->parentPlot() == chart);
    QVERIFY(!p._bars[0]->data()->isEmpty());
    QVERIFY(!p._bars[1]->data()->isEmpty());
    QVERIFY(!p._bars[2]->data()->isEmpty());
    QVERIFY(p._bars[0]->data()->size() == 3);
    QVERIFY(p._bars[1]->data()->size() == 3);
    QVERIFY(p._bars[2]->data()->size() == 3);
    QVERIFY(!p._group->isEmpty());
    QVERIFY(p._group->size() == 3);
    QVERIFY(p._group->bars(0) == p._bars[0]);
    QVERIFY(p._group->bars(1) == p._bars[1]);
    QVERIFY(p._group->bars(2) == p._bars[2]);
}

void Test1::test_createplot()
{
    crpl = new CreatePlot;
    crpl->plot = p;
    crpl->on_checkBox_legend_stateChanged(0);
    crpl->on_lineEdit_xAxis_textChanged("X");
    crpl->on_lineEdit_yAxis_textChanged("Y");
    crpl->on_spinBox_num_bars_valueChanged(4);
    crpl->on_comboBox_backcolor_currentIndexChanged("red");
    QVERIFY(!crpl->plot.legend());
    QVERIFY(crpl->plot.xAxis() == "X");
    QVERIFY(crpl->plot.yAxis() == "Y");
    QVERIFY(crpl->plot.num() == 4);
    QVERIFY(crpl->plot.background() == QColor(255,0,0));
}

QTEST_MAIN(Test1)

#include "tst_test1.moc"
