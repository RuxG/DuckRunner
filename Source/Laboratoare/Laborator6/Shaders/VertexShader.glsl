#version 330

// TODO: get vertex attributes from each location


layout (location = 3) in vec3 v_normal;
layout (location = 2) in vec3 v_texture;
layout (location = 1) in vec3 v_color;

// Uniform properties
uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;

layout(location = 0) in vec3 v_position;

// TODO: output values to fragment shader
out vec3 frag_normal;
out vec3 frag_texture;
out vec3 frag_color;


void main()
{
	// TODO: send output to fragment shader
	frag_normal = v_normal;
	frag_color = v_color;
	frag_texture = v_texture;
	// TODO: compute gl_Position

	gl_Position = Projection * View * Model * vec4(v_position, 1.0);
}
