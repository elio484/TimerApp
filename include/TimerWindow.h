#ifndef TIMERWINDOW_H
#define TIMERWINDOW_H

#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>

class TimerWindow : public QWidget {
    Q_OBJECT

public:
    explicit TimerWindow(QWidget *parent = nullptr);

public slots:
    void startTimer();
    void stopTimer();
    void resetTimer();
    void updateDisplay();

public:
    void setupUI();
    QString formatTime(int totalSeconds) const;

    QTimer *timer;
    QLabel *timeLabel;
    QLabel *unitLabel;
    QSpinBox *hourInput;
    QSpinBox *minuteInput;
    QSpinBox *secondInput;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;

    int remainingSeconds;
};

#endif // TIMERWINDOW_H
