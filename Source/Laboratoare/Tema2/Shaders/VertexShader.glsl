#version 330
layout(location = 0) in vec3 v_position;
layout(location = 1) in vec3 v_normal; 
layout(location = 2) in vec2 v_texture_coord;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform vec3 object_color;

// TODO: output values to fragment shader
out vec3 frag_position;
out vec3 frag_normal;
out vec2 frag_texture_coord;
out vec3 frag_color;

void main()
{
    // TODO: send output to fragment shader
    frag_position = v_position;
    frag_normal = v_normal;
    frag_texture_coord = v_texture_coord;
    frag_color = object_color;

    // TODO: compute gl_Position
    gl_Position = Projection * View * Model * vec4(v_position, 1.0);
}
