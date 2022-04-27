#include "MyGrid.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyGrid w;
    w.show();

    return a.exec();
}
