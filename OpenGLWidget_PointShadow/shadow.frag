#version 330 core
out vec4 FragColor;

in VS_OUT{
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
}fs_in;

uniform sampler2D diffuseTexture;
uniform samplerCube depthMap;

uniform vec3 lightPos;
uniform vec3 viewPos;

uniform float far_plane;
uniform bool IsShadows;

vec3 sampleOffsetDirections[20] = vec3[]
(
   vec3( 1,  1,  1), vec3( 1, -1,  1), vec3(-1, -1,  1), vec3(-1,  1,  1),
   vec3( 1,  1, -1), vec3( 1, -1, -1), vec3(-1, -1, -1), vec3(-1,  1, -1),
   vec3( 1,  1,  0), vec3( 1, -1,  0), vec3(-1, -1,  0), vec3(-1,  1,  0),
   vec3( 1,  0,  1), vec3(-1,  0,  1), vec3( 1,  0, -1), vec3(-1,  0, -1),
   vec3( 0,  1,  1), vec3( 0, -1,  1), vec3( 0, -1, -1), vec3( 0,  1, -1)
);

float ShadowCalculation(vec3 fragPos)
{
    vec3 fragToLight=fragPos-lightPos;

    //original
//    float closestDepth=texture(depthMap,fragToLight).r;
//    closestDepth*=far_plane;

    float currentDepth=length(fragToLight);
//    float bias=0.05;
//    float shadow=currentDepth-bias>closestDepth?1.0f:0.0f;
/**********************PCF*******************************/
//    float shadow = 0.0;
//    float bias = 0.05;
//    float samples = 4.0;
//    float offset = 0.1;
//    for(float x = -offset; x < offset; x += offset / (samples * 0.5))
//    {
//        for(float y = -offset; y < offset; y += offset / (samples * 0.5))
//        {
//            for(float z = -offset; z < offset; z += offset / (samples * 0.5))
//            {
//                float closestDepth = texture(depthMap, fragToLight + vec3(x, y, z)).r;
//                closestDepth *= far_plane;   // Undo mapping [0;1]
//                if(currentDepth - bias > closestDepth)
//                    shadow += 1.0;
//            }
//        }
//    }
//    shadow /= (samples * samples * samples);
/**********************节约资源的方法*******************************/
    float shadow = 0.0;
    float bias = 0.15;
    int samples = 20;
    float viewDistance = length(viewPos - fragPos);
//    float diskRadius = 0.05;
    float diskRadius = (1.0 + (viewDistance / far_plane)) / 25.0;
    for(int i = 0; i < samples; ++i)
    {
        float closestDepth = texture(depthMap, fragToLight + sampleOffsetDirections[i] * diskRadius).r;
        closestDepth *= far_plane;   // Undo mapping [0;1]
        if(currentDepth - bias > closestDepth)
            shadow += 1.0;
    }
    shadow /= float(samples);
    return shadow;
    

}

void main(void)
{
    vec3 color=texture2D(diffuseTexture,fs_in.TexCoords).rgb;
    vec3 normal=normalize(fs_in.Normal);
    vec3 lightColor=vec3(0.3);

    vec3 ambient=0.5*lightColor;
    vec3 lightDir=normalize(lightPos-fs_in.FragPos);
    float diff=max(dot(lightDir,normal),0);
    vec3 diffuse =diff*lightColor;
    vec3 viewDir=normalize(viewPos-fs_in.FragPos);
    vec3 half=normalize(viewDir+lightDir);
    float spec=pow(max(dot(half,normal),0),64);
    vec3 specular=spec*lightColor;

    float shadow=IsShadows?ShadowCalculation(fs_in.FragPos):0.0f;
    vec3 lighting=(ambient+(1-shadow)*(diffuse+specular))*color;
    FragColor=vec4(lighting,1.0f);
//    FragColor = vec4(vec3(ShadowCalculation(fs_in.FragPos) / far_plane), 1.0);



}

