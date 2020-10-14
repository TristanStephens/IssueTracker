#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QtSql>
#include "mainmenu.h"

namespace Ui {

class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    QSqlDatabase db;
    mainmenu m;

public slots:
    void on_loginB_clicked();

private:
    Ui::login *ui;
    QString user;
    QString pass;
};

#endif // LOGIN_H
