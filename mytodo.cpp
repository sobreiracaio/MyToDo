#include "mytodo.h"
#include "./ui_mytodo.h"

MyToDo::MyToDo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyToDo)
{
    ui->setupUi(this);
}

MyToDo::~MyToDo()
{
    delete ui;
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

