#include "choose.h"

Choose::Choose(QWidget *parent) : QWidget(parent) { setupUi(); }

void Choose::setupUi() {
  QHBoxLayout *main_lay = new QHBoxLayout;
  QVBoxLayout *input_lay = new QVBoxLayout;
  QVBoxLayout *output_lay = new QVBoxLayout;
  QButtonGroup *in_btn_group = new QButtonGroup;
  QButtonGroup *out_btn_group = new QButtonGroup;
  QGroupBox *in_box = new QGroupBox("Input");
  QGroupBox *out_box = new QGroupBox("Output");

  QStringList names = {"Bin", "Dec", "Hex"};
  QVector<qint8> values = {2, 10, 16};            // значения сс

  for (qint8 i = 0; i < names.size(); ++i) {
    QRadioButton *r_in = new QRadioButton(names[i]);
    QRadioButton *r_out = new QRadioButton(names[i]);
    if (names[i] == "Dec") {
      r_in->setChecked(true);
      r_out->setChecked(true);
    }

    in_btn_group->addButton(r_in, values[i]);
    input_lay->addWidget(r_in);
    out_btn_group->addButton(r_out, values[i]);
    output_lay->addWidget(r_out);


    // по изменению радиобаттонов, посылается сигнал со значением основания сс
    connect(r_in, &QRadioButton::clicked , this, [=](){
        emit(check_in (in_btn_group->checkedId ()));
    });
    connect(r_out, &QRadioButton::clicked , this, [=](){
        emit(check_out (out_btn_group->checkedId ()));
    });

  }

  in_box->setLayout(input_lay);
  out_box->setLayout(output_lay);
  main_lay->addWidget(in_box);
  main_lay->addWidget(out_box);
  setLayout(main_lay);
}
