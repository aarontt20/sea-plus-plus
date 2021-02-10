
//==================================================================================\\
//FILE NAME:			Boat.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/23/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\


#include "game\Boat.h"
#include <iostream>
#include "core\input\XInput.h"

#include "GLFW\glfw3.h"

#include "game\Water.h"

using namespace X::Math;

PhysicsPoint::PhysicsPoint() {
	pos = X::Math::Vector4(0, 0, 0, 1);
	magnitude = X::Math::Vector3(0, 0, 0);
}
PhysicsPoint::PhysicsPoint(X::Math::Vector4 pos) {
	this->pos = pos;
	magnitude = X::Math::Vector3(0, 0, 0);
}

void  PhysicsPoint::addForce(X::Math::Vector3 addMagnitude) {
	magnitude = magnitude + addMagnitude;
}
void  PhysicsPoint::setForce(X::Math::Vector3 newMagnitude) {
	magnitude = newMagnitude;
}
X::Math::Vector3 PhysicsPoint::getDir() { return X::Math::Vector3::normalize(magnitude); }
X::Math::Vector4 PhysicsPoint::getPos() { return pos; }
X::Math::Vector3 PhysicsPoint::getMagnitude() { return magnitude; }

std::vector<PhysicsPoint> processRawMeshData(aiMesh* mesh, const aiScene* scene) {
	std::vector<PhysicsPoint> points;

	for (int i = 0; i < mesh->mNumVertices; i++)
	{
		PhysicsPoint p(X::Math::Vector4(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z, 1.0));

		points.push_back(p);
	}

	return points;
}

std::vector<PhysicsPoint> processNode(aiNode* node, const aiScene* scene) {

	std::vector<PhysicsPoint> verts;

	for (GLuint i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		std::vector<PhysicsPoint> meshVerts = processRawMeshData(mesh, scene);
		verts.reserve(verts.size() + meshVerts.size());
		verts.insert(verts.end(), meshVerts.begin(), meshVerts.end());
	}
	for (GLuint i = 0; i < node->mNumChildren; i++)
	{
		std::vector<PhysicsPoint> meshVerts = processNode(node->mChildren[i], scene);
		verts.reserve(verts.size() + meshVerts.size());
		verts.insert(verts.end(), meshVerts.begin(), meshVerts.end());
	}

	return verts;
}

std::vector<PhysicsPoint> loadCollisionModel(const char *path) {

	std::vector<PhysicsPoint> verts;

	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_RemoveRedundantMaterials |
		aiProcess_OptimizeGraph |
		aiProcess_OptimizeMeshes |
		aiProcess_SplitLargeMeshes |
		aiProcess_JoinIdenticalVertices |
		aiProcess_ImproveCacheLocality |
		aiProcess_ValidateDataStructure);

	if (!scene) {
		std::cout << importer.GetErrorString() << std::endl;
	}
	else {
		std::vector<PhysicsPoint> newVerts = processNode(scene->mRootNode, scene);
		verts = newVerts;
	}
	return verts;
}

Boat::Boat() {
	this->renderingModel = X::Graphics::Model("resources/boat.obj");
	this->collisionMeshVertices = loadCollisionModel("resources/BoatCollision3.obj");
	this->sailScale = 0.02;

	this->velocity = 0.001;
	//std::vector<X::Graphics::ShaderVertexAttribute> at = {
	//	X::Graphics::ShaderVertexAttribute(0, "v_Position"),
	//	X::Graphics::ShaderVertexAttribute(1, "v_Normal"),
	//	X::Graphics::ShaderVertexAttribute(2, "v_TexCoord"),
	//};
	//X::Graphics::ShaderGL s("resources/shaders/BoatVertShader.glsl", nullptr, nullptr, nullptr, "resources/shaders/BoatFragShader.glsl", &at);

	//this->uvMap.setParameter(GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	std::cout << ilGetError();
	std::cout << glGetError();

	std::vector<X::Graphics::Vertex> vertices;
	std::vector<GLuint> indices;

	

	this->sailSize = 32;
	
	int size = sailSize;
	
	float textureScale = .04 * 16;
	
	float xScale = 2 / static_cast<float>(size);
	float zScale = 3 / static_cast<float>(size);
	
	int v = 0;
	
	for (int x = 0; x < size+1; x++) {
		for (int z = 0; z < size-x+1; z++) {
			X::Graphics::Vertex vert;
	
			vert.position.z = -((xScale * x));
			vert.position.y = ((zScale * z));
			vert.position.x = 0;
			vert.textureCoordinate.x = x*textureScale;
			vert.textureCoordinate.y = z*textureScale;
	
			vertices.push_back(vert);
	
		}
	}
	
	for (int x = 0; x < size; x++) {
		int k = x;
		int count = 0;
		while (k >= 1) {
			k--;
			count = count + size - (x - k)+2;
		}
		for (int z = 0; z < size - x; z++) {
			X::Math::Vector3u tri1;
			X::Math::Vector3u tri2;
	
			tri1.y = count + z;
			tri1.x = count + z + 1;
			tri1.z = count + z + 1 + (size - x);
			if (z != 0) {
			tri2.z = count + z;
			tri2.y = count + z + 1 + (size - x);
			tri2.x = count + z + (size - x);;
			}
				indices.push_back(tri1.x);
				indices.push_back(tri1.y);
				indices.push_back(tri1.z);
				if (z != 0) {
					indices.push_back(tri2.x);
					indices.push_back(tri2.y);
					indices.push_back(tri2.z);
				}
		}
	}
	sail = X::Graphics::Mesh(vertices, indices);

	
	//boomShader = X::Graphics::ShaderGL("resources/shaders/vertShaderBox.glsl", nullptr, nullptr, nullptr, "resources/shaders/fragShaderBox.glsl", nullptr);
	//boatShader = X::Graphics::ShaderGL("resources/shaders/BoatVertShader.glsl", nullptr, nullptr, nullptr, "resources/shaders/BoatFragShader.glsl", nullptr);
	
	//X::Graphics::Mesh newBoom(boomVertices, boomIndices);
	//glPolygonMode(GL_FRONT, GL_LINE);
	X::Graphics::Model m("resources/Boat2.obj");
	this->renderingModel = m;
	X::Graphics::Model n("resources/Boom.obj");
	this->boom = n;
	this->position = X::Math::Vector3(0, 0, 0);

	this->uvMap.setParameter(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	this->uvMap.setParameter(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
}
Boat::~Boat() {
	renderingModel.destroy();
}
X::Math::Vector3 Boat::getPosition() const {
	return this->position;
}
X::Math::Matrix4 Boat::getOrientation() const {
	return this->orientation;
}
float Boat::getMovement() const {
	return this->velocity;
}

void Boat::calcBoomPosition(Water * water, const X::Math::Vector2 &windDirection, float time) {
	X::Math::Matrix4 model;
	
	model = X::Math::scale(model, X::Math::Vector3(4, .0625, .0625));
	//finds boom's new direction, (boat orientation gets turned by boomDir around what should be the up vector of the local orientation from the center
	X::Math::Vector3 upVector = X::Math::Vector3(orientation*X::Math::Vector4(0, 1, 0, 1));
	X::Math::Matrix4 tempOrient;
	tempOrient = X::Math::rotateFromPoint(tempOrient, X::Math::Vector3(0, 0, 0), -X::Math::radians(boomDir), upVector);
	model = tempOrient * model;
	
	X::Math::Vector4 centOfMass = model*X::Math::Vector4(0, 1, 0, 1);
	
	float torqueX = 0;
	float torqueY = 0;
	float torqueZ = 0;
	for (int i = 0; i < this->boomCollsionMeshVertices.size(); i++) {
		float wave = water->heightAtPosition(X::Math::Vector3((model * this->boomCollsionMeshVertices.at(i).getPos()).x, 0.0, (model * this->boomCollsionMeshVertices.at(i).getPos()).z), windDirection, time);
		float bY = (model * this->boomCollsionMeshVertices.at(i).getPos()).y;
		
			if (boomDir+90 >= 45 && boomDir+90 <= 135) {
				this->boomCollsionMeshVertices.at(i).setForce(X::Math::Vector3(windDirection.x, 0, windDirection.y));
			}
		torqueY = torqueY + ((model * boomCollsionMeshVertices.at(i).getPos()).x - centOfMass.x)*(boomCollsionMeshVertices.at(i).getMagnitude().z);
		torqueY = torqueY - ((model * boomCollsionMeshVertices.at(i).getPos()).z - centOfMass.z)*(boomCollsionMeshVertices.at(i).getMagnitude().x);
		torqueX = torqueX + ((model * boomCollsionMeshVertices.at(i).getPos()).y - centOfMass.y)*(boomCollsionMeshVertices.at(i).getMagnitude().z);
		torqueX = torqueX - ((model * boomCollsionMeshVertices.at(i).getPos()).z - centOfMass.z)*(boomCollsionMeshVertices.at(i).getMagnitude().y);
		torqueZ = torqueZ + ((model * boomCollsionMeshVertices.at(i).getPos()).x - centOfMass.x)*(boomCollsionMeshVertices.at(i).getMagnitude().y);
		torqueZ = torqueZ - ((model * boomCollsionMeshVertices.at(i).getPos()).y - centOfMass.y)*(boomCollsionMeshVertices.at(i).getMagnitude().x);
	}
	
	
	if (torqueX != 0 || torqueY != 0 || torqueZ != 0) tempOrient = X::Math::rotate(tempOrient, .0003f*X::Math::Vector3::magnitude(X::Math::Vector3(torqueX, torqueY, torqueZ)),upVector);
	
	X::Math::Vector4 point2 = X::Math::Vector4(1, 0, 0,1);
	point2 = orientation*point2;
	
	
	float boatDeg = X::Math::degrees(std::atan2(point2.z, point2.x));
	if (boatDeg>0) {
		if (X::Math::degrees(std::atan2(point2.z, point2.x)+90) - 180>=0) {
			boatDeg = boatDeg*-1 + 180;
		}
	}
	else{
		if (X::Math::degrees(std::atan2(point2.z, point2.x)+90) - 180>=0) {
			boatDeg = boatDeg*-1 - 180;
		}
	}
	
	float difference = X::Math::normalizeDeg(X::Math::degrees(std::atan2(windDirection.y, windDirection.x)) + boatDeg-180) - 180;
	float windDifference = X::Math::normalizeDeg(X::Math::degrees(std::atan2(windDirection.y, windDirection.x)) + (boomDir + boatDeg)-90) - 180;
	
	float upperLimit = 22.5;
	float lowerLimit = -22.5;
	if (difference < -45) {
		lowerLimit = 4;
		upperLimit = -difference / 2;
	}
	if (difference > 45) {
		upperLimit = -4;
		lowerLimit = -difference / 2;
	}
	
	
	if (boomDir < upperLimit+90 && boomDir > lowerLimit+90) {
		if (windDifference > 10) {
			if (boomDir+.4 < upperLimit + 90)boomDir = boomDir + .4;
		}
		else if (windDifference < -10) {
			if (boomDir-.4 > lowerLimit + 90)boomDir = boomDir - .4;
		}
	}
	
	if (boomDir < lowerLimit+90) {
		boomSpeed = 0;
		boomDir = boomDir + .2;
	}
	if (boomDir > upperLimit+90) {
		boomSpeed = 0;
		boomDir = boomDir - .2;
	}
	
	//std::cout << boomDir << std::endl;
	boomDir = boomDir + boomSpeed;
}
void Boat::calcSailPositions(const X::Math::Vector2 &windDirection) {
	X::Math::Matrix4 model;
	
	model = X::Math::scale(model, X::Math::Vector3(4, .0625, .0625));
	//finds boom's new direction, (boat orientation gets turned by boomDir around what should be the up vector of the local orientation from the center
	X::Math::Vector3 upVector = X::Math::Vector3(orientation*X::Math::Vector4(0, 1, 0, 1));
	X::Math::Matrix4 tempOrient;
	tempOrient = X::Math::rotateFromPoint(tempOrient, X::Math::Vector3(0, 0, 0), -X::Math::radians(boomDir), upVector);
	model = tempOrient * model;
	std::vector<X::Graphics::Vertex> sailVerts = this->sail.getVertices();
	std::vector<GLuint> sailInds = this->sail.getIndices();
	int size = sailSize;
	X::Math::Vector4 point2 = X::Math::Vector4(1, 0, 0, 1);
	point2 = orientation*point2;
	
	
	float boatDeg = X::Math::degrees(std::atan2(point2.z, point2.x));

	if (boatDeg>0) {
		if (X::Math::degrees(std::atan2(point2.z, point2.x) + 90) - 180 >= 0) {
			boatDeg = boatDeg*-1 + 180;
		}
	}
	else {
		if (X::Math::degrees(std::atan2(point2.z, point2.x) + 90) - 180 >= 0) {
			boatDeg = boatDeg*-1 - 180;
		}
	}
	
	float difference = X::Math::normalizeDeg(X::Math::degrees(std::atan2(windDirection.y, windDirection.x)) + boatDeg - 180) - 180;
	float windDifference = X::Math::normalizeDeg(X::Math::degrees(std::atan2(windDirection.y, windDirection.x)) + (boomDir + boatDeg) - 90) - 180;
	
	
	for (int x = 1; x < size +1; x++) {
		int k = x;
		int count = 0;
		while (k >= 1) {
			k--;
			count = count + size - (x - k) + 2;
		}
		for (int z = 1; z < size - x + 1; z++) {
			if (windDifference > 10 && sailVerts.at(0).position.x - sailVerts.at(count + z).position.x < (x*z)/ X::Math::pow((float)sailSize, 1.6f)) {
				sailVerts.at(count + z).position += X::Math::Vector3(-1.0f, 0, 0)*.3f;
			}
			else if (windDifference < -10 && sailVerts.at(0).position.x - sailVerts.at(count + z).position.x > -(x*z)/X::Math::pow((float)sailSize, 1.6f)) {
				sailVerts.at(count + z).position += X::Math::Vector3(1.0f, 0, 0)*.3f;
			}
		}
	}
	
	this->sail.destroy();
	this->sail = X::Graphics::Mesh(sailVerts, sailInds);
}

void Boat::update(Water *water, const X::Math::Vector2 &windDirection, double time) {
	
	calcBoomPosition(water, windDirection, time);
	calcSailPositions(windDirection);
	
	X::Math::Matrix4 model;
	
	model = X::Math::scale(model, X::Math::Vector3(1, 1, 1));
	model = orientation * model;
	model = X::Math::translate(model, position);
	X::Math::Vector4 centOfMass = X::Math::Vector4(0, -100, 0, 1);
	for (int i = 0; i < this->collisionMeshVertices.size(); i++) {
			centOfMass = centOfMass + (model*this->collisionMeshVertices.at(i).getPos());
	}
	if (this->collisionMeshVertices.size() != 0)centOfMass = centOfMass / (float) this->collisionMeshVertices.size();
	int count = 0;
	float torqueX = 0;
	float torqueY = 0;
	float torqueZ = 0;
	for (int i = 0; i < this->collisionMeshVertices.size(); i++) {
		X::Math::Vector3 temp = this->collisionMeshVertices.at(i).getMagnitude();
	
		//this->collisionMeshVertices.at(i).addForce(velocity);
	
		float wave = water->heightAtPosition(X::Math::Vector3((model * this->collisionMeshVertices.at(i).getPos()).x, 0.0, (model * this->collisionMeshVertices.at(i).getPos()).z), windDirection, time);
		
		float bY = (model * this->collisionMeshVertices.at(i).getPos()).y;
		
		if (((model * this->collisionMeshVertices.at(i).getPos()).y) < wave) {
			count++;
			this->collisionMeshVertices.at(i).addForce(-this->collisionMeshVertices.at(i).getMagnitude() / 2.0f);
			this->collisionMeshVertices.at(i).addForce(X::Math::Vector3::normalize(X::Math::Vector3(windDirection.x, 0, windDirection.y)) * (water->getFrequency() / water->getAmplitude()) * 0.001f + X::Math::Vector3(0, .03*std::abs(collisionMeshVertices.at(i).getPos().z), 0)*(5*(wave - (model *collisionMeshVertices.at(i).getPos()).y)));
		}
		else {
			this->collisionMeshVertices.at(i).addForce(-this->collisionMeshVertices.at(i).getMagnitude() / 2.0f);
			this->collisionMeshVertices.at(i).addForce(X::Math::Vector3(0, -.06*std::abs(collisionMeshVertices.at(i).getPos().z), 0));
		}
		torqueY = torqueY + ((model * collisionMeshVertices.at(i).getPos()).x - centOfMass.x)*(collisionMeshVertices.at(i).getMagnitude().z);
		torqueY = torqueY - ((model * collisionMeshVertices.at(i).getPos()).z - centOfMass.z)*(collisionMeshVertices.at(i).getMagnitude().x);
		torqueX = torqueX + ((model * collisionMeshVertices.at(i).getPos()).y - centOfMass.y)*(collisionMeshVertices.at(i).getMagnitude().z);
		torqueX = torqueX - ((model * collisionMeshVertices.at(i).getPos()).z - centOfMass.z)*(collisionMeshVertices.at(i).getMagnitude().y);
		torqueZ = torqueZ + ((model * collisionMeshVertices.at(i).getPos()).x - centOfMass.x)*(collisionMeshVertices.at(i).getMagnitude().y);
		torqueZ = torqueZ - ((model * collisionMeshVertices.at(i).getPos()).y - centOfMass.y)*(collisionMeshVertices.at(i).getMagnitude().x);
	}


	X::Math::Vector4 point2 = X::Math::Vector4(1, 0, 0, 1);
	point2 = orientation*point2;

	float boatDeg = X::Math::degrees(std::atan2(point2.z, point2.x));
	if (boatDeg>0) {
		if (X::Math::degrees(std::atan2(point2.z, point2.x) + 90) - 180 >= 0) {
			boatDeg = boatDeg*-1 + 180;
		}
	}
	else {
		if (X::Math::degrees(std::atan2(point2.z, point2.x) + 90) - 180 >= 0) {
			boatDeg = boatDeg*-1 - 180;
		}
	}

	float windDifference = X::Math::abs(X::Math::normalizeDeg(X::Math::degrees(std::atan2(windDirection.y, windDirection.x)) + (boomDir + boatDeg) - 90) - 180);
	float difference = X::Math::abs(X::Math::normalizeDeg(X::Math::degrees(std::atan2(windDirection.y, windDirection.x)) + boatDeg - 180) - 180);

	float x = windDifference / 180.0f;

	float movement = 2.6 * X::Math::pow(-x + 1, 1.0f / 4.0f)*0.1f*this->sailScale;

	if (movement > this->velocity) {
		this->velocity*=1.004;
	}
	else {
		this->velocity*=0.998;
	}


	if (count > 50) {

		if (X::Input::isKeyPressed(X::Input::KEY_W) && sailScale < 0.98) {
			sailScale += 0.01;//velocity += X::Math::Vector3((orientation * X::Math::Vector4(.008, 0, 0, 1)));
		}
		if (X::Input::isKeyPressed(X::Input::KEY_S) && sailScale > 0.02) {
			sailScale -= 0.01;//velocity += X::Math::Vector3((orientation * X::Math::Vector4(-.008, 0, 0, 1)));
		}
		//std::cout << sailScale << std::endl;
		if (X::Input::isKeyPressed(X::Input::KEY_A)) {
			this->orientation = X::Math::rotate(this->orientation, 0.02 * velocity + 0.0006, X::Math::Vector3(0, 1, 0));
		}
		if (X::Input::isKeyPressed(X::Input::KEY_D)) {
			this->orientation = X::Math::rotate(this->orientation, -0.02 * velocity -0.0006, X::Math::Vector3(0, 1, 0));
		}
	}

	X::Math::Vector3 v = X::Math::Vector3(this->orientation * X::Math::Vector4(1, 0, 0, 1)) * velocity;
	this->position += v;
	
	
	if (torqueX != 0 || torqueY != 0 || torqueZ != 0) orientation = X::Math::rotate(orientation, .0003f*X::Math::Vector3::magnitude(X::Math::Vector3(torqueX, torqueY, torqueZ)), X::Math::Vector3::normalize(X::Math::Vector3(torqueX, torqueY, torqueZ)));
	
	X::Math::Vector3 translation;
	
	for (int i = 0; i < this->collisionMeshVertices.size(); i++) {
		translation += this->collisionMeshVertices.at(i).getMagnitude();
	}
	
	if(this->collisionMeshVertices.size()!=0)translation /= this->collisionMeshVertices.size();
	
	position += translation;
}

void Boat::renderShadowMap(X::Graphics::ShaderGL *shadowShader, const X::Math::Matrix4 lightSpaceMatrix, double time) {
	X::Math::Matrix4 M;
	M = X::Math::scale(M, X::Math::Vector3(1));
	M = this->orientation * M;
	M = X::Math::translate(M, this->position);
	// + X::Math::Vector3(-3.1, 0, 0)
	X::Math::Matrix4 shadowMatrix = lightSpaceMatrix * M;

	shadowShader->bind();
	shadowShader->setUniform("m_ShadowMatrix", 1, false, &shadowMatrix);	
	this->renderingModel.render();

	X::Math::Vector3 upVector = X::Math::Vector3(orientation*X::Math::Vector4(0, 1, 0, 1));

	M = X::Math::Matrix4();
	M = X::Math::scale(M, X::Math::Vector3(1, 1, 1));
	M = orientation * M;
	M = X::Math::rotate(M, X::Math::radians(boomDir), upVector);
	M = X::Math::translate(M, position);
	M = X::Math::translate(M, X::Math::Vector3(orientation * X::Math::Vector4(2.58, 4.2, 0, 1.0)));

	shadowMatrix = lightSpaceMatrix * M;
	shadowShader->setUniform("m_ShadowMatrix", 1, false, &shadowMatrix);

	boom.render();

	M = X::Math::Matrix4();
	M = X::Math::scale(M, X::Math::Vector3(1.0f*sailScale, 5.0f*sailScale, 6.0f * sailScale));
	M = orientation * M;
	M = X::Math::rotate(M, X::Math::radians(boomDir), upVector);
	M = X::Math::translate(M, position);
	M = X::Math::translate(M, X::Math::Vector3(orientation * X::Math::Vector4(2.58, 4.2, 0, 1.0)));

	shadowMatrix = lightSpaceMatrix * M;
	shadowShader->setUniform("m_ShadowMatrix", 1, false, &shadowMatrix);
	
	glDisable(GL_CULL_FACE);
	sail.render();
	glEnable(GL_CULL_FACE);

	shadowShader->unbind();
}

void Boat::render(X::Graphics::Texture2D *shadowMap, X::Math::Matrix4 lightSpaceMatrix, X::Math::Matrix4 viewMatrix, double time, X::Math::Vector3 cp) {
	this->shader.bind();
	X::Math::Matrix4 M;
	M = X::Math::scale(M, X::Math::Vector3(1));
	M = this->orientation * M;
	M = X::Math::translate(M, this->position);

	X::Math::Matrix4 V = viewMatrix;
	X::Math::Matrix4 P = projectionMatrtix;
	//X::Math::Vector3 cp = X::Math::Vector3(viewMatrix[3][0], viewMatrix[3][1], viewMatrix[3][2]);

	X::Math::Matrix4 MVP = P * V * M;

	X::Math::Matrix4 MI = X::Math::Matrix4::inverse(M);

	shader.setUniform("m_View", 1, false, &V);
	shader.setUniform("m_Projection", 1, false, &P);
	shader.setUniform("cameraPosition", 1, &cp);
	shader.setUniform("m_LightSpace", 1, false, &lightSpaceMatrix);
	shader.setUniform("shadowMap", shadowMap, 1);
	shader.setUniform("uvMap", &this->uvMap, 0);
	shader.setUniform("tex", true);

	shader.setUniform("m_ModelInverse", 1, false, &MI);

	shader.setUniform("m_Model", 1, false, &M);
	shader.setUniform("m_MVP", 1, false, &MVP);
	this->renderingModel.render();
	this->shader.unbind();

	this->shader.bind();
	X::Math::Vector3 upVector = X::Math::Vector3(orientation*X::Math::Vector4(0, 1, 0, 1));

	M = X::Math::Matrix4();
	M = X::Math::scale(M, X::Math::Vector3(1, 1, 1));
	M = orientation * M;
	M = X::Math::rotate(M, X::Math::radians(boomDir), upVector);
	M = X::Math::translate(M, position);
	M = X::Math::translate(M, X::Math::Vector3(orientation * X::Math::Vector4(2.58, 4.2, 0, 1.0)));
	
	MVP = P * V * M;
	MI = X::Math::Matrix4::inverse(M);
	shader.setUniform("m_ModelInverse", 1, false, &MI);
	shader.setUniform("m_Model", 1, false, &M);
	shader.setUniform("m_MVP", 1, false, &MVP);
	shader.setUniform("tex", false);
	
	boom.render();

	M = X::Math::Matrix4();
	M = X::Math::scale(M, X::Math::Vector3(1.0f*sailScale, 5.3f*sailScale, 6.0f * sailScale));
	M = orientation * M;
	M = X::Math::rotate(M, X::Math::radians(boomDir), upVector);
	M = X::Math::translate(M, position);
	M = X::Math::translate(M, X::Math::Vector3(orientation * X::Math::Vector4(2.58, 4.2, 0, 1.0)));
	
	MVP = P * V * M;
	MI = X::Math::Matrix4::inverse(M);
	shader.setUniform("m_ModelInverse", 1, false, &MI);
	shader.setUniform("m_Model", 1, false, &M);
	shader.setUniform("m_MVP", 1, false, &MVP);


	std::vector<X::Graphics::Vertex> sailVerts = this->sail.getVertices();
	std::vector<GLuint> sailInds = this->sail.getIndices();

	for (int i = 0; i < sailVerts.size(); i++) {
		X::Graphics::Vertex *v = &sailVerts.at(i);
		v->normal = X::Math::Vector3(1, 0, 0);
	}

	this->sail.destroy();
	this->sail = X::Graphics::Mesh(sailVerts, sailInds);

	sail.render();
	glCullFace(GL_FRONT);

	for (int i = 0; i < sailVerts.size(); i++) {
		X::Graphics::Vertex *v = &sailVerts.at(i);
		v->normal = X::Math::Vector3(-1, 0, 0);
	}

	this->sail.destroy();
	this->sail = X::Graphics::Mesh(sailVerts, sailInds);

	sail.render();
	glCullFace(GL_BACK);
	
}