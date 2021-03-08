//
// Created by ism on 07/03/2021.
//

#ifndef CROSS_WIDGET_H
#define CROSS_WIDGET_H


#include <QtWidgets>

class Widget : public QWidget {
public:
    explicit Widget(QWidget *parent = nullptr);

private:
    QRadioButton *kross_btn;
    QRadioButton *zero_btn;
    QButtonGroup *b_group;

    int count = 0;
    bool current = true;
    void setupUi();

public slots:
    void onClick();
    void onNewClick();
    bool test();
    void toggleBtn(bool state);
};


#endif //CROSS_WIDGET_H
