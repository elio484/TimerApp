#include <QApplication>
#include <QFile>
#include "TimerWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFile styleFile(":/style/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        app.setStyleSheet(style);
    }else {
        qWarning("Impossibile caricare il file di stile.");
    }

    TimerWindow window;
    window.setWindowTitle("TIMER");
    window.resize(400, 300);
    window.show();

    return app.exec();
}