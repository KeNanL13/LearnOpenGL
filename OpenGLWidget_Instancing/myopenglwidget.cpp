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
float quadVertices[] = {
    // 位置          // 颜色
    -0.05f,  0.05f,  1.0f, 0.0f, 0.0f,
     0.05f, -0.05f,  0.0f, 1.0f, 0.0f,
    -0.05f, -0.05f,  0.0f, 0.0f, 1.0f,

    -0.05f,  0.05f,  1.0f, 0.0f, 0.0f,
     0.05f, -0.05f,  0.0f, 1.0f, 0.0f,
     0.05f,  0.05f,  0.0f, 1.0f, 1.0f
};
MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) :
    QOpenGLWidget (parent),
    camera(this),
    lightPos(0.0f,1.2f,2.0f)
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
    model1=new Model("C:/Users/Administrator/Desktop/rock/rock.obj",this);
    model2=new Model("C:/Users/Administrator/Desktop/plane/planet.obj",this);
    int index=0;
    float offset=0.1f;
    for(int y=-10;y<10;y+=2)
    {
        for(int x=-10;x<10;x+=2)
        {
            translations[index].setX(x/10.0f+offset);
            translations[index].setY(y/10.0f+offset);
            index++;
        }
    }
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,":/arrayinstancever.vert");
//    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Geometry,":/geo.geom");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,":/frag.frag");
    shaderProgram.link();
    //小行星加载
    shaderModel.addShaderFromSourceFile(QOpenGLShader::Vertex,":/loadingvertex.vert");
    shaderModel.addShaderFromSourceFile(QOpenGLShader::Fragment,":/loadingfrag.frag");
    shaderModel.link();

    shaderInstance.addShaderFromSourceFile(QOpenGLShader::Vertex,":/instanceloading.vert");
    shaderInstance.addShaderFromSourceFile(QOpenGLShader::Fragment,":/loadingfrag.frag");
    shaderInstance.link();



    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof (quadVertices),quadVertices,GL_STATIC_DRAW);
//    glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(points),points);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,5*sizeof (float),(void*)nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(2*sizeof (float)));
    glEnableVertexAttribArray(1);
    glGenBuffers(1,&instanceVBO);
    glBindBuffer(GL_ARRAY_BUFFER,instanceVBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(QVector2D)*100,&translations[0],GL_STATIC_DRAW);
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,2*sizeof (float),(void*)0);
    glEnableVertexAttribArray(2);
    glVertexAttribDivisor(2,1);
    glBindVertexArray(0);

    //生成数组
    qsrand(QTime::currentTime().second());
    float radius=10.0f;
    float off=2.5f;
    for(unsigned int i=0;i<100000;i++)
    {
        QMatrix4x4 model;
        float angle=(float)i/(float)100000*360;
        float displacement=(qrand()%(int)(2 * off * 100)) / 100.0f - off;
        float x=sin(angle)*radius+displacement;
        displacement=(qrand()%(int)(2 * off * 100)) / 100.0f - off;
        float y=displacement*0.4f;
        displacement=(qrand()%(int)(2 * off * 100)) / 100.0f - off;
        float z=cos(angle)*radius+displacement;
        model.translate(x,y,z);
        float scale=(qrand()%10)/100.0f+0.005;
        model.scale(scale);
        float rotAngle=(qrand()%360);
        model.rotate(rotAngle,QVector3D(0.4f,0.6f,0.8f));
        //注意是列
        models[i]=model;
        matrix[i].row1=model.column(0);
        matrix[i].row2=model.column(1);
        matrix[i].row3=model.column(2);
        matrix[i].row4=model.column(3);

    }

    //普通加载行星
//    shaderProgram.bind();
//    for(int i=0;i<100;i++)
//    {
//        QString name=QString("offsets[%1]").arg(i);
//        shaderProgram.setUniformValue(name.toStdString().c_str(),translations[i]);
//    }

    //实例化加载行星
    glGenBuffers(1,&instanceVBOPlanet);
    glBindBuffer(GL_ARRAY_BUFFER,instanceVBOPlanet);
    glBufferData(GL_ARRAY_BUFFER,100000*sizeof(myMatrix4x4),matrix,GL_STATIC_DRAW);
    for(unsigned int i=0;i<model1->meshes.size();i++)
    {
        unsigned int VAO=model1->meshes[i]->VAO;
        glBindVertexArray(VAO);
//        glBindBuffer(GL_ARRAY_BUFFER,instanceVBOPlanet);
        GLsizei vector4Dsize=sizeof(QVector4D);
        glEnableVertexAttribArray(3);;
        glVertexAttribPointer(3,4,GL_FLOAT,GL_FALSE,4*vector4Dsize,(void*)nullptr);
        glEnableVertexAttribArray(4);;
        glVertexAttribPointer(4,4,GL_FLOAT,GL_FALSE,4*vector4Dsize,(void*)vector4Dsize);
        glEnableVertexAttribArray(5);;
        glVertexAttribPointer(5,4,GL_FLOAT,GL_FALSE,4*vector4Dsize,(void*)(2*vector4Dsize));
        glEnableVertexAttribArray(6);;
        glVertexAttribPointer(6,4,GL_FLOAT,GL_FALSE,4*vector4Dsize,(void*)(3*vector4Dsize));

        glVertexAttribDivisor(3,1);
        glVertexAttribDivisor(4,1);
        glVertexAttribDivisor(5,1);
        glVertexAttribDivisor(6,1);
        glBindVertexArray(0);

    }
    //行星加载
    shaderModel.bind();

    projection.perspective(45.0,width()/height(),0.1,100);
    model.setToIdentity();
    shaderModel.setUniformValue("projection",projection);
    shaderModel.setUniformValue("view",camera.getView());
    shaderModel.setUniformValue("model",model);
    shaderModel.setUniformValue("texture_diffuse",0);
    shaderInstance.bind();
    shaderInstance.setUniformValue("projection",projection);
    shaderInstance.setUniformValue("view",camera.getView());


    glEnable(GL_DEPTH_TEST);


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
        glBindVertexArray(VAO);
        glDrawArraysInstanced(GL_TRIANGLES,0,6,100);
        break;
    case ModelLoading:


        shaderModel.bind();
        shaderModel.setUniformValue("projection",projection);
        shaderModel.setUniformValue("model",model);
        shaderModel.setUniformValue("view",camera.getView());
        model2->Draw(shaderModel);
/****************普通加载***********/
//        for(int i=0;i<100000;i++)
//        {
//            shaderModel.setUniformValue("model",models[i]);
//            model1->Draw(shaderModel);

//        }
/********************实例化加载************/
        shaderInstance.bind();
        shaderInstance.setUniformValue("projection",projection);
        shaderInstance.setUniformValue("view",camera.getView());
        for(unsigned int i=0;i<model1->meshes.size();i++)
        {
            glBindVertexArray(model1->meshes[i]->VAO);
            glDrawElementsInstanced(
                        GL_TRIANGLES,model1->meshes[i]->indices.size(),GL_UNSIGNED_INT,0,100000);
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
   projection.perspective(fov,width()/height(),0.1f,1000);
    makeCurrent();
    update();
    doneCurrent();
}
