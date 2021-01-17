#ifndef OUTPANE_H
#define OUTPANE_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QLCDNumber>

class Outpane : public QWidget{
    Q_OBJECT


public:
    Outpane(QWidget *parent = nullptr);
    ~Outpane();

    QLCDNumber *sum, *sub, *div, *mul;

private:
    void setupUi();

};

#endif // OUTPANE_H
