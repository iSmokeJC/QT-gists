#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "outpane.h"
#include "inpane.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    Outpane *outpane;
    Inpane *inpane;
    QPushButton *btn;

public slots:
    void onclick();

private:
    void setupUi();
};
#endif // WIDGET_H
