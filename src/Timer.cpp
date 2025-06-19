#include "Timer.h"
#include <QString>

Timer::Timer(QObject *parent)
    : QObject(parent), totalSeconds(0) {}

void Timer::setTime(int seconds) {
    totalSeconds = seconds;
}

void Timer::reset() {
    totalSeconds = 0;
}

bool Timer::tick() {
    if (totalSeconds > 0) {
        --totalSeconds;
        return true;
    }
    return false;
}

QString Timer::formatTime(int seconds) const {
    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;
    return QString("%1:%2:%3")
        .arg(h, 2, 10, QChar('0'))
        .arg(m, 2, 10, QChar('0'))
        .arg(s, 2, 10, QChar('0'));
}

int Timer::getTotalSeconds() const {
    return totalSeconds;
}
