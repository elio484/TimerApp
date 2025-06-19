#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>

class Timer : public QObject
{
    Q_OBJECT

public:
    explicit Timer(QObject *parent = nullptr);

    void start(int seconds);
    void stop();
    int getRemainingTime() const;

    signals:
        void timeChanged(int secondsLeft);
    void timeout();

private slots:
    void updateTimer();

private:
    QTimer m_timer;
    int m_remainingSeconds;
};

#endif // TIMER_H
