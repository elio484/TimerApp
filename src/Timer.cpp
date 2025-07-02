#include "timer.h"

Timer::Timer(QObject *parent)
    : QObject(parent), m_remainingSeconds(0) //inizializza l'oggetto base Qt
{
    connect(&m_timer, &QTimer::timeout, this, &Timer::updateTimer); // collega il segnale timeout del QTimer alla funzione updateTimer() -> ogni secondo verrà chiamato updateTimer()
    m_timer.setInterval(1000); // ogni secondo
}

void Timer::start(int seconds)
{
    m_remainingSeconds = seconds;
    emit timeChanged(m_remainingSeconds); //emette un segnale per notificare il tempo iniziale
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
        emit timeChanged(m_remainingSeconds); //Emette i nuovi secondi rimanenti.

        if (m_remainingSeconds == 0)
        {
            m_timer.stop();
            emit timeout(); //emette il segnale per dire il tempo è scaduto
        }
    }
}
