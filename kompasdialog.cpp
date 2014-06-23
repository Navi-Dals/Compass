#include "kompasdialog.h"
#include "ui_kompasdialog.h"
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeError>
#include <QtDeclarative/QDeclarativeContext>
#include <QVBoxLayout>
#include <QObject>
#include <QDebug>

KompasDialog::KompasDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KompasDialog)
{
    ui->setupUi(this);

    QDeclarativeView *qmlView = new QDeclarativeView(this);
    kompas = new Kompas(this);

    connect(kompas->kompasThread,SIGNAL(started()),kompas,SLOT(on()));
    connect(kompas->kompasThread,SIGNAL(finished()),kompas,SLOT(off()));
    connect(kompas,SIGNAL(menuRequest()),kompas,SLOT(updateSettings()));

    qmlView->rootContext()->setContextProperty("_kompas", kompas);
    qmlView->rootContext()->setContextProperty("window", this);
    qmlView->setSource(QUrl("qrc:/main.qml"));
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(qmlView);
    kompas->kompasThread->start();

}

KompasDialog::~KompasDialog()
{
    kompas->deleteLater();
    delete ui;
}

void KompasDialog::closeEvent(QCloseEvent *event)
{
    if(kompas->kompasThread->isRunning())
        kompas->kompasThread->quit();
    event->accept();
    QDialog::closeEvent(event);
}
void KompasDialog::resizeEvent(QResizeEvent *event)
{
    event->accept();
    QDialog::resizeEvent(event);
    m_height=this->height();
    m_width=this->width();
    emit dwidthChanged();
    emit dheightChanged();
}
