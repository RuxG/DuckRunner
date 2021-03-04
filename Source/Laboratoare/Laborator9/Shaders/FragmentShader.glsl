#version 330
 
uniform sampler2D texture_1;
uniform sampler2D texture_2;
uniform int text_2;
 
in vec2 texcoord;


layout(location = 0) out vec4 out_color;

void main()
{
	// TODO : calculate the out_color using the texture2D() function
	vec4 color1 = texture2D(texture_1, texcoord);
	vec4 color2 = texture2D(texture_2, texcoord);

	if(text_2 == 1) {
		vec4 color = mix(color1, color2, 0.5f);
		if(color.a < 0.1f) {
			discard;
		}

		out_color = color;
	} else {
		if(color1.a < 0.1f) {
			discard;
		}

		out_color = color1;
	}
	

	
}