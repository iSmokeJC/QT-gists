#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtWidgets>

class Widget : public QWidget {
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private:
  void setupUi();

  QLineEdit *input, *input2, *output;

public slots:
  void action();
};
#endif // WIDGET_H
