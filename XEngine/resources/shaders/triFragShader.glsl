#version 450 core


out vec4 fragment;

in vec2 texCoord;
uniform sampler2D tex;

void main() {
	fragment = texture(tex, texCoord);
}