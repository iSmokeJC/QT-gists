#include "dialog.h"

#include <QSizePolicy>

Dialog::Dialog(QWidget *parent) : QDialog(parent) { initUi(); }

Dialog::~Dialog() {}

void Dialog::initUi() {
   QHBoxLayout *layout = new QHBoxLayout;
   QLineEdit *edit = new QLineEdit;
   QPushButton *button = new QPushButton("Clear");
   layout->addWidget(edit);
   layout->addWidget(button);
   setLayout(layout);

   connect (button, &QPushButton::clicked, edit, &QLineEdit::clear);

   QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
   QRegExp ipRegexp("^" + ipRange + "\\." + ipRange + "\\." + ipRange + "\\." + ipRange + "$");
   QRegExpValidator *validator = new QRegExpValidator(ipRegexp, edit);
   edit->setValidator (validator);

//   setSizePolicy (QSizePolicy::Minimum, QSizePolicy::Fixed);
//   setFixedSize (size ());
//    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
   this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}
