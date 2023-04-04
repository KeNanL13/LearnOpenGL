#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 fragPos;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform sampler2D  normalsMap;
uniform sampler2D diffuseMap;



void main(void)
{
   vec3 normal=texture2D(normalsMap,TexCoords).rgb;
   normal=2*normal-1;
   normal=normalize(normal);

   vec3 color=texture2D(diffuseMap,TexCoords).rgb;

   vec3 lightColor=vec3(1);
   vec3 ambinent=0.3*lightColor;
   vec3 lightDir=normalize(fragPos-lightPos);
   float diff=max(dot(-lightDir,normal),0);
   vec3 diffuse=diff*lightColor;
   vec3 viewDir=viewPos-fragPos;
   vec3 halfDir=(viewDir-lightDir)/2;

   float spec=pow(max(dot(halfDir,normal),0),64);
   vec3 specular=spec*lightColor;
   vec3 light=(ambinent+diffuse+specular)*color;

   FragColor=vec4(light,1.0f);

//    FragColor=texture2D(diffuseMap,TexCoords);


}

