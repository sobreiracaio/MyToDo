#include "mytodo.h"
#include "./ui_mytodo.h"

MyToDo::MyToDo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyToDo)
{
    ui->setupUi(this);
    start();

    db.setDatabaseName(user);

    if(!db.open())
    {
        qDebug() << "Failed finding db file: " + user;
    }
    else
    {
        qDebug() << "DB file successfully found.";
    }
}

MyToDo::~MyToDo()
{
    delete ui;
}

void MyToDo::start()
{
    QFile quser(user);

    if(!quser.exists())
    {
        QFile::copy(dir, user);
        system("chmod 600 ~/.config/database.db");
        qDebug() << "Initial file has been copied.";
    }
}

void MyToDo::on_actionExit_triggered()
{
    close();
}


void MyToDo::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About...", "<h2>MyTodo 1.0.0</h2>"
                                         "<p>Author: Caio S. <br>"
                                         "<p><a href='https://github.com/sobreiracaio'>Github</a></p>"
                       );
};


void MyToDo::on_pushButton_clicked()
{
    QString text = ui->lineEdit->text();
    if( text == "")
    {
        QMessageBox::warning(this, "Warning", "Blank fields not accepted.");
        return;
    }

    if(!db.isOpen())
    {
        QMessageBox::warning(this, "Warning", "Database is not connected.");
        return;
    }

    QSqlQuery query;
    QString sql = "INSERT INTO todos ( todos ) VALUES ('"+ text +"')";
    query.prepare(sql);

    if(query.exec())
    {
        ui->statusbar->showMessage("Data successfully inserted", 2000);
        ui->lineEdit->clear();
        ui->lineEdit->setFocus();
    }
    else
    {
        qDebug() << "Failed to insert data.";
    }

}

