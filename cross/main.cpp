#include <QtWidgets/QApplication>
#include "Widget.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Widget widget;
    widget.show();

    return QApplication::exec();
}