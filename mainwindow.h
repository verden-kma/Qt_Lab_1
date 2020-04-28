#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "custompopup.h"

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

private slots:
    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
    CustomPopup* cp;
    Office* office;
    QAbstractTableModel* model;
};
#endif // MAINWINDOW_H
