#ifndef KOMPASSETTINGS_H
#define KOMPASSETTINGS_H

#include <QDialog>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QAbstractButton>

namespace Ui {
class kompasSettings;
}

class kompasSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit kompasSettings(QWidget *parent = 0);
    ~kompasSettings();

    void setLabel(QString msg);
    
private:
    Ui::kompasSettings *ui;
    bool m_accept;
public:
    int m_interface;

    QString m_name_COM;
    int m_Baud_rate;
    int m_Number_of_data_bits;
    int m_Stop_bits;
    int m_Parity;
    void setSettings();

private slots:
    void closeEvent(QCloseEvent *);
    void on_Interface_c_currentIndexChanged(const QString &arg1);
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_buttonRevert_clicked();

public slots:
    int exec();
signals:
    void revertRequest();
};

#endif // KOMPASSETTINGS_H
