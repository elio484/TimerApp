#include "test_timerwindow.h"
#include "TimerWindow.h"
#include <QtTest/QtTest>

void TestTimerWindow::initTestCase() {

}

void TestTimerWindow::testInitialTimeDisplay() {
    TimerWindow timer;
    QCOMPARE(timer.findChild<QLabel*>("timeLabel")->text(), QString("00:00:00"));
}

void TestTimerWindow::testStartTimer() {
    TimerWindow timer;
    timer.findChild<QSpinBox*>("")->setValue(0);
    timer.startTimer();
    QVERIFY(timer.findChild<QPushButton*>("")->isEnabled() == false);
}

void TestTimerWindow::testStopTimer() {
    TimerWindow timer;
    timer.startTimer();
    timer.stopTimer();
    QVERIFY(timer.findChild<QPushButton*>("")->isEnabled());
}

void TestTimerWindow::testResetTimer() {
    TimerWindow timer;
    timer.startTimer();
    timer.resetTimer();
    QCOMPARE(timer.findChild<QLabel*>("timeLabel")->text(), QString("00:00:00"));
}

void TestTimerWindow::testFormatTime() {
    TimerWindow timer;
    QString result = timer.formatTime(3661);
    QCOMPARE(result, QString("01:01:01"));
}
