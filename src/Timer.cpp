#include "Timer.h"
#include <QString>
#include <iomanip>
#include <sstream>

Timer::Timer() : remainingSeconds(0) {}

void Timer::setTime(int hours, int minutes, int seconds) {
    remainingSeconds = hours * 3600 + minutes * 60 + seconds;
}

QString Timer::formatTime() const {
    int hours = remainingSeconds / 3600;
    int minutes = (remainingSeconds % 3600) / 60;
    int seconds = remainingSeconds % 60;

    return QString("%1:%2:%3")
        .arg(hours, 2, 10, QChar('0'))
        .arg(minutes, 2, 10, QChar('0'))
        .arg(seconds, 2, 10, QChar('0'));
}

bool Timer::tick() {
    if (remainingSeconds > 0) {
        --remainingSeconds;
        return true;
    }
    return false;
}

void Timer::reset() {
    remainingSeconds = 0;
}

int Timer::getRemainingSeconds() const {
    return remainingSeconds;
}
