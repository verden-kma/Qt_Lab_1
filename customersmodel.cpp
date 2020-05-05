#include "customersmodel.h"

CustomersModel::CustomersModel(Office* ofc, QObject* parent) : QAbstractTableModel(parent), office(ofc)
{

}

int CustomersModel::rowCount(const QModelIndex&) const {
    return office->peekPeople().size();
}

int CustomersModel::columnCount(const QModelIndex&) const {
    return Person::Properties;
}

QVariant CustomersModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }
    if (index.row() >= office->peekPeople().size() || index.column() >= Person::Properties) {
        return QVariant();
    }
    if (role == Qt::TextAlignmentRole) {
            return Qt::AlignCenter;
    }
    if (role==Qt::DisplayRole) {
        const Person& p = *office->peekPeople().at(index.row());
        switch(index.column()) {
        case 0 :
            return p.getId();
        case 1:
            return p.getName();
        case 2:
            return p.getSurname();
        case 3:
            return p.getAge();
        case 4:
            return p.getPrimaryNumber();
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
        case 4: return QString("Primary number");
        }
    else return QString("%2").arg(selection + 1);
    return QVariant();
}

Qt::ItemFlags CustomersModel::flags(const QModelIndex& index) const {
    if (index.column() == 0) return Qt::ItemFlag(false); // forbid to change ID
    if (!index.isValid())
        return Qt::ItemIsEnabled;
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

bool CustomersModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (index.isValid() && role==Qt::EditRole) {
        Person& p = *office->peekPeople().at(index.row());
        switch(index.column()) {
        case 1:
            p.setName(value.toString().toLocal8Bit().constData()); // toString
            return true;
        case 2:
            p.setSurname(value.toString().toLocal8Bit().constData());
            return true;
        case 3:
            p.setAge(value.toInt());
            return true;
        case 4:
            p.setPrimaryNumber(value.toULongLong());
            return true;
        }

        emit dataChanged(index, index);
    }
    return false;
}

bool CustomersModel::insertRows(int position, int rows, const QModelIndex &)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row) {
        office->peekPeople().insert(office->peekPeople().begin() + row, new Person("<Empty>", "<Empty>", 0, 0));
    }

    endInsertRows();
    return true;
}

bool CustomersModel::removeRows(int position, int rows, const QModelIndex &)
{
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row) {
        Person* doomed = office->peekPeople().at(position);
        delete doomed;  // delete pointed object
        office->peekPeople().erase(office->peekPeople().begin() + position); // delete pointer
    }

    endRemoveRows();
    return true;
}

const std::vector<Person*>& CustomersModel::peekCustomers() const {
    return office->peekPeople();
}

void CustomersModel::emitChange(const QModelIndex& index) {
    emit dataChanged(index, index);
}

//void CustomersModel::UPDATE() {
//    beginEdit();
//}






































