#include "mainwindow.h"

#include <QApplication>
#include <QTest>
#include "test_calculation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTest::qExec(new Test_Calculation, argc, argv);
    return a.exec();
}
