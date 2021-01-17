#ifndef INPANE_H
#define INPANE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>

class Inpane: public QWidget
{
    Q_OBJECT
public:
    Inpane(QWidget *parent = nullptr);
    ~Inpane();

    QLineEdit *firstedit, *secondedit;

private:
    void setupUi();

};

#endif // INPANE_H
