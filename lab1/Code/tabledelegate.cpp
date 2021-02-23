#include "tabledelegate.h"

TableDelagate::TableDelagate(QObject *parent) :
    QItemDelegate(parent)
{
}

// TableView need to create an Editor
// Create Editor when we construct MyDelegate
// and return the Editor
QWidget* TableDelagate::createEditor(QWidget *parent,
                                  const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const
{

    QDoubleSpinBox *editor = new QDoubleSpinBox(parent);
    editor->setMinimum(-100);
    editor->setMaximum(100);
    return editor;
}

// Then, we set the Editor
// Gets the data from Model and feeds the data to Editor
void TableDelagate::setEditorData(QWidget *editor,
                               const QModelIndex &index) const
{
    // Get the value via index of the Model
    int value = index.model()->data(index, Qt::EditRole).toDouble();

    // Put the value into the SpinBox
    QDoubleSpinBox *spinbox = static_cast<QDoubleSpinBox*>(editor);
    spinbox->setValue(value);
}

// When we modify data, this model reflect the change
void TableDelagate::setModelData(QWidget *editor, QAbstractItemModel *model,
                              const QModelIndex &index) const
{
    QDoubleSpinBox *spinbox = static_cast<QDoubleSpinBox*>(editor);
        spinbox->interpretText();
        double value = spinbox->value();
        model->setData(index, value, Qt::EditRole);
}

// Give the SpinBox the info on size and location
void TableDelagate::updateEditorGeometry(QWidget *editor,
                                      const QStyleOptionViewItem &option,
                                      const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
