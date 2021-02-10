
//==================================================================================\\
//FILE NAME:			Water.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/23/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "game\Water.h"
#include <iostream>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"
#include "game\Boat.h"

#include "game\Boat.h"

Water::Water() {

	//std::vector<X::Graphics::ShaderVertexAttribute> at = {
	//	X::Graphics::ShaderVertexAttribute(0, "v_Position"),
	//	X::Graphics::ShaderVertexAttribute(1, "v_Normal"),
	//	X::Graphics::ShaderVertexAttribute(2, "v_TexCoord"),
	//};
	//
	//X::Graphics::ShaderGL s("resources/shaders/WaterVertShader.glsl", nullptr, nullptr, nullptr, "resources/shaders/WaterFragShader.glsl", &at);
	//this->shader = s;

	int vertWidthCount = 512, vertHeightCount = 512;

	float textureScale = .04*64;

	std::vector<X::Graphics::Vertex> vertices;
	std::vector<GLuint> indices;

	float xScale = 2 / static_cast<float>(vertWidthCount - 1);
	float zScale = 2 / static_cast<float>(vertHeightCount - 1);

	int v = 0;

	for (int x = 0; x < vertWidthCount; x++) {
		for (int z = 0; z < vertHeightCount; z++) {
			X::Graphics::Vertex vert;

			vert.position.x = ((xScale * x) - 1);
			vert.position.z = ((zScale * z) - 1);
			vert.position.y = 0;
			vert.textureCoordinate.x = x*textureScale;
			vert.textureCoordinate.y = z*textureScale;

			vertices.push_back(vert);

			if (v < vertWidthCount*vertHeightCount - vertHeightCount && v % vertHeightCount != vertHeightCount - 1) {
				X::Math::Vector3u tri1;
				X::Math::Vector3u tri2;

				tri1.y = v + 1;
				tri1.x = v;
				tri1.z = v + vertHeightCount;

				tri2.z = v + 1;
				tri2.y = v + vertHeightCount;
				tri2.x = v + vertHeightCount + 1;

				indices.push_back(tri1.x);
				indices.push_back(tri1.y);
				indices.push_back(tri1.z);
				indices.push_back(tri2.x);
				indices.push_back(tri2.y);
				indices.push_back(tri2.z);
			}

			v++;
		}
	}

	X::Graphics::Mesh m(vertices, indices);
	this->mesh = m;

	this->frequency = 2;
	this->amplitude = 1;

	normalMap = new X::Graphics::Texture2D(X::Graphics::Image("resources/WaterNorm.png"));
}
Water::~Water() {
	this->mesh.destroy();
	delete this->normalMap;
}

float Water::heightAtPosition(const X::Math::Vector3 &position, const X::Math::Vector2 windDirection, double time) {
	return (sin(((((position.x*-windDirection.x / 2) + (time*this->getFrequency()))) + (((windDirection.y*-windDirection.y / 2) + (time*this->getFrequency())))) / this->getFrequency()) / 240 * 64 * this->getAmplitude());
}

float Water::getFrequency() {
	return this->frequency;
}
float Water::getAmplitude() {
	return this->amplitude;
}

void Water::update() {
	if (X::Input::isKeyPressed(X::Input::KEY_UP) && this->amplitude < 8)	this->amplitude += 0.04;
	if (X::Input::isKeyPressed(X::Input::KEY_DOWN) && this->amplitude > 1)	this->amplitude -= 0.04;
	if (X::Input::isKeyPressed(X::Input::KEY_LEFT) && this->frequency > 1)	this->frequency -= 0.04;
	if (X::Input::isKeyPressed(X::Input::KEY_RIGHT) && this->frequency < 20)	this->frequency += 0.04;
}

void Water::renderShadowMap(X::Graphics::ShaderGL *shadowShader, const X::Math::Matrix4 lightSpaceMatrix) {
	X::Math::Matrix4 M = X::Math::scale(X::Math::Matrix4(), X::Math::Vector3(256 * 4));

	X::Math::Matrix4 shadowMatrix = lightSpaceMatrix * M;

	shadowShader->bind();
	shadowShader->setUniform("m_ShadowMatrix", 1, false, &shadowMatrix);
	this->mesh.render();
	shadowShader->unbind();
}

void Water::render(X::Graphics::Texture2D *shadowMap, const X::Math::Matrix4 &lightSpaceMatrix, Boat *boat, X::Graphics::CubeMap *envMap, X::Math::Matrix4 viewMatrix, float time, X::Math::Vector3 cp) {
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	this->shader.bind();
	X::Math::Matrix4 model = X::Math::translate(X::Math::scale(X::Math::Matrix4(), X::Math::Vector3(256*4)), X::Math::Vector3(0));
	X::Math::Matrix4 view = viewMatrix;
	X::Math::Matrix4 projection = projectionMatrtix;
	float a = this->getAmplitude();
	float f = this->getFrequency();

	X::Math::Vector2 dir(1, 1);
	X::Math::Matrix4 MVP = projection * view * model;

	//X::Math::Vector3 camp(-viewMatrix[3][0], -viewMatrix[3][1], -viewMatrix[3][2]);

	shader.setUniform("cameraPosition", 1, &cp);
	shader.setUniform("m_MVP", 1, false, &MVP);
	shader.setUniform("m_Model", 1, false, &model);
	shader.setUniform("m_View", 1, false, &view);
	shader.setUniform("m_Projection", 1, false, &projection);
	shader.setUniform("time", time);
	shader.setUniform("amplitude", a);
	shader.setUniform("frequency", f);
	shader.setUniform("windDirection", 1, &dir);
	shader.setUniform("normalMap", this->normalMap, 0);
	shader.setUniform("m_LightSpace", 1, false, &lightSpaceMatrix);
	shader.setUniform("shadowMap", shadowMap, 1);
	shader.setUniform("envMap", envMap, 2);

	this->mesh.render();
	this->shader.unbind();
}