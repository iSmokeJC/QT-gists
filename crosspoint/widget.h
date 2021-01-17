#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "field.h"
#include <QtWidgets>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void setupUi();
public slots:
    void new_game();

private:
    Field *field;
    QRadioButton *cross;
};
#endif // WIDGET_H
