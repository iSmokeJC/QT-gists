#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) { setupUi(); }

Widget::~Widget() {}

void Widget::setupUi() {
  QVBoxLayout *ch_lay = new QVBoxLayout;

  QStringList list = {"Чисбургер", "Гамбургер", "Кока-кола", "Наггетсы"};
  QVector<QCheckBox *> *boxes = new QVector<QCheckBox *>();

  for (QString s : list) {
    QCheckBox *ch = new QCheckBox(s);
    ch_lay->addWidget(ch);
    boxes->append(ch);
  }

  QPushButton *btn = new QPushButton("Заказать");
  ch_lay->addWidget(btn);
  QPlainTextEdit *edit = new QPlainTextEdit;
  ch_lay->addWidget(edit);

  connect(btn, &QPushButton::clicked, this, [=]() {
    edit->setPlainText("Ваш заказ:\n");
    for (QCheckBox *b : *boxes) {
      if (b->isChecked()) {
        edit->appendPlainText(b->text());
      }
    }
  });

  setWindowTitle("Заказ в Макдональдсе");
  setLayout(ch_lay);
}
