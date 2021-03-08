//
// Created by ism on 07/03/2021.
//

#include "Widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent) {
    setupUi();
}

void Widget::setupUi() {
    auto *v_layout = new QVBoxLayout;
    auto *h_layout = new QHBoxLayout;
    b_group = new QButtonGroup;
    kross_btn = new QRadioButton("x");
    kross_btn->setChecked(true);
    zero_btn = new QRadioButton("o");
    b_group->addButton(kross_btn);
    b_group->addButton(zero_btn);
    connect(b_group, qOverload<int>(&QButtonGroup::buttonClicked), [&]() {
        current = !current;
        toggleBtn(false);
    });

    h_layout->addWidget(kross_btn);
    h_layout->addWidget(zero_btn);
    h_layout->setAlignment(Qt::AlignCenter);

    auto *grid = new QGridLayout;
    grid->setMargin(40);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            auto *btn = new QPushButton;
            btn->setFixedSize(30, 30);
            connect(btn, &QPushButton::clicked, this, &Widget::onClick);
            grid->addWidget(btn, i, j);
        }
    }
    auto *newBtn = new QPushButton("Новая игра");
    connect(newBtn, &QPushButton::clicked, this, &Widget::onNewClick);

    v_layout->addLayout(h_layout);
    v_layout->addLayout(grid);
    v_layout->addWidget(newBtn);
    setLayout(v_layout);
    setWindowTitle("Крестики-нолики");
}

void Widget::onClick() {
    auto *btn = (QPushButton *) sender();
    btn->setText(current ? "X" : "O");
    btn->setEnabled(false);
    current = !current;
    count++;
    toggleBtn(false);
    test();
}

void Widget::onNewClick() {
    QList<QPushButton *> list = this->findChildren<QPushButton *>();
    for (int i = 0; i < list.size() - 1; ++i) {
        auto *bt = list.at(i);
        bt->setText("");
        bt->setEnabled(true);
        current = kross_btn->isChecked();
        toggleBtn(true);
        count = 0;
    }
}

bool Widget::test() {

    QList<QPushButton *> list = this->findChildren<QPushButton *>();
    bool result = false;
    for (int i = 0; i < 3; i++) {
        if (((list.at(i)->text() == "X" || list.at(i)->text() == "O") &&
             list.at(i)->text() == list.at(i + 3)->text() &&
             list.at(i)->text() == list.at(i + 6)->text()) ||
            ((list.at(i * 3)->text() == "X" || list.at(i * 3)->text() == "O") &&
             list.at(i * 3)->text() == list.at(i * 3 + 1)->text() &&
             list.at(i * 3)->text() == list.at(i * 3 + 2)->text()))
            result = true;
    }

    if (((list.at(0)->text() == "X" || list.at(0)->text() == "O") &&
         list.at(0)->text() == list.at(4)->text() &&
         list.at(0)->text() == list.at(8)->text()) ||

        ((list.at(2)->text() == "X" || list.at(2)->text() == "O") &&
         list.at(2)->text() == list.at(4)->text() &&
         list.at(2)->text() == list.at(6)->text()))
        result = true;

    if (result) {
        QString res = "Победитель: ";
        res += current ? "НОЛИК" : "КРЕСТИК";
        QMessageBox::information(this, "WIN!", res);
        onNewClick();
    }
    if (count == 9) {
        QMessageBox::information(this, "DRAW!", "Ничья !!!");
        onNewClick();
    }
}

void Widget::toggleBtn(bool state) {
    kross_btn->setEnabled(state);
    zero_btn->setEnabled(state);
}