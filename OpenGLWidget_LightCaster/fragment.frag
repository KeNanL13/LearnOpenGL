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
    vec3 position;//光源位置
    vec3 direction;//聚光方向spotDir
    //3. 聚光spotlight
    float cutOff;
    float outerCutOff;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
//  2.会衰减的点光源：
//    float constant;
//    float linear;
//    float quadratic;
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

//相机位置
uniform vec3 cameraPos;

void main(void)
{
    //计算衰减系数  2.会衰减的点光源：
//    vec3 fragToLight=light.position-fragPos;
//    float distance=length(fragToLight);
//    float Fatt=1.0/(light.constant+light.linear*distance+light.quadratic*pow(distance,2));
    //3.SpotLight
    float theta=dot(normalize(light.position-fragPos),normalize(-light.direction));
    float epsilon=light.cutOff-light.outerCutOff;
//    float intensity=clamp((theta-light.outerCutOff)/epsilon,0.0f,1.0f);
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);



    //环境光部分
//    float ambientStrength=0.1;
    vec3 ambient = vec3(texture(material.diffuse,TexCoords))* light.ambient/**Fatt*/;
    //散射光部分
    vec3 norm=normalize(normal);
    vec3 lightDir=normalize(light.position-fragPos);
    float diff=max(dot(norm,lightDir),0.0);
    vec3 diffuse=light.diffuse*diff*vec3(texture(material.diffuse,TexCoords))/**Fatt*/;

    //镜面反射光部分
//    float specularStrength=0.5;
    vec3 viewDir=normalize(cameraPos-fragPos);
    vec3 reflectDir= reflect(-lightDir,norm);
    float spec=pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
    vec3 specular=  light.specular* spec * vec3(texture(material.specular,TexCoords))/**Fatt*/;

//    diffuse*=intensity;
//    specular*=intensity;

    //emission map
//    vec3 emission=vec3(texture(material.emission,TexCoords));


    vec3 result  = ambient+diffuse+specular/*+emission*/;
    gl_FragColor=vec4(result,1.0f);


//        gl_FragColor=vec4(1.0,0.0,1.0,1.0);

//     gl_FragColor =vec4(1.0f,1.0f,1.0f,1.0f);
//    gl_FragColor =vec4(lightColor*objectColor,1.0f);
}
