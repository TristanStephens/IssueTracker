#include "updateD.h"
#include "ui_updateD.h"

updateD::updateD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updateD)
{
    ui->setupUi(this);
}

updateD::~updateD()
{
    delete ui;
}

void updateD::on_pushButton_clicked()
{
    this->close();
}
