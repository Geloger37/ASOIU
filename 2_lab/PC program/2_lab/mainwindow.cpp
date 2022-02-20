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
    parsed_data = "";
    temperature_value = 0.0;

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
        QMessageBox::information(this, "Serialportinfo", arduino_uno_port_name);
        qDebug() << "Found the arduino port...\n";
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
//        arduino->waitForBytesWritten(100);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
        QTimer *timer = new QTimer(this);
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(writeSerial()));
        timer->start(1000);
    }else{
        qDebug() << "Couldn't find the correct port for the arduino.\n";
        QMessageBox::information(this, "Serial Port Error", "Couldn't open serial port to arduino.");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSerial()
{
    // read all the data from serial but not garantee ALL we need
    serialData = arduino->readAll();
//    qDebug() << serialData;
    // add new information to the buffer
    serialBuffer += QString(serialData);
    // check on the end of buffer. If ended symbol is '\n' that means 1 full data/
    if(serialBuffer.back() == '\n') {/* That is try to check start of the sending
        if(serialBuffer == QString("Start")) {
            QMessageBox::information(this, "Success", "Test message received!");
//            MainWindow::writeSerial("0");
        }
        else {*/
            QStringList buffer_split = serialBuffer.split(":"); // split data into temperature and pressure (format: "ttt:ppp")
            ui->temperature_textEdit->setText(buffer_split[0]);
            ui->pressure_textEdit->setText(buffer_split[1]);
//            MainWindow::writeSerial("0");
//        }
        serialBuffer = ""; // buffer is flushed
    }
}

void MainWindow::writeSerial()
{
    arduino->write("0"); // send a request
}

