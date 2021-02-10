#version 140

in vec3 position;
in vec2 texCoord;
in vec4 lightSpacePos;
in vec3 normal;

uniform sampler2D normalMap;

out vec4 fragment;

uniform float time;
uniform mat4 m_View;
uniform sampler2D shadowMap;
uniform samplerCube envMap;

bool blinn = false;
uniform vec2 windDirection;

vec3 lightDir = -normalize(vec3(1, -.8, 1));

uniform vec3 cameraPosition;

float calcShadow(vec4 lightSpacePosition);

void main() {
	//vec3 color = vec3(0.1, 0.2, 0.4);
	//
    //vec3 ambient = 0.05 * color;
	//
	//vec4 normal = texture(normalMap, vec2((texCoord.x - (time*windDirection.x)*50), texCoord.y -(time*windDirection.y)*50));
	//vec3 newNormal = vec3(normal.x*2 -1, normal.z, normal.y*2 - 1);
	//
    //newNormal = normalize(newNormal) * 1.3;
    //float diff = max(dot(-lightDir, newNormal), 0.8);
    //vec3 diffuse = diff * color;
	//
    //vec3 viewDir = normalize(cameraPosition - position);
    //vec3 reflectDir = reflect(-lightDir, newNormal);
    //float spec = 0.0;
    //if(blinn)
    //{
    //    vec3 halfwayDir = normalize(lightDir + viewDir); 
    //    spec = pow(max(dot(newNormal, halfwayDir), 0.0), 256.0);
    //}
    //else
    //{
    //    vec3 reflectDir = reflect(-lightDir, newNormal);
    //    spec = pow(max(dot(viewDir, reflectDir), 0.0), 256.0);
    //}
    //vec3 specular = vec3(0.35) * spec;
    //fragment = vec4(ambient + diffuse + specular, 1.0f);

	vec3 color = vec3(0.02, 0.04, 0.1);
	//vec3 color = vec3(0.04, 0.01, 0.02);
	
	vec3 ambient = vec3(0), diffuse = vec3(0), specular = vec3(0);
	
	vec4 newNormal = texture(normalMap, vec2((texCoord.x - (time*windDirection.x)/4), texCoord.y - (time*windDirection.y)/4));
	vec3 v1 = normalize(vec3(newNormal.x*2 -1, newNormal.z, newNormal.y*2 - 1)) * 0.2;
	vec3 v2 = normal;
	vec3 norm = normalize((v2 + v1));
	//norm = vec3(0, 1, 0);
	
	ambient = color * 0.6;
	
	float diff = max(dot(norm, lightDir), 0.0);
	diffuse = diff * vec3(1.0, 1.0, 1.0);
	
	float shadow = calcShadow(lightSpacePos);
	//float shadow = 0;
	
	float spec = 0.0;
	vec3 viewDir = normalize(cameraPosition - position);
	vec3 halfwayDir = normalize(lightDir + viewDir);
    spec = pow(max(dot(norm, halfwayDir), 0.0), 128.0);
	specular = (spec * (1.0 - shadow)) * vec3(1.0, 1.0, 1.0);
	
	fragment = mix(vec4(((ambient*3 + (0.2 - shadow)) * (diffuse) + specular) * color*3, 1.0), vec4(texture(envMap, reflect(viewDir, norm))), 0.08);
}

float calcShadow(vec4 lightSpacePosition) {
	
	vec3 projCoord = lightSpacePosition.xyz / lightSpacePosition.w;

	projCoord = projCoord * 0.5 + 0.5;

	float closestDepth = texture(shadowMap, projCoord.xy).r;

	float currentDepth = projCoord.z;

	if(projCoord.z > 1.0) {
        return 0.0;
	}

	float shadow = 0.0;
	vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
	for(int x = -2; x <= 2; ++x)
	{
	    for(int y = -2; y <= 2; ++y)
	    {
	        float pcfDepth = texture(shadowMap, projCoord.xy + vec2(x, y) * texelSize).r; 
	        shadow += currentDepth - 0.0000002 > pcfDepth ? 1.0 : 0.0;        
	    }    
	}
	shadow /= 25.0;

	return shadow;
}