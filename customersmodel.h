#ifndef CUSTOMERSMODEL_H
#define CUSTOMERSMODEL_H
#include <QAbstractTableModel>
#include "office.h"

class CustomersModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomersModel(Office* office, QObject* parent = 0);
    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex&) const;
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int selection, Qt::Orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    const std::vector<Person*>& peekCustomers() const;
private:
    Office* office;
};



#endif // CUSTOMERSMODEL_H
