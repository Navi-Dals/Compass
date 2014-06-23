#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include <kompasdialog.h>
#include <QDebug>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
