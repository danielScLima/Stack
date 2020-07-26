#include "mainwindow.h"

#include <QApplication>
#include "stack.h"
#include <iostream>

/*!
 * \brief qMain
 * \param argc
 * \param argv
 * \return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
