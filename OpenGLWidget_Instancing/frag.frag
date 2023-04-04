#version 330 core
in vec3 fColor;

void main(void)
{
    gl_FragColor = vec4(fColor,1.0);
}
