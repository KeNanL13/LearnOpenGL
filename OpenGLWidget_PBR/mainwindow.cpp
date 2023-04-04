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
    connect(ui->actionloadModel,&QAction::triggered,[=](){
        openGLWidget->loadModel();
    });
    connect(ui->actionTimerStart,&QAction::triggered,[=](){
        openGLWidget->TimerStart();
    });
    connect(ui->actionTimerEnd,&QAction::triggered,[=](){
        openGLWidget->TimerEnd();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
