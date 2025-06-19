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

int Timer::getTotalSeconds() const {
    return totalSeconds;
}
