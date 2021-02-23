#ifndef TABLEDELEGATE_H
#define TABLEDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QObject>
#include <QSize>
#include <QSpinBox>

/*!
 * \class TableDelagate
 * \brief The TableDelagate class describes delegate for table model
 *
 * This delegate describes the item of our model, which resalts in creation of doublespinbox
 */

class TableDelagate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit TableDelagate(QObject *parent = 0);

    /*!
     * \brief createEditor
     * Create Editor when we construct MyDelegat
     */
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    /*!
     * \brief setEditorData
     * Set the Editor
     */
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

    /*!
     * \brief setModelData
     * Function reflect the change when we modify data
     */
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    /*!
     * \brief updateEditorGeometry
     * Function give the Editor the info on size and location
     */
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

public slots:

};

#endif // TABLEDELEGATE_H
