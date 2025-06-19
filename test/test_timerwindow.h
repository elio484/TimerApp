#ifndef TEST_TIMERWINDOW_H
#define TEST_TIMERWINDOW_H

#include <QObject>

class TestTimerWindow : public QObject {
    Q_OBJECT

private slots:
    void initTestCase();
    void testInitialTimeDisplay();
    void testFormatTime();
};

#endif // TEST_TIMERWINDOW_H
