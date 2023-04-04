#include "myopenglwidget.h"

//const float verticles[]={
//    -0.5f,-0.5f,-0.5f,-0.5f,0.0f,0.0f,//左上
//    0.5f,-0.5f,-0.5f,-0.5f,1.0f,0.0f,//左下
//    0.5f,0.5f,-0.5f,-0.5f,1.0f,1.0f,//右下
//    0.5f,0.5f,-0.5f,-0.5f,1.0f,1.0f,//右上
//    -0.5f,0.5f,-0.5f,-0.5f,0.0f,1.0f,//右上
//    -0.5f,-0.5f,-0.5f,-0.5f,0.0f,0.0f,//右上

//    -0.5f,-0.5f,0.5f,-0.5f,0.0f,0.0f,//左上
//    0.5f,-0.5f,0.5f,-0.5f,1.0f,0.0f,//左下
//    0.5f,0.5f,0.5f,-0.5f,1.0f,1.0f,//右下
//    0.5f,0.5f,0.5f,-0.5f,1.0f,1.0f,//右上
//    -0.5f,0.5f,0.5f,-0.5f,0.0f,1.0f,//右上
//    -0.5f,-0.5f,0.5f,-0.5f,0.0f,0.0f,//右上

//    -0.5f,0.5f,0.5f,-0.5f,1.0f,0.0f,//左上
//    -0.5f,0.5f,-0.5f,-0.5f,1.0f,1.0f,//左下
//    -0.5f,-0.5f,-0.5f,-0.5f,0.0f,1.0f,//右下
//    -0.5f,-0.5f,-0.5f,-0.5f,0.0f,1.0f,//右上
//    -0.5f,-0.5f,0.5f,-0.5f,0.0f,0.0f,//右上
//    -0.5f,0.5f,0.5f,-0.5f,1.0f,0.0f,//右上

//    0.5f,0.5f,0.5f,-0.5f,1.0f,0.0f,//左上
//    0.5f,0.5f,-0.5f,-0.5f,1.0f,1.0f,//左下
//    0.5f,-0.5f,-0.5f,-0.5f,0.0f,1.0f,//右下
//    0.5f,-0.5f,-0.5f,-0.5f,0.0f,1.0f,//右上
//    0.5f,-0.5f,0.5f,-0.5f,0.0f,0.0f,//右上
//    0.5f,0.5f,0.5f,-0.5f,1.0f,0.0f,//右上

//    -0.5f,-0.5f,-0.5f,-0.5f,0.0f,1.0f,
//    0.5f,-0.5f,-0.5f,-0.5f,1.0f,1.0f,
//    0.5f,-0.5f,0.5f,-0.5f,1.0f,0.0f,
//    0.5f,-0.5f,0.5f,-0.5f,1.0f,0.0f,
//    -0.5f,-0.5f,0.5f,-0.5f,0.0f,0.0f,
//    -0.5f,-0.5f,-0.5f,-0.5f,0.0f,1.0f,

//    -0.5f,0.5f,-0.5f,-0.5f,0.0f,1.0f,
//    0.5f,0.5f,-0.5f,-0.5f,1.0f,1.0f,
//    0.5f,0.5f,0.5f,-0.5f,1.0f,0.0f,
//    0.5f,0.5f,0.5f,-0.5f,1.0f,0.0f,
//    -0.5f,0.5f,0.5f,-0.5f,0.0f,0.0f,
//    -0.5f,0.5f,-0.5f,-0.5f,0.0f,1.0f
//                  };
float vertices[] = {
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
};
MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) :
    QOpenGLWidget (parent),
    camera(this),
    lightPos(0.0f,1.2f,2.0f)
{

    QTimer *timer=new QTimer;
    timer->setInterval(18);
    connect(timer,&QTimer::timeout,[=](){
        makeCurrent();
        update();
        doneCurrent();
    });
    timer->start();
    timerLight=new QTimer;
//    timerLight->setInterval(100);
//    connect(timer,&QTimer::timeout,[=](){
//        makeCurrent();

//        lightPos.setX(2*cosf(x));
//        lightPos.setZ(2*sinf(x));
//        modelLight.setToIdentity();
//        modelLight.translate(lightPos);
//        modelLight.scale(0.1f);
//        x=x+0.03;
//        doneCurrent();

//    });
    camera.init();

}

void MyOpenGLWidget::createRect(float * ver ,int length)
{
     float r=0.5;
    ver[0]=0;
    ver[1]=0;
    ver[2]=0;
    ver[3]=r;
    ver[4]=0;
    ver[5]=0;
    float cita=2*M_PI/(length/3-2);
    for(int i=2;i<length/3;i++)
    {
        ver[i*3]=r*cos(cita*(i-1));
        ver[i*3+1]=r*sin(cita*(i-1));
        ver[i*3+2]=0;
    }
}

void MyOpenGLWidget::setShape()
{

    m_Shape=Rect;
    update();
}

void MyOpenGLWidget::create3D(float * ver )
{
    float x=1.0f/100;
    for (int i =0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
          ver[i*300+j*3]=x*j;
          ver[i*300+j*3+1]=x*i;
          ver[i*300+j*3+2]=x*j*x*j+x*i*x*i;
        }

    }
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
    //物体的shaderprogram
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/vertex.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/fragment.frag");
    shaderProgram.link();
    //光源的shaderprogram
    shaderProgramLight.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/vertexlight.vert");
    shaderProgramLight.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/fragmentlight.frag");
    shaderProgram.link();
//    for (int i=0;i<3000;i++)
//    {
//        qDebug()<<ver[i];
//    }
    //设置物体的VAO和VBO
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof (float),nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof (float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
//    glBindBuffer(GL_BUFFER,0);
    glBindVertexArray(0);
    //设置光源的VAO和VBO;
    glGenVertexArrays(1,&VAOLight);
    glBindVertexArray(VAOLight);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof (float),(void*)0);
    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof (float),(void*)(3*sizeof(float)));
//    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    projection.perspective(45.0f,this->width()/this->height(),0.1f,100);
//    model.translate(0.0f,-1.5f,0.0f);
    model.setToIdentity();
//    modelLight.setToIdentity();

    modelLight.translate(lightPos);
    modelLight.scale(0.2f);
//    QMatrix4x4 model;
//    model.translate(-0.0f,-0.0f,0.0f);
//    shaderProgram.setUniformValue("model",model);
    glEnable(GL_DEPTH_TEST);

    shaderProgram.bind();
    shaderProgram.setUniformValue("projection",projection);
    shaderProgram.setUniformValue("model",model);
//    shaderProgram.setUniformValue("lightColor",1.0f,0.5f,0.31f);
    shaderProgram.setUniformValue("material.ambient",1.0f,0.5f,0.31f);
    shaderProgram.setUniformValue("material.diffuse",1.0f,0.5f,0.31f);
    shaderProgram.setUniformValue("material.specular",0.5f,0.5f,0.5f);
    shaderProgram.setUniformValue("material.shininess",32.0f);
    shaderProgram.setUniformValue("light.position",lightPos);


    shaderProgram.setUniformValue("light.ambient",0.2f,0.2f,0.2f);
    shaderProgram.setUniformValue("light.diffuse",0.5f,0.5f,0.5f);
    shaderProgram.setUniformValue("light.specular",1.0f,1.0f,1.0f);
//    shaderProgram.setUniformValue("objectColor",1.0f,1.0f,1.0f);
//    shaderProgram.setUniformValue("lightPos",lightPos);
    shaderProgramLight.bind();
    shaderProgramLight.setUniformValue("projection",projection);
//    shaderProgramLight.setUniformValue("model",modelLight);
//    timerLight->start();

}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void MyOpenGLWidget::paintGL()
{

    glClearColor(0.4f,0.5f,0.4f,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    shaderProgram.bind();

//    shaderProgram.setUniformValue("projection",projection);

//    shaderProgram.setUniformValue("model",model);
//    shaderProgram.setUniformValue("view",camera.getView());


    switch (m_Shape) {
    case Rect:

        //绘制物体
        shaderProgram.bind();
        shaderProgram.setUniformValue("projection",projection);
        shaderProgram.setUniformValue("model",model);
        shaderProgram.setUniformValue("view",camera.getView());
        shaderProgram.setUniformValue("cameraPos",camera.getCameraPos());
        shaderProgram.setUniformValue("light.position",lightPos);

//        shaderProgram.setUniformValue("light.ambient",0.2f,0.2f,0.2f);
//        shaderProgram.setUniformValue("light.diffuse",0.5f,0.5f,0.5f);
//        shaderProgram.setUniformValue("lightColor",1.0f,0.5f,0.31f);
//        shaderProgram.setUniformValue("objectColor",1.0f,1.0f,1.0f);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,36);

        //绘制光源
        shaderProgramLight.bind();
//        shaderProgramLight.setUniformValue("projection",projection);
        shaderProgramLight.setUniformValue("model",modelLight);
        shaderProgramLight.setUniformValue("view",camera.getView());
        glBindVertexArray(VAOLight);

        glDrawArrays(GL_TRIANGLES,0,36);

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
    switch (event->key()) {
    case Qt::Key_Up:
        model.scale(1.1f);
        break;
    case Qt::Key_Down:
        model.scale(0.9f);
        break;
    default:
        break;
    }
    makeCurrent();
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
