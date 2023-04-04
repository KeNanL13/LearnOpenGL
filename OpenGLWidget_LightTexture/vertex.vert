#version 330 core
layout(location=0)in vec3 aPosition;
layout(location=1)in vec3 aNormal;
layout(location=2)in vec2 aTexCoords;

out vec3 normal;
out vec3 fragPos;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(void)
{
    gl_Position = projection*view*model*vec4(aPosition,1.0f);
    normal=vec3(vec4(aNormal,1.0f)*model);
//    normal=aNormal;
    fragPos=vec3(model*vec4(aPosition,1.0f));
    TexCoords=aTexCoords;
}

