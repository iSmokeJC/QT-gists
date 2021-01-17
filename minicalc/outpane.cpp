#include "outpane.h"

Outpane::Outpane(QWidget *parent):QWidget (parent)
{
    setupUi();
}

Outpane::~Outpane (){};

void Outpane::setupUi(){
    QFormLayout *layout = new QFormLayout(this);
    layout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
    sum = new QLCDNumber;
    div = new QLCDNumber;
    mul = new QLCDNumber;
    sub = new QLCDNumber;

    layout->addRow ("Сумма: ", sum);
    layout->addRow ("Разность: ", sub);
    layout->addRow ("Произведение: ", mul);
    layout->addRow ("Частное: ", div);

    setLayout (layout);
}
