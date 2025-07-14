#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>

class Timer : public QObject
{
    Q_OBJECT

public:
    explicit Timer(QObject *parent = nullptr); //explicit impedisce conversioni esplicite e Accetta un QObject* come genitore

    void start(int seconds);
    void stop();
    int getRemainingTime() const; //restituisce il numero di secondi ancora da contare, const non modifica lo stato dell’oggetto.

    signals:
        void timeChanged(int secondsLeft); // viene emesso un segnale ogni secondo per dire quanti sencondi mancano
    void timeout();

private slots:
    void updateTimer();//serve per aggiornare il tempo rimanente ed emettere un timeChanged() alla fine timeout()

private:
    QTimer m_timer; //è il timer di Qt che genera un evento a intervalli regolari
    int m_remainingSeconds; //tiene conto di quanti secondi mancano alla fine
};

#endif // TIMER_H
