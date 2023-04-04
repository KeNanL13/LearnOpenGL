#version 330 core
layout(location=0)in vec3 aPosition;
layout(location=1)in vec3 aNormal;


out VS_OUT{
    vec3 Normal;
}vs_out;


uniform mat4 model;
uniform mat4 view;


void main(void)
{
    gl_Position=view*model*vec4(aPosition,1.0f);
    vs_out.Normal=mat3(transpose(inverse(view*model)))*aNormal;
//    vs_out.Normal=mat3(transpose(inverse(projection*view*model)))*aNormal;//法向量可视化
    //        normal = mat3(transpose(inverse(model))) * aNormal;
}
