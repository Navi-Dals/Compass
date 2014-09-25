#include "dialogcomp.h"
#include "ui_dialogcomp.h"

DialogComp::DialogComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogComp)
{
    ui->setupUi(this);
}

DialogComp::~DialogComp()
{
    delete ui;
}

void DialogComp::setBar(int binNum, int progress)
{
    switch(binNum)
    {
    case 0:
        ui->bin0->setValue(progress);
        break;
    case 1:
        ui->bin1->setValue(progress);
        break;
    case 2:
        ui->bin2->setValue(progress);
        break;
    case 3:
        ui->bin3->setValue(progress);
        break;
    case 4:
        ui->bin4->setValue(progress);
        break;
    case 5:
        ui->bin5->setValue(progress);
        break;
    case 6:
        ui->bin6->setValue(progress);
        break;
    case 7:
        ui->bin7->setValue(progress);
        break;
    }
}
