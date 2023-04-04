#version 330 core
out vec4 gl_FragColor;
in vec2 TexCoords;
uniform sampler2D texture_diffuse;

float near=0.1;
float far=100.0;

float LinearizeDepth(float depth)
{
    float z=depth*2.0-1.0;
    return (2.0*near*far)/(far+near-z*(far-near));
}
void main(void)
{
//    vec4 texColor =texture2D(texture_diffuse,TexCoords);
//    if(texColor.a<0.1)
//        discard;
//    gl_FragColor=texColor;

    gl_FragColor=texture2D(texture_diffuse,TexCoords);
}
