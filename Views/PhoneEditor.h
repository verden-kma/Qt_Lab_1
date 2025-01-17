#ifndef PHONEEDITER_H
#define PHONEEDITER_H

#include <QDialog>
#include "ViewModels/EditNumberModel.h"

class Person;

namespace Ui {
class PhoneEditor;
}

class PhoneEditor : public QDialog
{
    Q_OBJECT

public:
    explicit PhoneEditor(QWidget *parent = nullptr);
    ~PhoneEditor();

    void setPerson(Person& p);

    void reject() override;
private slots:
    void on_AddNumBtn_clicked();

    void on_RemoveNumBtn_clicked();

    void on_OkBtn_clicked();

private:
    void clearInputs();

    Ui::PhoneEditor *ui;
    EditNumberModel editModel;
    Person* passedPerson;
};

#endif // PHONEEDITER_H
