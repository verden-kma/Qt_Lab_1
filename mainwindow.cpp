#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QDebug>
#include "customersmodel.h"
#include "office.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), cp(nullptr)
{
    ui->setupUi(this);
    office = new Office();
    generateSampleData();
    model = new CustomersModel(office->getPeople());
    ui->customersTable->setModel(model);
    ui->customersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->customersTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete cp;
    delete office;
    delete model;
}

void MainWindow::generateSampleData(){
    Person multNum("Hung", "Stair", 20, 380685795413);
    multNum.addPhoneNumber(380734194864);
    office->addPerson(multNum);
    Person secondMultNum("Devorah", "Egli", 18, 380682496317);
    secondMultNum.addPhoneNumber(38066492035);
    office->addPerson(secondMultNum);
    office->addPerson(Person("Vita", "Jarrett", 23, 380689820120));
    office->addPerson(Person("Scarlet", "Odle", 25, 380686713498));
    office->addPerson(Person("Leon", "Darrah", 27, 380681027906));
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
    if (cp == nullptr) {
        cp = new CustomPopup(this);
    }
    cp->setEnabled(true);
    cp->show();
}

