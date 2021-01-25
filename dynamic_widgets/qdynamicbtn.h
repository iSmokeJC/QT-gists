#ifndef QDYNAMICBTN_H
#define QDYNAMICBTN_H

#include <QPushButton>

class QDynamicBtn : public QPushButton
{
    Q_OBJECT
public:
    QDynamicBtn(QWidget *parent = nullptr);
    ~QDynamicBtn();
    static int BtnID;
    int getID();

private:
    int id = 0;
};



#endif // QDYNAMICBTN_H
