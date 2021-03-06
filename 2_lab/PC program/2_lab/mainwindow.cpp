#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->temperature_textEdit->setText("0");
    ui->pressure_textEdit->setText("0");

    arduino = new QSerialPort(this);
    serialBuffer = "";
    first_try = true;

    /*
     *   Identify the port the arduino uno is on.
     */
    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    //
    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier()){
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id)
                    && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id)){
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }

    /*
     *  Open and configure the arduino port if available
     */
    if(arduino_is_available){
        QMessageBox::information(this, "Serialportinfo", "Port name is " + arduino_uno_port_name);
        qDebug() << "Found the arduino port...\n";

        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl); // doesn't influence on work
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
//        arduino->waitForBytesWritten(100); // how does it work?

        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));

        QTimer *timer = new QTimer(this);
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(writeSerial()));
        timer->start(1000);
    } else {
        qDebug() << "Couldn't find the correct port for the arduino.\n";
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSerial()
{
    if(first_try) {
        serialData = arduino->readAll();
        if(serialData == "\xFF") {
            qDebug() << "Test message received!";
        }
        else {
            qDebug() << "Port settings is incorrected!";
        }
        first_try = false;
        serialBuffer = ""; // buffer string is flushed
        return;
    }
    // read all the data from serial but not garantee ALL we need
    serialData = arduino->readAll();
    // add new information to the buffer
    serialBuffer += QString(serialData);
    // check on the end of buffer. If ended symbol is '\n' that means 1 full data
    if(serialBuffer.back() == '\n') {// That is try to check start of the sending
            QStringList buffer_split = serialBuffer.split(":"); // split data into temperature and pressure (format: "ttt:ppp")

            ui->temperature_textEdit->setText(buffer_split[0]);
            ui->pressure_textEdit->setText(buffer_split[1].split("\n")[0]);

            serialBuffer = ""; // buffer string is flushed
    }
}

void MainWindow::writeSerial()
{
    arduino->write("0"); // send a request
}
