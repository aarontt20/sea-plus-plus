
//==================================================================================\\
//FILE NAME:			Boat.h														\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/23/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\

#ifndef BOAT_H
#define BOAT_H


#include "core\math\XMath.h"
#include "core\graphics\XModel.h"
#include "core\graphics\Camera.h"
#include "core\graphics/XShaderGL.h"
#include <vector>
//#include "game\Water.h"

class Water;

extern X::Math::Matrix4 projectionMatrtix;
extern X::Graphics::Camera camera;

struct PhysicsPoint {
private:
	X::Math::Vector3 magnitude;

public:
	X::Math::Vector4 pos;
	PhysicsPoint();
	PhysicsPoint(X::Math::Vector4 pos);

	void addForce(X::Math::Vector3 addMagnitude);
	void setForce(X::Math::Vector3 newMagnitude);
	X::Math::Vector3 getDir();
	X::Math::Vector4 getPos();
	X::Math::Vector3 getMagnitude();
};

std::vector<PhysicsPoint> loadCollisionModel(const char *path);

class Boat {
private:
	X::Math::Vector3 position;
	X::Math::Matrix4 orientation;
	float velocity;

	X::Graphics::Model renderingModel;
	X::Graphics::Model boom;
	X::Graphics::Mesh sail;
	X::Graphics::Texture2D uvMap = X::Graphics::Texture2D(X::Graphics::Image("resources/BoatUVNoMastBasic.png"));

	std::vector<X::Graphics::ShaderVertexAttribute> at = {
		X::Graphics::ShaderVertexAttribute(0, "v_Position"),
		X::Graphics::ShaderVertexAttribute(1, "v_Normal"),
		X::Graphics::ShaderVertexAttribute(2, "v_TexCoord"),
	};
	X::Graphics::ShaderGL shader = X::Graphics::ShaderGL("resources/shaders/BoatVertShader.glsl", nullptr, nullptr, nullptr, "resources/shaders/BoatFragShader.glsl", &at);

	std::vector<PhysicsPoint> collisionMeshVertices;
	std::vector<PhysicsPoint> boomCollsionMeshVertices;

	double boomDir;
	double boomSpeed;
	int sailSize;
	float sailScale;

	void calcBoomPosition(Water *water, const X::Math::Vector2 &windDirection, float time);
	void calcSailPositions(const X::Math::Vector2 &windDirection);
public:
	Boat();
	~Boat();

	X::Math::Vector3 getPosition() const;
	X::Math::Matrix4 getOrientation() const;
	float getMovement() const;

	void update(Water *water, const X::Math::Vector2 &windDirection, double time);
	void renderShadowMap(X::Graphics::ShaderGL *shadowShader, const X::Math::Matrix4 lightSpaceMatrix, double time);
	void render(X::Graphics::Texture2D *shadowMap, X::Math::Matrix4 lightSpaceMatrix, X::Math::Matrix4 viewMatrix, double time, X::Math::Vector3 cp);
};

#endif // !BOAT_H
