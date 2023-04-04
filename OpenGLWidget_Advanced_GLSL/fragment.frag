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

struct DirectionLight{
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
struct PointLight{
    vec3 position;


    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};
#define NR_POINT_LIGHTS 4
struct SpotLight{
    vec3 position;
    vec3 spotDirection;
    float cutOff;
    float outCutOff;

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
uniform DirectionLight directLight;
uniform PointLight pointLight[4];
uniform SpotLight spotLight;


//相机位置
uniform vec3 cameraPos;
//函数
vec3 caculateDirLight(DirectionLight light,vec3 normal,vec3 viewDir);
vec3 caculatePointLight(PointLight light,vec3 normal,vec3 fragPos,vec3 viewDir);
vec3 caculateSpotLight(SpotLight light,vec3 normal,vec3 fragPos,vec3 viewDir);
void main(void)
{
    vec3 viewDir=normalize(cameraPos-fragPos);
    vec3 Normal=normalize(normal);
    //定向光结果
    vec3 directResult=caculateDirLight(directLight,Normal,viewDir);

    //点光源结果
    vec3 pointResult;
    for(int i=0;i<4;i++)
    {
        pointResult+=caculatePointLight(pointLight[i],Normal,fragPos,viewDir);
    }

    //聚光结果
    vec3 spotResult=caculateSpotLight(spotLight,Normal,fragPos,viewDir);
    //最后光集合
    vec3 result=directResult+pointResult+spotResult;
    gl_FragColor=vec4(result,1.0f);
}

vec3 caculateDirLight(DirectionLight light,vec3 normal,vec3 viewDir)
{


    //散射光
    float diff=max(dot(normalize(-light.direction),normal),0.0f);

    //镜面反射光
    vec3 reflectLight=reflect(-light.direction,normal);
    float spec=pow(max(dot(normalize(reflectLight),viewDir),0.0f),material.shininess);
    //合并结果
    vec3 diffuse=diff*light.diffuse*vec3(texture(material.diffuse,TexCoords));
    vec3 specular=spec*light.specular*vec3(texture(material.specular,TexCoords));
    vec3 ambient=light.ambient*vec3(texture(material.diffuse,TexCoords));


    return ambient+diffuse+specular;
}

vec3 caculatePointLight(PointLight light,vec3 normal,vec3 fragPos,vec3 viewDir)
{
    float distance=length(light.position-fragPos);
    //计算衰减系数
    float Fatt=1/(light.constant+light.linear*distance+light.quadratic*distance*distance);
    //散射光
    vec3 lightDir=normalize(light.position-fragPos);
    float diff=max(dot(lightDir,normal),0.0f);
    //反射光
    vec3 reflectLight=normalize(reflect(lightDir,normal));
    float spec=pow(max(dot(reflectLight,viewDir),0.0f),material.shininess);

    //整合
    vec3 ambient=light.ambient*vec3(texture(material.diffuse,TexCoords));
    vec3 diffuse=light.diffuse*vec3(texture(material.diffuse,TexCoords))*diff*Fatt;
    vec3 specualr=light.specular*vec3(texture(material.specular,TexCoords))*spec*Fatt;

    return ambient+diffuse+specualr;
}

vec3 caculateSpotLight(SpotLight light,vec3 normal,vec3 fragPos,vec3 viewDir)
{


    vec3 lightDir=normalize(light.position-fragPos);
    float theta=max(dot(lightDir,normalize(-light.spotDirection)),0.0f);
    float epsilon=light.cutOff-light.outCutOff;
    float intesity=clamp((theta-light.outCutOff)/epsilon,0.0f,1.0f);

    //散射光
    float diff=max(dot(lightDir,normal),0.0f);




    //镜面光
    vec3 reflectLight=normalize(reflect(lightDir,normal));
    float spec=pow(max(dot(reflectLight,viewDir),0.0f),material.shininess);

    //整合
    vec3 ambient=light.ambient*vec3(texture(material.diffuse,TexCoords));
    vec3 diffuse=diff*light.diffuse*vec3(texture(material.diffuse,TexCoords))*intesity;

    vec3 specular=spec*light.specular*vec3(texture(material.specular,TexCoords))*intesity;

    return ambient+diffuse+specular;;
}
