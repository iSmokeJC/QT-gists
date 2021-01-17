#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) { setupUi(); }

Widget::~Widget() {}

void Widget::setupUi() {
   QFormLayout *layout = new QFormLayout(this);
   for (int i = 0; i < 4; ++i) {
      QCheckBox *ch = new QCheckBox("checkbox " + QString::number(i));
      QLineEdit *ed = new QLineEdit("lineedit " + QString::number(i));
      layout->addRow(ch, ed);
      //  connect(ch, &QCheckBox::clicked, this, [ed](bool checked) { ed->setVisible(!checked);});
      connect(ch, &QCheckBox::stateChanged, [=](bool state) { ed->setVisible(!state); });
   }
   setWindowTitle("Прятки виджетов");
}
