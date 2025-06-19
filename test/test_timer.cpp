#include "test_timer.h"
#include "Timer.h"
#include <QtTest/QtTest>

void TestTimer::initTestCase() {
    // Setup iniziale se necessario
}

// Verifica che dopo start() il tempo rimanente sia corretto
void TestTimer::testStart() {
    Timer timer;
    timer.start(5);
    QCOMPARE(timer.getRemainingTime(), 5);
}

// Verifica che il countdown diminuisca ogni secondo
void TestTimer::testCountdown() {
    Timer timer;
    QSignalSpy spy(&timer, &Timer::timeChanged);

    timer.start(3);

    QTest::qWait(3100); // attendi 3.1 secondi per il conteggio

    QCOMPARE(timer.getRemainingTime(), 0);
    QVERIFY(spy.count() >= 3);
}

// Verifica che stop() fermi il timer
void TestTimer::testStop() {
    Timer timer;
    timer.start(5);
    timer.stop();
    int timeBefore = timer.getRemainingTime();
    QTest::qWait(2000); // aspetta 2 secondi
    QCOMPARE(timer.getRemainingTime(), timeBefore); // il tempo non deve cambiare
}

// Verifica che venga emesso il segnale timeout()
void TestTimer::testTimeoutSignal() {
    Timer timer;
    QSignalSpy timeoutSpy(&timer, &Timer::timeout);

    timer.start(1);
    QTest::qWait(1500); // attendi che scatti timeout

    QCOMPARE(timeoutSpy.count(), 1);
}
