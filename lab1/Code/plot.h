#ifndef PLOT_H
#define PLOT_H
#include <qcustomplot.h>
#include <QListWidgetItem>

/*!
 * \class Plot
 * \brief This class is a container for chart
 *
 * This class contains structer of the chart, such as number of bars, their colors, names, background color.
 * It also contains data of bars and information about legend
 */

class Plot
{
private:
    QString _name;
    QColor _background;
    int _num;
    QVector<QColor> _color_bars;
    QVector<QString> _name_bars;
    QString _xAxis;
    QString _yAxis;
    bool _main_x;
    bool _legend;
    QListWidgetItem *_listWidgetItem;
    QVector<QVector<double>> _data;
    QVector<double> _ticker;
    int _last;
    QVector<QString> _ticks_name;
public:
    Plot();
    /*!
     * \brief name
     * string, name of our chart
     */
    QString name() const;
    /*!
     * \brief setName
     * Function sets chart`s name
     */
    void setName(const QString &name);
    /*!
     * \brief background
     * Qcolor, color of chart`s background
     */
    QColor background() const;
    /*!
     * \brief setName
     * Function sets color of chart`s background
     */
    void setBackground(const QColor &background);
    /*!
     * \brief num
     * int, number of bars
     */
    int num() const;
    /*!
     * \brief setName
     * Function sets number of bars
     */
    void setNum(int num);
    /*!
     * \brief color_bars
     * QVector<QColor>, colors of bars
     */
    QVector<QColor> color_bars() const;
    /*!
     * \brief setColor_bars
     * Function sets colors of bars
     */
    void setColor_bars(const QVector<QColor> &color_bars);
    /*!
     * \brief name_bars
     * QVector<QString>, names of bars
     */
    QVector<QString> name_bars() const;
    /*!
     * \brief setName_bars
     * Function sets names of bars
     */
    void setName_bars(const QVector<QString> &name_bars);
    /*!
     * \brief xAxis
     * QString, name of xAxis
     */
    QString xAxis() const;
    /*!
     * \brief setXAxis
     * Function sets name of xAxis
     */
    void setXAxis(const QString &xAxis);
    /*!
     * \brief yAxis
     * QString, name of yAxis
     */
    QString yAxis() const;
    /*!
     * \brief setYAxis
     * Function sets name of yAxis
     */
    void setYAxis(const QString &yAxis);
    /*!
     * \brief main_x
     * bool, orientation of chart
     */
    bool main_x() const;
    /*!
     * \brief setMain_x
     * Function sets orientation of chart
     */
    void setMain_x(bool main_x);
    /*!
     * \brief legend
     * Returns \c true if legend is visible, \c false if different
     */
    bool legend() const;
    /*!
     * \brief setLegend
     * Function sets legend`s visibility
     */
    void setLegend(bool legend);
    QListWidgetItem *listWidgetItem() const;
    void setListWidgetItem(QListWidgetItem *listWidgetItem);
    /*!
     * \brief data
     * QVector<QVector<double>>, chart`s data
     */
    QVector<QVector<double> > data() const;
    /*!
     * \brief setData
     * Function sets chart`s data
     */
    void setData(const QVector<QVector<double> > &data);
    /*!
     * \brief ticker
     * QVector<double>, bar`s numeration
     */
    QVector<double> ticker() const;
    /*!
     * \brief setTicker
     * Function sets bar`s numeration
     */
    void setTicker(const QVector<double> &ticker);
    /*!
     * \brief last
     * int, number of bars group
     */
    int last() const;
    /*!
     * \brief setLast
     * Function sets  number of bars group
     */
    void setLast(int last);
    /*!
     * \brief ticks_name
     * QVector<QString>, names of bar`s numeration
     */
    QVector<QString> ticks_name() const;
    /*!
     * \brief setTicks_name
     * Function sets  names of bar`s numeration
     */
    void setTicks_name(const QVector<QString> &ticks_name);
};
/*!
 * \brief operator <<
 * \param out
 * \param plot
 * \return
 * Function tells how to write class into file
 */
QDataStream &operator<<(QDataStream &out, const Plot &plot);
/*!
 * \brief operator >>
 * \param in
 * \param plot
 * \return
 * Function tells how to read class into file
 */
QDataStream &operator>>(QDataStream &in, Plot &plot);

#endif // PLOT_H
