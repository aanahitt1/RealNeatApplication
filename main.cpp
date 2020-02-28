#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    GraphicsWindow* test = new GraphicsWindow();
    test->show("C:\\Users\\Anahit\\Documents\\rah1.FASTA");
    return a.exec();

}
