#ifndef CUSTOMPOPUP_H
#define CUSTOMPOPUP_H

#include <QDialog>

class QRegExpValidator;
class MainWindow;

namespace Ui {
class AddPersonPopup;
}

class AddPersonPopup : public QDialog
{
    Q_OBJECT

public:
    explicit AddPersonPopup(QWidget *parent);
    ~AddPersonPopup();

    void reject() override;

private slots:
    void on_pushButton_clicked();

private:
    void clearInputs();
    bool checkNewCustomerData();
    Ui::AddPersonPopup *ui;
    QRegExpValidator* nameValidator;
    QRegExpValidator* numberValidator;
    MainWindow& mw;
};

#endif // CUSTOMPOPUP_H
