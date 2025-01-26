#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Comput_clicked()
{
    QString inputExpression = ui->expression->text();
    std::string str = inputExpression.toStdString();

    float result;
    std::string conv, binStr, octStr, hexStr;

    if (ui->checkBox_Bin->isChecked()) {
        conv = Calc.ExpBinToDec(str);
        result = Calc.Compute(conv);
    } else if (ui->checkBox_Oct->isChecked()) {
        conv = Calc.ExpOctToDec(str);
        result = Calc.Compute(conv);
    } else if (ui->checkBox_Hex->isChecked()) {
        conv = Calc.ExpHexToDec(str);
        result = Calc.Compute(conv);
    } else {
        result = Calc.Compute(str);
    }

    binStr = Calc.FloatToBin(result);
    octStr = Calc.FloatToOct(result);
    hexStr = Calc.FloatToHex(result);

    ui->Float->setText(QString::number(result));
    ui->Bin->setText(QString::fromStdString(binStr));
    ui->Oct->setText(QString::fromStdString(octStr));
    ui->Hex->setText(QString::fromStdString(hexStr));
}


void MainWindow::on_checkBox_Float_clicked()
{
    ui->checkBox_Bin->setChecked(false);
    ui->checkBox_Oct->setChecked(false);
    ui->checkBox_Hex->setChecked(false);
}


void MainWindow::on_checkBox_Bin_clicked()
{
    ui->checkBox_Hex->setChecked(false);
    ui->checkBox_Oct->setChecked(false);
    ui->checkBox_Float->setChecked(false);
}


void MainWindow::on_checkBox_Oct_clicked()
{
    ui->checkBox_Bin->setChecked(false);
    ui->checkBox_Hex->setChecked(false);
    ui->checkBox_Float->setChecked(false);
}


void MainWindow::on_checkBox_Hex_clicked()
{
    ui->checkBox_Bin->setChecked(false);
    ui->checkBox_Oct->setChecked(false);
    ui->checkBox_Float->setChecked(false);
}
