#version 330

// TODO: get values from fragment shader

in vec3 frag_color;
uniform sampler2D texture_1;
in vec2 texcoord;

layout(location = 0) out vec4 out_color;


void main()
{       
     vec4 color1 = texture2D(texture_1, texcoord);
     vec4 color = mix(color1, vec4(frag_color, 1), 0.5);
     out_color = color;

}