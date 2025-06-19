#include "timer.h"

Timer::Timer(QObject *parent)
    : QObject(parent), m_remainingSeconds(0)
{
    connect(&m_timer, &QTimer::timeout, this, &Timer::updateTimer);
    m_timer.setInterval(1000); // ogni secondo
}

void Timer::start(int seconds)
{
    m_remainingSeconds = seconds;
    emit timeChanged(m_remainingSeconds);
    m_timer.start();
}

void Timer::stop()
{
    m_timer.stop();
}

int Timer::getRemainingTime() const
{
    return m_remainingSeconds;
}

void Timer::updateTimer()
{
    if (m_remainingSeconds > 0)
    {
        m_remainingSeconds--;
        emit timeChanged(m_remainingSeconds);

        if (m_remainingSeconds == 0)
        {
            m_timer.stop();
            emit timeout();
        }
    }
}
