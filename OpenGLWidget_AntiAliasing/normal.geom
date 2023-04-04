#version 330 core
layout(triangles) in;
layout(line_strip,max_vertices=6)out;

in VS_OUT{
    vec3 Normal;
}gs_in[];

uniform float time;
const float value=0.2f;
uniform mat4 projection;

void generateLine(int index)
{

    vec3 direction=gs_in[index].Normal*value;
    gl_Position=projection*gl_in[index].gl_Position;
    EmitVertex();
    gl_Position=projection*(gl_in[index].gl_Position+vec4(direction,0));
    EmitVertex();
    EndPrimitive();
}

void main(void)
{
    generateLine(0);
    generateLine(1);
    generateLine(2);

}
