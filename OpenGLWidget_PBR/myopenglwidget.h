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
    void TimerStart();
    void TimerEnd();

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
    Camera camera;
    QMatrix4x4 projection;
    QMatrix4x4 view;
    QMatrix4x4 model;;


    float fov=45.0f;
    QOpenGLShaderProgram *shaderProgram;
    QVector3D lightPositions[4];
    QVector3D lightColors[4];
    int nrRows=7;
    int nrColumns=7;
    float spacing=2.5;

    shape m_Shape=None;
    QTimer * m_timer;
    int count;

private:
    unsigned int sphereVAO=0;
    unsigned int indexCount;
    void RenderSphere();
    float Clamp(float x,float min,float max);
signals:

public slots:

};

#endif // MYOPENGLWIDGET_H
