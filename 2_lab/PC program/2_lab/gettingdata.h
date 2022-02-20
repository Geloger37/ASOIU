#ifndef GETTINGDATA_H
#define GETTINGDATA_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

class GettingData : public QObject
{
    Q_OBJECT

public:
    QSerialPort *port;
    QTimer *timer;

    GettingData();
    explicit GettingData(QObject *parent = nullptr);

signals:


private slots:
    void update_measures();
};

#endif // GETTINGDATA_H
