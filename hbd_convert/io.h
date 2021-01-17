#ifndef IO_H
#define IO_H

#include <QWidget>
#include <QtWidgets>

class IO : public QWidget {
  Q_OBJECT
public:
  IO(QWidget *p = nullptr);

private:
  void setupUi();
};

#endif // IO_H
