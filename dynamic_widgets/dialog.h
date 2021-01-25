#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSplitter>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "qdynamicbtn.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    void setupUi();
    QVBoxLayout *left_lay;
    QLabel *result;

private slots:
    void on_new_clicked();
    void on_del_clicked();
    void slot_get_id();
};
#endif // DIALOG_H
