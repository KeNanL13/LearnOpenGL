#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QVector3D>
#include <QTime>
#include <QTimer>
const float PI=3.14159265359f;
void GetSpherePoint()
{
    int thetaSegment=64;
    int alphaSegment=64;
    float radius=1.0;
    float d_theta=(2.0f*PI)/thetaSegment;
    float d_alpha=(PI)/alphaSegment;
    QVector<QVector3D>coords;
    for(int i=0;i<alphaSegment;i++)
    {
        for(int j=0;j<=thetaSegment;j++)
        {
            float x=radius * sinf(d_alpha * i) * cosf(d_theta * j);
            float y=radius * cosf(d_alpha * i) ;
            float z=radius * sinf(d_alpha * i) * sinf(d_theta * j);
//            qDebug()<<"x="<<x<<"\ty="<<y<<"\tz="<<z;
            coords.push_back(QVector3D(x,y,z));
        }
    }
//    for(int i=0;i<(2*thetaSegment);i++)
//    {
//        qDebug()<<"coords:"<<i<<"\t"<<coords[i];
//    }
    QVector<int> indices;
//    bool isOdd=false;
    for(int i=0;i<alphaSegment;i++)
    {
            for(int j=0;j<=thetaSegment;j++)
            {
                    indices.push_back(i * (thetaSegment+1) + j);
                    indices.push_back((i+1) * (thetaSegment + 1) + j);
            }
    }

}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();

    GetSpherePoint();
    return 0;
}
