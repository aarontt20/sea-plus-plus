#version 140

//layout (location = 0) in vec3 i_Position;

in vec3 i_Position;

uniform mat4 u_MVP;

out vec3 texCoords;

void main() {
	gl_Position = u_MVP * vec4(i_Position, 1.0);
	texCoords = i_Position;
}