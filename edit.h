#ifndef EDIT_H
#define EDIT_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

#include <QMessageBox>

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr, int id = 0, QString toDo = NULL);
    ~Edit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Edit *ui;
};

#endif // EDIT_H
