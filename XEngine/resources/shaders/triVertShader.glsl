#version 450 core

layout (location = 0) in vec3 _position;
layout (location = 1) in vec2 _texCoord;

out vec2 texCoord;

void main() {
	gl_Position = vec4(_position, 1.0);
	texCoord = _texCoord;
}