#ifndef DIALOGCOMP_H
#define DIALOGCOMP_H

#include <QDialog>

namespace Ui {
class DialogComp;
}

class DialogComp : public QDialog
{
    Q_OBJECT

public:
    explicit DialogComp(QWidget *parent = 0);
    ~DialogComp();

    void setBar(int binNum,int progress);

private:
    Ui::DialogComp *ui;
};

#endif // DIALOGCOMP_H
