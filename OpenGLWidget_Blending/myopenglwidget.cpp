#include "myopenglwidget.h"


float cubeVertices[] = {
        // positions          // texture Coords
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
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
float transparentVertices[] = {
       // positions         // texture Coords (swapped y coordinates because texture is flipped upside down)
       0.0f,  0.5f,  0.0f,  0.0f,  0.0f,
       0.0f, -0.5f,  0.0f,  0.0f,  1.0f,
       1.0f, -0.5f,  0.0f,  1.0f,  1.0f,

       0.0f,  0.5f,  0.0f,  0.0f,  0.0f,
       1.0f, -0.5f,  0.0f,  1.0f,  1.0f,
       1.0f,  0.5f,  0.0f,  1.0f,  0.0f
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
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(cubeVertices),cubeVertices,GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(3*sizeof (float)));
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

    glGenVertexArrays(1,&VAOGrass);
    glGenBuffers(1,&VBOGrass);

    glBindVertexArray(VAOGrass);
    glBindBuffer(GL_ARRAY_BUFFER,VBOGrass);

    glBufferData(GL_ARRAY_BUFFER,sizeof(transparentVertices),transparentVertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*5,(void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(float)*5,(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

    textureCube=new QOpenGLTexture(QImage(":/Texture/marble.jpg").mirrored());
    texturePlane=new QOpenGLTexture(QImage(":/Texture/metal.png").mirrored());
    textureGlass=new QOpenGLTexture(QImage(":/Texture/blending_transparent_window.png"));
//    textureGlass->setWrapMode(QOpenGLTexture::WrapMode::ClampToEdge);//消除边框插值 造成边框为半透明。

    model.setToIdentity();
    projection.perspective(45.0f,width()/height(),0.1,100);
    modelTranslate.translate(3,0,3);
    shaderProgram.setUniformValue("projection",projection);
    shaderProgram.setUniformValue("model",model);
    shaderProgram.setUniformValue("texture_diffuse",0);
//    GrassPosition.push_back(QVector3D(-1.5f,0.0f,-0.48f));
//    GrassPosition.push_back(QVector3D(1.5f,0.0f,0.51f));
//    GrassPosition.push_back(QVector3D(0.0f,0.0f,0.7f));
    GrassPosition.push_back(QVector3D(-0.3f,0.0f,-2.3f));
    GrassPosition.push_back(QVector3D(-0.8f,0.0f,-1.3f));
    GrassPosition.push_back(QVector3D(-0.5f,0.0f,-3.6f));



    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);





}

void MyOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
}

void MyOpenGLWidget::paintGL()
{

    glClearColor(0.4f,0.5f,0.4f,0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    std::map<float,QVector3D> sorted;
    for( auto x :GrassPosition)
    {
        float key=camera.getCameraPos().distanceToPoint(x);
        sorted[key]=x;
    }


//    shaderProgram.setUniformValue("projection",projection);
//    shaderProgram.setUniformValue("model",model);
//    shaderProgram.setUniformValue("view",camera.getView());

//    shaderProgram.setUniformValue("cameraPos",camera.getCameraPos());
    model.setToIdentity();
    shaderProgram.bind();
    shaderProgram.setUniformValue("projection",projection);
    shaderProgram.setUniformValue("model",model);
    shaderProgram.setUniformValue("view",camera.getView());

    switch (m_Shape) {
    case Rect:
        shaderProgram.bind();
        //画地面

        glBindVertexArray(VAOLight);
        texturePlane->bind(0);
        glDrawArrays(GL_TRIANGLES,0,6);

        //画箱子

        glBindVertexArray(VAO);
        textureCube->bind(0);

        glDrawArrays(GL_TRIANGLES,0,36);

        shaderProgram.setUniformValue("model",modelTranslate);
        glDrawArrays(GL_TRIANGLES,0,36);
        //画草
        glBindVertexArray(VAOGrass);
        textureGlass->bind(0);
        for(std::map<float,QVector3D>::reverse_iterator it =sorted.rbegin();it!=sorted.rend();++it)

        {
            model.setToIdentity();
            model.translate(it->second);
            shaderProgram.setUniformValue("model",model);
            glDrawArrays(GL_TRIANGLES,0,6);

        }







        break;
    case ModelLoading:
//        x=x+0.01;
//        pointLightPos=QVector3D(5.0*sin(x),10,5*cos(x));
//        modelLight.setToIdentity();
//        modelLight.translate(pointLightPos);
        //绘制物体
        shaderProgram.bind();

        shaderProgram.setUniformValue("projection",projection);
        shaderProgram.setUniformValue("model",model);
        shaderProgram.setUniformValue("view",camera.getView());

        shaderProgram.setUniformValue("pointLight1.position",pointLightPos);
        shaderProgram.setUniformValue("cameraPos",camera.getCameraPos());
        model_To->Draw(shaderProgram);
//        model2->Draw(shaderProgram);

        //绘制光源
        shaderProgramLight.bind();


        glBindVertexArray(VAOLight);
        shaderProgramLight.setUniformValue("projection",projection);
        shaderProgramLight.setUniformValue("model",modelLight);
        shaderProgramLight.setUniformValue("view",camera.getView());
        glDrawArrays(GL_TRIANGLES,0,36);
        glBindVertexArray(0);
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
