#version 330 core
#extension GL_NV_shadow_samplers_cube : enable
out vec4 gl_FragColor;

in vec3 Normal;
in vec3 position;

uniform vec3 cameraPos;
uniform samplerCube skybox;
void main(void)
{
    //反射
//    vec3 I=normalize(position-cameraPos);
//    vec3 R=reflect(I,normalize(Normal));
    //折射
    float ratio=1.00/1.52;
    vec3 I=normalize(position-cameraPos);
    vec3 R=refract(I,normalize(Normal),ratio);
    gl_FragColor=vec4(textureCube(skybox,R).rgb,1.0);

}
