#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) { setupUi(); }

Widget::~Widget() {}

void Widget::setupUi() {
  QHBoxLayout *h_lay1 = new QHBoxLayout;
  QHBoxLayout *h_lay2 = new QHBoxLayout;
  QHBoxLayout *h_lay3 = new QHBoxLayout;
  QVBoxLayout *v_lay1 = new QVBoxLayout;
  QLineEdit *edit = new QLineEdit;

  int j = 0;
  for (char i = 'a'; i <= 'z'; ++i, ++j) {
    QPushButton *btn = new QPushButton(QChar(i));
    btn->setFixedSize(20, 20);
    connect(btn, &QPushButton::clicked, this,
            [=]() { edit->setText(edit->text() + list.at(j)); });

    if (i >= 'm') {
      h_lay2->addWidget(btn);
    } else {
      h_lay1->addWidget(btn);
    }
  }
  QPushButton *btn2 = new QPushButton("C");
  btn2->setFixedSize(25, 25);
  connect(btn2, &QPushButton::clicked, this, [=]() { edit->setText(""); });

  v_lay1->addLayout(h_lay1);
  v_lay1->addLayout(h_lay2);
  h_lay3->addWidget(edit);
  h_lay3->addWidget(btn2);
  v_lay1->addLayout(h_lay3);

  setWindowTitle("Азбука Морзе");
  setLayout(v_lay1);
}
