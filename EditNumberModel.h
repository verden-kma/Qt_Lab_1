#ifndef EDITNUMBERMODEL_H
#define EDITNUMBERMODEL_H

#include <QAbstractListModel>

class EditNumberModel : public QAbstractListModel
{
    Q_OBJECT
public:
    EditNumberModel(QObject *parent = nullptr);
    ~EditNumberModel() = default;

    void resetPersonNumbers(const std::list<unsigned long long>& phNums); // todo: use defencive copy in case user decides to abort changes

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());

    void clearData();
    bool containsNum(const QString&);
private:
    QStringList currentNumbers;
};

#endif // EDITNUMBERMODEL_H
