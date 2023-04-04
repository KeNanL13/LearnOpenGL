#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openGLWidget=new MyOpenGLWidget(this);
    this->resize(600,600);
    this->setCentralWidget(openGLWidget);
    connect(ui->actionDraw,&QAction::triggered,[=](){
//        openGLWidget->createRect();
        openGLWidget->setShape();
    });
    ui->actionWireFrame->setCheckable(true);
    connect(ui->actionWireFrame,&QAction::triggered,[=](){
        openGLWidget->setWireFrame(ui->actionWireFrame->isChecked());
    });
    connect(ui->actionClear,&QAction::triggered,[=](){
        openGLWidget->Clear();
    });
    ui->actionShadow->setCheckable(true);
    connect(ui->actionShadow,&QAction::triggered,[=](){
        openGLWidget->setIsShadow(ui->actionShadow->isChecked());
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
