#include "myopenglwidget.h"

float vertices[] = {
    // positions          // normals           // texture coords
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
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
    timerLight->setInterval(100);
//    connect(timer,&QTimer::timeout,[=](){
//        makeCurrent();


//        lightPos.setZ(10*sinf(x));
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
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof (float),nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof (float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);
//    glBindBuffer(GL_BUFFER,0);
    glBindVertexArray(0);
    //设置光源的VAO和VBO;
    glGenVertexArrays(1,&VAOLight);
    glBindVertexArray(VAOLight);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof (float),(void*)0);
    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof (float),(void*)(3*sizeof(float)));
//    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
//设置投影矩阵和模型位置矩阵
    projection.perspective(45.0f,this->width()/this->height(),0.1f,100);
//    model.translate(0.0f,-1.5f,0.0f);
    model.setToIdentity();
//    modelLight.setToIdentity();

    modelLight.translate(lightPos);
    modelLight.scale(0.2f);
//    QMatrix4x4 model;
//    model.translate(-0.0f,-0.0f,0.0f);
//    shaderProgram.setUniformValue("model",model);
    glEnable(GL_DEPTH_TEST);//开启深度测试
//设置vertex里的矩阵值
    shaderProgram.bind();
    shaderProgram.setUniformValue("projection",projection);
    shaderProgram.setUniformValue("model",model);

//设置片段着色器的材料、光、纹理内容
    shaderProgram.setUniformValue("material.shininess",32.0f);

//    shaderProgram.setUniformValue("light.direction",-0.2f,-1.0f,-0.3f);
    shaderProgram.setUniformValue("material.diffuse",0);
    shaderProgram.setUniformValue("material.specular",1);
//    shaderProgram.setUniformValue("material.emission",2);
    textureDiffuse=new QOpenGLTexture(QImage(":/Texture/container2.png").mirrored());
    textureSpecular=new QOpenGLTexture(QImage(":/Texture/container2_specular.png"));
//    textureEmission=new QOpenGLTexture(QImage(":/Texture/matrix.jpg"));

    shaderProgram.setUniformValue("light.ambient",0.1f,0.1f,0.1f);
    shaderProgram.setUniformValue("light.diffuse",0.8f,0.8f,0.8f);
    shaderProgram.setUniformValue("light.specular",1.0f,1.0f,1.0f);
    //1,2设置
//    shaderProgram.setUniformValue("light.position",lightPos);
    //1. directional light 平行光：
    //    shaderProgram.setUniformValue("light.direction",-0.2f,-1.0f,-0.3f);
    // 2.会衰减的点光源：
//    shaderProgram.setUniformValue("light.constant",1.0f);
//    shaderProgram.setUniformValue("light.linear",0.09f);
//    shaderProgram.setUniformValue("light.quadratic",0.032f);
    //3.聚光
    shaderProgram.setUniformValue("light.position",camera.getCameraPos());
    shaderProgram.setUniformValue("light.direction",camera.getCameraDir());
    shaderProgram.setUniformValue("light.cutOff",cosf(12.5f*M_PI/180.0f));
    shaderProgram.setUniformValue("light.outerCutOff",cosf(17.5f*M_PI/180.0f));

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
        textureDiffuse->bind(0);
        textureSpecular->bind(1);

        shaderProgram.setUniformValue("projection",projection);
//        shaderProgram.setUniformValue("model",model);
        shaderProgram.setUniformValue("view",camera.getView());
        shaderProgram.setUniformValue("cameraPos",camera.getCameraPos());
        shaderProgram.setUniformValue("light.position",camera.getCameraPos());
        shaderProgram.setUniformValue("light.direction",camera.getCameraDir());
//        shaderProgram.setUniformValue("light.position",lightPos);

        glBindVertexArray(VAO);

        for(int i=0;i<10;i++)
        {

            QMatrix4x4 moveModel;
            moveModel.translate(QVector3D(2*sin(i),2*cos(i),2*i));
            float angle=i*20.0f;
            moveModel.rotate(angle,QVector3D(1.0f,0.3f,0.5f));
            shaderProgram.setUniformValue("model",moveModel);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES,0,36);
        }

//        glDrawArrays(GL_TRIANGLES,0,36);

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
