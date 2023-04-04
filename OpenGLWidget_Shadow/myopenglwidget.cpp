#include "myopenglwidget.h"

float planeVertices[] = {
       // positions            // normals         // texcoords
        25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,  25.0f,  0.0f,
       -25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
       -25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,   0.0f, 25.0f,

        25.0f, -0.5f,  25.0f,  0.0f, 1.0f, 0.0f,  25.0f,  0.0f,
       -25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,   0.0f, 25.0f,
        25.0f, -0.5f, -25.0f,  0.0f, 1.0f, 0.0f,  25.0f, 25.0f
   };

float vertices[] = {
            // back face
            -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
             1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
             1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f, // bottom-right
             1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
            -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
            -1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f, // top-left
            // front face
            -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
             1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f, // bottom-right
             1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
             1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
            -1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f, // top-left
            -1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
            // left face
            -1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
            -1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-left
            -1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
            -1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
            -1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-right
            -1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
            // right face
             1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
             1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
             1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-right
             1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
             1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
             1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-left
            // bottom face
            -1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
             1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // top-left
             1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
             1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
            -1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f, // bottom-right
            -1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
            // top face
            -1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
             1.0f,  1.0f , 1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
             1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f, // top-right
             1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
            -1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
            -1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f  // bottom-left
        };

float quadVertices[] = {
            // positions        // texture Coords
            -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
             1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
             1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        };
MyOpenGLWidget::MyOpenGLWidget(QWidget *parent) :
    QOpenGLWidget (parent),
    camera(this)

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
    shaderProgramShadowMapping.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/vertex.vert");
    shaderProgramShadowMapping.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/fragment.frag");
    shaderProgramShadowMapping.link();

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/debug_quad.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/debug_quad.frag");
    shaderProgram.link();

    glGenVertexArrays(1,&VAOQuad);
    glGenBuffers(1,&VBOQuad);
    glBindVertexArray(VAOQuad);
    glBindBuffer(GL_ARRAY_BUFFER,VBOQuad);
    glBufferData(GL_ARRAY_BUFFER,sizeof(quadVertices),quadVertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*5,nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,sizeof(float)*5,(void*)(sizeof(float)*3));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
    glEnable(GL_DEPTH_TEST);

    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof (planeVertices),planeVertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*8,nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*8,(void*)(sizeof(float)*3));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(float)*8,(void*)(sizeof(float)*6));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);

    glGenVertexArrays(1,&VAOCube);
    glGenBuffers(1,&VBOCube);
    glBindVertexArray(VAOCube);
    glBindBuffer(GL_ARRAY_BUFFER,VBOCube);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*8,nullptr);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*8,(void*)(sizeof(float)*3));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(float)*8,(void*)(sizeof(float)*6));
    glEnableVertexAttribArray(2);
    glBindVertexArray(0);




    texturePlane=new QOpenGLTexture(QImage(":/Texture/wood.png").mirrored());


    shaderProgramLight.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/depthShader.vert");
    shaderProgramLight.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/depthShader.frag");
    shaderProgramLight.link();
    glGenFramebuffers(1,&depthMapFBO);
    glGenTextures(1,&depthMap);
    glBindTexture(GL_TEXTURE_2D,depthMap);
    glTexImage2D(GL_TEXTURE_2D,0,GL_DEPTH_COMPONENT,shadowWidth,shadowHeight,0,GL_DEPTH_COMPONENT,GL_FLOAT,nullptr);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_BORDER);
    float border[]={1.0,1.0,1.0,1.0};
    glTexParameterfv(GL_TEXTURE_2D,GL_TEXTURE_BORDER_COLOR,border);

    glBindFramebuffer(GL_FRAMEBUFFER,depthMapFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,GL_TEXTURE_2D,depthMap,0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER,defaultFramebufferObject());


    QVector3D lightPos(-2.0f,4.0,-1.0);
    lightProjection.ortho(-10,10,-10,10,1.0f,7.5f);
    lightView.lookAt(lightPos,QVector3D(0,0,0),QVector3D(0,1,0));
    lightSpaceMatrix=lightProjection*lightView;

    shaderProgramShadowMapping.bind();
    model.setToIdentity();
    projection.perspective(45,width()/height(),0.1,100);
    shaderProgramShadowMapping.setUniformValue("model",model);
    shaderProgramShadowMapping.setUniformValue("projection",projection);
    shaderProgramShadowMapping.setUniformValue("lightSpaceMatrix",lightSpaceMatrix);
    shaderProgramShadowMapping.setUniformValue("lightPos",lightPos);
    shaderProgramShadowMapping.setUniformValue("diffuseTexture",0);
    shaderProgramShadowMapping.setUniformValue("shadowMap",1);




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
      shaderProgramLight.bind();
//      lightSpaceMatrix=camera.getView()*lightProjection;
      shaderProgramLight.setUniformValue("lightSpaceMatrix",lightSpaceMatrix);
      glViewport(0,0,shadowWidth,shadowHeight);
      glBindFramebuffer(GL_FRAMEBUFFER,depthMapFBO);
      glClear(GL_DEPTH_BUFFER_BIT);
      texturePlane->bind();
      glCullFace(GL_FRONT);
      drawScene(shaderProgramLight);
      glCullFace(GL_BACK);


      glBindFramebuffer(GL_FRAMEBUFFER,this->defaultFramebufferObject());
      glViewport(0,0,width(),height());
      glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//      shaderProgram.bind();
//      shaderProgram.setUniformValue("near_plane",1.0f);
//      shaderProgram.setUniformValue("far_plane",7.5f);
      shaderProgramShadowMapping.bind();
      shaderProgramShadowMapping.setUniformValue("projection",projection);
      shaderProgramShadowMapping.setUniformValue("view",camera.getView());
      shaderProgramShadowMapping.setUniformValue("viewPos",camera.getCameraPos());
      texturePlane->bind(0);
      glActiveTexture(GL_TEXTURE1);
      glBindTexture(GL_TEXTURE_2D,depthMap);
      drawScene(shaderProgramShadowMapping);



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
    default:
        break;
    }

    update();
    doneCurrent();
}

void MyOpenGLWidget::drawScene(QOpenGLShaderProgram &shaderProgram)
{
    model.setToIdentity();
    shaderProgram.setUniformValue("model",model);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,6);

    model.translate(QVector3D(0,1.5,0));
    model.scale(0.5f);
    shaderProgram.setUniformValue("model",model);
    glBindVertexArray(VAOCube);
    glDrawArrays(GL_TRIANGLES,0,36);
    model.setToIdentity();
    model.translate(QVector3D(2,0,1));
    model.scale(0.5);
    shaderProgram.setUniformValue("model",model);
    glDrawArrays(GL_TRIANGLES,0,36);
    model.setToIdentity();
    model.translate(QVector3D(-1,0,2));
    model.rotate(60,QVector3D(1,0,1));
    model.scale(0.25);
    shaderProgram.setUniformValue("model",model);
    glDrawArrays(GL_TRIANGLES,0,36);
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
