#ifndef MYTODO_H
#define MYTODO_H

#include <QMainWindow>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyToDo;
}
QT_END_NAMESPACE

class MyToDo : public QMainWindow
{
    Q_OBJECT

public:
    MyToDo(QWidget *parent = nullptr);
    ~MyToDo();


    QString home = getenv("HOME");
    QString dir = ":/database.db";
    QString user = home + "/.config/database.db";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    void show_data();

    void start();



private slots:
    void on_actionExit_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MyToDo *ui;
};
#endif // MYTODO_H
