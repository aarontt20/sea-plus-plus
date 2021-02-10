#version 140

//layout (location = 0) in vec3 v_Position;

in vec3 v_Position;

uniform mat4 m_ShadowMatrix;

out vec4 color;

void main() {
	gl_Position = m_ShadowMatrix * vec4(v_Position, 1.0);
}