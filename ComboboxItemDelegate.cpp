#include "ComboboxItemDelegate.h"
#include "customersmodel.h"
#include <QComboBox>
#include <QDebug>

ComboBoxItemDelegate::ComboBoxItemDelegate(CustomersModel** const model, QObject *parent)
    : QStyledItemDelegate(parent), currModel(model)
{
}


ComboBoxItemDelegate::~ComboBoxItemDelegate()
{
}

QWidget *ComboBoxItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &, const QModelIndex &index) const
{
    // Create the combobox and populate it
    QComboBox *cb = new QComboBox(parent);
    Person* p = (**currModel).peekCustomers().at(index.row());

    unsigned long long prNum = p->getPrimaryNumber();
    int cbIndex = 0;
    auto phoneIter = p->peekPhoneNumbers().begin();
    while (phoneIter != p->peekPhoneNumbers().end()) {
        cb->addItem(QString::fromStdString(std::to_string(*phoneIter)));
        if (*phoneIter == prNum) cb->setCurrentIndex(cbIndex);
        else cbIndex++;
        phoneIter++;
    }
    return cb;
}

void ComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    // get the index of the text in the combobox that matches the current value of the item
    const QString currentText = index.data(Qt::EditRole).toString();
    const int cbIndex = cb->findText(currentText);
    // if it is valid, adjust the combobox
    if (cbIndex >= 0) {
       cb->setCurrentIndex(cbIndex);
       unsigned long long selectedNumber = std::strtoull(currentText.toStdString().c_str(), nullptr, 10);
       (**currModel).setData(index, selectedNumber, Qt::EditRole);
    }
}

void ComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *cb = qobject_cast<QComboBox *>(editor);
    Q_ASSERT(cb);
    model->setData(index, cb->currentText(), Qt::EditRole);
}

void ComboBoxItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const {
    editor->setGeometry(option.rect);
}

































