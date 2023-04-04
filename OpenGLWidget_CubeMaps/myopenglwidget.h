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
#include <QMatrix4x4>
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
    unsigned int loadCubeMap(QVector<QString>faces);

    unsigned int VAO,VBO;
    unsigned int VAOLight,VBOLight,VAOSky,VBOSky;
    unsigned int texCubeMap;
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
    QOpenGLShaderProgram shaderSky;
    shape m_Shape=None;
    QOpenGLTexture * textureCube;
    QOpenGLTexture * texturePlane;

    QVector3D pointLightPositon[4];
    QVector3D pointLightPos;
    Model *model_To;
    Model * model2;

signals:

public slots:

};

#endif // MYOPENGLWIDGET_H
