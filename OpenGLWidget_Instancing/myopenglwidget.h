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

    unsigned int VAO,VBO;
    unsigned int VAOLight,VBOLight;
    unsigned int instanceVBO;
    unsigned int instanceVBOPlanet;
    QVector2D translations[100];
    Camera camera;
    QMatrix4x4 projection;
    QMatrix4x4 view;
    QMatrix4x4 model;
    QMatrix4x4 modelLight;
    QVector3D lightPos;
    QMatrix4x4 models[100000];
    myMatrix4x4 matrix[100000];


    float fov=45.0f;
     float x=0;
    QOpenGLShaderProgram shaderProgram;
    QOpenGLShaderProgram shaderModel;
    QOpenGLShaderProgram shaderNormal;
    QOpenGLShaderProgram shaderInstance;
    shape m_Shape=None;
    QOpenGLTexture * textureCube;
    QOpenGLTexture * texturePlane;
    QVector3D pointLightPositon[4];
    QVector3D pointLightPos;
    Model *model1,*model2;

signals:

public slots:

};

#endif // MYOPENGLWIDGET_H
