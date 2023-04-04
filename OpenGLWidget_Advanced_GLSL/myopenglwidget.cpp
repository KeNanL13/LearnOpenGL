#include "myopenglwidget.h"


float cubeVertices[] = {
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
float planeVertices[] = {
        // positions          // texture Coords (note we set these higher than 1 (together with GL_REPEAT as texture wrapping mode). this will cause the floor texture to repeat)
         5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
        -5.0f, -0.5f,  5.0f,  0.0f, 0.0f,
        -5.0f, -0.5f, -5.0f,  0.0f, 2.0f,

         5.0f, -0.5f,  5.0f,  2.0f, 0.0f,
        -5.0f, -0.5f, -5.0f,  0.0f, 2.0f,
         5.0f, -0.5f, -5.0f,  2.0f, 2.0f
    };

float skyboxVertices[] = {
    // positions
    -1.0f,  1.0f, -1.0f,
    -1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f, -1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,

    -1.0f, -1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f, -1.0f,  1.0f,
    -1.0f, -1.0f,  1.0f,

    -1.0f,  1.0f, -1.0f,
     1.0f,  1.0f, -1.0f,
     1.0f,  1.0f,  1.0f,
     1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f,  1.0f,
    -1.0f,  1.0f, -1.0f,

    -1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f, -1.0f,
     1.0f, -1.0f, -1.0f,
    -1.0f, -1.0f,  1.0f,
     1.0f, -1.0f,  1.0f
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


    camera.init();


}

MyOpenGLWidget::~MyOpenGLWidget()
{
    if(model_To!=nullptr)
    {
        delete model_To;
        model_To=nullptr;
    }
    makeCurrent();
    glDeleteVertexArrays(1,&VAO);
    glDeleteVertexArrays(1,&VAOLight);
    glDeleteVertexArrays(1,&VAOSky);
    glDeleteBuffers(1,&VBO);
    glDeleteBuffers(1,&VBOLight);
    glDeleteBuffers(1,&VBOSky);
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

    //物体的shaderprogram
//    glEnable(GL_PROGRAM_POINT_SIZE);
    shaderRed.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/advancevertex.vert");
    shaderRed.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/redfrag.frag");
    shaderRed.link();
    shaderBlue.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/advancevertex.vert");
    shaderBlue.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/bluefrg.frag");
    shaderBlue.link();
    shaderGreen.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/advancevertex.vert");
    shaderGreen.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/greenfrag.frag");
    shaderGreen.link();
    shaderYellow.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/advancevertex.vert");
    shaderYellow.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/yellofrag.frag");
    shaderYellow.link();

//    unsigned int uniformBlockIndexRed =glGetUniformBlockIndex(shaderRed.programId(),"Matrices");
//    unsigned int uniformBlockIndexBlue=glGetUniformBlockIndex(shaderBlue.programId(),"Matrices");
//    unsigned int uniformBlockIndexGreen=glGetUniformBlockIndex(shaderGreen.programId(),"Matrices");
//    unsigned int uniformBlockIndexYello=glGetUniformBlockIndex(shaderYellow.programId(),"Matrices");

//    glUniformBlockBinding(shaderRed.programId(),uniformBlockIndexRed,0);
//    glUniformBlockBinding(shaderBlue.programId(),uniformBlockIndexBlue,0);
//    glUniformBlockBinding(shaderGreen.programId(),uniformBlockIndexGreen,0);
//    glUniformBlockBinding(shaderYellow.programId(),uniformBlockIndexYello,0);
    glGenBuffers(1,&uboMatrices);
    glBindBuffer(GL_UNIFORM_BUFFER,uboMatrices);
    glBufferData(GL_UNIFORM_BUFFER,2*sizeof (QVector4D)*4,NULL,GL_STATIC_DRAW);
    glBindBuffer(GL_UNIFORM_BUFFER,0);

    glBindBufferRange(GL_UNIFORM_BUFFER,0,uboMatrices,0,2*sizeof (QMatrix4x4));

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(cubeVertices),cubeVertices,GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3*sizeof (float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    glGenVertexArrays(1,&VAOLight);
    glGenBuffers(1,&VBOLight);
    glBindVertexArray(VAOLight);
    glBindBuffer(GL_ARRAY_BUFFER,VBOLight);

    glBufferData(GL_ARRAY_BUFFER,sizeof (planeVertices),planeVertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*5,(void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(float)*5,(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    glGenVertexArrays(1,&VAOSky);
    glGenBuffers(1,&VBOSky);
    glBindVertexArray(VAOSky);
    glBindBuffer(GL_ARRAY_BUFFER,VBOSky);
    glBufferData(GL_ARRAY_BUFFER,sizeof(skyboxVertices),skyboxVertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)nullptr);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    textureCube=new QOpenGLTexture(QImage(":/Texture/marble.jpg"));
    texturePlane=new QOpenGLTexture(QImage(":/Texture/metal.png"));
    QVector<QString> path;
    path<<":/Texture/skybox/right.jpg"<<":/Texture/skybox/left.jpg";
    path<<":/Texture/skybox/top.jpg"<<":/Texture/skybox/bottom.jpg";
    path<<":/Texture/skybox/front.jpg"<<":/Texture/skybox/back.jpg";
    texCubeMap=this->loadCubeMap(path);



    model.setToIdentity();
    projection.perspective(45.0f,width()/height(),0.1,100);



    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    qDebug()<<sizeof(QMatrix4x4)<<endl<<sizeof (QVector4D);

}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void MyOpenGLWidget::paintGL()
{

    glClearColor(0.4f,0.5f,0.4f,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    QMatrix4x4 view=camera.getView();
    glBindBuffer(GL_UNIFORM_BUFFER,uboMatrices);
    glBufferSubData(GL_UNIFORM_BUFFER,0,sizeof (QVector4D)*4,projection.constData());
    glBufferSubData(GL_UNIFORM_BUFFER,sizeof(QVector4D)*4,sizeof(QVector4D)*4,camera.getView().constData());

    glBindBuffer(GL_UNIFORM_BUFFER,0);


    switch (m_Shape) {
    case Rect:
        shaderRed.bind();
        model.setToIdentity();
        model.translate(-0.75,0.75,0);
        shaderRed.setUniformValue("model",model);
//        shaderRed.setUniformValue("projection1",projection);
//        shaderRed.setUniformValue("view1",camera.getView());
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,36);

        shaderBlue.bind();
        model.setToIdentity();
        model.translate(0.75,0.75,0);
        shaderRed.setUniformValue("model",model);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,36);

        shaderGreen.bind();
        model.setToIdentity();
        model.translate(-0.75,-0.75,0);
        shaderRed.setUniformValue("model",model);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,36);

        shaderYellow.bind();
        model.setToIdentity();
        model.translate(0.75,-0.75,0);
        shaderRed.setUniformValue("model",model);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES,0,36);



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

unsigned int MyOpenGLWidget::loadCubeMap(QVector<QString> faces)
{
    unsigned int textureId;
    glGenTextures(1,&textureId);
    glBindTexture(GL_TEXTURE_CUBE_MAP,textureId);

    for( int i=0;i<faces.size();i++)
    {
        QImage image=QImage(faces[i]).convertToFormat(QImage::Format::Format_RGB888);

        if(image.bits()!=nullptr)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i,0,
                         GL_RGB,image.width(),image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,image.bits());
        }
        else {
            qDebug()<<"CubeMap texture fail to load at path:"<<faces[i];
        }
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE);
    return textureId;
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
