#include <QtTest/QtTest>
#include "test_timerwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    TestTimerWindow test;
    return QTest::qExec(&test, argc, argv);
}
