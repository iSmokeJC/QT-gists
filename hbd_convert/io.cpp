#include "io.h"

IO::IO(QWidget *parent):QWidget (parent){
    setupUi ();

}

void IO::setupUi(){
    QGridLayout *main_lay = new QGridLayout(this);
    main_lay->addWidget (new QLabel("Input here: "), 0, 0);
    main_lay->addWidget (new QLabel("Result: "), 2, 0);
    QLineEdit *input = new QLineEdit;
    QLineEdit *output = new QLineEdit;
    output->setReadOnly (true);
    main_lay->addWidget (input, 1, 0);
    main_lay->addWidget (output, 3, 0);
    QCheckBox *in_format = new QCheckBox("format");
    QCheckBox *out_format = new QCheckBox("format");
    main_lay->addWidget (in_format, 0, 4);
    main_lay->addWidget (out_format, 2, 4);

}
