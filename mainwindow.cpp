#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDeclarativeView *qmlView = new QDeclarativeView(this);
    kompas = new Kompas(this);

    //connect(kompas->kompasThread,SIGNAL(started()),kompas,SLOT(on()));
    //connect(kompas->kompasThread,SIGNAL(finished()),kompas,SLOT(off()));
    connect(kompas,SIGNAL(menuRequest()),kompas,SLOT(updateSettings()));

    qmlView->rootContext()->setContextProperty("_kompas", kompas);
    qmlView->rootContext()->setContextProperty("window", this);
    qmlView->setSource(QUrl("qrc:/main.qml"));
    setCentralWidget(qmlView);
    //kompas->kompasThread->start();
}

MainWindow::~MainWindow()
{
    kompas->deleteLater();
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    //kompas->kompasThread->quit();
    kompas->off();
    event->accept();
    QMainWindow::closeEvent(event);
}
void MainWindow::resizeEvent(QResizeEvent *event)
{
    event->accept();
    QMainWindow::resizeEvent(event);
    m_height=this->height();
    m_width=this->width();
    emit dwidthChanged();
    emit dheightChanged();
}
