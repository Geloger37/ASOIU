#include <QTest>
#include "test_calculation.h"
#include "calculation.h"

Test_Calculation::Test_Calculation(QObject *parent)
    : QObject{parent}
{

}

void Test_Calculation::addition() {
    Calculation c;
    QCOMPARE(c.addition(2, 3), 5);
    QCOMPARE(c.addition(19, 3), 22);

}

void Test_Calculation::substraction() {
    Calculation c;
    QCOMPARE(c.substraction(2, 3), -1);
    QCOMPARE(c.substraction(19, 3), 16);
}

void Test_Calculation::multiplication() {
    Calculation c;
    QCOMPARE(c.multiplication(2, 3), 6);
    QCOMPARE(c.multiplication(3, 3), 9);
}

void Test_Calculation::division() {
    Calculation c;
    QCOMPARE(c.division(3, 1), 3);
    QCOMPARE(c.division(18, 3), 6);
}

