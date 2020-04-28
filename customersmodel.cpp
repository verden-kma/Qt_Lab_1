#include "customersmodel.h"

CustomersModel::CustomersModel(const std::vector<Person>& customers, QObject* parent) : QAbstractTableModel(parent), _people(customers)
{

}

int CustomersModel::rowCount(const QModelIndex&) const {
    return _people.size();
}

int CustomersModel::columnCount(const QModelIndex&) const {
    return Person::Properties;
}

QVariant CustomersModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }
    if (index.row() >= _people.size() || index.column() >= Person::Properties) {
        return QVariant();
    }
    if (role==Qt::DisplayRole) {
        const Person& p = _people.at(index.row());
        switch(index.column()) {
        case 0 :
            return p.getId();
        case 1:
            return QString::fromStdString(p.getName());
        case 2:
            return QString::fromStdString(p.getSurname());
        case 3:
            return p.getAge();
        case 4:
            QStringList phNumbers;
            for (unsigned long long int n : p.getPhoneNumbers()) {
                phNumbers.append(QString::fromStdString(std::to_string(n)));
            }
            return phNumbers;
        }
    }
    return QVariant();
}

QVariant CustomersModel::headerData(int selection, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Horizontal)
        switch(selection) {
        case 0: return QString("ID");
        case 1: return QString("Name");
        case 2: return QString("Surname");
        case 3: return QString("Age");
        case 4: return QString("Phone");
        default: return QString("FixMe");
        }
    else return QString("%2").arg(selection + 1);
}

//Qt::ItemFlags CustomersModel::flags(const QModelIndex& index) const {
//    if (!index.isValid())
//        return Qt::ItemIsEnabled;
//    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
//}

//bool CustomersModel::setData(const QModelIndex &index, const QVariant &value, int role) {
//    if (index.isValid() && role==Qt::EditRole) {
//        Person& p = _people.at(index.row());

//        emit dataChanged(index, index);
//    }
//    return false;
//}










































