#version 330 core
out vec4 fragColor;
in vec2 TexCoords;
uniform sampler2D texture_screen;

void main(void)
{
    fragColor=texture(texture_screen,TexCoords);

}
