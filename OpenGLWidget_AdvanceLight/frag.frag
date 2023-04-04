#version 330 core
in VS_OUT{
in vec3 normal;
in vec2 TexCoords;
in vec3 fragPos;
}fs_in;
struct PointLight
{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct Material
{
   sampler2D diff_texture;
};

uniform PointLight light;
uniform Material material;

uniform vec3 viewPos;
uniform bool shadingMode;

out vec4 fragColor;

vec3 caculatePointLight(vec3 n_normal)
{


    //散射
    vec3 direction=normalize(light.position-fs_in.fragPos);
    float diff=max(dot(direction,n_normal),0);

    //镜面
    vec3 eyeDirection=normalize(viewPos-fs_in.fragPos);
    float spec;
    if(shadingMode)
    {
            vec3 reflectLight=reflect(-direction,n_normal);//Phong shading
            spec=pow(max(dot(eyeDirection,reflectLight),0),1);
    }
    else
    {
        vec3 halfLight=normalize(eyeDirection+direction);//Blinn Phong Shading
         spec=pow(max(dot(n_normal,halfLight),0),1);
    }

//    vec3 reflectLight=reflect(-direction,n_normal);//Phong shading


    vec3 ambient=light.ambient*vec3(texture2D(material.diff_texture,fs_in.TexCoords));
    vec3 diffuse=light.diffuse*vec3(texture2D(material.diff_texture,fs_in.TexCoords))* diff ;
    vec3 specular=light.specular*spec;
    return diffuse+specular+ambient;

}

void main()
{
    vec3 nor=normalize(fs_in.normal);
    fragColor=vec4(caculatePointLight(nor),1.0f);
//    fragColor=texture2D(material.diff_texture,fs_in.TexCoords);

}
