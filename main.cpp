#include "qtimgprocsr.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qtimgprocsr w;
    w.show();
    return a.exec();
}
