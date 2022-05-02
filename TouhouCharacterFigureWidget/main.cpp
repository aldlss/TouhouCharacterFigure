#include "TouhouCharacterFigureWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TouhouCharacterFigureWidget w;
    w.show();
    return a.exec();
}
