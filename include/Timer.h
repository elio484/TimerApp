#ifndef TIMER_H
#define TIMER_H

#include <QObject>

class Timer : public QObject {
    Q_OBJECT

private:
    int totalSeconds;

public:
    explicit Timer(QObject *parent = nullptr);

    void setTime(int seconds);
    void reset();
    bool tick();  // Ritorna true se il timer è arrivato a zero
    QString formatTime(int totalSeconds) const;

    int getTotalSeconds() const;
};

#endif // TIMER_H
