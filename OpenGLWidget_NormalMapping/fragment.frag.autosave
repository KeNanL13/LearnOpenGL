#version 330 core
out vec4 FragColor;
in VS_OUT{
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
    vec4 FragPosLightSpace;
}fs_in;

uniform sampler2D diffuseTexture;
uniform sampler2D shadowMap;

uniform vec3 lightPos;
uniform vec3 viewPos;

float ShadowCalculation(vec4 fragPosLightSpace,vec3 normal,vec3 lightDir)
{
    vec3 projCoords=fragPosLightSpace.xyz/fragPosLightSpace.w;
    
    projCoords=0.5*projCoords+0.5;
//without pcf
//    float closestDepth=texture2D(shadowMap,projCoords.xy).r;
    float currentDepth=projCoords.z;

    float bias=max(0.05*(1.0-dot(lightDir,normal)),0.005);

    //pcf
    float shadow=0.0f;
    vec2 texelSize=1.0/textureSize(shadowMap,0);
    for(int x=-1;x<=1;++x )
    {
        for(int y=-1;y<=1;++y)
        {
            float pcfDepth=texture(shadowMap,projCoords.xy+vec2(x,y)*texelSize).r;
            shadow+=currentDepth-bias>pcfDepth?1.0:0.0;
        }
    }
    if(projCoords.z>1)
    {
        shadow=0;
    }
    return shadow/9.0f;
        //without pcf
//    float shadow=currentDepth-bias>closestDepth?1.0:0.0;
//    if(projCoords.z>1)
//    {
//        shadow=0;
//    }
//    return shadow;
}

void main(void)
{
    vec3 color=texture2D(diffuseTexture,fs_in.TexCoords).rgb;
    vec3 normal=normalize(fs_in.Normal);
    vec3 lightColor=vec3(0.3);

    vec3 ambient=0.3*lightColor;
    vec3 lightDir=normalize(lightPos-fs_in.FragPos);
    float diff=max(dot(lightDir,normal),0);
    vec3 diffuse =diff*lightColor;
    vec3 viewDir=normalize(viewPos-fs_in.FragPos);
    vec3 half=normalize(viewDir+lightDir);
    float spec=pow(max(dot(half,normal),0),64);
    vec3 specular=spec*lightColor;

    float shadow=ShadowCalculation(fs_in.FragPosLightSpace,normal,lightDir);
    vec3 lighting=(ambient+(1-shadow)*(diffuse+specular))*color;
    FragColor=vec4(lighting,1.0f);
}

