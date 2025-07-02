#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>

class TimerWindow : public QWidget {
    Q_OBJECT

public:
    explicit TimerWindow(QWidget *parent = nullptr);

    void startTimer();
    void stopTimer();
    void resetTimer();
    QString formatTime(int seconds);

private slots:
    void updateDisplay();

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
