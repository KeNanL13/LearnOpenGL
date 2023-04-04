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

MyOpenGLWidget::~MyOpenGLWidget()
{
    makeCurrent();
    delete textureDiffuse;
    delete textureSpecular;
    doneCurrent();
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
    //光照设置
    //1.(平行光)
    shaderProgram.setUniformValue("directLight.direction",-0.2f,-1.0f,-0.3f);
    shaderProgram.setUniformValue("directLight.ambient",0.1f,0.1f,0.1f);
    shaderProgram.setUniformValue("directLight.diffuse",0.8f,0.8f,0.8f);
    shaderProgram.setUniformValue("directLight.specular",1.0f,1.0f,1.0f);
//    2.(点光源)

    pointLightPositon[0]=QVector3D(0.7f,0.2f,2.0f);
    pointLightPositon[1]=QVector3D(2.3f,-3.3f,-4.0f);
    pointLightPositon[2]=QVector3D(-4.0f,2.0f,-12.0f);
    pointLightPositon[3]=QVector3D(0.0f,0.0f,-3.0f);
    for(int i=0;i<4;i++)
    {
        QString sr=QString("pointLight[%1].position").arg(i);
        shaderProgram.setUniformValue(QString("pointLight[%1].position").arg(i).toStdString().c_str(),pointLightPositon[i]);

        shaderProgram.setUniformValue(QString("pointLight[%1].ambient").arg(i).toStdString().c_str(),0.1f,0.1f,0.1f);
        shaderProgram.setUniformValue(QString("pointLight[%1].diffuse").arg(i).toStdString().c_str(),0.8f,0.8f,0.8f);
        shaderProgram.setUniformValue(QString("pointLight[%1].specular").arg(i).toStdString().c_str(),1.0f,1.0f,1.0f);

        shaderProgram.setUniformValue(QString("pointLight[%1].constant").arg(i).toStdString().c_str(),1.0f);
        shaderProgram.setUniformValue(QString("pointLight[%1].linear").arg(i).toStdString().c_str(),0.09f);
        shaderProgram.setUniformValue(QString("pointLight[%1].quadratic").arg(i).toStdString().c_str(),0.032f);
    }

//    //3.(聚点光)
    shaderProgram.setUniformValue("spotLight.position",camera.getCameraPos());

    shaderProgram.setUniformValue("spotLight.spotDirection",camera.getCameraDir());
    shaderProgram.setUniformValue("spotLight.cutOff",cosf(12.5f*M_PI/180.0f));
    shaderProgram.setUniformValue("spotLight.outCutOff",cosf(17.5f*M_PI/180.0f));
    shaderProgram.setUniformValue("spotLight.ambient",0.1f,0.1f,0.1f);
    shaderProgram.setUniformValue("spotLight.diffuse",0.8f,0.8f,0.8f);
    shaderProgram.setUniformValue("spotLight.specular",1.0f,1.0f,1.0f);


    shaderProgramLight.bind();
    shaderProgramLight.setUniformValue("projection",projection);


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

        shaderProgram.setUniformValue("spotLight.position",camera.getCameraPos());
        shaderProgram.setUniformValue("spotLight.spotDirection",camera.getCameraDir());


        glBindVertexArray(VAO);

        for(int i=0;i<10;i++)
        {

            QMatrix4x4 moveModel;
            moveModel.translate(QVector3D(2*sin(i),2*cos(i),-2*i));
            float angle=i*20.0f;
            moveModel.rotate(angle,QVector3D(1.0f,0.3f,0.5f));
            shaderProgram.setUniformValue("model",moveModel);

            glDrawArrays(GL_TRIANGLES,0,36);
        }

//        glDrawArrays(GL_TRIANGLES,0,36);

        //绘制光源
        shaderProgramLight.bind();
        glBindVertexArray(VAOLight);
        shaderProgramLight.setUniformValue("view",camera.getView());
        shaderProgramLight.setUniformValue("projection",projection);
        for(int i=0;i<4;i++)
        {
            modelLight.setToIdentity();
            modelLight.translate(pointLightPositon[i]);
            modelLight.scale(0.1f);
            shaderProgramLight.setUniformValue("model",modelLight);
             glDrawArrays(GL_TRIANGLES,0,36);
        }



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
