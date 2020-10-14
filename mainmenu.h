#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QtSql>
#include "updateD.h"

namespace Ui {

class mainmenu;
}

class mainmenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_loginB_clicked();
    void on_logOut_clicked();
    void on_viewAll_clicked();
    void on_addIss_clicked();
    void on_viewIss_clicked();
    void on_searchBtn_clicked();
    void on_bugDesc_textChanged();
    void on_addIssueBtn_clicked();

    void clearAddForm();

private:
    Ui::mainmenu *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    QSqlQueryModel *viewAllModel = new QSqlQueryModel;
    QSqlQueryModel *searchModel = new QSqlQueryModel;
    QSqlQuery *addIssueQ = new QSqlQuery;

};

#endif // MAINMENU_H
