#version 330 core
struct Material
{

    sampler2D texture_diffuse1;
    sampler2D texture_specular1;

    float shininess;
};
struct PointLight
{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

//struct Material
//{
//    sampler2D texture_diffuse1;
//    float shininess;
//};
uniform PointLight pointLight1;//设置一个点光源
uniform Material material;//材料贴图（散射贴图和镜面贴图）和参数
uniform vec3 cameraPos;//相机位置
out vec4 FragColor;

//in vec3 normal;
//in vec3 fragPos;
in vec2 TexCoords;

vec3 caculatePointLight(PointLight light,vec3 normal,vec3 fragPos,vec3 viewDir);

void main(void)
{
//    vec3 viewDir=normalize(cameraPos-fragPos);
//    vec3 Normal=normalize(normal);

//    vec3 pointResult;
//    pointResult=caculatePointLight(pointLight1,Normal,fragPos,viewDir);
//    FragColor=vec4(pointResult,1.0);
    FragColor=texture2D(material.texture_diffuse1,TexCoords);

}
vec3 caculatePointLight(PointLight light,vec3 normal,vec3 fragPos,vec3 viewDir)
{
    float distance=length(light.position-fragPos);
    float Fatt=1/(light.constant+light.linear*distance+light.quadratic*distance*distance);

    vec3 lightDir=normalize(light.position-fragPos);
    float diff=max(dot(lightDir,normal),0.0f);

    vec3 reflectLight=normalize(reflect(-lightDir,normal));
    float spec=pow(max(dot(reflectLight,viewDir),0.0f),material.shininess);

    vec3 ambient=light.ambient*vec3(texture2D(material.texture_diffuse1,TexCoords));
    vec3 diffuse=light.diffuse*vec3(texture2D(material.texture_diffuse1,TexCoords))*diff/**Fatt*/;
    vec3 specular=light.specular*vec3(texture2D(material.texture_specular1,TexCoords))*spec/**Fatt*/;
    vec3 result=ambient+diffuse+specular;;
    return result;
}
