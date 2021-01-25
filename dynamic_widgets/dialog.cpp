#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent) { setupUi(); }

Dialog::~Dialog() {}

void Dialog::setupUi() {
   QVBoxLayout *main_lay = new QVBoxLayout;
   QSplitter *splitter = new QSplitter(Qt::Horizontal);

   left_lay = new QVBoxLayout;
   QVBoxLayout *right_lay = new QVBoxLayout;

   QWidget *left = new QWidget(this);
   QWidget *right = new QWidget(this);
   splitter->addWidget(left);
   splitter->addWidget(right);
   splitter->setStretchFactor(0, 1);
   splitter->setStretchFactor(1, 0);
   main_lay->addWidget(splitter);

   QPushButton *newBtn = new QPushButton("New button");
   QPushButton *delBtn = new QPushButton("Delete button");
   result = new QLabel("LABEL");
   right_lay->addWidget(result);
   right_lay->addWidget(newBtn);
   right_lay->addWidget(delBtn);
   right->setLayout(right_lay);

   left->setLayout(left_lay);
   setLayout(main_lay);

   connect(newBtn, &QPushButton::clicked, this, &Dialog::on_new_clicked);
   connect(delBtn, &QPushButton::clicked, this, &Dialog::on_del_clicked);
}

void Dialog::on_new_clicked() {
   QDynamicBtn *btn = new QDynamicBtn(this);
   btn->setText("Button " + QString::number(btn->getID()));
   left_lay->addWidget(btn);
   connect (btn, &QPushButton::clicked, this, &Dialog::slot_get_id);
}

void Dialog::on_del_clicked() {
   for (int i = 0; i < left_lay->count(); ++i) {
      QDynamicBtn *btn = qobject_cast<QDynamicBtn *>(left_lay->itemAt(i)->widget());
      if (btn->getID() == result->text().toInt()) {
         btn->hide();
         delete btn;
         result->clear ();
      }
   }
}

void Dialog::slot_get_id() {
   QDynamicBtn *btn = qobject_cast<QDynamicBtn *>(sender());
   result->setText(QString::number(btn->getID()));
}
