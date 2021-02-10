#version 140

in vec3 position;
in vec3 normal;
in vec2 textureCoordinate;
in vec4 lightSpacePos;

out vec4 fragment;

uniform sampler2D shadowMap;
uniform sampler2D uvMap;
uniform bool tex;

bool blinn = false;

uniform vec3 cameraPosition;

vec3 lightDir = -normalize(vec3(1, -.8, 1));

float calcShadow(vec4 lightSpacePosition);

void main()
{           
    //vec3 color = vec3(1.0, 0.8, 0.3);
	//
    //vec3 ambient = 0.05 * color;
	//
    //vec3 newNormal = normalize(normal) * 1.3;
    //float diff = max(dot(lightDir, newNormal), 0.0);
    //vec3 diffuse = diff * color;
	//
    //vec3 viewDir = normalize(cameraPosition - position);
    //vec3 reflectDir = reflect(lightDir, newNormal);
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
    //vec3 specular = vec3(0.3) * spec;
    //fragment = vec4(ambient + diffuse + specular, 1.0f);


	vec3 color;
	if(tex) color = vec3(texture(uvMap, textureCoordinate));
	else color = vec3(0.8, 0.8, 0.9);
	
	vec3 ambient = vec3(0), diffuse = vec3(0), specular = vec3(0);

	vec3 norm = normalize(normal);

	ambient = color * 0.1;

	float diff = max(dot(norm, lightDir), 0.0);
	diffuse = diff * vec3(1.0, 1.0, 1.0);
	
	float shadow = calcShadow(lightSpacePos);
	//float shadow = 0;

	float spec = 0.0;
	vec3 viewDir = normalize(cameraPosition - position);
	vec3 halfwayDir = normalize(lightDir + viewDir);  
    spec = pow(max(dot(norm, halfwayDir), 0.0), 256.0);
	specular = (spec * (1.0 - shadow)) * vec3(1.0, 1.0, 1.0);

	
	fragment = vec4(((ambient + (1.0 - shadow)) * (diffuse + specular)) * color, 1.0);
}

float calcShadow(vec4 lightSpacePosition) {
	
	vec3 projCoord = lightSpacePosition.xyz / lightSpacePosition.w;

	projCoord = projCoord * 0.5 + 0.5;

	float closestDepth = texture(shadowMap, projCoord.xy).r;

	float currentDepth = projCoord.z;

	//if(projCoord.z > 1.0) {
    //    return 0.0;
	//}

	float shadow = 0.0;
	vec2 texelSize = 1.0 / textureSize(shadowMap, 0);
	for(int x = -2; x <= 2; ++x)
	{
	    for(int y = -2; y <= 2; ++y)
	    {
	        float pcfDepth = texture(shadowMap, projCoord.xy + vec2(x, y) * texelSize).r; 
	        shadow += currentDepth - 0.0003 > pcfDepth ? 1.0 : 0.0;        
	    }    
	}
	shadow /= 25.0;

	return shadow;
}