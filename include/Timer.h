#ifndef TIMER_H
#define TIMER_H

#include <QString>

class Timer {
public:
    Timer();

    void setTime(int hours, int minutes, int seconds);
    QString formatTime() const;
    bool tick(); // Decrementa il tempo e ritorna true se il timer continua, false se è finito
    void reset();
    int getRemainingSeconds() const;

private:
    int remainingSeconds;
};

#endif // TIMER_H
