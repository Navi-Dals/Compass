#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <kompas.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(double dwidth READ dwidth WRITE setDWidth NOTIFY dwidthChanged)
    Q_PROPERTY(double dheight READ dheight WRITE setDHeight NOTIFY dheightChanged)
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Kompas *kompas;

    int dwidth(){return m_width;}
    void setDWidth(double arg){m_width=arg;}
    int dheight(){return m_height;}
    void setDHeight(double arg){m_height=arg;}

signals:
    void dwidthChanged();
    void dheightChanged();
private:
    Ui::MainWindow *ui;
    double m_height;
    double m_width;
private slots:
    void closeEvent(QCloseEvent *);
    void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
