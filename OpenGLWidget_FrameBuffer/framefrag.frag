#version 330 core
out vec4 gl_FragColor;
in vec2 TexCoords;
uniform sampler2D texture_Frame;
const float offset=1.0/300.0;


void main(void)
{
    gl_FragColor=texture2D(texture_Frame,TexCoords);
    //反向
//    gl_FragColor=vec4(vec3(1.0-texture2D(texture_Frame,TexCoords)),1.0);
    //灰度

//    vec4 FragColor=texture2D(texture_Frame,TexCoords);
//    float average=FragColor.r*0.2126+FragColor.g*0.7152+FragColor.b*0.0722;
//    gl_FragColor=vec4(average,average,average,1.0);
//    vec2 offsets[9]=vec2[](
//            vec2(-offset,offset),
//            vec2(0.0f,offset),
//            vec2(offset,offset),
//            vec2(-offset,0.0f),
//            vec2(0.0f,0.0f),
//            vec2(offset,0.0),
//            vec2(-offset,-offset),
//            vec2(0.0f,-offset),
//            vec2(offset,-offset)
//            );
    // 锐化核
//    float kernel[9]=float[](
//            -1,-1,-1,
//             -1,9,-1,
//             -1,-1,-1);
    //模糊核
//    float kernel[9]=float[](
//            1.0f/16,2.0f/16,1.0f/16,
//            2.0f/16,4.0f/16,2.0f/16,
//            1.0f/16,2.0f/16,1.0f/16);
    //边缘检测
//    float kernel[9]=float[](
//            1,1,1,
//             1,-8,1,
//             1,1,1);

//    vec3 sampleTex[9];
//    vec3 col=vec3(0.0);
//    for(int i=0;i<9;i++)
//    {
//        sampleTex[i]=vec3(texture2D(texture_Frame,TexCoords.st+offsets[i]));
//        col+=sampleTex[i]*kernel[i];

//    }
//    gl_FragColor=vec4(col,1.0f);
}
