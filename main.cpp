#include <QApplication>
#include "widgets/FramelessWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    FramelessWindow window;
    window.show();

    return app.exec();
}