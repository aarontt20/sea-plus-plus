#version 140

//layout (location = 0) in vec3 v_Position;
//layout (location = 1) in vec3 v_Normal;
//layout (location = 2) in vec2 v_TexCoord;

in vec3 v_Position;
in vec3 v_Normal;
in vec2 v_TexCoord;

uniform mat4 m_MVP;

uniform mat4 m_Model;
uniform mat4 m_View;
uniform mat4 m_Projection;
uniform mat4 m_LightSpace;

out vec2 texCoord;
out vec3 position;
out vec4 lightSpacePos;
out vec3 normal;

uniform vec2 windDirection;
uniform float time;
uniform float amplitude;
uniform float frequency;

float vertY;

void main() {

	
	vec4 worldPos = m_Model * vec4(v_Position, 1.0);

	vertY = sin(((((worldPos.x*-windDirection.x/2) + (time*frequency))) + (((worldPos.z*-windDirection.y/2) + (time*frequency))))/frequency) / 240 *64 * amplitude;
	
	gl_Position = m_Projection * m_View * vec4(worldPos.x, vertY + worldPos.y, worldPos.z, worldPos.w);


	position = vec3(m_Model * vec4(v_Position, 1.0));

	float f = sqrt(2) *0.1;

	vec3 v1 = vec3(worldPos.x, 0, worldPos.z + 0.1);
	vec3 v2 = vec3(worldPos.x + f, 0, worldPos.z - f);
	vec3 v3 = vec3(worldPos.x - f, 0, worldPos.z + f);

	normal = normalize(cross(v2 - v1, v3 - v1));

	texCoord = v_TexCoord;

	lightSpacePos = m_LightSpace * vec4(position, 1.0);
}