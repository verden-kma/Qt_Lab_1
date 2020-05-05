#ifndef CUSTOMERSMODEL_H
#define CUSTOMERSMODEL_H
#include <QAbstractTableModel>
#include "Models/Office.h"

class CustomersModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomersModel(Office* office, QObject* parent = 0);
    int rowCount(const QModelIndex&) const override;
    int columnCount(const QModelIndex&) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int selection, Qt::Orientation, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    const std::vector<Person*>& peekCustomers() const;

    void emitChange(const QModelIndex&);
    //void UPDATE();
private:
    Office* office;
};



#endif // CUSTOMERSMODEL_H
