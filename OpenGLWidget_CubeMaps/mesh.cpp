#include "mesh.h"

Mesh::Mesh( QOpenGLFunctions_3_3_Core*glFuc,QVector<Vertex>vertices,QVector<unsigned int>indices,QVector<Texture> textures)
    :
      vertices(vertices),
      indices(indices),
      textures(textures),
      glFuc(glFuc)
{
    setupMesh();
}

void Mesh::Draw( QOpenGLShaderProgram &shaderProgram)
{
    unsigned int diffuseNr=1;
    unsigned int specularNr=1;
    for(unsigned int i=0;i<textures.size();i++)
    {

        QString number;
        QString name=textures[i].type;
        if(name=="texture_diffuse")
            number=QString::number(diffuseNr++);
        else if(name=="texture_specular")
            number=QString::number(specularNr++);
        QString textureName=QString("material."+name+number);
        shaderProgram.setUniformValue(textureName.toStdString().c_str(),i);
        textures[i].texture->bind(i);
    }
    shaderProgram.bind();

    glFuc->glBindVertexArray(VAO);
    glFuc->glDrawElements(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0);
    glFuc->glBindVertexArray(0);

}
void Mesh:: setupMesh()
{
    glFuc->glGenVertexArrays(1,&VAO);
    glFuc->glGenBuffers(1,&VBO);
    glFuc->glGenBuffers(1,&EBO);

    glFuc->glBindVertexArray(VAO);

    glFuc->glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glFuc->glBufferData(GL_ARRAY_BUFFER,vertices.size()*sizeof (Vertex),&vertices[0],GL_STATIC_DRAW);

    glFuc->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glFuc->glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size()*sizeof (unsigned int),&indices[0],GL_STATIC_DRAW);

    glFuc->glEnableVertexAttribArray(0);
    glFuc->glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void *)0);
    glFuc->glEnableVertexAttribArray(1);
    glFuc->glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,Normal));
    glFuc->glEnableVertexAttribArray(2);
    glFuc->glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(Vertex),(void*)offsetof(Vertex,TexCoords));

    glFuc->glBindVertexArray(0);



}
