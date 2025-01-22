#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "Calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Comput_clicked();

    void on_checkBox_Float_clicked();

    void on_checkBox_Bin_clicked();

    void on_checkBox_Oct_clicked();

    void on_checkBox_Hex_clicked();

private:
    Ui::MainWindow *ui;
    Calculator Calc;
};
#endif // MAINWINDOW_H
