#ifndef CALCULATION_H
#define CALCULATION_H

#include <QObject>

class Calculation : public QObject
{
    Q_OBJECT
public:
    explicit Calculation(QObject *parent = nullptr);

public slots:
    double addition(double a, double b);

    double substraction(double a, double b);

    double multiplication(double a, double b);

    double division(double a, double b);

signals:

};

#endif // CALCULATION_H
