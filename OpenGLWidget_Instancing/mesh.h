#ifndef MESH_H
#define MESH_H
#include <QVector3D>
#include <QString>
#include <QVector>
#include <QOpenGLShaderProgram>
#include <qopenglfunctions_3_3_core.h>
#include <QOpenGLTexture>
struct Vertex{
    QVector3D Positon;
    QVector3D Normal;
    QVector3D TexCoords;
};

struct Texture{
    QOpenGLTexture *texture;
    QString type;
    QString path;
};

class Mesh
{
public:
    QVector<Vertex> vertices;
    QVector<unsigned int> indices;
    QVector<Texture> textures;
    Mesh(QOpenGLFunctions_3_3_Core*glFuc,QVector<Vertex>vertices,QVector<unsigned int>indices,QVector<Texture> textures);
    void Draw( QOpenGLShaderProgram&);
    unsigned int VAO;
private:
    unsigned int VBO,EBO;
    QOpenGLFunctions_3_3_Core *glFuc;
    void setupMesh();
};

#endif // MESH_H
