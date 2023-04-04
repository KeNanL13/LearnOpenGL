#version 330 core
layout(triangles) in;
layout(triangle_strip,max_vertices=3)out;

in VS_OUT{
    vec3 position;
    vec3 Normal;
    vec2 texCoords;
}gs_in[];

out vec2 TexCoords;
uniform float time;

vec4 explode(vec4 position,vec3 normal){
    float magnitude=2.0;
    vec3 direction = normal * ((sin(time) + 1.0) / 2.0) * magnitude;
    return position+vec4(direction,1.0f);
}

vec3 getNormal(){
    vec3 vector1=vec3(gl_in[0].gl_Position-gl_in[1].gl_Position);
    vec3 vector2=vec3(gl_in[2].gl_Position-gl_in[1].gl_Position);
    return normalize(cross(vector1,vector2));
}

void main(void)
{
    vec3 normal=getNormal();

    gl_Position=explode(gl_in[0].gl_Position,normal);
    TexCoords=gs_in[0].texCoords;
    EmitVertex();
    gl_Position=explode(gl_in[1].gl_Position,normal);
    TexCoords=gs_in[1].texCoords;
    EmitVertex();
    gl_Position=explode(gl_in[2].gl_Position,normal);
    TexCoords=gs_in[2].texCoords;
    EmitVertex();
    EndPrimitive();
}
