#ifndef FILTERPOPUP_H
#define FILTERPOPUP_H

#include <QDialog>

namespace Ui {
class FilterPopup;
}

class FilterPopup : public QDialog
{
    Q_OBJECT

public:
    explicit FilterPopup(QWidget *parent = nullptr);
    ~FilterPopup();

private:
    Ui::FilterPopup *ui;
};

#endif // FILTERPOPUP_H
