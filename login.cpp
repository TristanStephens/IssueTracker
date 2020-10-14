#include "login.h"
#include "ui_login.h"



login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    db.close();
    delete ui;
}

void login::on_loginB_clicked()
{
    ui->verifyLogin->clear();
    user = ui->userName->toPlainText();
    pass = ui->userPassword->toPlainText();
    db.setUserName(user);
    db.setPassword(pass);
    db.open();
    ui->verifyLogin->setText("Login Successful");

    //mainmenu
    this->hide();
    m.mergeDB(db);
    m.show();

}

