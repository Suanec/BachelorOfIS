#include <QApplication>
#include "qtboard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtBoard *BoardWindow = new QtBoard();
    BoardWindow->show();
    
    return a.exec();
}
