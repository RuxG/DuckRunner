#version 330

// TODO: get values from fragment shader
in vec3 frag_position;
in vec3 frag_normal;
in vec2 frag_texture_coord;
in vec3 frag_color;

layout(location = 0) out vec4 out_color;

varying float noise;


void main()
{
    // TODO: write pixel out color
    //out_color = vec4( color.rgb, 1.0 );

   out_color = vec4(frag_color, 1);
}