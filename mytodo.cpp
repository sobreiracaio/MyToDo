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

    show_data();
}

MyToDo::~MyToDo()
{
    delete ui;
}

void MyToDo::show_data()
{
    QSqlQuery query;
    QString sql = "SELECT * FROM todos ORDER BY id DESC";
    query.prepare(sql);

    if(query.exec())
    {
        int i = 0;
        QStringList headers = {"ID", "Task", "Date/Time"};

        ui->tableWidget->setRowCount(0);

        ui->tableWidget->setColumnCount(3);

        ui->tableWidget->setHorizontalHeaderLabels(headers);

        ui->tableWidget->setColumnWidth(0,60);
        ui->tableWidget->setColumnWidth(1,580);
        ui->tableWidget->setColumnWidth(2,160);

        ui->tableWidget->verticalHeader()->setVisible(false);

        while(query.next())
        {
            ui->tableWidget->insertRow(i);
            for(int j = 0; j < 3; j++)
            {
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(query.value(j).toString()));
            }

            ++i;
        }


    }
    else
    {
        qDebug() << "Failure obtaining data.";
    }
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
        ui->tableWidget->clear();
        show_data();
    }
    else
    {
        qDebug() << "Failed to insert data.";
    }

}


void MyToDo::on_tableWidget_cellClicked(int row, int column)
{
    column = 0;
    int id = ui->tableWidget->item(row, column)->text().toInt();
    QString task = ui->tableWidget->item(row, 1)->text();



    Edit e(this, id, task);

    e.exec();

    show_data();
}

