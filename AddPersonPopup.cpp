#include "AddPersonPopup.h"
#include "ui_custompopup.h"
#include <QMessageBox>
#include "office.h"
#include "mainwindow.h"

AddPersonPopup::AddPersonPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonPopup),
    mw(*dynamic_cast<MainWindow*>(parent))
{
    ui->setupUi(this);
    QRegExp rxName("^[A-Z][a-zA-Z]+$");
    QRegExp rxNum("^\\d{11,13}$");
    nameValidator = new QRegExpValidator(rxName, this);
    numberValidator = new QRegExpValidator(rxNum, this);

    ui->nameText->setValidator(nameValidator);
    ui->surnameText->setValidator(nameValidator);
    ui->phoneText->setValidator(numberValidator);
}

void AddPersonPopup::reject() {
    static_cast<QWidget *>(parent())->setEnabled(true);
    hide();
    clearInputs();
}

AddPersonPopup::~AddPersonPopup()
{
    delete ui;
    delete nameValidator;
    delete numberValidator;
}

void AddPersonPopup::on_pushButton_clicked()
{
    if (!checkNewCustomerData()) return;
    QString name = ui->nameText->text();
    QString surname = ui->surnameText->text();
    int age = ui->ageSpinBox->value();
    QString phoneNumber = ui->phoneText->text();
    try {
        mw.updateCustomers(name, surname, age, phoneNumber.toULongLong());
    } catch (const std::invalid_argument& e) {
        QMessageBox::critical(this, "Error", e.what());
    }


   reject();
}

bool AddPersonPopup::checkNewCustomerData() {
    QString value = ui->nameText->text();
    int len = ui->nameText->text().length();
    if (len < 2 || len > 20) {
        QMessageBox::critical(this, "Error", "Allowed name length is [2;20].");
        return false;
    }

    len = ui->surnameText->text().length();
    if (len < 2 || len > 20) {
        QMessageBox::critical(this, "Error", "Allowed surname length is [2;20].");
        return false;
    }

    int age = ui->ageSpinBox->value();
    if (age < 0 || age > 135) {
        QMessageBox::critical(this, "Error", "Allowed age is in range [0;135].");
        return false;
    }

    if (ui->phoneText->text().length() < 11) {
        QMessageBox::critical(this, "Error", "Allowed phone number length is [11;13].");
        return false;
    }
    return true;
}

void AddPersonPopup::clearInputs() {
    ui->nameText->setText("");
    ui->surnameText->setText("");
    ui->ageSpinBox->setValue(0);
    ui->phoneText->setText("");
}
