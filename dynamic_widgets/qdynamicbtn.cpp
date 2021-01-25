#include "qdynamicbtn.h"

QDynamicBtn::QDynamicBtn(QWidget *parent):QPushButton (parent) {
    id = ++BtnID;
}

QDynamicBtn::~QDynamicBtn(){
    BtnID--;
}

int QDynamicBtn::getID(){
    return id;
}

int QDynamicBtn::BtnID = 0;
