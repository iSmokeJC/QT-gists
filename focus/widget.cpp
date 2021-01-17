#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUi ();
    connect (btn, SIGNAL(clicked()), this, SLOT(click ()));
}

Widget::~Widget(){}

void Widget::setupUi (){
    QHBoxLayout *main_layout = new QHBoxLayout(this);
    setWindowTitle ("Фокус со словами");
    setWindowIcon (QIcon(":/ico/QT.png"));
    setFixedSize (250, 50);
    input = new QLineEdit;
    output = new QLineEdit;
    output->setEnabled (false);
    btn = new QPushButton;
    btn->setFixedSize (25, 25);
    btn->setText ("->");
    main_layout->addWidget (input);
    main_layout->addWidget (btn);
    main_layout->addWidget (output);
    setLayout (main_layout);
}

void Widget::click (){
    if(btn->text ()=="->"){
        output->setEnabled (true);
        btn->setText ("<-");
        output->setText (input->text ());
        input->setText ("");
        input->setEnabled (false);
        output->setFocus ();
    } else {
        input->setEnabled (true);
        btn->setText ("->");
        input->setText (output->text ());
        output->setText ("");
        output->setEnabled (false);
        input->setFocus ();
    }
//    qDebug()<< "click";
}
