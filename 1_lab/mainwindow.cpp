#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculation.h"
#include <string>
//#include "QtDebug"

/*
void test_add_in_1_4_out_5() {
    double num1 = 1, num2 = 4, res = 5;
    double check = addition( num1, num2 );
    if(check == res) {
        qDebug() << "Test add passed!";
    } else {
        qDebug() << "Test add did not pass!";
    }
}*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Number_1->setText("0");
    ui->Number_2->setText("0");
    ui->Result->setText("0");

    //    test_add_in_1_4_out_5();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PlusButton_clicked()
{
    double number1 = ui->Number_1->toPlainText().toDouble();
    double number2 = ui->Number_2->toPlainText().toDouble();
    Calculation c;
    ui->Result->setText(std::to_string(c.addition( number1, number2 )).c_str());
}


void MainWindow::on_MinusButton_clicked()
{
    double number1 = ui->Number_1->toPlainText().toDouble();
    double number2 = ui->Number_2->toPlainText().toDouble();
    Calculation c;
    ui->Result->setText(std::to_string(c.substraction( number1, number2 )).c_str());
}


void MainWindow::on_MultiplicationButton_clicked()
{
    double number1 = ui->Number_1->toPlainText().toDouble();
    double number2 = ui->Number_2->toPlainText().toDouble();
    Calculation c;
    ui->Result->setText(std::to_string(c.multiplication( number1, number2 )).c_str());
}


void MainWindow::on_DivisionButton_clicked()
{
    double number1 = ui->Number_1->toPlainText().toDouble();
    double number2 = ui->Number_2->toPlainText().toDouble();
    Calculation c;
    ui->Result->setText(std::to_string(c.division( number1, number2 )).c_str());
}

