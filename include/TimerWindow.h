#ifndef TIMERWINDOW_HPP
#define TIMERWINDOW_HPP

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QSpinBox>

class TimerWindow : public QWidget {
    Q_OBJECT

public:
    TimerWindow(QWidget *parent = nullptr);

private slots:
    void updateDisplay();
    void startTimer();
    void stopTimer();
    void resetTimer();

private:
    QLabel *timeLabel;
    QSpinBox *hourInput;
    QSpinBox *minuteInput;
    QSpinBox *secondInput;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QTimer *timer;
    QLabel *unitLabel;
    int remainingSeconds;
    void setupUI();
    QString formatTime(int totalSeconds) const;
};

#endif // TIMERWINDOW_HPP
