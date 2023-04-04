#version 330 core
layout(location=0)in vec3 aPos;
layout(location=1)in vec3 aNormal;
layout(location=2)in vec2 aTexCoords;

out VS_OUT{
out vec3 normal;
out vec2 TexCoords;
out vec3 fragPos;
}vs_out;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

void main()
{
    gl_Position=projection*view*model*vec4(aPos,1.0f);

    vs_out.normal=mat3(transpose(inverse(model)))*aNormal;

    vs_out.TexCoords=aTexCoords;
    vs_out.fragPos=vec3(model*vec4(aPos,1.0));
}
