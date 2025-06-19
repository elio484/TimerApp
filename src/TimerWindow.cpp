#include "TimerWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFont>

TimerWindow::TimerWindow(QWidget *parent) : QWidget(parent) {
    qtimer = new QTimer(this);
    qtimer->setInterval(1000);
    connect(qtimer, &QTimer::timeout, this, &TimerWindow::updateDisplay);
    setupUI();
}

void TimerWindow::setupUI() {
    unitLabel = new QLabel("h              min              sec", this);
    unitLabel->setAlignment(Qt::AlignCenter);
    QFont unitFont;
    unitFont.setPointSize(40);
    unitLabel->setFont(unitFont);
    unitLabel->setContentsMargins(0, 100, 0, 0);

    timeLabel = new QLabel("00:00:00", this);
    timeLabel->setObjectName("timeLabel");
    QFont font;
    font.setPointSize(150);
    timeLabel->setFont(font);
    timeLabel->setAlignment(Qt::AlignCenter);
    timeLabel->setMaximumHeight(100);
    timeLabel->setWordWrap(true);

    hourInput = new QSpinBox(this);
    hourInput->setRange(0, 23);
    hourInput->setPrefix("Ore: ");

    minuteInput = new QSpinBox(this);
    minuteInput->setRange(0, 59);
    minuteInput->setPrefix("Min: ");

    secondInput = new QSpinBox(this);
    secondInput->setRange(0, 59);
    secondInput->setPrefix("Sec: ");

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(hourInput);
    inputLayout->addWidget(minuteInput);
    inputLayout->addWidget(secondInput);

    startButton = new QPushButton("Start", this);
    stopButton = new QPushButton("Stop", this);
    resetButton = new QPushButton("Reset", this);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(stopButton);
    buttonLayout->addWidget(resetButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(unitLabel);
    mainLayout->addWidget(timeLabel);
    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(40, 40, 40, 40);

    connect(startButton, &QPushButton::clicked, this, &TimerWindow::startTimer);
    connect(stopButton, &QPushButton::clicked, this, &TimerWindow::stopTimer);
    connect(resetButton, &QPushButton::clicked, this, &TimerWindow::resetTimer);
}

void TimerWindow::startTimer() {
    if (!qtimer->isActive()) {
        if (timerLogic.getRemainingSeconds() == 0) {
            int hours = hourInput->value();
            int minutes = minuteInput->value();
            int seconds = secondInput->value();
            timerLogic.setTime(hours, minutes, seconds);
        }

        QFont font = timeLabel->font();
        font.setPointSize(150);
        timeLabel->setFont(font);
        timeLabel->setText(timerLogic.formatTime());
        unitLabel->setVisible(true);

        qtimer->start();

        hourInput->setEnabled(false);
        minuteInput->setEnabled(false);
        secondInput->setEnabled(false);
        startButton->setEnabled(false);
    }
}

void TimerWindow::stopTimer() {
    qtimer->stop();

    hourInput->setEnabled(true);
    minuteInput->setEnabled(true);
    secondInput->setEnabled(true);
    startButton->setEnabled(true);
}

void TimerWindow::resetTimer() {
    qtimer->stop();
    timerLogic.reset();

    QFont font = timeLabel->font();
    font.setPointSize(150);
    timeLabel->setFont(font);
    timeLabel->setText("00:00:00");

    unitLabel->setVisible(true);
    hourInput->setValue(0);
    minuteInput->setValue(0);
    secondInput->setValue(0);

    hourInput->setEnabled(true);
    minuteInput->setEnabled(true);
    secondInput->setEnabled(true);
    startButton->setEnabled(true);
}

void TimerWindow::updateDisplay() {
    if (timerLogic.tick()) {
        timeLabel->setText(timerLogic.formatTime());
    } else {
        qtimer->stop();

        QFont smallFont = timeLabel->font();
        smallFont.setPointSize(50);
        timeLabel->setFont(smallFont);
        timeLabel->setText("Tempo scaduto!");

        unitLabel->setVisible(false);

        hourInput->setEnabled(true);
        minuteInput->setEnabled(true);
        secondInput->setEnabled(true);
        startButton->setEnabled(true);
    }
}
