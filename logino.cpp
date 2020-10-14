#include "logino.h"
#include "ui_logino.h"

loginO::loginO(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginO)
{
    ui->setupUi(this);
}

loginO::~loginO()
{
    db.close();
    delete ui;
}

void loginO::on_loginB_clicked()
{
    user = ui->userName->toPlainText();
    pass = ui->userPassword->toPlainText();
    db.setUserName(user);
    db.setPassword(pass);
    db.open();
}
