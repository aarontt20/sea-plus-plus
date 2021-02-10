#version 140

in vec3 texCoords;

uniform samplerCube cubeMap;

out vec4 o_Fragment;

vec3 lightDir = -normalize(vec3(1, -.8, 1));

void main() {
	//o_Fragment = vec4(1.0, 0.0, 1.0, 1.0);


	if(dot(normalize(texCoords), lightDir) > .999)	{
		o_Fragment = vec4(0.95, 0.9*dot(normalize(texCoords), lightDir), 0.85, 1.0);
		return;
	}

	o_Fragment = texture(cubeMap, vec3(texCoords.x, texCoords.y, texCoords.z)) - vec4(0.2);
}