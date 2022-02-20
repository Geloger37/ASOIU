#include "gettingdata.h"
#include <QDebug>

GettingData::GettingData(QObject *parent)
    : QObject{parent}
{

}

GettingData::GettingData() {
    port = new QSerialPort();
    port->setBaudRate(QSerialPort::Baud9600);
    port->setPortName("COM4");
    port->setDataBits(QSerialPort::Data8);
    port->setParity(QSerialPort::NoParity);
    port->setFlowControl(QSerialPort::NoFlowControl);

    if(!port->open(QIODevice::ReadWrite)) {
        qDebug() << "LOL, ur loser!";
    }





//    this->timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, SLOT(update_measures));
//    timer->start(5000);

}


void GettingData::update_measures() {
    return;
}
