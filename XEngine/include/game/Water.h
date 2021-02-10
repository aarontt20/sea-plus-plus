
//==================================================================================\\
//FILE NAME:			Water.h														\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/23/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\

#ifndef WATER_H
#define WATER_H


#include "core\graphics\XMesh.h"
#include "core\graphics\XShaderGL.h"
#include "core\graphics\Camera.h"
#include "core\graphics\XTexture2D.h"
#include "core\graphics\XImage.h"


class Boat;


extern X::Math::Matrix4 projectionMatrtix;
extern X::Graphics::Camera camera;

class Water {
private:
	X::Graphics::Mesh mesh;

	std::vector<X::Graphics::ShaderVertexAttribute> at = {
		X::Graphics::ShaderVertexAttribute(0, "v_Position"),
		X::Graphics::ShaderVertexAttribute(1, "v_Normal"),
		X::Graphics::ShaderVertexAttribute(2, "v_TexCoord"),
	};
	X::Graphics::ShaderGL shader = X::Graphics::ShaderGL("resources/shaders/WaterVertShader.glsl", nullptr, nullptr, nullptr, "resources/shaders/WaterFragShader.glsl", &at);
	X::Graphics::Texture2D *normalMap;// = X::Graphics::Texture2D(X::Graphics::Image("resources/WaterNorm.png"));

	float frequency;
	float amplitude;

public:
	Water();
	~Water();

	float getFrequency();
	float getAmplitude();

	void update();

	float heightAtPosition(const X::Math::Vector3 &position, const X::Math::Vector2 windDirection, double time);

	void renderShadowMap(X::Graphics::ShaderGL *shadowShader, const X::Math::Matrix4 lightSpaceMatrix);
	void render(X::Graphics::Texture2D *shadowMap, const X::Math::Matrix4 &lightSpaceMatrix, Boat *boat, X::Graphics::CubeMap *envMap, X::Math::Matrix4 viewMatrix, float time, X::Math::Vector3 cp);


};


#endif // ! WATER_H
