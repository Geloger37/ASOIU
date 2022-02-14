#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PlusButton_clicked();

    void on_MinusButton_clicked();

    void on_MultiplicationButton_clicked();

    void on_DivisionButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
