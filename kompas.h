#ifndef KOMPAS_H
#define KOMPAS_H

#include <QObject>
#include <QWidget>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QtDeclarative/QDeclarativeContext>
#include <kompassettings.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include "skldialog.h"
#include "dempfdialog.h"



class Kompas : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int angle READ angle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(double fractPart READ fractPart WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(double afterComma READ afterComma WRITE setAfterComma NOTIFY afterCommaChanged)
    Q_PROPERTY(double fullangle READ fullangle WRITE setAngle NOTIFY angleChanged)
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
    Q_PROPERTY(int supply READ supply WRITE setSupply NOTIFY supplyChanged)
    Q_PROPERTY(int connect_state READ connect_state WRITE setConnect_state NOTIFY connect_stateChanged)
    Q_PROPERTY(int Connect READ Connect WRITE setConnect NOTIFY connectChanged)
    Q_PROPERTY(int color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(double  skl READ skl WRITE setSkl NOTIFY sklChanged)
    Q_PROPERTY(double  savedCourse READ savedCourse WRITE setSavedCourse NOTIFY savedCourseChanged)
    Q_PROPERTY(bool  savedCourseVisibility READ savedCourseVisibility WRITE setSavedCourseVisibility NOTIFY savedCourseVisibilityChanged)
    Q_PROPERTY(double  pitch READ pitch WRITE setPitch NOTIFY pitchChanged)
    Q_PROPERTY(double  roll READ roll WRITE setRoll NOTIFY rollChanged)
    Q_PROPERTY(int  lastAngle READ lastAngle WRITE setLastAngle NOTIFY angleChanged)
    Q_PROPERTY(bool  infoVisibility READ infoVisibility WRITE setInfoVisibility NOTIFY infoVisibilityChanged)
    Q_PROPERTY(bool  trueMagneticCourse READ trueMagneticCourse WRITE setTrueMagneticCourse NOTIFY trueMagneticCourseChanged)
public:
    explicit Kompas(QWidget *parent = 0);
    ~Kompas();


public slots:

    Q_INVOKABLE void on();
    Q_INVOKABLE void off();
    Q_INVOKABLE void startThread();
    Q_INVOKABLE void quitThread();
    Q_INVOKABLE void showMenu();
    Q_INVOKABLE void changeColor();
    Q_INVOKABLE void changeSkl();
    Q_INVOKABLE void changeA();
    Q_INVOKABLE void saveCourse();
    Q_INVOKABLE void changeDempf();
    Q_INVOKABLE void changeInfoScreenVisibility();
    Q_INVOKABLE void changeTrueMagneticCourse();


    void setSupply(int st){m_supply=st;}
    int supply(){return m_supply;}

    void setState(int st){m_state=st;}
    int state(){return m_state;}

    void setConnect_state(int st){m_connect_state=st;}
    int connect_state(){return m_connect_state;}

    void setConnect(int st){m_connect=st;}
    int Connect(){return m_connect;}

    int angle() const{return m_angle;}
    void setAngle(double a);

    int color() const{return m_color;}
    void setColor(int a){m_color=a;}

    int savedCourse() const{return m_savedCourse;}
    void setSavedCourse(double a){m_savedCourse=a;}

    double afterComma() const{return m_afterComma;}
    void setAfterComma(double a){m_afterComma=a;}

    int savedCourseVisibility() const{return m_savedCourseVisibility;}
    void setSavedCourseVisibility(bool a){m_savedCourseVisibility=a;}

    int infoVisibility() const{return m_infoVisibility;}
    void setInfoVisibility(bool a){m_infoVisibility=a;}

    double skl() const {return m_skl;}
    Q_INVOKABLE void setSkl(double a) {m_skl=a;emit sklChanged();}

    double fractPart() const{return m_fractPart;}
    double fullangle() const{return m_fullangle;}

    void setRoll(double st);
    double roll(){return m_roll;}

    void setPitch(double st);
    double pitch(){return m_pitch;}

    void setLastAngle(int st){m_lastAngle=st;}
    int lastAngle()const {return m_lastAngle;}

    void updateSettings();
    void ShowAngle();

    void setTrueMagneticCourse(bool st){m_tmCourse = st;}
    bool trueMagneticCourse() const {return m_tmCourse;}



signals:
    void angleChanged();
    void stateChanged();
    void supplyChanged();
    void connect_stateChanged();
    void connectChanged();
    void colorChanged();
    void menuRequest();
    void sklChanged();
    void savedCourseChanged();
    void savedCourseVisibilityChanged();
    void pitchChanged();
    void rollChanged();
    void afterCommaChanged();
    void infoVisibilityChanged();
    void trueMagneticCourseChanged();

private:
    bool m_tmCourse;
    double m_dempf;
    double m_coef_A;
    double m_last;
    double m_last2;
    int m_angle;
    double m_fractPart;
    double m_fullangle;
    double m_afterComma;
    int m_state;
    int m_supply;
    int m_connect_state;
    int m_connect;
    int m_color;
    double m_skl;
    double m_savedCourse;
    bool m_savedCourseVisibility;
    double m_pitch;
    double m_roll;
    int m_lastAngle;
    double m_lastAngle1;
    double m_sum;
    int m_con;
    int m_con1;
    int m_temp;
    bool m_infoVisibility;
    double m_summ_ang;

    QTimer *timer;

    double toDec(QBitArray,int);
public:
    QThread *kompasThread;
    kompasSettings *settings;
    QSerialPort *port;
};


#endif // KOMPAS_H
