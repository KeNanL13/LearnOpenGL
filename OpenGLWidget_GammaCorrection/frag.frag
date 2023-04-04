#version 330 core
out vec4 FragColor;

in VS_OUT{
in vec3 normal;
in vec2 TexCoords;
in vec3 fragPos;
}fs_in;

uniform sampler2D floorTexture;

uniform vec3 lightPosition[4];
uniform vec3 lightColor[4];
uniform vec3 viewPos;
uniform bool gamma;

vec3 caculatePointLight(vec3 n_normal,vec3 fragPos,vec3 lightPos,vec3 lightColor)
{


    //散射
    vec3 direction=normalize(lightPos-fragPos);
    float diff=max(dot(direction,n_normal),0);

    //镜面
    vec3 eyeDirection=normalize(viewPos-fragPos);
    float spec;

    vec3 halfLight=normalize(eyeDirection+direction);//Blinn Phong Shading
    spec=pow(max(dot(n_normal,halfLight),0),64);

//    vec3 reflectLight=reflect(-direction,n_normal);//Phong shading

    vec3 diffuse=diff*lightColor;
    vec3 specular=spec*lightColor;

    float max_distance=1.5;
    float distance=length(lightPos-fragPos);
    float attenuation=1.0/(gamma?distance*distance:distance);

    diffuse*=attenuation;
    specular*=attenuation;
    return diffuse+specular;

}

void main()
{
    vec3 color=texture2D(floorTexture,fs_in.TexCoords).rgb;
    vec3 nor=normalize(fs_in.normal);
//    fragColor=vec4(caculatePointLight(nor),1.0f);
    vec3 light=vec3(0.0f);
   for(int i=0;i<4;i++)
   {
       light+=caculatePointLight(nor,fs_in.fragPos,lightPosition[i],lightColor[i]);
   }
   color=light*color;
   if(gamma)
       color=pow (color,vec3(1.0/2.2));
   FragColor=vec4(color,1.0f);

}
