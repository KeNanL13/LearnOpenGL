#include "mycamera.h"

MyCamera::MyCamera():position(QVector3D(0.0f,0.0f,1.0f)),
                     lookPoint(QVector3D(0.0f,0.0f,0.0f)),
                     vectorUp(QVector3D(0.0f,1.0f,0.0f))
{
    vectorLook=lookPoint-position;
    vectorRight=QVector3D::crossProduct(vectorLook,vectorUp);
    view.lookAt(position,lookPoint,vectorUp);

}

void MyCamera::handle(QEvent *event)
{
     QMouseEvent * mouseEvent=static_cast<QMouseEvent*>(event);
     QWheelEvent * wheelEvent=static_cast<QWheelEvent*>(event);
    if(event->type()==QEvent::MouseButtonPress)
    {

        if(mouseEvent->button()==Qt::LeftButton)
        {
            m_ViewState=Rotation;
            Pos.setX(mouseEvent->pos().x());
            Pos.setY(mouseEvent->pos().y());
        }
        else if (mouseEvent->button()==Qt::RightButton)
        {
            m_ViewState=Move;
            Pos.setX(mouseEvent->pos().x());
            Pos.setY(mouseEvent->pos().y());
        }
    }
    else if(event->type()==QEvent::MouseMove)
    {
        if(m_ViewState==Rotation)
        {
            float xoff=(Pos.x()-mouseEvent->pos().x())*0.00000001;
            float yoff=(Pos.y()-mouseEvent->pos().y())*0.00000001;
            position.setX(position.x()+xoff);
            position.setY(position.y()+yoff);
            view.lookAt(position,lookPoint,vectorUp);
            Pos.setX(mouseEvent->pos().x());
            Pos.setY(mouseEvent->pos().y());

        }
        else if (m_ViewState ==Move)
        {
            float xoff=(Pos.x()-mouseEvent->pos().x())*0.00000001;
            float yoff=(Pos.y()-mouseEvent->pos().y())*0.00000001;
//            view.translate(xoff,yoff,0);
            position.setX(position.x()+xoff);
            position.setY(position.y()+yoff);
            lookPoint.setX(lookPoint.x()+xoff);
            lookPoint.setY(position.y()+yoff);
            view.lookAt(position,lookPoint,vectorUp);
            Pos.setX(mouseEvent->pos().x());
            Pos.setY(mouseEvent->pos().y());
        }
    }else if(event->type()==QEvent::MouseButtonRelease)
    {
        m_ViewState=None;
    }else if (event->type()==QEvent::Wheel)
    {
        int delta=wheelEvent->delta();
        position=position+delta*0.1*(lookPoint-position);
        view.lookAt(position,lookPoint,vectorUp);
    }


}

QMatrix4x4 MyCamera::getView()
{
    return  view;
}



QMatrix4x4 MyCamera::RodriguesMatrix(QVector3D rotationAxis,float theta)
{
    QMatrix4x4 Matrix;
    float x,y,z;
    x=rotationAxis.x();
    y=rotationAxis.y();
    z=rotationAxis.z();
    Matrix.setRow(0,QVector4D(cosf(theta)+x*x*(1-cosf(theta)),
                              x*y*(1-cosf(theta))-z*sinf(theta),
                             x*z*(1-cosf(theta)+y*sinf(theta)),0));
    Matrix.setRow(1,QVector4D(y*x*(1-cosf(theta))+z*sinf(theta),
                              cosf(theta)+y*y*(1-cosf(theta)),
                              y*z*(1-cosf(theta))-x*sinf(theta),0));
    Matrix.setRow(2,QVector4D(z*x*(1-cosf(theta))-y*sinf(theta),
                             z*y*(1-cosf(theta))+x*sinf(theta),
                             cosf(theta)+z*z*(1-cosf(theta)),0));
    Matrix.setRow(3,QVector4D(0.0f,0.0f,0.0f,1.0f));
    return Matrix;
}
