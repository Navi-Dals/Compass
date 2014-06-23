#ifndef KOMPASDIALOG_H
#define KOMPASDIALOG_H

#include <QDialog>
#include <kompas.h>

namespace Ui {
class KompasDialog;
}

class KompasDialog : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(double dwidth READ dwidth WRITE setDWidth NOTIFY dwidthChanged)
    Q_PROPERTY(double dheight READ dheight WRITE setDHeight NOTIFY dheightChanged)
public:
    explicit KompasDialog(QWidget *parent = 0);
    ~KompasDialog();
    Kompas *kompas;

    int dwidth(){return m_width;}
    void setDWidth(double arg){m_width=arg;}
    int dheight(){return m_height;}
    void setDHeight(double arg){m_height=arg;}
signals:
    void dwidthChanged();
    void dheightChanged();
private:
    Ui::KompasDialog *ui;
    double m_height;
    double m_width;
private slots:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);
};

#endif // KOMPASDIALOG_H
