#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class AddPersonPopup;
class PhoneEditor;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Office;
class QAbstractTableModel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void generateSampleData();

    void updateSelectedNumber() const;
private slots:
    void on_addButton_clicked();

    void on_editButton_clicked();

private:
    Ui::MainWindow *ui;
    AddPersonPopup* addPopup = nullptr;
    PhoneEditor* phEdit = nullptr;
    Office* office;
    QAbstractTableModel** const model; // const pointer to mutable pointer to QAbstractTableModel
    QAbstractTableModel* mainModel;
    QAbstractTableModel* filterModel = nullptr;
};
#endif // MAINWINDOW_H
