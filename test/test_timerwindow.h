#ifndef TEST_TIMERWINDOW_H
#define TEST_TIMERWINDOW_H

#include <QObject>

class TestTimerWindow : public QObject {
    Q_OBJECT

private slots:
    void initTestCase(); //viene chiamata una volta sola all’inizio di tutti i test, Serve per configurare l’ambiente: ad esempio creare un oggetto TimerWindow, impostare dati iniziali, ecc.
    void testInitialTimeDisplay(); //Testa se la finestra mostra correttamente il tempo iniziale
    void testFormatTime();//Testa il formato del tempo visualizzato
};

#endif // TEST_TIMERWINDOW_H
