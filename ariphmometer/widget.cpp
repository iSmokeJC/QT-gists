#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) { setupUi(); }

Widget::~Widget() {}

void Widget::setupUi() {
  QStringList list = {"+", "-", "*"};

  QHBoxLayout *lay = new QHBoxLayout;
  input = new QLineEdit;
  input->setPlaceholderText("0");
  input2 = new QLineEdit;
  input2->setPlaceholderText("0");
  output = new QLineEdit;
  output->setEnabled(false);
  lay->addWidget(input);

  for (int i = 0; i < list.size(); ++i) {
    QPushButton *bt = new QPushButton(list.at(i));
    bt->setFixedSize(25, 25);
    bt->setObjectName(list.at(i));
    lay->addWidget(bt);
    connect(bt, &QPushButton::clicked, this, &Widget::action);
  }
  lay->addWidget(input2);
  lay->addWidget(new QLabel(" = "));
  lay->addWidget(output);

  setLayout(lay);
}

void Widget::action() {
  QString op = sender()->objectName();
  int result = 0;
  int x = input->text().toInt();
  int y = input2->text().toInt();
  if (op == "+") {
    result = x + y;
  } else if (op == "-") {
    result = x - y;
  } else {
    result = x * y;
  }
  output->setText(QString::number(result));
}
