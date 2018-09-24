#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QSplashScreen>
#include <QTimer>
#include <QLabel>
#include <QStatusBar>
#include <QDebug>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash=new QSplashScreen;

    #ifdef Q_OS_LINUX
    qDebug()<<"LINUX OS";
    splash->setPixmap(QPixmap("/home/optimus/Documentos/qtSourceCode/shimming/icons/animal.png"));
    #endif

    #ifdef Q_OS_MACOS
    qDebug()<<"MAC OS";
    splash->setPixmap(QPixmap("/home/optimus/Documentos/qtSourceCode/shimming/icons/animal.png"));
    #endif

    splash->setWindowOpacity(0.95);
    splash->show();
    QTimer::singleShot(500,splash,SLOT(close()));

    MainWindow w;

    QIcon icon("/home/optimus/Documentos/qtSourceCode/shimming/icons/icon.png");

    w.setWindowIcon(icon);
    w.move(QApplication::desktop()->screen()->rect().center() - w.rect().center());
    QTimer::singleShot(500,&w,SLOT(show()));


    return a.exec();
}
