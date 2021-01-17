#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent){
    setupUi ();
    connect(btn, SIGNAL(clicked()), this, SLOT(onclick ()));
}

Widget::~Widget(){}

void Widget::setupUi (){
    outpane = new Outpane();
    inpane = new Inpane();
    QHBoxLayout *layout = new QHBoxLayout;
    btn = new QPushButton("-->");

    layout->addWidget (inpane);
    layout->addWidget (btn);
    layout->addWidget (outpane);
    setLayout (layout);

    setWindowIcon (QIcon(":/icons/QT.png"));
    setFixedSize (450, 140);
}

void Widget::onclick (){
    int x = inpane->firstedit->text ().toInt ();
    int y = inpane->secondedit->text ().toInt ();
    outpane->mul->display (x*y);
    outpane->sub->display (x-y);
    outpane->sum->display (x+y);

    if (y == 0){
        QMessageBox::critical (0, "Error!", "Divizion by zero!");
        outpane->div->display (0);
    } else {
        outpane->div->display (x/y);
    }
}
