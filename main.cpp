#include <QApplication>
#include "mainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mainWindow mWindow;
    mWindow.show();
    return app.exec();
}