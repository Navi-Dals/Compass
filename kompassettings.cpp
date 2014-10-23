#include "kompassettings.h"
#include "ui_kompassettings.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>


kompasSettings::kompasSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kompasSettings)
{
    ui->setupUi(this);
    ui->Interface_c->setCurrentIndex(0);
    foreach (QSerialPortInfo info, QSerialPortInfo::availablePorts())
    {
        ui->Com_n->addItems(QStringList(info.portName()));
    }
    ui->speed->setCurrentIndex(3);
    ui->data_bits->setCurrentIndex(3);
    ui->bit_stop->setCurrentIndex(0);
    ui->parity_c->setCurrentIndex(0);
    m_interface=0;
    ui->Com_n->setCurrentIndex(0);
    m_name_COM=ui->Com_n->currentText();
    m_Baud_rate=9600;
    m_Number_of_data_bits=8;
    m_Stop_bits=1;
    m_Parity=0;
    m_accept = true;
}

kompasSettings::~kompasSettings()
{
    delete ui;
}

void kompasSettings::closeEvent(QCloseEvent *event)
{
    if(m_accept)
    switch(QMessageBox::warning(this,tr("Подтверждение"),tr("Сохранить изменения?"),QMessageBox::Ok,QMessageBox::Cancel))
    {
    case QMessageBox::Ok:
        m_interface=ui->Interface_c->currentIndex();
        m_name_COM=ui->Com_n->currentText();
        m_Baud_rate=ui->speed->currentText().toInt();
        m_Number_of_data_bits=ui->data_bits->currentIndex()+5;
        m_Stop_bits=ui->bit_stop->currentIndex()+1;
        if(ui->parity_c->currentIndex() == 0)
        {
            m_Parity=0;
        }
        else
        {
            m_Parity=ui->parity_c->currentIndex()+1;
        }
        break;
    case QMessageBox::Cancel:
        break;
    }
    event->accept();
    ui->label_Revert->setText("");
}
void kompasSettings::on_Interface_c_currentIndexChanged(const QString &arg1)
{
    if(arg1=="RS-232")
    {
        ui->speed->setCurrentIndex(2);
        ui->data_bits->setCurrentIndex(3);
        ui->bit_stop->setCurrentIndex(0);
        ui->parity_c->setCurrentIndex(0);
    }
    else if(arg1=="RS-485")
    {
        ui->speed->setCurrentIndex(3);
        ui->data_bits->setCurrentIndex(0);
        ui->bit_stop->setCurrentIndex(1);
        ui->parity_c->setCurrentIndex(1);
     }
    else if(arg1=="MIL-STD-1553")
     {
        ui->speed->setCurrentIndex(4);
        ui->data_bits->setCurrentIndex(1);
        ui->bit_stop->setCurrentIndex(1);
        ui->parity_c->setCurrentIndex(2);
      }
}
void kompasSettings::setSettings()
{
    ui->Com_n->setEditText(m_name_COM);
    ui->Interface_c->setCurrentIndex(m_interface);
    ui->speed->setEditText(QString::number(m_Baud_rate));
    ui->data_bits->setEditText(QString::number(m_Number_of_data_bits));
    ui->bit_stop->setEditText(QString::number(m_Stop_bits));
    ui->parity_c->setEditText(QString::number(m_Parity));
}

int kompasSettings::exec()
{
    setSettings();
    m_accept = true;
    QDialog::exec();
    return 0;
}

void kompasSettings::on_buttonBox_clicked(QAbstractButton *button)
{
    if(button->text()=="OK")
    {
        m_interface=ui->Interface_c->currentIndex();
        ui->Com_n->setCurrentIndex(1);
        m_name_COM=ui->Com_n->currentText();
        m_Baud_rate=ui->speed->currentText().toInt();
        m_Number_of_data_bits=ui->data_bits->currentIndex()+5;
        m_Stop_bits=ui->bit_stop->currentIndex()+1;
        if(ui->parity_c->currentIndex() == 0)
        {
            m_Parity=0;
        }
        else
        {
            m_Parity=ui->parity_c->currentIndex()+1;
        }
        m_accept = false;
        close();
    }
    else
    {
        m_accept = false;
        close();
    }
}

void kompasSettings::on_buttonRevert_clicked()
{
    emit revertRequest();
    qDebug()<<"Here";
}

void kompasSettings::setLabel(QString msg)
{
    ui->label_Revert->setText(msg);

}
