#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent, int id, QString todo)
    : QDialog(parent)
    , ui(new Ui::Edit)
{
    ui->setupUi(this);
    ui->label->setText(QString::number(id));
    ui->lineEdit->setText(todo);
}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_pushButton_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::warning(this, "Warning", "Blank fields are not allowed.");
        return;
    }

    QString id = ui->label->text();

    QSqlQuery query;
    QString sql = "DELETE FROM todos WHERE id=" + id;
    query.prepare(sql);

    if(query.exec())
    {
        close();
    }
    else
    {
        qDebug() << "Delete data failed";
    }
}


void Edit::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::warning(this, "Warning", "Blank fields are not allowed.");
        return;
    }

    QString id = ui->label->text();

    QSqlQuery query;
    QString sql = "UPDATE todos SET todos='"+ ui->lineEdit->text() +"' WHERE id=" + id;
    query.prepare(sql);

    if(query.exec())
    {
        close();
    }
    else
    {
        qDebug() << "Update data failed";
    }
}

