#ifndef EDITNUMBERMODEL_H
#define EDITNUMBERMODEL_H

#include <QAbstractListModel>

class EditNumberModel : public QAbstractListModel
{
    Q_OBJECT
public:
    EditNumberModel(QObject *parent = nullptr);
    ~EditNumberModel() = default;

    void resetPersonNumbers(const std::list<unsigned long long>& phNums);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;

    void clearData();
    bool containsNum(const QString&);
private:
    QStringList currentNumbers;
};

#endif // EDITNUMBERMODEL_H
