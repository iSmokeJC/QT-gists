#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  //    this->layout ()->setSizeConstraint (QLayout::SetFixedSize);
  setFixedSize(400, 300);
  main = new QWidget(this);
  QVBoxLayout *main_lay = new QVBoxLayout(this);
  Choose *choose = new Choose;
  main_lay->addWidget(choose);
  IO *io = new IO;
  main_lay->addWidget(io);
  main->setLayout(main_lay);
  setCentralWidget(main);
}

MainWindow::~MainWindow() {}
