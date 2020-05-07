#ifndef COMBOBOXITEMDELEGATE_H
#define COMBOBOXITEMDELEGATE_H
#include <QStyledItemDelegate>

class CustomersModel;
class ComboBoxItemDelegate : public QStyledItemDelegate
{
public:
    ComboBoxItemDelegate(CustomersModel* const model, QObject *parent = nullptr);
    ~ComboBoxItemDelegate();

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

private:
    CustomersModel* const currModel;
};

#endif // COMBOBOXITEMDELEGATE_H
