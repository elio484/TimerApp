#include <QTest>
#include "test_timer.h"
#include "test_timerwindow.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    int result = 0;
    {
        TestTimer testTimer;
        result |= QTest::qExec(&testTimer, argc, argv);
    }
    {
        TestTimerWindow testTimerWindow;
        result |= QTest::qExec(&testTimerWindow, argc, argv);
    }

    return result;
}
