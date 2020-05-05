#include "FilterPopup.h"
#include "ui_FilterPopup.h"

FilterPopup::FilterPopup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterPopup)
{
    ui->setupUi(this);
}

FilterPopup::~FilterPopup()
{
    delete ui;
}

void FilterPopup::reject() {
    static_cast<QWidget *>(parent())->setEnabled(true);
    hide();
}