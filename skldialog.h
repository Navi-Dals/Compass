#ifndef SKLDIALOG_H
#define SKLDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>

namespace Ui {
class sklDialog;
}

class sklDialog : public QDialog
{
    Q_OBJECT
    QString strSkl;
    int skl;
public:

    explicit sklDialog(QWidget *parent = 0,int sklon = 0,int b=0);
    int getSkl();
    ~sklDialog();

private slots:

    void closeEvent(QCloseEvent* );

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::sklDialog *ui;
};

#endif // SKLDIALOG_H
