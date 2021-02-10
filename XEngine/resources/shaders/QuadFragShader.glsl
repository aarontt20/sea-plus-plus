#version 140

in vec2 TexCoords;
out vec4 color;

uniform sampler2D u_texture;

void main()
{ 
    color = vec4(vec3(texture(u_texture, TexCoords) * 0.4), 0.8);
}