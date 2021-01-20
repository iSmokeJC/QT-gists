#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTime>
#include <QTimer>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QTimer *timer;
    QLabel *label;

private slots:
    void onTimer();
};
#endif // DIALOG_H
