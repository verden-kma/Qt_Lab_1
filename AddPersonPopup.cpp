#include "AddPersonPopup.h"
#include "ui_custompopup.h"
#include <QMessageBox>

AddPersonPopup::AddPersonPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomPopup)
{
    ui->setupUi(this);
    QRegExp rx("^[A-Z][a-zA-Z]+$");
    nameValidator = new QRegExpValidator(rx, this);
    ui->nameText->setValidator(nameValidator);
    ui->surnameText->setValidator(nameValidator);
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
}

void AddPersonPopup::on_pushButton_clicked()
{
    if (!checkNewCustomerData()) return;
    QString name = ui->nameText->text();
    QString surname = ui->surnameText->text();
    int age = ui->ageSpinBox->value();
    QString phoneNumber = ui->phoneText->text();

    clearInputs();
    hide();
}

bool AddPersonPopup::checkNewCustomerData() {
    QString value = ui->nameText->text();
    int len;
    if (ui->nameText->validator()->validate(value, len)) {
        QMessageBox::critical(this, "Error", len < 2 ? "Name is too short." : "Incorrect pattern.");
        return false;
    }

    value = ui->surnameText->text();
    if (ui->nameText->validator()->validate(value, len)) {
        QMessageBox::critical(this, "Error", len < 2 ? "Surname is too short." : "Incorrect pattern.");
        return false;
    }

    int age = ui->ageSpinBox->value();
    if (age < 0 || age > 135) {
        QMessageBox::critical(this, "Error", "Allowed age is in range [0;135].");
        return false;
    }

    value = ui->phoneText->text();
    QRegularExpression re("\\d{11,13}");
    QRegularExpressionMatch match = re.match(value);
    if (!match.hasMatch()) {
        QMessageBox::critical(this, "Error", "Incorrect phone number pattern.");
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
