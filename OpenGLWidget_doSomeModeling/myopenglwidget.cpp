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

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) :
    QOpenGLWidget (parent),
    camera(this),
    lightPos(0.0f,1.2f,2.0f)
{
    QSurfaceFormat format;
    format.setSamples(4);
    this->setFormat(format);

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
    if(model_To!=nullptr)
    {
        delete model_To;
        model_To=nullptr;
    }
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
    makeCurrent();
    model_To=new Model("C:/Users/Administrator/Desktop/nanosuit/nanosuit.obj",this);
    doneCurrent();
    m_Shape=ModelLoading;
}




void MyOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/vertex.vert");
//    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Geometry,"");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/frag.frag");
    shaderProgram.link();
    this->createShape();

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof (QVector3D),&vertices[0],GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof (float)*3,nullptr);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    glGenBuffers(1,&VBO1);
    glGenVertexArrays(1,&VAO1);
    glBindVertexArray(VAO1);
    glBindBuffer(GL_ARRAY_BUFFER,VBO1);
    glBufferData(GL_ARRAY_BUFFER,vertices2.size()*sizeof(QVector3D),&vertices2[0],GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof (float)*3,nullptr);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    projection.perspective(45,width()/height(),0.1,100);

    model.setToIdentity();
    shaderProgram.bind();
    shaderProgram.setUniformValue("projection",projection);
    shaderProgram.setUniformValue("model",model);

//    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,Normal));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,TexCoords));
//    glEnableVertexAttribArray(2);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_LINE_SMOOTH);







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
        shaderProgram.setUniformValue("model",model);
        shaderProgram.setUniformValue("view",camera.getView());

        glBindVertexArray(VAO);
        glLineWidth(5);
        glDrawArrays(GL_LINE_STRIP,0,acc);
        glBindVertexArray(VAO1);
        glLineWidth(5);
        glDrawArrays(GL_LINE_STRIP,0,acc);


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

void MyOpenGLWidget::createShape()
{
    int precision=100;
    for(int i=0;i<acc;i++)
    {
        QVector3D v,v1;
        float x=M_PI*2/precision*i;

        v.setX(x);
        v.setY(cosf(x));
        v.setZ(sinf(x));

        v1.setX(x);
        v1.setY(-cosf(x));
        v1.setZ(-sinf(x));
        vertices.push_back(v);
        vertices2.push_back(v1);
    }



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
