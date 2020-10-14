#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>

namespace Ui {
class updateD;
}

class updateD : public QDialog
{
    Q_OBJECT

public:
    explicit updateD(QWidget *parent = nullptr);
    ~updateD();

private slots:
    void on_pushButton_clicked();

private:
    Ui::updateD *ui;
};

#endif // UPDATE_H
