#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>

class TimerWindow : public QWidget {
    Q_OBJECT //è una macro necessaria per abilitare segnali e slots

public:
    explicit TimerWindow(QWidget *parent = nullptr); //serve per collegare il widget ad un eventuale genitore.

    void startTimer();
    void stopTimer();
    void resetTimer();
    QString formatTime(int seconds);

private slots:
    void updateDisplay(); //è uno slot, quindi può essere collegato ai segnali Qt

public:
    QLabel *unitLabel;
    QLabel *timeLabel;

    //Pulsanti per controllare il timer (start, stop, reset).
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;

    //Tre QSpinBox per impostare ore, minuti e secondi.
    QSpinBox *hourSpinBox;
    QSpinBox *minuteSpinBox;
    QSpinBox *secondSpinBox;

    QTimer *qtimer;

    int totalSeconds = 0;
};

#endif // TIMERWINDOW_H
