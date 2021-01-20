#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QCloseEvent>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QCheckBox *box = new QCheckBox("Hide to tray");

protected:
    void closeEvent(QCloseEvent *event);

private:
    void setupUi();
    QSystemTrayIcon *trayIcon;

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
};
#endif // DIALOG_H
