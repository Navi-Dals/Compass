#include "dempfdialog.h"
#include "ui_dempfdialog.h"

DempfDialog::DempfDialog(QWidget *parent, int d) :
    QDialog(parent),
    ui(new Ui::DempfDialog)
{
    ui->setupUi(this);
    dempf=d;
    maxD=64;
    ui->lineEdit->setText(QString::number(dempf));
    this->move(QPoint(880,560));
}

DempfDialog::~DempfDialog()
{
    delete ui;
}

void DempfDialog::on_dempf2_clicked()
{
    if(dempf<maxD)
        dempf*=2;
    ui->lineEdit->setText(QString::number(dempf));
}

void DempfDialog::on_demp1_clicked()
{
    if(dempf>1)
        dempf/=2;
    ui->lineEdit->setText(QString::number(dempf));
}

void DempfDialog::on_pushButton_3_clicked()
{
    accept();
}

void DempfDialog::on_pushButton_4_clicked()
{
    reject();
}

double DempfDialog::get()
{
    return dempf;
}
