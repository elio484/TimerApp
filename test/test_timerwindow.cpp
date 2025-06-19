#include "test_timerwindow.h"
#include "TimerWindow.h"
#include <QtTest/QtTest>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>

void TestTimerWindow::initTestCase() {
    // Eventuali setup globali
}

// Verifica che QLabel mostri inizialmente "00:00:00"
void TestTimerWindow::testInitialTimeDisplay() {
    TimerWindow timer;
    QLabel* label = timer.findChild<QLabel*>("timeLabel");
    QVERIFY(label);
    QCOMPARE(label->text(), QString("00:00:00"));
}

// Verifica il formato dell'orario
void TestTimerWindow::testFormatTime() {
    TimerWindow timer;
    QString result = timer.formatTime(3661); // 1h 1min 1sec
    QCOMPARE(result, QString("01:01:01"));
}
