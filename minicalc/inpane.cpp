#include "inpane.h"

Inpane::Inpane(QWidget *parent):QWidget (parent){
    setupUi ();
}

Inpane::~Inpane (){}

void Inpane::setupUi(){
    QLabel *first = new QLabel("Первое число (целое): ");
    QLabel *second = new QLabel("Второе число (целое): ");
    firstedit = new QLineEdit;
    secondedit = new QLineEdit;

    QIntValidator *validator = new QIntValidator;
    firstedit->setValidator (validator);
    secondedit->setValidator (validator);
    firstedit->setPlaceholderText ("0");
    secondedit->setPlaceholderText ("0");


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget (first);
    layout->addWidget (firstedit);
    layout->addWidget (second);
    layout->addWidget (secondedit);

    setLayout (layout);
}
