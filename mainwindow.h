#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
