#include "ui_PhoneEditor.h"
#include "Views/PhoneEditor.h"
#include "Models/Person.h"
#include <QMessageBox>
#include "mainwindow.h"

PhoneEditor::PhoneEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhoneEditor)
{
    ui->setupUi(this);
    ui->numList->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->numList->setModel(&editModel);
}

PhoneEditor::~PhoneEditor()
{
    delete ui;
}

void PhoneEditor::setPerson(Person& p) {
    passedPerson = &p;
    editModel.resetPersonNumbers(p.peekPhoneNumbers());
}

void PhoneEditor::reject() {
    static_cast<QWidget *>(parent())->setEnabled(true);
    hide();
    editModel.clearData();
}

void PhoneEditor::on_AddNumBtn_clicked()
{
    if (!Person::numberIsValid(ui->newNumLine->text())) {
        QMessageBox::critical(this, "Wrong number pattern", "Allowed pattern is 11 to 13 decimal digits");
        return;
    }
    if (editModel.containsNum(ui->newNumLine->text())) {
        QMessageBox::critical(this, "Duplicate", "Number is already present.");
        return;
    }
    editModel.insertRow(editModel.rowCount());
    QModelIndex index = editModel.index(editModel.rowCount() - 1);
    editModel.setData(index, ui->newNumLine->text());
    ui->newNumLine->clear();
}

void PhoneEditor::on_RemoveNumBtn_clicked()
{
    if (!ui->numList->selectionModel()->hasSelection()) {
        QMessageBox::information(this, "No selected number", "You should select number prior to removing.");
        return;
    }
    editModel.removeRow(ui->numList->selectionModel()->selectedRows().first().row());
}

void PhoneEditor::on_OkBtn_clicked()
{
    qulonglong oldPrime = passedPerson->getPrimaryNumber();
    passedPerson->peekPhoneNumbers().clear();
    for (int i = 0; i < editModel.rowCount(); i++) {
        passedPerson->peekPhoneNumbers().push_back(editModel.data(editModel.index(i), Qt::DisplayRole).toULongLong());
    }
    if (!editModel.containsNum(QString::number(oldPrime))) {
        passedPerson->setPrimaryNumber(*passedPerson->peekPhoneNumbers().begin());
    }
    static_cast<MainWindow *>(parent())->updateSelectedNumber();
    reject();
}






















