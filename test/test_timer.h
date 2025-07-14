#ifndef TEST_TIMER_H
#define TEST_TIMER_H

#include <QObject>

class TestTimer : public QObject {
    Q_OBJECT

private slots: //QT le usa come funzioni automatiche
    void initTestCase(); //Viene chiamata una sola volta prima di tutti i test per inizializzare l'ambiente di test: creare oggetti settare condizioni iniziali
    void testStart();
    void testCountdown();
    void testStop();
    void testTimeoutSignal(); //viene emesso correttamente quando il timer scade
};

#endif // TEST_TIMER_H
