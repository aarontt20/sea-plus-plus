#version 140

//layout (location = 0) in vec3 v_Position;
//layout (location = 1) in vec3 v_Normal;
//layout (location = 2) in vec2 v_TexCoord;

in vec3 v_Position;
in vec3 v_Normal;
in vec2 v_TexCoord;

uniform mat4 m_MVP;

out vec3 normal;
out vec3 position;
out vec2 textureCoordinate;
out vec4 lightSpacePos;

uniform mat4 m_Model;
uniform mat4 m_View;
uniform mat4 m_Projection;
uniform mat4 m_ModelInverse;

uniform mat4 m_LightSpace;

void main() {
	gl_Position = m_MVP * vec4(v_Position, 1.0);

	normal = mat3(transpose(m_ModelInverse)) * v_Normal;

	position = vec3(m_Model * vec4(v_Position, 1.0));

	lightSpacePos = m_LightSpace * vec4(position, 1.0);

	textureCoordinate = v_TexCoord;
}