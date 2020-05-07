#ifndef FILTERPOPUP_H
#define FILTERPOPUP_H

#include <QDialog>
#include <QRegularExpression>
#include "mainwindow.h"

namespace Ui {
class FilterPopup;
}

class FilterPopup : public QDialog
{
    Q_OBJECT

public:
    explicit FilterPopup(QWidget *parent = nullptr);
    ~FilterPopup();

    void reject() override;
private slots:
    void on_applyFilterBtn_clicked();

    void on_cancelFilter_clicked();

private:
    Ui::FilterPopup *ui;
    QRegularExpression numRX;
    QRegularExpression nameRX;
    MainWindow* mw;
};

#endif // FILTERPOPUP_H
