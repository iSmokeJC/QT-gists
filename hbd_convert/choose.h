#ifndef CHOOSE_H
#define CHOOSE_H

#include <QWidget>
#include <QtWidgets>

class Choose : public QWidget
{
    Q_OBJECT
public:
    Choose(QWidget *parent = nullptr);

signals:
    void check_in(int);
    void check_out(int);
private:
    void setupUi();
};

#endif // CHOOSE_H
