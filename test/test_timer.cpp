#include "test_timer.h"
#include "Timer.h"
#include <QtTest/QtTest>

void TestTimer::initTestCase() {
    // Setup iniziale se necessario
}

// Verifica che dopo start() il tempo rimanente sia corretto
void TestTimer::testStart() {
    Timer timer;
    timer.start(5); //parte ogni 5 secondi
    QCOMPARE(timer.getRemainingTime(), 5); //controlla che restituisce 5
}

// Verifica che il countdown diminuisca ogni secondo
void TestTimer::testCountdown() {
    Timer timer;
    QSignalSpy spy(&timer, &Timer::timeChanged); //osserva quante volte viene emesso il segnale

    timer.start(3);

    QTest::qWait(3100);

    QCOMPARE(timer.getRemainingTime(), 0); //verifica che il tempo rimante sia arrivato a zero
    QVERIFY(spy.count() >= 3); //deve aver emesso almeno 3 timechange()
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
    QSignalSpy timeoutSpy(&timer, &Timer::timeout); //osserva il segnale timeout() del timer, tiene traccia

    timer.start(1);
    QTest::qWait(1500); // attendi che scatti timeout

    QCOMPARE(timeoutSpy.count(), 1); //controlla quante volte è stato emesso timeout, restituisce segnale emesso
}
