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
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/vertexbasic.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/fragmentbasic.frag");
    shaderProgram.link();
    shaderSky.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/skycubevertex.vert");
    shaderSky.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/skycubefrag.frag");
    shaderSky.link();
    shaderProgramLight.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/vertexlight.vert");
    shaderProgramLight.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/fragmentlight.frag");
    shaderProgramLight.link();
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
    shaderProgram.setUniformValue("projection",projection);
    shaderProgram.setUniformValue("model",model);
    shaderProgram.setUniformValue("texture_diffuse",0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void MyOpenGLWidget::paintGL()
{

    glClearColor(0.4f,0.5f,0.4f,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    QMatrix4x4 skyView=camera.getView();
    skyView.setColumn(3,QVector4D(0,0,0,1));

    shaderProgram.bind();
    shaderProgram.setUniformValue("projection",projection);
    shaderProgram.setUniformValue("model",model);
    shaderProgram.setUniformValue("view",camera.getView());
    shaderProgram.setUniformValue("cameraPos",camera.getCameraPos());
    switch (m_Shape) {
    case Rect:
//        glDepthMask(GL_FALSE);
//        shaderSky.bind();
//        shaderSky.setUniformValue("projection",projection);

//        shaderSky.setUniformValue("view",skyView );
//        glBindVertexArray(VAOSky);
//        glBindTexture(GL_TEXTURE_CUBE_MAP,texCubeMap);
//        glDrawArrays(GL_TRIANGLES,0,36);
//        glDepthMask(GL_TRUE);

        shaderProgram.bind();
        glBindVertexArray(VAO);
        glBindTexture(GL_TEXTURE_2D,texCubeMap);

        glDrawArrays(GL_TRIANGLES,0,36);

//        glBindVertexArray(VAOLight);
//        texturePlane->bind(0);
//        glDrawArrays(GL_TRIANGLES,0,6);

        glDepthFunc(GL_LEQUAL);
        shaderSky.bind();
        shaderSky.setUniformValue("projection",projection);

        shaderSky.setUniformValue("view",skyView );
        glBindVertexArray(VAOSky);
        glBindTexture(GL_TEXTURE_CUBE_MAP,texCubeMap);
        glDrawArrays(GL_TRIANGLES,0,36);
        glDepthFunc(GL_LESS);
        break;
    case ModelLoading:
//        x=x+0.01;
//        pointLightPos=QVector3D(5.0*sin(x),10,5*cos(x));
//        modelLight.setToIdentity();
//        modelLight.translate(pointLightPos);
        //绘制物体
//        glDepthMask(FALSE);

        shaderProgram.bind();

        shaderProgram.setUniformValue("projection",projection);
        shaderProgram.setUniformValue("model",model);
        shaderProgram.setUniformValue("view",camera.getView());

        shaderProgram.setUniformValue("pointLight1.position",pointLightPos);
        shaderProgram.setUniformValue("cameraPos",camera.getCameraPos());
        model_To->Draw(shaderProgram);

        glDepthFunc(GL_LEQUAL);
        shaderSky.bind();
        shaderSky.setUniformValue("projection",projection);

        shaderSky.setUniformValue("view",skyView );
        glBindVertexArray(VAOSky);
        glBindTexture(GL_TEXTURE_CUBE_MAP,texCubeMap);
        glDrawArrays(GL_TRIANGLES,0,36);
        glDepthFunc(GL_LESS);
//        model2->Draw(shaderProgram);

        //绘制光源
//        shaderProgramLight.bind();


//        glBindVertexArray(VAOLight);
//        shaderProgramLight.setUniformValue("projection",projection);
//        shaderProgramLight.setUniformValue("model",modelLight);
//        shaderProgramLight.setUniformValue("view",camera.getView());
//        glDrawArrays(GL_TRIANGLES,0,36);
//        glBindVertexArray(0);
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
