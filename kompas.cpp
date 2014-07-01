#include "kompas.h"
#include <QDebug>
#include <cmath>
#include <QInputDialog>
#include <math.h>

double Round(double st,int count);

Kompas::Kompas(QWidget *parent) :
    QWidget(parent)
{
    m_dempf=2;
    m_tmCourse = true;
    m_coef_A=0;
    m_last=0;
    m_last2=0;
    m_angle=0;
    m_fractPart=0;
    m_fullangle=0;
    m_state=0;
    m_supply=0;
    m_connect_state=0;
    m_connect=0;
    m_color=0;
    m_skl=0;
    m_savedCourse=0;
    m_roll=0;
    m_pitch=0;
    m_afterComma=0;
    m_lastAngle=0;
    m_lastAngle1=0;
    m_sum=0;
    m_con=0;
    m_con1=0;
    m_summ_ang=0;
    m_infoVisibility=false;
    m_savedCourseVisibility=false;
    kompasThread = new QThread(this);
    settings = new kompasSettings(parent);
    port = new QSerialPort;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ShowAngle()));
}

void Kompas::on()
{
    timer->start(2000);
    m_state=1;
    emit stateChanged();
    m_connect_state=1;
    emit connect_stateChanged();
    qDebug()<<"state = 1 ON";
}

void Kompas::ShowAngle()
{
    double arg=qrand()%40+80;
    arg=arg/10+90;
    setAngle(arg);
}

/*
Output Data: 18 bytes:
Data          Type ByteOffset   Description

Roll          Kang 0-1          Compass Roll

Pitch         Kang 2-3          Compass Pitch

Azimuth       Kang 4-5          Compass Azimuth

Rightward     int  6-7          Rightward acceleration
acceleration
Forward       int  8-9          Forward acceleration
acceleration
Upward        int 10-11         Upward acceleration
acceleration
Rightward     int 12-13         Magnetometer reading in the local-coordinates rightward direction
magnetometer
Forward       int 14-15         Magnetometer reading in the local-coordinates forward direction
magnetometer
Upward        int 16-17         Magnetometer reading in the local-coordinates upward direction
magnetometer */

//void Kompas::on()
//{
//    qDebug()<<settings->m_name_COM;
//    port->setPortName(settings->m_name_COM);
//    if (port->open(QIODevice::ReadWrite))
//    {
//        updateSettings();
//        QSerialPortInfo *info = new QSerialPortInfo(*port);
//        qDebug() << "Name        : " << info->portName();
//        qDebug() << "Description : " << info->description();
//        qDebug() << "Manufacturer: " << info->manufacturer();
//        qDebug() << "BaudRate: " << port->baudRate();
//        qDebug() << "Parity: " << port->parity();
//        qDebug() << "Data bits: " << port->dataBits();
//        qDebug() << "Stop Bits: " << port->stopBits();
//        delete info;
//        m_state=1;
//        emit stateChanged();
//        m_connect_state=1;
//        emit connect_stateChanged();
//        qDebug()<<"state = 1 ON";
//        qDebug()<<settings->m_name_COM<<"opened";

//        if(port->waitForReadyRead(1000))
//        {
//            QString data;
//            QByteArray ByteArray;
//            while(m_state)
//            {
//                qint64 byteAvail = port->bytesAvailable();
//                qApp->processEvents();
//                if(byteAvail >=23)
//                {
//                    ByteArray = port->readAll();
//                    data = data.fromLocal8Bit(ByteArray).trimmed();
//                    if(ByteArray[3]=='p')
//                    {
//                        QBitArray bitdata(144),two_bytes(16);
//                        for(int i = 0,j; i < 144; ++i)
//                        {
//                            j=i/8;
//                            if(j<=18)
//                                bitdata[i] = ByteArray[j] & (1 << i%8);
//                            else
//                                break;
//                        }
//                        /*qDebug()<<"First Start byte:"<<ByteArray[0];
//                        for(int i=0,j=7;i<8,j>=0;i++,j--){byte[j]=bitdata[i];} qDebug()<<byte;
//                        qDebug()<<"Second Start byte:"<<ByteArray[1];
//                        for(int i=8,j=7;i<16,j>=0;i++,j--){byte[j]=bitdata[i];} qDebug()<<byte;
//                        qDebug()<<"Third Start byte:"<<ByteArray[2];
//                        for(int i=16,j=7;i<24,j>=0;i++,j--){byte[j]=bitdata[i];} qDebug()<<byte;
//                        qDebug()<<"Message ID:"<<ByteArray[3];
//                        for(int i=24,j=7;i<32,j>=0;i++,j--){byte[j]=bitdata[i];} qDebug()<<byte;
//                        qDebug()<<"Count of bytes:"<<ByteArray[4];
//                        for(int i=32,j=7;i<40,j>=0;i++,j--){byte[j]=bitdata[i];} qDebug()<<byte;*/
//                        for(int i=40,j=15;i<56&&j>=0;i++,j--){two_bytes[j]=bitdata[i];} //Roll
//                        setRoll(Round(toDec(two_bytes,1)*1.41,1));
//                        for(int i=56,j=15;i<72&&j>=0;i++,j--){two_bytes[j]=bitdata[i];} //Pitch
//                        setPitch(Round(toDec(two_bytes,1)*1.41,1));
//                        for(int i=72,j=15;i<88&&j>=0;i++,j--){two_bytes[j]=bitdata[i];} //Azimuth
//                        //qDebug()<<"Dec form: "<<toDec(two_bytes);
//                        //qDebug()<<"DATA " << bitdata;
//                        /*m_sum+=Round(toDec(two_bytes,0)*1.41,1);
//                        m_con++;
//                        if(m_con==3)
//                        {
//                          setAngle(m_sum/m_con);
//                        }
//                        else if(m_con==1)
//                        {
//                            setAngle(m_sum);
//                        }*/
//                        setAngle(Round(toDec(two_bytes,0)*1.41,1));
//                        //qApp->processEvents();
//                    }
//                    if(m_state == 0)
//                    {
//                        qApp->processEvents();
//                        break;
//                    }
//                }
//            }
//            if(port->isOpen())
//                port->close();
//            qDebug()<<"port state"<<port->isOpen();
//        }
//        else
//        {
//            qDebug()<<"WaitForReadyRead failed";
//        }
//    }
//    else
//    {
//        if(port->isOpen())
//            port->close();
//        qDebug()<<"Error while opening";
//    }
//}


void Kompas::startThread()
{
    kompasThread->start();
}

void Kompas::quitThread()
{
    kompasThread->quit();
}
void Kompas::off()
{
    //timer->stop();
    m_state=0;
    emit stateChanged();
    m_connect_state=0;
    emit connect_stateChanged();
    setAngle(0);
    qApp->processEvents();
    qDebug()<<"state = 0 OFF";
    qDebug()<<m_con;
    if(port->isOpen())
        port->close();
}

Kompas::~Kompas()
{
    kompasThread->deleteLater();
}

void Kompas::setAngle(double a)
{

    if(!m_tmCourse)
        a=m_skl+a+m_coef_A;
    if(a<0)
       a+=360;
    if(a>360)
        a-=360;
    if (a!=0)
    {
        double temp;
        double *pt=new double;
        temp=QString::number(modf(a,pt)).left(3).toDouble();
        m_afterComma=temp;
        m_fractPart=(QString::number(*pt).right(1).toDouble()+temp)*10;
        m_angle=*pt;
        m_fullangle=m_angle+temp;
    }
    else
        m_afterComma=m_fractPart=m_angle=m_fullangle=m_lastAngle=0;

    if(m_angle-m_lastAngle > 180)
    {
        m_con--;
    }
    else if(m_angle-m_lastAngle < -180)
    {
         m_con++;
    }
    ;
    m_lastAngle=m_angle;
    m_angle=m_angle+360*m_con;
    m_angle=m_angle-(m_angle-m_last)/m_dempf;
    m_last=m_angle;
    if(m_fractPart-m_lastAngle1 > 50)
    {
        m_con1--;
    }
    else if(m_fractPart-m_lastAngle1 < -50)
    {
         m_con1++;
    }
    m_lastAngle1=m_fractPart;
    m_fractPart=m_fractPart+100*m_con1;
    m_fractPart=m_fractPart-(m_fractPart-m_last2)/m_dempf;
    m_last2=m_fractPart;
    qApp->processEvents();
    emit angleChanged();
}

void Kompas::showMenu()
{
    kompasThread->quit();
    settings->exec();
    emit menuRequest();
    kompasThread->start();
}
//void Kompas::setPotenA()
//{

//}

//void Kompas::setPotenB()
//{

//}

//void Kompas::setPotenC()
//{

//}

void Kompas::updateSettings()
{
    m_connect=settings->m_interface;
    emit connectChanged();
    port->setPortName(settings->m_name_COM);
    port->setBaudRate(settings->m_Baud_rate);
    port->setDataBits(QSerialPort::DataBits(settings->m_Number_of_data_bits));
    port->setStopBits(QSerialPort::StopBits(settings->m_Stop_bits));
    port->setParity(QSerialPort::Parity(settings->m_Parity));
}

void Kompas::changeColor()
{
    m_color++;
    if(m_color == 2)
        m_color=0;
    emit colorChanged();
}
void Kompas::changeSkl()
{
    sklDialog* dlg= new sklDialog(this,m_skl,0);
    if(dlg->exec()) m_skl=dlg->getSkl();
    delete (dlg);
}
void Kompas::changeA()
{
    sklDialog* dlg= new sklDialog(this,m_coef_A,1);
    if(dlg->exec()) m_coef_A=dlg->getSkl();
    delete (dlg);
}

void Kompas::changeDempf()
{
    DempfDialog* dlg= new DempfDialog(this,m_dempf);
    if(dlg->exec()) m_dempf=dlg->get();
    delete (dlg);
}

void Kompas::saveCourse()
{
    m_savedCourse=m_fullangle;
    if(m_savedCourseVisibility==false)
        m_savedCourseVisibility=true;
    else
        m_savedCourseVisibility=false;
    emit savedCourseChanged();
    emit savedCourseVisibilityChanged();
}

double Kompas::toDec(QBitArray bitdata,int p)
{
    double intpart=0;
    double fractpart=0;
    QBitArray bit1(8),bit2(8);
    bit1.fill(true);
    for(int i=0;i<8;i++)
    {
        bit2[i]=bitdata[i];
    }
    int k=1;
    if((p && bitdata[0]) || (!p && bit2 == bit1))//отрицаетельное число в обратном коде
    {
        bitdata=~bitdata;
        p==1? k=-1:k=1;
    }
    for(int i=0,j=7;i<8 && j>=0;i++,j--)
        intpart+=pow(2,j)*bitdata[i];
    for(int i=8,j=1;i<16 && j<=8;i++,j++)
        fractpart+=1/pow(2,j)*bitdata[i];
    return (intpart+QString::number(fractpart).left(5).toDouble())*k;

}

void Kompas::setRoll(double st)
{
    m_roll=Round(st,1);
    emit rollChanged();
}

void Kompas::setPitch(double st)
{
    m_pitch=Round(st,1);
    emit pitchChanged();
}

double Round(double st,int count)
{
    double temp;
    double *pt=new double;
    if(st!=0)
    {
        temp=fabs(modf(st,pt));
        QString str = QString::number(temp),arg="0.";
        if(count<=str.size()+2)
        {
            if(QString(str[count+2]).toInt()<5)
            {
                str=str.left(count+2);
                temp=str.toDouble();
            }
            else
            {
                for(int i=0;i<count-1;i++)
                    arg.push_back("0");
                arg.push_back("1");
                temp+=arg.toDouble();
                temp=QString::number(temp).left(count+2).toDouble();
            }
        }
        return (fabs(*pt)+temp)*(st/fabs(st));
    }
    else return 0;

}

void Kompas::changeInfoScreenVisibility()
{
    if(!m_infoVisibility)
    {
        m_infoVisibility=true;
    }
    else
    {
        m_infoVisibility=false;
    }
    emit infoVisibilityChanged();
}
void Kompas::changeTrueMagneticCourse()
{
    if(!m_tmCourse)
    {
        m_tmCourse = true;
    }
    else
    {
        m_tmCourse = false;
    }
    emit trueMagneticCourseChanged();
}

/*if(port->waitForReadyRead(1000))
        {
            QString data;
            QByteArray ByteArray,course,supply;
            qint64 byteAvail = port->bytesAvailable();
            qDebug()<<"bytesAvailable "<<byteAvail;
            forever
            {
                qint64 byteAvail = port->bytesAvailable();
                qApp->processEvents();
                if(byteAvail >=13)
                {
                    ByteArray = port->readAll();
                    if(ByteArray.startsWith("$HCHDT"))
                    {
                        course=ByteArray.mid(7,5);
                        supply=ByteArray.mid(13,1);
                        setAngle(course.toDouble()+m_skl);
                        if(supply=="T")
                            m_supply=0;
                        else if(supply=="N")
                            m_supply=1;
                        emit supplyChanged();
                        qDebug()<<ByteArray;
                        qApp->processEvents();

                    }
                }
                if(m_state == 0)
                    break;
            }
            data = data.fromLatin1(ByteArray).trimmed();
            qDebug()<<"DATA " << data;
        }
        else
        {
            qDebug()<<"WaitForReadyRead failed";
        }
        */
