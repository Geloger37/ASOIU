#include "calculation.h"

Calculation::Calculation(QObject *parent)
    : QObject{parent}
{

}

double Calculation::addition(double a, double b) {
    return a + b;
}

double Calculation::substraction(double a, double b) {
    return a - b;
}

double Calculation::multiplication(double a, double b) {
    return a * b;
}

double Calculation::division(double a, double b) {
    return a / b;
}
