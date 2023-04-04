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
    //配置shaderProgram
    shaderProgramDepth.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/depthShader.vert");
    shaderProgramDepth.addShaderFromSourceFile(QOpenGLShader::Geometry,":/GLSL/depthShader.geom");
    shaderProgramDepth.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/depthShader.frag");
    shaderProgramDepth.link();

    shaderProgramPointShadow.addShaderFromSourceFile(QOpenGLShader::Vertex,":/GLSL/shadow.vert");
    shaderProgramPointShadow.addShaderFromSourceFile(QOpenGLShader::Fragment,":/GLSL/shadow.frag");
    shaderProgramPointShadow.link();

    //加载纹理
    texturePlane=new QOpenGLTexture(QImage(":/Texture/wood.png"));

    //配置 深度映射 FBO
    glGenFramebuffers(1,&depthMapFBO);
    glGenTextures(1,&depthMap);
    glBindTexture(GL_TEXTURE_CUBE_MAP,depthMap);
    for(unsigned int i=0;i<6;++i)
    {
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X+i,0,GL_DEPTH_COMPONENT,shadowWidth,shadowHeight,0,GL_DEPTH_COMPONENT,GL_FLOAT,nullptr);
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);

    glBindFramebuffer(GL_FRAMEBUFFER,depthMapFBO);
    glFramebufferTexture(GL_FRAMEBUFFER,GL_DEPTH_ATTACHMENT,depthMap,0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);
    glBindFramebuffer(GL_FRAMEBUFFER,defaultFramebufferObject());
    QVector3D lightPos=QVector3D(0,0,0);
    shaderProgramPointShadow.bind();
    shaderProgramPointShadow.setUniformValue("diffuseTexture",0);
    shaderProgramPointShadow.setUniformValue("depthMap",1);
    shaderProgramPointShadow.setUniformValue("lightPos",QVector3D(0,0,0));
    projection.perspective(90,width()/height(),0.1,100);
    shaderProgramPointShadow.setUniformValue("projection",projection);


    QMatrix4x4 shadowProj;
    shadowProj.perspective(90,shadowWidth/shadowHeight,nearField,farField);
    QVector<QMatrix4x4>shadowTransforms;
    QMatrix4x4 shadowLook;
    shadowLook.lookAt(lightPos,lightPos+QVector3D(1,0,0),QVector3D(0,-1,0));
    shadowTransforms.push_back(shadowProj*shadowLook);shadowLook.setToIdentity();
    shadowLook.lookAt(lightPos,lightPos+QVector3D(-1,0,0),QVector3D(0,-1,0));
    shadowTransforms.push_back(shadowProj*shadowLook);shadowLook.setToIdentity();
    shadowLook.lookAt(lightPos,lightPos+QVector3D(0,1,0),QVector3D(0,0,1));
    shadowTransforms.push_back(shadowProj*shadowLook);shadowLook.setToIdentity();
    shadowLook.lookAt(lightPos,lightPos+QVector3D(0,-1,0),QVector3D(0,0,-1));
    shadowTransforms.push_back(shadowProj*shadowLook);shadowLook.setToIdentity();
    shadowLook.lookAt(lightPos,lightPos+QVector3D(0,0,1),QVector3D(0,-1,0));
    shadowTransforms.push_back(shadowProj*shadowLook);shadowLook.setToIdentity();
    shadowLook.lookAt(lightPos,lightPos+QVector3D(0,0,-1),QVector3D(0,-1,0));
    shadowTransforms.push_back(shadowProj*shadowLook);shadowLook.setToIdentity();
    shaderProgramDepth.bind();
    for(int i=0;i<6;i++)
    {
        shaderProgramDepth.setUniformValue(QString("shadowMatrices[%1]").arg(i).toStdString().c_str(),shadowTransforms[i]);
    }
    shaderProgramDepth.setUniformValue("lightPos",QVector3D(0,0,0));
    shaderProgramDepth.setUniformValue("far_plane",farField);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);









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
        //render scene to depth cubemap
        glViewport(0,0,shadowWidth,shadowHeight);
        glBindFramebuffer(GL_FRAMEBUFFER,depthMapFBO);
        glClear(GL_DEPTH_BUFFER_BIT);
        shaderProgramDepth.bind();
        drawScene(shaderProgramDepth);
        //render scene as normal
        glBindFramebuffer(GL_FRAMEBUFFER,defaultFramebufferObject());
        glViewport(0,0,this->width(),this->height());
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        shaderProgramPointShadow.bind();
        shaderProgramPointShadow.setUniformValue("projection",projection);
        shaderProgramPointShadow.setUniformValue("view",camera.getView());
        shaderProgramPointShadow.setUniformValue("IsShadows",isShadow);
        shaderProgramPointShadow.setUniformValue("far_plane",farField);
        shaderProgramPointShadow.setUniformValue("viewPos",camera.getCameraPos());
        glActiveTexture(GL_TEXTURE0);
        texturePlane->bind(0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_CUBE_MAP,depthMap);
        drawScene(shaderProgramPointShadow);
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
   //room cube
    model.setToIdentity();
    model.scale(QVector3D(5.0f,5.0,5.0));
    shaderProgram.setUniformValue("model",model);
    glDisable(GL_CULL_FACE);
    shaderProgram.setUniformValue("reverse_normal",1);
    renderCube();
    shaderProgram.setUniformValue("reverse_normal",0);
    glEnable(GL_CULL_FACE);
    //CUBE
    model.setToIdentity();
    model.translate(QVector3D(4,-3.5,0));
    model.scale(0.5);
    shaderProgram.setUniformValue("model",model);
    renderCube();
    model.setToIdentity();
    model.translate(QVector3D(2,3,1));
    model.scale(0.75);
    shaderProgram.setUniformValue("model",model);
    renderCube();
    model.setToIdentity();
    model.translate(QVector3D(-3,-1,0));
    model.scale(0.5);
    shaderProgram.setUniformValue("model",model);
    renderCube();
    model.setToIdentity();
    model.translate(QVector3D(-1.5,1,1.5));
    model.scale(0.5);
    shaderProgram.setUniformValue("model",model);
    renderCube();
    model.setToIdentity();
    model.translate(QVector3D(-1.5,2,-3));
    model.scale(0.75);
    shaderProgram.setUniformValue("model",model);
    renderCube();
}

void MyOpenGLWidget::renderCube()
{
    if(VAOCube==0)
    {
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
        glGenVertexArrays(1,&VAOCube);
        glGenBuffers(1,&VBOCube);
        glBindVertexArray(VAOCube);
        glBindBuffer(GL_ARRAY_BUFFER,VBOCube);
        glBufferData(GL_ARRAY_BUFFER,sizeof (vertices),vertices,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof (float)*8,nullptr);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*8,(void*)(sizeof(float)*3));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof (float)*8,(void*)(sizeof(float)*6));
        glEnableVertexAttribArray(2);
        glBindVertexArray(0);
    }
    glBindVertexArray(VAOCube);
    glDrawArrays(GL_TRIANGLES,0,36);
    glBindVertexArray(0);
}

void MyOpenGLWidget::setIsShadow(bool isShadow)
{
    this->isShadow=isShadow;
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
