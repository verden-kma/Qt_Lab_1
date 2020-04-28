#ifndef CUSTOMERSMODEL_H
#define CUSTOMERSMODEL_H
#include <QAbstractTableModel>
#include "person.h"

class CustomersModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomersModel(const std::vector<Person>& customers, QObject* parent = 0);
    int rowCount(const QModelIndex&) const;
    int columnCount(const QModelIndex&) const;
    QVariant data(const QModelIndex& index, int role) const;
    QVariant headerData(int selection, Qt::Orientation, int role = Qt::DisplayRole) const;
//    Qt::ItemFlags flags(const QModelIndex& index) const;
//    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
private:
    std::vector<Person> _people;
};



#endif // CUSTOMERSMODEL_H
