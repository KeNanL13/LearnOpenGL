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

    unsigned int VAO,VBO;
    unsigned int VAOLight;
    unsigned int textureWithGramma;
    Camera camera;
    QMatrix4x4 projection;
    QMatrix4x4 view;
    QMatrix4x4 model;
    QMatrix4x4 modelLight;
    QVector3D lightPos;
    float fov=45.0f;
     float x=0;
    QOpenGLShaderProgram shaderProgram;
    QOpenGLShaderProgram shaderProgramLight;
    QOpenGLTexture *texture;
    shape m_Shape=None;
    bool shadingMode=false;
signals:

public slots:

};

#endif // MYOPENGLWIDGET_H
