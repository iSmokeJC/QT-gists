#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent) {
   QHBoxLayout *lay = new QHBoxLayout;
   QFont font("Times", 28, QFont::Bold);

   label = new QLabel;
   label->setFont (font);
   lay->addWidget(label);
   setLayout (lay);
   label->setText(QTime::currentTime().toString("hh:mm:ss"));
   timer = new QTimer;
   connect(timer, &QTimer::timeout, this, &Dialog::onTimer);
   timer->start(1000);
}

Dialog::~Dialog() {}

void Dialog::onTimer() { label->setText(QTime::currentTime().toString("hh:mm:ss")); }
