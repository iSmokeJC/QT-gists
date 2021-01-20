#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent) { setupUi(); }

Dialog::~Dialog() {}

void Dialog::setupUi() {
   QVBoxLayout *lay = new QVBoxLayout;
   lay->addWidget(box);
   setLayout(lay);

   setWindowFlags(Qt::Window);
   setFixedSize(200, 75);
   setWindowTitle("Tray program");

   QIcon mainIcon(":/img/QT.png");
   trayIcon = new QSystemTrayIcon(this);

   // не работает на диалоге, очевидно только для MainWindow
   // trayIcon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));
   trayIcon->setToolTip("Tray Program" "\n" "Работа со сворачиванием программы трей");
   trayIcon->setIcon(mainIcon);
   setWindowIcon(mainIcon);

   QMenu *menu = new QMenu(this);
   QAction *viewWindow = new QAction("Show", this);
   QAction *quitAction = new QAction("Exit", this);
   connect(viewWindow, &QAction::triggered, this, &Dialog::show);
   connect(quitAction, &QAction::triggered, this, &Dialog::close);

   menu->addAction(viewWindow);
   menu->addAction(quitAction);

   trayIcon->setContextMenu(menu);
   trayIcon->show();

   connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this,
           SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void Dialog::closeEvent(QCloseEvent *event) {
   if (this->isVisible() && box->isChecked()) {
      event->ignore();
      this->hide();
      QSystemTrayIcon::MessageIcon icon =
         QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

      trayIcon->showMessage("Tray Program", "Some text", icon, 2000);
   }
}

void Dialog::iconActivated(QSystemTrayIcon::ActivationReason reason) {
   if (reason == QSystemTrayIcon::Trigger && box->isChecked()) {
      if (!this->isVisible()) {
         this->show();
      } else {
         this->hide();
      }
   }
}
