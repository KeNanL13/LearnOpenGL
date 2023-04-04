#include "myopenglwidget.h"

float planeVertices[] = {
       // positions            // normals         // texcoords
        10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
       -10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
       -10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,

        10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
       -10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,
        10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,  10.0f, 10.0f
   };
MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) :
    QOpenGLWidget (parent),
    camera(this),
    lightPos(0.0f,1.2f,2.0f)
{
    QSurfaceFormat format;
    format.setSamples(4);

    QTimer *timer=new QTimer;
    timer->setInterval(18);
    connect(timer,&QTimer::timeout,[=](){
        makeCurrent();
        update();
        doneCurrent();
    });
    timer->start();
    camera.init();


}

MyOpenGLWidget::~MyOpenGLWidget()
{
    makeCurrent();

    doneCurrent();
}



void MyOpenGLWidget::setShape()
{

    m_Shape=Rect;
    update();
}



void MyOpenGLWidget::setWireFrame(bool isWireFrame)
{
    makeCurrent();
    if(isWireFrame)
    {

        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    }
    update();
    doneCurrent();
}

void MyOpenGLWidget::Clear()
{
    m_Shape=None;
    makeCurrent();
    update();
    doneCurrent();
}

void MyOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/vert.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/frag.frag");
    shaderProgram.link();

    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(planeVertices),planeVertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*8,(void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*8,(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(float)*8,(void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
//    glEnable(GL_FRAMEBUFFER_SRGB);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    projection.perspective(45,width()/height(),0.1,100);
    model.setToIdentity();
    shaderProgram.bind();
    shaderProgram.setUniformValue("projection",projection);
    shaderProgram.setUniformValue("model",model);
    QVector3D lightPosition[4]={
        QVector3D(-3,0,0),
        QVector3D(-1,0,0),
        QVector3D(1.0,0,0),
        QVector3D(3.0,0,0)
    };
    QVector3D lightColor[4]={
        QVector3D(0.25,0.25,0.25),
        QVector3D(0.5,0.5,0.5),
        QVector3D(0.75,0.75,0.75),
        QVector3D(1.0,1.0,1.0)
    };


    shaderProgram.setUniformValue("floorTexture",0);
    shaderProgram.setUniformValueArray("lightPosition",lightPosition,4);
    shaderProgram.setUniformValueArray("lightColor",lightColor,4);


    texture=new QOpenGLTexture(QImage(":/Texture/wood.png"));
    qDebug()<<texture->format();
    QImage image(":/Texture/wood.png");
    glGenTextures(1,&textureWithGramma);
    glBindTexture(GL_TEXTURE_2D,textureWithGramma);
    glTexImage2D(GL_TEXTURE_2D,0,GL_SRGB,image.width(),image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,image.bits());
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);







}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void MyOpenGLWidget::paintGL()
{

    glClearColor(0.4f,0.5f,0.4f,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);



    switch (m_Shape) {
    case Rect:
        shaderProgram.bind();
        shaderProgram.setUniformValue("projection",projection);
        shaderProgram.setUniformValue("view",camera.getView());
        shaderProgram.setUniformValue("model",model);


        shaderProgram.setUniformValue("viewPos",camera.getCameraPos());

        shaderProgram.setUniformValue("gamma",shadingMode);
        texture->bind(0);

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,6);



        break;
    default:
        break;
    }

}

bool MyOpenGLWidget::event(QEvent *e)
{
    camera.handle(e);
    return QWidget::event(e);
}

void MyOpenGLWidget::keyPressEvent(QKeyEvent *event)
{
        makeCurrent();
    switch (event->key()) {
    case Qt::Key_Up:
        model.scale(1.1f);
        break;
    case Qt::Key_Down:
        model.scale(0.9f);
        break;
    case Qt::Key_Right:
        shaderProgram.bind();
        shaderProgram.setUniformValue("gamma",shadingMode);
        shadingMode=!shadingMode;
        qDebug()<<shadingMode;
        break;
    default:
        break;
    }

    update();
    doneCurrent();
}

void MyOpenGLWidget::wheelEvent(QWheelEvent *event)
{
    if(fov>=1.0f&&fov<=90.0f)
    {
        fov-=event->delta()*0.08f;
    }
    if(fov<=1)
    {
        fov=1.0f;

    }
   if(fov>=90)
    {
        fov=90.0f;
    }
   projection.setToIdentity();
   projection.perspective(fov,width()/height(),0.1f,100);
    makeCurrent();
    update();
    doneCurrent();
}
