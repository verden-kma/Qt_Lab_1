#ifndef CUSTOMPOPUP_H
#define CUSTOMPOPUP_H

#include <QDialog>

class QRegExpValidator;

namespace Ui {
class CustomPopup;
}

class CustomPopup : public QDialog
{
    Q_OBJECT

public:
    explicit CustomPopup(QWidget *parent = nullptr);
    ~CustomPopup();

    void reject() override;

private slots:
    void on_pushButton_clicked();

private:
    void clearInputs();
    bool checkNewCustomerData();
    Ui::CustomPopup *ui;
    QRegExpValidator* nameValidator = nullptr;
};

#endif // CUSTOMPOPUP_H
