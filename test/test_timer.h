#ifndef TEST_TIMER_H
#define TEST_TIMER_H

#include <QObject>

class TestTimer : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void testStart();
    void testCountdown();
    void testStop();
    void testTimeoutSignal();
};

#endif // TEST_TIMER_H
