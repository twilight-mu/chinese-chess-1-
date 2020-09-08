#include "zhujiemian.h"
#include <QApplication>
#include "board.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    Board h;
    h.show();
    return a.exec();
}
