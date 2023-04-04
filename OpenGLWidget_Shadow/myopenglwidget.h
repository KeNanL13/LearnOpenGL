#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QObject>
#include <QOpenGLWidget>
#include <qopenglfunctions_3_3_core.h>
#include <QtMath>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>
#include <camera.h>
#include <QImage>
class MyOpenGLWidget : public QOpenGLWidget,QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit MyOpenGLWidget(QWidget *parent = nullptr);
    ~MyOpenGLWidget();
    void setShape();
    void setWireFrame(bool);
    void Clear();

    enum shape{Rect,None};
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void wheelEvent(QWheelEvent *event);
    bool event(QEvent *e) override;
    void keyPressEvent(QKeyEvent *event);

private:

    unsigned int VAO,VBO,VAOCube,VBOCube,VAOQuad,VBOQuad;
    unsigned int VAOLight;
    unsigned int depthMapFBO,depthMap;
    int shadowWidth=1024,shadowHeight=1024;
    Camera camera;
    QMatrix4x4 projection,lightProjection;
    QMatrix4x4 view,lightView;
    QMatrix4x4 lightSpaceMatrix;
    QMatrix4x4 model;
    QMatrix4x4 modelLight;
//    QVector3D lightPos;
    float fov=45.0f;
     float x=0;
    QOpenGLShaderProgram shaderProgram;
    QOpenGLShaderProgram shaderProgramLight;
    QOpenGLShaderProgram shaderProgramShadowMapping;
    QOpenGLTexture * texturePlane;
    shape m_Shape=None;

    void drawScene(QOpenGLShaderProgram& shaderProgram);

signals:

public slots:

};

#endif // MYOPENGLWIDGET_H
