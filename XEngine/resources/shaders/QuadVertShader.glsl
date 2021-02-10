#version 140

//layout (location = 0) in vec2 position;
//layout (location = 2) in vec2 texCoords;

in vec3 position;
in vec2 textureCoords;

out vec2 TexCoords;

void main()
{
    gl_Position = vec4(position.xy, 0.0f, 1.0f); 
    TexCoords = textureCoords;
}  