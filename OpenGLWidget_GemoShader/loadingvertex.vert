#version 330 core
layout(location=0)in vec3 aPosition;
layout(location=1)in vec3 aNormal;
layout(location=2)in vec2 aTexCoords;
//爆炸
//out VS_OUT{
//    vec3 position;
//    vec3 Normal;
//    vec2 texCoords;
//}vs_out;

out vec2 TexCoords;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void)
{
    gl_Position = projection*view*model*vec4(aPosition,1.0f);
    TexCoords=aTexCoords;

//    vs_out.texCoords=aTexCoords;

//    vs_out.position=vec3(model*vec4(aPosition,1.0f));
//        vs_out.Normal=aNormal;//模型爆炸
//    vs_out.Normal=mat3(transpose(inverse(projection*view*model)))*aNormal;//法向量可视化
    //        normal = mat3(transpose(inverse(model))) * aNormal;
}
