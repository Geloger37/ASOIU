/*
* Author: Shirokov Maxim aka Geloger
* Created: 18.02.2022 16:40
* Version: 1.0
* Description: This program gets data from arduino and every 1 min updates temperature and pressure on the form. Temperature sensor have to be connected to A0 and pressure sensor have to be connected to A1.
* The program automatically find COM port and set it up.
*
**/



#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


