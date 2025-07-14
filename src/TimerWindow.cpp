#include "TimerWindow.h"
#include <QVBoxLayout>
#include <QFont>

TimerWindow::TimerWindow(QWidget *parent)
    : QWidget(parent),
      startButton(new QPushButton("Start", this)),
      stopButton(new QPushButton("Stop", this)),
      resetButton(new QPushButton("Reset", this)),
      hourSpinBox(new QSpinBox(this)),
      minuteSpinBox(new QSpinBox(this)),
      secondSpinBox(new QSpinBox(this)),
      qtimer(new QTimer(this)),
      totalSeconds(0)
{
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

    // Imposta range e valori iniziali e objectName (importante per i test)
    hourSpinBox->setRange(0, 23);
    hourSpinBox->setValue(0);
    hourSpinBox->setObjectName("hourBox");

    minuteSpinBox->setRange(0, 59);
    minuteSpinBox->setValue(0);
    minuteSpinBox->setObjectName("minuteBox");

    secondSpinBox->setRange(0, 59);
    secondSpinBox->setValue(0);
    secondSpinBox->setObjectName("secondBox");

    // Layout orizzontale per spinbox e pulsanti
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(hourSpinBox);
    hLayout->addWidget(minuteSpinBox);
    hLayout->addWidget(secondSpinBox);
    hLayout->addWidget(startButton);
    hLayout->addWidget(stopButton);
    hLayout->addWidget(resetButton);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(unitLabel);
    vLayout->addWidget(timeLabel);
    vLayout->addLayout(hLayout);

    connect(startButton, &QPushButton::clicked, this, &TimerWindow::startTimer);//collega un segnale(evento) allo slots(funzione che risponde a un segnale) usando la funzione connect
    connect(stopButton, &QPushButton::clicked, this, &TimerWindow::stopTimer);
    connect(resetButton, &QPushButton::clicked, this, &TimerWindow::resetTimer);
    connect(qtimer, &QTimer::timeout, this, &TimerWindow::updateDisplay);//viene emesso ogni volta che scade l’intervallo del timer

    stopButton->setEnabled(false);
    resetButton->setEnabled(false);
}

void TimerWindow::startTimer()
{
    totalSeconds = hourSpinBox->value() * 3600
                 + minuteSpinBox->value() * 60
                 + secondSpinBox->value();

    if (totalSeconds <= 0)
        return;

    hourSpinBox->setEnabled(false);
    minuteSpinBox->setEnabled(false);
    secondSpinBox->setEnabled(false);

    startButton->setEnabled(false);
    stopButton->setEnabled(true);
    resetButton->setEnabled(true);

    qtimer->start(1000); // ogni secondo
    updateDisplay();
}

void TimerWindow::stopTimer()
{
    qtimer->stop();

    startButton->setEnabled(true);
    stopButton->setEnabled(false);

    hourSpinBox->setEnabled(true);
    minuteSpinBox->setEnabled(true);
    secondSpinBox->setEnabled(true);
}

void TimerWindow::resetTimer()
{
    qtimer->stop();
    totalSeconds = 0;
    timeLabel->setText("00:00:00");

    hourSpinBox->setValue(0);
    minuteSpinBox->setValue(0);
    secondSpinBox->setValue(0);

    hourSpinBox->setEnabled(true);
    minuteSpinBox->setEnabled(true);
    secondSpinBox->setEnabled(true);

    startButton->setEnabled(true);
    stopButton->setEnabled(false);
    resetButton->setEnabled(false);
}

void TimerWindow::updateDisplay()
{
    if (totalSeconds <= 0) {
        stopTimer();
        return;
    }

    timeLabel->setText(formatTime(totalSeconds));
    totalSeconds--;
}

QString TimerWindow::formatTime(int seconds)
{
    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;

    return QString("%1:%2:%3")
        .arg(h, 2, 10, QChar('0'))
        .arg(m, 2, 10, QChar('0'))
        .arg(s, 2, 10, QChar('0'));
}
