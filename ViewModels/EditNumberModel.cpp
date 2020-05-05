#include "ViewModels/EditNumberModel.h"
#include "Models/Person.h"
#include <QMessageBox>

EditNumberModel::EditNumberModel(QObject *parent) : QAbstractListModel(parent)
{
}

void EditNumberModel::resetPersonNumbers(const std::list<unsigned long long>& phNums) {
    beginResetModel();
    for (auto phNumIter = phNums.begin(); phNumIter != phNums.end(); phNumIter++) {
        currentNumbers.push_back(QString::fromStdString(std::to_string(*phNumIter)));
    }
    endResetModel();
}

int EditNumberModel::rowCount(const QModelIndex &) const {
    return currentNumbers.size();
}

QVariant EditNumberModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= currentNumbers.size())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return currentNumbers.at(index.row());
    else
        return QVariant();
}

QVariant EditNumberModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Phone number");
    else
        return QString("%1").arg(section);
}

Qt::ItemFlags EditNumberModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool EditNumberModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        if (!Person::numberIsValid(value.toString())) {
            QMessageBox::critical(nullptr, "Wrong pattern", "Allowed patern is \\d{11,13}");
            return false;
        }
        currentNumbers.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

bool EditNumberModel::insertRows(int position, int rows, const QModelIndex &)
{
    beginInsertRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row) {
        currentNumbers.insert(position, "");
    }

    endInsertRows();
    return true;
}

bool EditNumberModel::removeRows(int position, int rows, const QModelIndex &)
{
    beginRemoveRows(QModelIndex(), position, position+rows-1);
    for (int row = 0; row < rows; ++row) {
        currentNumbers.removeAt(position);
    }

    endRemoveRows();
    return true;
}

void EditNumberModel::clearData() {
    currentNumbers.clear();
}

bool EditNumberModel::containsNum(const QString& num) {
    return currentNumbers.contains(num);
}

















