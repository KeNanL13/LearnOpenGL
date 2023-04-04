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
#include <model.h>
struct myMatrix4x4
{
    QVector4D row1;
    QVector4D row2;
    QVector4D row3;
    QVector4D row4;
};

class MyOpenGLWidget : public QOpenGLWidget,QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit MyOpenGLWidget(QWidget *parent = nullptr);
    ~MyOpenGLWidget();

    void setShape();

    void setWireFrame(bool);
    void Clear();

    void loadModel();

    enum shape{None,Rect,ModelLoading};
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void wheelEvent(QWheelEvent *event);
    bool event(QEvent *e) override;
    void keyPressEvent(QKeyEvent *event);

private:

    unsigned int VAO,VBO,VAOquad,VBOquad;
    unsigned int tex,texInter;
    unsigned int FBOMuti,FBO;
    unsigned int RBO;
    Camera camera;
    QMatrix4x4 projection;
    QMatrix4x4 view;
    QMatrix4x4 model;


    float fov=45.0f;
     float x=0;
    QOpenGLShaderProgram shaderProgram,shaderQuad;

    shape m_Shape=None;




signals:

public slots:

};

#endif // MYOPENGLWIDGET_H
