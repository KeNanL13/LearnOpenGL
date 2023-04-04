#ifndef MODEL_H
#define MODEL_H
#include <QOpenGLShaderProgram>
#include <QVector>
#include <mesh.h>
#include <QString>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <QOpenGLFunctions_3_3_Core>
#include <QImage>

class Model
{
public:
    Model(char* path,QOpenGLFunctions_3_3_Core *glfuc);
    ~Model();
    void Draw( QOpenGLShaderProgram &shaderProgram);

private:
    void loadModel(QString path);
    QVector<Texture> textures_loaded;
    QVector<Mesh*> meshes;
    QString directory;
    QOpenGLFunctions_3_3_Core *glFuc;
//    void loadModel(QString path);
    void processNode(aiNode* node,const aiScene *scene);
    Mesh* processMesh(aiMesh* mesh,const aiScene *scene);
    QVector<Texture>loadMaterialTextures(aiMaterial * mat,aiTextureType type,QString typeName/*,const aiScene*scene*/);
    QOpenGLTexture* loadEmbeddedTexture(const aiTexture* aiTexture);

};

#endif // MODEL_H
