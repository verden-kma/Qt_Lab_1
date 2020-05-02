#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include "customersmodel.h"
#include "office.h"
#include "comboboxitemdelegate.h"
#include "AddPersonPopup.h"
#include "PhoneEditor.h"

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
    ui->customersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->customersTable->setItemDelegateForColumn(4, new ComboBoxItemDelegate((CustomersModel** const)(model), ui->customersTable));
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
//**************************************    ui->customersTable->update();
    Person& selected = *office->peekPeople().at(sModel->selectedRows().first().row());
    setEnabled(false);
    if (phEdit == nullptr)
        phEdit = new PhoneEditor(this);
    phEdit->setPerson(selected);
    phEdit->setEnabled(true);
    phEdit->show();
}

void MainWindow::updateSelectedNumber() const {
    qDebug() << ui->customersTable->selectionModel()->hasSelection();
    int selectedRow = ui->customersTable->selectionModel()->selectedRows().first().row();
    QModelIndex index = ui->customersTable->model()->index(selectedRow, 5);
    emit ui->customersTable->model()->dataChanged(index, index);
}








