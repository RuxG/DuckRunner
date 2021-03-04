#version 330
 
uniform sampler2D texture_1;
uniform sampler2D texture_2;
uniform int text_2;
uniform vec3 lightPosition[20];
uniform vec3 lightDirection[20];
uniform int spotlight[20];
uniform vec3 lightColours[20];
uniform int lightCount;

in vec3 world_position;
in vec3 world_normal;
uniform vec3 eye_position;

uniform float material_kd;
uniform float material_ks;
uniform int material_shininess;

uniform int light_source;



in vec2 texcoord;


layout(location = 0) out vec4 out_color;


void main()
{
	// light
	vec3 light = vec3(0,0,0);

	for(int i = 0; i < lightCount; i++) {

		vec3 L = normalize( lightPosition[i] - world_position );

		vec3 V = normalize( eye_position - world_position );

		vec3 R = normalize( reflect (-L, world_normal));

		vec3 H = normalize( L + V );

		float atenuare = 0;

		if(spotlight[i] == 1) {
			float cut_off = radians(30.0);
			float spot_light = dot(-L, lightDirection[i]);
			float spot_light_limit = cos(cut_off);
		
			if (spot_light > cos(cut_off)) {
				// Quadratic attenuation
				float linear_att = (spot_light - spot_light_limit) / (1.0f - spot_light_limit);
				atenuare = pow(linear_att, 2);
			}

		} else {
			 float d  = distance(lightPosition[i], world_position);
			 atenuare = 1;
		}

		// diffuse light component
		float diffuse_light = material_ks * max(dot(world_normal, L), 0);

		// TODO: compute specular light component
		float specular_light = 0;

		if (diffuse_light > 0)
		{
			specular_light = material_ks * pow(max(dot(world_normal, H), 0), material_shininess);
		}

		light += lightColours[i] * atenuare * (diffuse_light + specular_light);
	}



	// TODO : calculate the out_color using the texture2D() function
	vec4 color1 = texture2D(texture_1, texcoord);
	vec4 color2 = texture2D(texture_2, texcoord);

	vec4 color;

	if(text_2 == 1) {
		color = mix(color1, color2, 0.5f);
		if(color.a < 0.1f) {
			discard;
		}

		
	} else {
		if(color1.a < 0.1f) {
			discard;
		}
		color = color1;
	}
	
	light += vec3(0.20, 0.20, 0.20 );

	if(light_source == 1) {
		light = vec3(1, 1, 1);
	}
	out_color = vec4(light, 1) * color;
}