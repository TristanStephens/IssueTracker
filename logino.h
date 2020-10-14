#ifndef LOGINO_H
#define LOGINO_H

#include <QWidget>
#include <QtSql>
#include "mainmenu.h"

namespace Ui {
class loginO;
}

class loginO : public QWidget
{
    Q_OBJECT

public:
    explicit loginO(QWidget *parent = nullptr);
    ~loginO();
    QSqlDatabase db;
    mainmenu m;

private slots:
    void on_loginB_clicked();

private:
    Ui::loginO *ui;
    QString user;
    QString pass;
};

#endif // LOGINO_H
