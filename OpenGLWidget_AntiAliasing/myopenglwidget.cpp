#include "myopenglwidget.h"


float cubeVertices[] = {
        // positions          // texture Coords
        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,

        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,

         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,

        -0.5f, -0.5f, -0.5f,
         0.5f, -0.5f, -0.5f,
         0.5f, -0.5f,  0.5f,
         0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f,  0.5f,
        -0.5f, -0.5f, -0.5f,

        -0.5f,  0.5f, -0.5f,
         0.5f,  0.5f, -0.5f,
         0.5f,  0.5f,  0.5f,
         0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f,  0.5f,
        -0.5f,  0.5f, -0.5f,
    };
float planeVertices[] = {
        // positions          // texture Coords (note we set these higher than 1 (together with GL_REPEAT as texture wrapping mode). this will cause the floor texture to repeat)
         5.0f, -0.5f,  5.0f,
        -5.0f, -0.5f,  5.0f,
        -5.0f, -0.5f, -5.0f,

         1.0f, -0.5f,  5.0f,
        -5.0f, -0.5f, -5.0f,
         1.0f, -0.5f, -5.0f,
    };

float color[]={
    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,

    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,

     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,

    -0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,
     0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f,  0.5f,
    -0.5f, -0.5f, -0.5f,

    -0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f,
     0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f,  0.5f,
    -0.5f,  0.5f, -0.5f,
};
float quadVertices[] = {   // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
      // positions   // texCoords
      -1.0f,  1.0f,  0.0f, 1.0f,
      -1.0f, -1.0f,  0.0f, 0.0f,
       1.0f, -1.0f,  1.0f, 0.0f,

      -1.0f,  1.0f,  0.0f, 1.0f,
       1.0f, -1.0f,  1.0f, 0.0f,
       1.0f,  1.0f,  1.0f, 1.0f
  };
MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) :
    QOpenGLWidget (parent),
    camera(this)

{
//    QSurfaceFormat format;
//    format.setSamples(4);
//    this->setFormat(format);
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

void MyOpenGLWidget::loadModel()
{
//    makeCurrent();
//    model1=new Model("C:/Users/Administrator/Desktop/rock/rock.obj",this);
//    model2=new Model("C:/Users/Administrator/Desktop/plane/planet.obj",this);

//    doneCurrent();
    m_Shape=ModelLoading;
}


void MyOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,":/ver.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,":/frag.frag");
    shaderProgram.link();
    shaderQuad.addShaderFromSourceFile(QOpenGLShader::Vertex,":/verquad.vert");
    shaderQuad.addShaderFromSourceFile(QOpenGLShader::Fragment,":/fragqaud.frag");
    shaderQuad.link();


    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(cubeVertices),cubeVertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof (float)*3,(void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    glGenVertexArrays(1,&VAOquad);
    glGenBuffers(1,&VBOquad);
    glBindVertexArray(VAOquad);
    glBindBuffer(GL_ARRAY_BUFFER,VBOquad);
    glBufferData(GL_ARRAY_BUFFER,sizeof (quadVertices),quadVertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float)*4,(void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(float)*4,(void*)(2*sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    //配置FBOMuti
    glGenFramebuffers(1,&FBOMuti);
    glBindFramebuffer(GL_FRAMEBUFFER,FBOMuti);
    //生成颜色纹理存储采样图像
    glGenTextures(1,&tex);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE,tex);
    glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE,4,GL_RGB,
                            width(),height(),GL_TRUE);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE,0);
    //帧缓存附加颜色纹理附件
    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,
                           GL_TEXTURE_2D_MULTISAMPLE,tex,0);
    //渲染缓冲对象生成 深度和模板附件
    glGenRenderbuffers(1,&RBO);
    glBindRenderbuffer(GL_RENDERBUFFER,RBO);
    glRenderbufferStorageMultisample(GL_RENDERBUFFER,4,
                                     GL_DEPTH24_STENCIL8,
                                     width(),height());
    glBindRenderbuffer(GL_RENDERBUFFER,0);
    //帧缓存附加 渲染缓冲对象作为深度和模板附件
    glFramebufferRenderbuffer(GL_FRAMEBUFFER,GL_DEPTH_STENCIL,
                              GL_RENDERBUFFER,RBO);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER)!=GL_FRAMEBUFFER_COMPLETE)
    {
        qDebug()<<false;
    }
    glBindFramebuffer(GL_FRAMEBUFFER,0);
    //设置普通渲染的FBO
    glGenFramebuffers(1,&FBO);
    glBindFramebuffer(GL_FRAMEBUFFER,FBO);
//    设置颜色纹理
    glGenTextures(1,&texInter);
    glBindTexture(GL_TEXTURE_2D,texInter);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width(),height(),0,GL_RGB,GL_UNSIGNED_BYTE,nullptr);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D,0);
    //FBO绑定颜色纹理附件

    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_COLOR_ATTACHMENT0,
                           GL_TEXTURE_2D,texInter,0);
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER)!=GL_FRAMEBUFFER_COMPLETE)
    {
        qDebug()<<"false";
    }
    glBindFramebuffer(GL_FRAMEBUFFER,defaultFramebufferObject());






    projection.perspective(45.0f,width()/height(),0.1,100);
    model.setToIdentity();
    shaderProgram.setUniformValue("projection",projection);
    shaderProgram.setUniformValue("model",model);




    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);


}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void MyOpenGLWidget::paintGL()
{

    glClearColor(0.4f,0.5f,0.4f,1.0);
    glClear(GL_COLOR_BUFFER_BIT/*|GL_DEPTH_BUFFER_BIT*/);


    switch (m_Shape) {
    case Rect:
        glBindFramebuffer(GL_FRAMEBUFFER,FBOMuti);
        glClearColor(0.4f,0.5f,0.4f,1.0);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST);
        shaderProgram.bind();
        shaderProgram.setUniformValue("projection",projection);
        shaderProgram.setUniformValue("model",model);
        shaderProgram.setUniformValue("view",camera.getView());
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,36);

        glBindFramebuffer(GL_READ_FRAMEBUFFER,FBOMuti);
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER,FBO);
        glBlitFramebuffer(0,0,width(),height(),0,0,width(),
                          height(),GL_COLOR_BUFFER_BIT,GL_NEAREST);

        glBindFramebuffer(GL_FRAMEBUFFER,defaultFramebufferObject());
        glClearColor(0.4f,0.5f,0.4f,0);
        glClear(GL_COLOR_BUFFER_BIT);
        glDisable(GL_DEPTH_TEST);

        shaderQuad.bind();
        glBindVertexArray(VAOquad);
        glBindTexture(GL_TEXTURE_2D,texInter);
        glDrawArrays(GL_TRIANGLES,0,6);

        break;
    case ModelLoading:



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
   projection.perspective(fov,width()/height(),0.1f,1000);
    makeCurrent();
    update();
    doneCurrent();
}
