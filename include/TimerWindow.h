#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include "Timer.h"  // Inclusione della nuova classe Timer

class TimerWindow : public QWidget {
    Q_OBJECT

public:
    explicit TimerWindow(QWidget *parent = nullptr);
    void setupUI();

public slots:
    void startTimer();
    void stopTimer();
    void resetTimer();
    void updateDisplay();

private:
    QLabel *timeLabel;
    QLabel *unitLabel;
    QSpinBox *hourInput;
    QSpinBox *minuteInput;
    QSpinBox *secondInput;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;

    QTimer *qtimer;
    Timer timerLogic;  // Nuova istanza della logica di timer
};

#endif // TIMERWINDOW_H
