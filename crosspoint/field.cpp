#include "field.h"

Field::Field(QWidget *p) : QWidget(p) { setupUi(); }

void Field::setupUi() {
  lay = new QGridLayout(this);
  state = true;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      QPushButton *key = new QPushButton;
      key->setFixedSize(40, 40);
      key->setProperty("x", i);
      key->setProperty("y", j);
      keyConnect(key, i, j);
      lay->addWidget(key, i, j);
    }
  }
}

void Field::state_change() { state = !state; }

void Field::clear_field() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      QPushButton *b =
          qobject_cast<QPushButton *>(lay->itemAtPosition(i, j)->widget());
      b->setText("");
      keyConnect(b, i, j);
    }
  }
  state = true;
}

void Field::keyConnect(QPushButton *key, int x, int y) {
  connect(key, &QPushButton::clicked, [=]() {
    key->setText(QString(pic[state]));
    state_change();
    field[x][y] = pic[state];
    key->disconnect();
    test ();
  });
}

bool Field::test() {
  bool result = false;
  for (int i = 0; i < 3; ++i) {
      if(testLine (field[i])) qDebug() << "win";
  }
  return false;
}

bool Field::testLine(char *line){
    for (int i = 0; i<2; ++i){
        if(line[i]!=' ' && line[i]!=line[i+1]) return false;
    }
    return true;
}
