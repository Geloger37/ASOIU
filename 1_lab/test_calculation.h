#ifndef TEST_CALCULATION_H
#define TEST_CALCULATION_H

#include <QObject>

class Test_Calculation : public QObject
{
    Q_OBJECT
public:
    explicit Test_Calculation(QObject *parent = nullptr);

private slots:
    void addition();

    void substraction();

    void multiplication();

    void division();

signals:

};

#endif // TEST_CALCULATION_H
