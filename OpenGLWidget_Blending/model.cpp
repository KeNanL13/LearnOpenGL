#include "model.h"

Model::Model(char* path,QOpenGLFunctions_3_3_Core *glfuc):glFuc(glfuc)
{
        this->loadModel(path);
}

Model::~Model()
{
    for(auto x:meshes)
    {
        if(x!=nullptr)
        {
            delete x;
            x=nullptr;
        }
    }
}

void Model::Draw( QOpenGLShaderProgram & shaderProgram)
{
    for(unsigned int i=0;i<meshes.size();i++)
    {
        meshes[i]->Draw(shaderProgram);
    }
}

void Model::loadModel(QString path)
{
    Assimp::Importer import;
    const aiScene * scene=import.ReadFile(path.toStdString(),aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene ||scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE||!scene->mRootNode)
    {
        qDebug()<<"ERROR::ASSIMP::"<<import.GetErrorString();
        return;
    }
    directory=path.toStdString().substr(0,path.toStdString().find_last_of('/')).c_str();
    processNode(scene->mRootNode,scene);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    for(unsigned int i=0;i<node->mNumMeshes;i++)
    {
        aiMesh* mesh=scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh,scene));
    }
    for(unsigned int i=0;i<node->mNumChildren;i++)
    {
        processNode(node->mChildren[i],scene);
    }
}

Mesh* Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    QVector<Vertex> vertices;
    QVector<unsigned int> indices;
    QVector<Texture> textures;

    for(unsigned int i=0;i<mesh->mNumVertices;i++)
    {
        Vertex vertex;
        QVector3D vector;
        vector.setX(mesh->mVertices[i].x);
        vector.setY(mesh->mVertices[i].y);
        vector.setZ(mesh->mVertices[i].z);
        vertex.Positon=vector;

        vector.setX(mesh->mNormals[i].x);
        vector.setY(mesh->mNormals[i].y);
        vector.setZ(mesh->mNormals[i].z);
        vertex.Normal=vector;

        if(mesh->mTextureCoords[0])
        {
            QVector2D vector2;
            vector2.setX(mesh->mTextureCoords[0][i].x);
            vector2.setY(mesh->mTextureCoords[0][i].y);
            vertex.TexCoords=vector2;
        }
        else {
            vertex.TexCoords=QVector2D(0.0f,0.0f);
        }
        vertices.push_back(vertex);
    }

    for (unsigned int i=0;i<mesh->mNumFaces;i++)
    {
        aiFace face=mesh->mFaces[i];
        for(unsigned int j=0;j<face.mNumIndices;j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }



    //纹理
    if(mesh->mMaterialIndex>=0)
    {
        aiMaterial * material=scene->mMaterials[mesh->mMaterialIndex];
        QVector<Texture> diffuseMaps;
        diffuseMaps=this->loadMaterialTextures(material,aiTextureType_DIFFUSE,QString("texture_diffuse")/*,scene*/);

        textures.append(diffuseMaps);
        QVector<Texture> specularMaps;
        specularMaps=this->loadMaterialTextures(material,aiTextureType_SPECULAR,QString("texture_specular")/*,scene*/);
        textures.append(specularMaps);
    }

    Mesh *mesh_to=new Mesh(glFuc,vertices,indices,textures);
    return mesh_to;
}

QVector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, QString typeName/*,const aiScene*scene*/)
{
    QVector<Texture> textures;
    for(unsigned int i=0;i<mat->GetTextureCount(type);i++)
    {
        aiString str;
        mat->GetTexture(type,i,&str);
//        qDebug()<<str.C_Str();
        bool skip=false;
        for( int j=0;j<textures_loaded.size();j++)
        {
            if(textures_loaded[j].path==str.C_Str())
            {
                textures.push_back(textures_loaded[j]);
                skip=true;
                break;
            }
        }
        if(!skip)
        {
            Texture texture;
            QString path=directory+"/"+str.C_Str();
            qDebug()<<path;
//            const aiTexture* aiTexture1=scene->GetEmbeddedTexture(str.C_Str());
//            if(aiTexture1!=nullptr)
//            {
//                texture.texture=this->loadEmbeddedTexture(aiTexture1);

//            }
//            else {
                 texture.texture=new QOpenGLTexture(QImage(path));
//            }
            texture.path=str.C_Str();
            texture.type=typeName;

            textures.push_back(texture);
        }
    }
    return  textures;
}

QOpenGLTexture *Model::loadEmbeddedTexture(const aiTexture*aiTexture)
{


    QImage image;
    image.loadFromData(reinterpret_cast<unsigned char*>(aiTexture->pcData),sizeof(aiTexture->pcData));
    QOpenGLTexture * texture=new QOpenGLTexture(image);
    qDebug()<<1;
    return texture;
}
