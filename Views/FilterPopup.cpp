#include "FilterPopup.h"

#include "ui_FilterPopup.h"

#include "Models/Office.h"

#include <QMessageBox>

#include "Models/Office.h"

FilterPopup::FilterPopup(QWidget * parent):
  QDialog(parent),
  ui(new Ui::FilterPopup),
  numRX("^\\d+$"),
  nameRX("^[A-Z][a-z]+$"),
  mw(dynamic_cast < MainWindow * > (parent)) {
    ui -> setupUi(this);
    ui -> filtersCombo -> addItem("ID");
    ui -> filtersCombo -> addItem("Name");
    ui -> filtersCombo -> addItem("Surname");
    ui -> filtersCombo -> addItem("Age");
    ui -> filtersCombo -> addItem("Phone");
  }

FilterPopup::~FilterPopup() {
  delete ui;
}

void FilterPopup::reject() {
  static_cast < QWidget * > (parent()) -> setEnabled(true);
  hide();
}

void FilterPopup::on_applyFilterBtn_clicked() {
  QString input = ui -> filterValue -> text();
  switch (ui -> filtersCombo -> currentIndex()) {
  case 0:
    {
      if (!numRX.match(input).hasMatch()) {
        QMessageBox::critical(this, "error", "only decimal numbers are allowed for id");
        return;
      }
      mw -> takeFilter( & Office::findByID, input.toUInt());
      break;
    }
  case 1:
    {
      if (!nameRX.match(input).hasMatch() || input.length() > 20) {
        QMessageBox::information(this, "info", "allowed name length is [2;20], only letters are allowed");
        return;
      }
      mw -> takeFilter( & Office::findByName, input);
      break;
    }
  case 2:
    {
      if (!nameRX.match(input).hasMatch() || input.length() > 20) {
        QMessageBox::information(this, "info", "allowed surname length is [2;20], only letters are allowed");
        return;
      }
      mw -> takeFilter( & Office::findBySurname, input);
      break;
    }
  case 3:
    {
      if (!numRX.match(input).hasMatch() && input.toInt() <= 135) {
        QMessageBox::critical(this, "error", "only decimal numbers are allowed for age, allowd range is [0;135]");
        return;
      }
      mw -> takeFilter( & Office::findByAge, input.toInt());
      break;
    }
  case 4:
    {
      if (!numRX.match(input).hasMatch() && input.length() >= 11 && input.length() <= 13) {
        QMessageBox::critical(this, "error", "only decimal numbers are allowed for age, allowed length is [11;13]");
        return;
      }
      mw -> takeFilter( & Office::findByPhoneNumber, input.toULongLong());
      break;
    }
  }
  reject();
}

void FilterPopup::on_cancelFilter_clicked() {
  mw -> setMainModel();
  reject();
}
