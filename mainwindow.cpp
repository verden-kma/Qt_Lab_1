#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include "customersmodel.h"
#include "office.h"
#include "ComboboxItemDelegate.h"
#include "AddPersonPopup.h"
#include "PhoneEditor.h"
#include <QStyleOptionViewItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), model(new QAbstractTableModel*)
{
    ui->setupUi(this);
    office = new Office();
    generateSampleData();
    mainModel = new CustomersModel(office);
    *model = mainModel;
    ui->customersTable->setModel(*model);
    ui->customersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->customersTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->customersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->customersTable->setItemDelegateForColumn(4, new ComboBoxItemDelegate((CustomersModel** const)(model), ui->customersTable));
    //ComboBoxItemDelegate cbid((CustomersModel** const)(model), ui->customersTable);


    //cbid.createEditor(this, QStyleOptionViewItem::Middle, ui->customersTable->model()->index(0,4));
    //cbid.updateEditorGeometry();
    //cbid.destroyEditor();
   // ui->customersTable->update(0,0,0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addPopup;
    delete office;
    delete model;
    delete mainModel;
    delete filterModel;
    delete phEdit;
}

void MainWindow::generateSampleData() {
    Person* multNum = new Person("Hung", "Stair", 20, 380685795413);
    multNum->addPhoneNumber(380734194864);
    office->addPerson(multNum);
    Person* secondMultNum = new Person("Devorah", "Egli", 18, 380682496317);
    secondMultNum->addPhoneNumber(38066492035);
    office->addPerson(secondMultNum);
    office->addPerson(new Person("Vita", "Jarrett", 23, 380689820120));
    office->addPerson(new Person("Scarlet", "Odle", 25, 380686713498));
    office->addPerson(new Person("Leon", "Darrah", 27, 380681027906));
}

void MainWindow::on_addButton_clicked()
{
    // QMessageBox::about(this, "header", "content");
    //QMessageBox::critical(this, "header", "error");
//    QMessageBox::information(this, "header", "info");
//    QMessageBox::warning(this, "header", "warning");
//    QMessageBox::StandardButton reply = QMessageBox::question(this, "header", "choose", QMessageBox::Yes | QMessageBox::No);
//    if (reply == QMessageBox::Yes) {
//        QApplication::quit();
//    } else {
//        qDebug() << "No was pressed\n";
//    }
    setEnabled(false);
    if (addPopup == nullptr) {
        addPopup = new AddPersonPopup(this);
    }
    addPopup->setEnabled(true);
    addPopup->show();
}


void MainWindow::on_editButton_clicked()
{
    QItemSelectionModel* sModel = ui->customersTable->selectionModel();
    if (!sModel->hasSelection()) {
        QMessageBox::critical(this, "Error", "No selected person");
        return;
    }
    Person& selected = *office->peekPeople().at(sModel->selectedRows().first().row());
    setEnabled(false);
    if (phEdit == nullptr)
        phEdit = new PhoneEditor(this);
    phEdit->setPerson(selected);
    phEdit->setEnabled(true);
    phEdit->show();
}

void MainWindow::on_deleteButton_clicked()
{
    QItemSelectionModel* sModel = ui->customersTable->selectionModel();
    if (!sModel->hasSelection()) {
        QMessageBox::information(this, "info", "no selected item");
        return;
    }
    (**model).removeRow(sModel->selectedRows().first().row());
}

void MainWindow::updateCustomers(QString& name, QString surname, int age, unsigned long long phNumber) {
    (**model).insertRow((**model).rowCount());
    QModelIndex nameIndex = (**model).index((**model).rowCount() - 1, 1);
    QModelIndex surnameIndex = (**model).index((**model).rowCount() - 1, 2);
    QModelIndex ageIndex = (**model).index((**model).rowCount() - 1, 3);
    QModelIndex prNumIndex = (**model).index((**model).rowCount() - 1, 4);
    (**model).setData(nameIndex, name);
    (**model).setData(surnameIndex, surname);
    (**model).setData(ageIndex, age);
    (**model).setData(prNumIndex, phNumber);
}

void MainWindow::updateSelectedNumber() {
    qDebug() << ui->customersTable->selectionModel()->hasSelection();
    int selectedRow = ui->customersTable->selectionModel()->selectedRows().first().row();
    QModelIndex index = ui->customersTable->model()->index(selectedRow, 4);
    dynamic_cast<CustomersModel*>(ui->customersTable->model())->emitChange(index);
}










