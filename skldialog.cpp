#include "skldialog.h"
#include "ui_skldialog.h"

sklDialog::sklDialog(QWidget *parent, int sklon, int b) :
    QDialog(parent),
    ui(new Ui::sklDialog)
{
    ui->setupUi(this);
    if(b)
        this->setWindowTitle("Введите коэффициент А");
    else
        this->setWindowTitle("Введите склонение");
    this->move(QPoint(980,400));
    skl=sklon;
    strSkl=QString::number(skl);
    ui->lineEdit->setText(strSkl);
}

sklDialog::~sklDialog()
{
    delete ui;
}

void sklDialog::on_pushButton_clicked()
{
    if(!strSkl.length()||strSkl=="0")
    {
        strSkl="";
        ui->lineEdit->clear();
    }

    strSkl+="1";
    skl=strSkl.toInt();
    if(skl>180)
    {
        strSkl="180";
    }
    if(skl<-180)
    {

        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_2_clicked()
{
    if(!strSkl.length()||strSkl=="0")
    {
        strSkl="";
        ui->lineEdit->clear();
    }

    strSkl+="2";
    skl=strSkl.toInt();
    if(skl>180)
    {
        strSkl="180";
    }
    if(skl<-180)
    {
        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_3_clicked()
{
    if(!strSkl.length()||strSkl=="0")
    {
        strSkl="";
        ui->lineEdit->clear();
    }

    strSkl+="3";
    skl=strSkl.toInt();
    if(skl>180)
    {
        strSkl="180";
    }
    if(skl<-180)
    {
        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_4_clicked()
{
    if(!strSkl.length()||strSkl=="0")
    {
        strSkl="";
        ui->lineEdit->clear();
    }

    strSkl+="4";
    skl=strSkl.toInt();
    if(skl>180)
    {
        strSkl="180";
    }
    if(skl<-180)
    {
        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_5_clicked()
{
    if(!strSkl.length()||strSkl=="0")
    {
        strSkl="";
        ui->lineEdit->clear();
    }

    strSkl+="5";
    skl=strSkl.toInt();
    if(skl>180)
    {
        strSkl="180";
    }
    if(skl<-180)
    {
        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_6_clicked()
{
    if(!strSkl.length()||strSkl=="0")
    {
        strSkl="";
        ui->lineEdit->clear();
    }

    strSkl+="6";
    skl=strSkl.toInt();
    if(skl>180)
    {
        strSkl="180";
    }
    if(skl<-180)
    {
        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_7_clicked()
{
    if(!strSkl.length()||strSkl=="0")
    {
        strSkl="";
        ui->lineEdit->clear();
    }

    strSkl+="7";
    skl=strSkl.toInt();
    if(skl>180)
    {
        strSkl="180";
    }
    if(skl<-180)
    {
        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_8_clicked()
{
    if(!strSkl.length()||strSkl=="0")
    {
        strSkl="";
        ui->lineEdit->clear();
    }

    strSkl+="8";
    skl=strSkl.toInt();
    if(skl>180)
    {
        strSkl="180";
    }
    if(skl<-180)
    {
        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_9_clicked()
{
    if(!strSkl.length()||strSkl=="0")
    {
        strSkl="";
        ui->lineEdit->clear();
    }

    strSkl+="9";
    skl=strSkl.toInt();
    if(skl>180)
    {
        strSkl="180";
    }
    if(skl<-180)
    {
        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_10_clicked()
{
    if(!strSkl.length()||strSkl=="0"||strSkl=="-")
    {
        if(!(strSkl=="-"))
            strSkl="";
        ui->lineEdit->setText(strSkl);
        return;
    }
    strSkl+="0";
    skl=strSkl.toInt();
    if(skl>180)
    {

        strSkl="180";
    }
    if(skl<-180)
    {

        strSkl="-180";
    }
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_13_clicked()
{
    strSkl="";
    skl=0;
    ui->lineEdit->setText("");
}

void sklDialog::on_pushButton_14_clicked()
{
    strSkl=strSkl.remove(strSkl.length()-1,1);
    skl=strSkl.toInt();
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_15_clicked()
{
    if(strSkl==""||skl==0)
    {
        strSkl="";
    } else
    {
        skl=skl*-1;
        strSkl=QString::number(skl);
    }
    ui->lineEdit->setText(strSkl);
}

void sklDialog::on_pushButton_12_clicked()
{
    reject();
}

void sklDialog::on_pushButton_11_clicked()
{
    accept();
}
int sklDialog::getSkl()
{
    return skl;
}
void sklDialog::closeEvent(QCloseEvent* event)
{
    event->accept();
    switch(QMessageBox::warning(this,tr("Подтверждение"),tr("Сохранить изменения?"),QMessageBox::Ok,QMessageBox::Cancel))
    {
    case QMessageBox::Ok: accept(); break;
    case QMessageBox::Cancel:reject();break;
    }
}
