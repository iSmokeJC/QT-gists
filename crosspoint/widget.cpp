#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) { setupUi(); }

Widget::~Widget() {}

void Widget::setupUi() {
  field = new Field;
  QVBoxLayout *lay = new QVBoxLayout(this);
  QHBoxLayout *ch_lay = new QHBoxLayout;
  cross = new QRadioButton("X");
  cross->setChecked(true);
  QRadioButton *zero = new QRadioButton("O");

  connect(cross, &QRadioButton::toggled, field, &Field::state_change);
  connect(cross, &QRadioButton::toggled, cross, &QRadioButton::setEnabled);

  ch_lay->addWidget(cross);
  ch_lay->addWidget(zero);

  QPushButton *btn = new QPushButton("NEW GAME");
  connect(btn, &QPushButton::clicked, this, &Widget::new_game);
  lay->addLayout(ch_lay);
  lay->addWidget(field);
  lay->addWidget(btn);
}

void Widget::new_game() {
  field->clear_field();
  cross->setChecked(true);
}
