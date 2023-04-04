#version 330 core
layout(location=0)in vec3 aPosition;

uniform mat4 model;

void main(void)
{
    gl_Position=model*vec4(aPosition,1.0f);
}
