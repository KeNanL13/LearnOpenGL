#version 330 core
struct Material//定义材质结构
{
//    vec3 ambient;
//    vec3 diffuse;
    sampler2D diffuse;
    sampler2D specular;
//    sampler2D emission; //发光纹理
    float shininess;
};
struct Light
{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

//输出
out vec4 gl_FragColor;
//输入
in vec3 normal;
in vec3 fragPos;
in vec2 TexCoords;
//光照和材质量
uniform Material material;
uniform Light light;
//uniform vec3 lightColor;
//uniform vec3 objectColor;
//相机位置
//uniform vec3 lightPos;
uniform vec3 cameraPos;

void main(void)
{
    //环境光部分
//    float ambientStrength=0.1;
    vec3 ambient = vec3(texture(material.diffuse,TexCoords))* light.ambient;
    //散射光部分
    vec3 norm=normalize(normal);
    vec3 lightDir=normalize(light.position-fragPos);
    float diff=max(dot(norm,lightDir),0.0);
    vec3 diffuse=light.diffuse*diff*vec3(texture(material.diffuse,TexCoords));

    //镜面反射光部分
//    float specularStrength=0.5;
    vec3 viewDir=normalize(cameraPos-fragPos);
    vec3 reflectDir= reflect(-lightDir,norm);
    float spec=pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
    vec3 specular=  light.specular* spec * vec3(texture(material.specular,TexCoords));

    //emission map
//    vec3 emission=vec3(texture(material.emission,TexCoords));


    vec3 result  = ambient+diffuse+specular/*+emission*/;
    gl_FragColor=vec4(result,1.0f);
//     gl_FragColor =vec4(1.0f,1.0f,1.0f,1.0f);
//    gl_FragColor =vec4(lightColor*objectColor,1.0f);
}
