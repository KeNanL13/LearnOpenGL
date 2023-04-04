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
    gl_FragColor =texture2D(texture_diffuse,TexCoords);
//    float depth=LinearizeDepth(gl_FragCoord.z)/far;
//    gl_FragColor=vec4(vec3(depth),10.0);
}
