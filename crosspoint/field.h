#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QtWidgets>


class Field : public QWidget {
  Q_OBJECT
public:
  Field(QWidget *parent = nullptr);
  void setupUi();
  bool state;

private:
  bool test();
  char pic[2]{'O', 'X'};
  char field[3][3]{{' '}};

  QGridLayout *lay;
  void keyConnect(QPushButton *, int, int);
  bool testLine(char *line);

public slots:
  void state_change();
  void clear_field();
};

#endif // FIELD_H
