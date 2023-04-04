#version 330 core
out vec4 FragColor;
in vec2 TexCoords;
in vec3 WorldPos;
in vec3 Normal;

uniform vec3 camPos;

uniform vec3 albedo;
uniform float metallic;
uniform float roughness;
uniform float ao;

//lights
uniform vec3 lightPosition[4];
uniform vec3 lightColors[4];

const float PI=3.14159265359;


//法线分布函数 输入为：半程向量H ，法线向量N， 粗糙度roughness
//表示为 与半程向量取向一致的微平面比例 取值范围 0.0-1.0
float DistributionGGX(vec3 H,vec3 N,float roughness)
{
    float roughness2=roughness*roughness;
    float NdotH=max(dot(H,N),0);
    float NdotH2=NdotH*NdotH;
    float com=NdotH2*(roughness2-1)+1;
    float down=PI*com*com;
    return roughness2/down;
}

//几何函数 输入为： 光线方向与法线的点乘NdotV，粗糙程度roughness
//近似求得微表面间相互遮蔽的比率，这种遮蔽会消耗光线的能量
float GeometrySchlickGGX(float NdotV,float roughness )
{
    float r=(roughness+1.0);
    float k=r*r/8.0;

    float down=NdotV*(1.0-k)+k;
    return NdotV/down;
}

//史密斯方法 输入为;入射光方向L， 摄像机方向V， 法线方向N， 粗糙程度roughness
//将入射光方向和视角方向的影响都考虑进去
float GeometrySmith(vec3 N,vec3 V,vec3 L,float roughness)
{
    float NdotV=max(dot(N,V),0.0);
    float NdotL=max(dot(N,L),0.0);
    float ggx2=GeometrySchlickGGX(NdotV,roughness);
    float ggx1=GeometrySchlickGGX(NdotL,roughness);

    return ggx1 * ggx2;
}

//菲涅尔方程 输入为： 摄像机方向V与法向量N的夹角cosTheta，基础反射率F0
//描述被反射的光线对比光线被折射的部分所占的比率，与观察的视角有关
vec3 FresnelSchlick(float cosTheta,vec3 F0)
{
    return F0+(1-F0)*pow(clamp(1-cosTheta,0.0,1.0),5.0);
}

void main ()
{
    vec3 N=normalize(Normal);
    vec3 V=normalize(camPos-WorldPos);

    //计算反射率，设置一个基础反射率F0，如果是金属使用albedo颜色作为F0
    vec3 F0=vec3(0.04);
    F0=mix(F0,albedo,metallic);

    //反射方程
    vec3 Lo=vec3(0.0);
    //计算四个点光源
    for(int i=0;i<4;++i)
    {
        vec3 L=normalize(lightPosition[i]-WorldPos);
        vec3 H=normalize(L+V);
        float distancce=length(lightPosition[i]-WorldPos);
        float attenution=1.0 /(distancce * distancce);
        vec3 radiance = lightColors[i] * attenution ;

        //Cook-Torrance BRDF
        float NDF=DistributionGGX(H,N,roughness);
        float G=GeometrySmith(N,V,L,roughness);
        vec3 F=FresnelSchlick(clamp(dot(H,V),0.0,1.0),F0);

        vec3 numerator =NDF * G * F;
        float denominator = 4.0 * max(dot(N,V),0.0) * max(dot(N,L),0.0) + 0.0001;
        vec3 specular = numerator / denominator ;

        //kS equal to Fresnel
        vec3 kS=F;

        vec3 kD=vec3(1.0)-kS;
        //金属没有漫反射
        kD*=1.0-metallic;

        //
        float NdotL=max(dot(N,L),0.0);
        //由于 kS等于 F 所以不需要再乘以 kS
//        Lo+=(kD * albedo / PI + specular) * radiance *NdotL;
        Lo+=radiance*(kD * albedo / PI + specular)*NdotL;
    }

    vec3 ambient = vec3(0.03) * albedo * ao;

    vec3 color=ambient +Lo;

//     color=Normal;

    //HDR tonemapping
    color =color/(color+vec3(1.0));
    //gamma correct
    color=pow(color,vec3(1.0/2.2));

    FragColor=vec4(color,1.0);
}
