#ifndef DEMPFDIALOG_H
#define DEMPFDIALOG_H

#include <QDialog>

namespace Ui {
class DempfDialog;
}

class DempfDialog : public QDialog
{
    Q_OBJECT
    double dempf;
    int maxD;
public:
    double get();
    explicit DempfDialog(QWidget *parent = 0, int d=1);
    ~DempfDialog();

private slots:
//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

    void on_dempf2_clicked();

    void on_demp1_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::DempfDialog *ui;
};

#endif // DEMPFDIALOG_H
