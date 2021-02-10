#version 140

in vec3 position;

uniform mat4 model;
uniform mat4 view;
uniform mat4 per;

uniform vec2 windDirection;
uniform float time;
uniform float amplitude;
uniform float frequency;

float vertY;

void main() {
	vec4 worldPos = model * vec4(position, 1.0);
	
	//gl_Position = per * view * vec4(worldPos.x, sin((worldPos.x*-windDirection.x/intensity)+time) + cos((worldPos.z*-windDirection.y/intensity)+time) * intensity + worldPos.y, worldPos.z, worldPos.w);
	
	//gl_Position = per * view * vec4(worldPos.x, (sin((((((worldPos.x*windDirection.x/2) + (time*intensity)))) + cos((((worldPos.z*windDirection.y/2) + (time*intensity))))))) / 240 *64 * intensity + worldPos.y, worldPos.z, worldPos.w);
	//gl_Position = per * view * vec4(worldPos.x, sin(worldPos.x + worldPos.z), worldPos.z, worldPos.w);

	vertY = sin(((((worldPos.x*-windDirection.x/2) + (time*frequency))) + (((worldPos.z*-windDirection.y/2) + (time*frequency))))/frequency) / 240 *64 * amplitude;
	
	gl_Position = per * view * vec4(worldPos.x, vertY + worldPos.y, worldPos.z, worldPos.w);
	
	//gl_Position = per * view * vec4(worldPos.x, sin((((worldPos.x*windDirection.x) + time/64) *48) * intensity + (((worldPos.z*windDirection.y) + time/64) *48) * intensity) / 360 * intensity, worldPos.z, worldPos.w);
	//gl_Position = MVP * vec4(position.x, ((sin((((position.x*windDirection.x) + time/64) + ((position.z*windDirection.y)+ time/64) *48)) * intensity) + (cos(((2*(position.x*windDirection.y)+ time/64) + (position.z*windDirection.y)+ time/64)*48) * intensity)) / 360 * intensity, position.z, 1.0);
}