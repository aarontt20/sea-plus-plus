
//==================================================================================\\
//FILE NAME:			XCamera.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/23/2017													\\
//LAST MODIIFED:		04/09/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\

#include "core\graphics\Camera.h"
#include "core\math\XMath.h"
#include <iostream>
#include <vector>
#include "core/input/XInput.h"

namespace X {	namespace Graphics {
	Camera::Camera() {
		this->posistion = X::Math::Vector3(0.0f, 0.0f, 0.0f);
		this->orientation = X::Math::Vector3(0.0f, 0.0f, -1.0f);
		this->up = X::Math::Vector3(0.0f, 1.0f, 0.0f);
		this->pitch = 0.0f;
		this->yaw = -X::Math::PI / 2;
		this->canToggleFree = true;
		this->freeCamera = true;
		this->movementSpeed = 0.064;
		this->rotationSpeed = 0.008;
	}
	Camera::Camera(const X::Math::Vector3& posistion) {
		this->posistion = posistion;
		this->orientation = X::Math::Vector3(0.0f, 0.0f, -1.0f);
		this->up = X::Math::Vector3(0.0f, 1.0f, 0.0f);
		this->pitch = 0.0f;
		this->yaw = -X::Math::PI / 2;
		this->canToggleFree = true;
		this->freeCamera = true;
		this->movementSpeed = 0.064;
		this->rotationSpeed = 0.008;
	}
	Camera::Camera(const X::Math::Vector3& posistion, const X::Math::Vector3& orientation) {
		this->posistion = posistion;
		this->orientation = X::Math::Vector3(0.0f, 0.0f, -1.0f);
		this->up = X::Math::Vector3(0.0f, 1.0f, 0.0f);
		this->pitch = 0.0f;
		this->yaw = -X::Math::PI / 2;
		this->canToggleFree = true;
		this->freeCamera = true;
		this->movementSpeed = 0.064;
		this->rotationSpeed = 0.008;
	}
	Camera::Camera(const X::Math::Vector3& posistion, const X::Math::Vector3& orientation, const X::Math::Vector3& upVector) {
		this->posistion = posistion;
		this->orientation = X::Math::Vector3(0.0f, 0.0f, -1.0f);
		this->up = X::Math::Vector3::normalize(upVector);
		this->pitch = 0.0f;
		this->yaw = -X::Math::PI / 2;
		this->canToggleFree = true;
		this->freeCamera = true;
		this->movementSpeed = 0.064;
		this->rotationSpeed = 0.008;
	}
	
	
	X::Math::Vector3 Camera::getPosistion() const {
		return this->posistion;
	}
	X::Math::Vector3 Camera::getOrientation() const {
		return this->orientation;
	}
	X::Math::Vector3 Camera::getUpVector() const {
		return this->up;
	}
	bool Camera::isFree() const {
		return this->freeCamera;
	}
	float Camera::getMovementSpeed() const {
		return this->movementSpeed;
	}
	float Camera::getRoationSpeed() const {
		return this->rotationSpeed;
	}
	
	std::vector<X::Input::Key> Camera::getLinkedMoveForwardKeys() const {
		return this->linkedMovementKeys[0];
	}
	std::vector<X::Input::Key> Camera::getLinkedMoveBackwardKeys() const {
		return this->linkedMovementKeys[1];
	}
	std::vector<X::Input::Key> Camera::getLinkedMoveLeftKeys() const {
		return this->linkedMovementKeys[2];
	}
	std::vector<X::Input::Key> Camera::getLinkedMoveRightKeys() const {
		return this->linkedMovementKeys[3];
	}
	std::vector<X::Input::Key> Camera::getLinkedMoveUpKeys() const {
		return this->linkedMovementKeys[4];
	}
	std::vector<X::Input::Key> Camera::getLinkedMoveDownKeys() const {
		return this->linkedMovementKeys[5];
	}
	
	std::vector<X::Input::Key> Camera::getLinkedRotateLeftKeys() const {
		return this->linkedRotationKeys[0];
	}
	std::vector<X::Input::Key> Camera::getLinkedRotateRightKeys() const {
		return this->linkedRotationKeys[1];
	}
	std::vector<X::Input::Key> Camera::getLinkedRotateUpKeys() const {
		return this->linkedRotationKeys[2];
	}
	std::vector<X::Input::Key> Camera::getLinkedRotateDownKeys() const {
		return this->linkedRotationKeys[3];
	}
	
	std::vector<X::Input::Key> Camera::getLinkedFreeCameraKeys() const {
		return this->linkedFreeCameraKeys;
	}
	std::vector<X::Input::Key> Camera::getLinkedToggleFreeCameraKeys() const {
		return this->linkedToggleFreeCameraKeys;
	}
	
	
	bool Camera::shouldMoveForward() {
		for each(X::Input::Key i in this->linkedMovementKeys[0]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	bool Camera::shouldMoveBackward() {
		for each(X::Input::Key i in this->linkedMovementKeys[1]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	bool Camera::shouldMoveLeft() {
		for each(X::Input::Key i in this->linkedMovementKeys[2]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	bool Camera::shouldMoveRight() {
		for each(X::Input::Key i in this->linkedMovementKeys[3]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	bool Camera::shouldMoveUp() {
		for each(X::Input::Key i in this->linkedMovementKeys[4]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	bool Camera::shouldMoveDown() {
		for each(X::Input::Key i in this->linkedMovementKeys[5]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	
	bool Camera::shouldRotateLeft() {
		for each(X::Input::Key i in this->linkedRotationKeys[0]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	bool Camera::shouldRotateRight() {
		for each(X::Input::Key i in this->linkedRotationKeys[1]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	bool Camera::shouldRotateUp() {
		for each(X::Input::Key i in this->linkedRotationKeys[2]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	bool Camera::shouldRotateDown() {
		for each(X::Input::Key i in this->linkedRotationKeys[3]) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	
	bool Camera::shouldFreeCamera() {
		for each(X::Input::Key i in this->linkedFreeCameraKeys) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	bool Camera::shouldToggleFreeCamera() {
		for each(X::Input::Key i in this->linkedToggleFreeCameraKeys) {
			if (X::Input::isKeyPressed(i))	return true;
		}
		return false;
	}
	
	
	void Camera::setPosistion(const X::Math::Vector3& posistion) {
		this->posistion = posistion;
	}
	void Camera::setOrientation(const X::Math::Vector3& orientation) {
	
	}
	void Camera::setUpVector(const X::Math::Vector3& upVector) {
		this->up = X::Math::Vector3::normalize(upVector);
	}
	void Camera::setFreeCamera(const bool& isFree) {
		this->freeCamera = isFree;
	}
	void Camera::setMovementSpeed(const float& speed) {
		this->movementSpeed = speed;
	}
	void Camera::setRotationSpeed(const float& speed) {
		this->rotationSpeed = speed;
	}
	
	void Camera::linkMoveForwardKey(const X::Input::Key& key) {
		for each(int i in this->linkedMovementKeys[0]) {
			if (i == key) return;
		}
		this->linkedMovementKeys[0].push_back(key);
	}
	void Camera::linkMoveBackwardKey(const X::Input::Key& key) {
		for each(int i in this->linkedMovementKeys[1]) {
			if (i == key) return;
		}
		this->linkedMovementKeys[1].push_back(key);
	}
	void Camera::linkMoveLeftKey(const X::Input::Key& key) {
		for each(int i in this->linkedMovementKeys[2]) {
			if (i == key) return;
		}
		this->linkedMovementKeys[2].push_back(key);
	}
	void Camera::linkMoveRightKey(const X::Input::Key& key) {
		for each(int i in this->linkedMovementKeys[3]) {
			if (i == key) return;
		}
		this->linkedMovementKeys[3].push_back(key);
	}
	void Camera::linkMoveUpKey(const X::Input::Key& key) {
		for each(int i in this->linkedMovementKeys[4]) {
			if (i == key) return;
		}
		this->linkedMovementKeys[4].push_back(key);
	}
	void Camera::linkMoveDownKey(const X::Input::Key& key) {
		for each(int i in this->linkedMovementKeys[5]) {
			if (i == key) return;
		}
		this->linkedMovementKeys[5].push_back(key);
	}
	
	void Camera::linkRotateLeftKey(const X::Input::Key& key) {
		for each(int i in this->linkedRotationKeys[0]) {
			if (i == key) return;
		}
		this->linkedRotationKeys[0].push_back(key);
	}
	void Camera::linkRotateRightKey(const X::Input::Key& key) {
		for each(int i in this->linkedRotationKeys[1]) {
			if (i == key) return;
		}
		this->linkedRotationKeys[1].push_back(key);
	}
	void Camera::linkRotateUpKey(const X::Input::Key& key) {
		for each(int i in this->linkedRotationKeys[2]) {
			if (i == key) return;
		}
		this->linkedRotationKeys[2].push_back(key);
	}
	void Camera::linkRotateDownKey(const X::Input::Key& key) {
		for each(int i in this->linkedRotationKeys[3]) {
			if (i == key) return;
		}
		this->linkedRotationKeys[3].push_back(key);
	}
	
	void Camera::linkFreeCameraKey(const X::Input::Key& key) {
		for each(int i in this->linkedFreeCameraKeys) {
			if (i == key)	return;
		}
		this->linkedFreeCameraKeys.push_back(key);
	}
	void Camera::linkToggleFreeCameraKey(const X::Input::Key& key) {
		for each(int i in this->linkedToggleFreeCameraKeys) {
			if (i == key)	return;
		}
		this->linkedToggleFreeCameraKeys.push_back(key);
	}
	
	void Camera::delinkMoveForwardKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedMovementKeys[0].size(); i++) {
			if (this->linkedMovementKeys[0].at(i) == key) {
				this->linkedMovementKeys[0].erase(this->linkedMovementKeys[0].begin()+i);
				break;
			}
		}
	}
	void Camera::delinkMoveBackwardKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedMovementKeys[1].size(); i++) {
			if (this->linkedMovementKeys[1].at(i) == key) {
				this->linkedMovementKeys[1].erase(this->linkedMovementKeys[1].begin() + i);
				break;
			}
		}
	}
	void Camera::delinkMoveLeftKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedMovementKeys[2].size(); i++) {
			if (this->linkedMovementKeys[2].at(i) == key) {
				this->linkedMovementKeys[2].erase(this->linkedMovementKeys[2].begin() + i);
				break;
			}
		}
	}
	void Camera::delinkMoveRightKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedMovementKeys[3].size(); i++) {
			if (this->linkedMovementKeys[3].at(i) == key) {
				this->linkedMovementKeys[3].erase(this->linkedMovementKeys[3].begin() + i);
				break;
			}
		}
	}
	void Camera::delinkMoveUpKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedMovementKeys[4].size(); i++) {
			if (this->linkedMovementKeys[4].at(i) == key) {
				this->linkedMovementKeys[4].erase(this->linkedMovementKeys[4].begin() + i);
				break;
			}
		}
	}
	void Camera::delinkMoveDownKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedMovementKeys[5].size(); i++) {
			if (this->linkedMovementKeys[5].at(i) == key) {
				this->linkedMovementKeys[5].erase(this->linkedMovementKeys[5].begin() + i);
				break;
			}
		}
	}
	
	void Camera::delinkRotateLeftKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedRotationKeys[0].size(); i++) {
			if (this->linkedRotationKeys[0].at(i) == key) {
				this->linkedRotationKeys[0].erase(this->linkedRotationKeys[0].begin() + i);
				break;
			}
		}
	}
	void Camera::delinkRotateRightKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedRotationKeys[1].size(); i++) {
			if (this->linkedRotationKeys[1].at(i) == key) {
				this->linkedRotationKeys[1].erase(this->linkedRotationKeys[1].begin() + i);
				break;
			}
		}
	}
	void Camera::delinkRotateUpKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedRotationKeys[2].size(); i++) {
			if (this->linkedRotationKeys[2].at(i) == key) {
				this->linkedRotationKeys[2].erase(this->linkedRotationKeys[2].begin() + i);
				break;
			}
		}
	}
	void Camera::delinkRotateDownKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedRotationKeys[3].size(); i++) {
			if (this->linkedRotationKeys[3].at(i) == key) {
				this->linkedRotationKeys[3].erase(this->linkedRotationKeys[3].begin() + i);
				break;
			}
		}
	}
	
	void Camera::delinkFreeCameraKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedFreeCameraKeys.size(); i++) {
			if (this->linkedFreeCameraKeys.at(i) == key) {
				this->linkedFreeCameraKeys.erase(this->linkedFreeCameraKeys.begin() + i);
				break;
			}
		}
	}
	void Camera::delinkToggleFreeCameraKey(const X::Input::Key& key) {
		for (int i = 0; i < this->linkedToggleFreeCameraKeys.size(); i++) {
			if (this->linkedToggleFreeCameraKeys.at(i) == key) {
				this->linkedToggleFreeCameraKeys.erase(this->linkedToggleFreeCameraKeys.begin() + i);
				break;
			}
		}
	}
	
	void Camera::delinkAllMoveForwardKeys() {
		this->linkedMovementKeys[0].clear();
	}
	void Camera::delinkAllMoveBackwardKeys() {
		this->linkedMovementKeys[1].clear();
	}
	void Camera::delinkAllMoveLeftKeys() {
		this->linkedMovementKeys[2].clear();
	}
	void Camera::delinkAllMoveRightKeys() {
		this->linkedMovementKeys[3].clear();
	}
	void Camera::delinkAllMoveUpKeys() {
		this->linkedMovementKeys[4].clear();
	}
	void Camera::delinkAllMoveDownKeys() {
		this->linkedMovementKeys[5].clear();
	}
	
	void Camera::delinkAllRotateLeftKeys() {
		this->linkedRotationKeys[0].clear();
	}
	void Camera::delinkAllRotateRightKeys() {
		this->linkedRotationKeys[1].clear();
	}
	void Camera::delinkAllRotateUpKeys() {
		this->linkedRotationKeys[2].clear();
	}
	void Camera::delinkAllRotateDownKeys() {
		this->linkedRotationKeys[3].clear();
	}
	
	void Camera::delinkAllFreeCameraKeys() {
		this->linkedFreeCameraKeys.clear();
	}
	void Camera::delinkAllToggleFreeCameraKeys() {
		this->linkedToggleFreeCameraKeys.clear();
	}
	
	
	void Camera::moveForward() {
		this->posistion += this->orientation * this->movementSpeed;
	}
	void Camera::moveBackward() {
		this->posistion -= this->orientation * this->movementSpeed;
	}
	void Camera::moveLeft() {
		this->posistion += (X::Math::Vector3::normalize(X::Math::Vector3::cross(this->up, this->orientation))) * this->movementSpeed;
	}
	void Camera::moveRight() {
		this->posistion -= (X::Math::Vector3::normalize(X::Math::Vector3::cross(this->up, this->orientation))) * this->movementSpeed;
	}
	void Camera::moveUp() {
		this->posistion += this->up * this->movementSpeed;
	}
	void Camera::moveDown() {
		this->posistion -= this->up * this->movementSpeed;
	}
	void Camera::moveForward(const float& dist) {
		this->posistion += this->orientation * dist;
	}
	void Camera::moveBackward(const float& dist) {
		this->posistion -= this->orientation * dist;
	}
	void Camera::moveLeft(const float& dist) {
		this->posistion += (X::Math::Vector3::normalize(X::Math::Vector3::cross(this->up, this->orientation))) * dist;
	}
	void Camera::moveRight(const float& dist) {
		this->posistion -= (X::Math::Vector3::normalize(X::Math::Vector3::cross(this->up, this->orientation))) * dist;
	}
	void Camera::moveUp(const float& dist) {
		this->posistion += this->up * dist;
	}
	void Camera::moveDown(const float& dist) {
		this->posistion -= this->up * dist;
	}
	
	void Camera::rotate() {
		float xOffset = (X::Input::getCursorX() - X::Input::getLastCursorX()) * this->rotationSpeed;
		float yOffset = (X::Input::getCursorY() - X::Input::getLastCursorY()) * this->rotationSpeed;
		
		this->yaw += xOffset;
		this->pitch -= yOffset;
		
		if (this->pitch > X::Math::PI / 2 - 0.008f)	this->pitch = X::Math::PI / 2 - 0.008f;
		else if (this->pitch < -X::Math::PI / 2 + 0.008f) this->pitch = -X::Math::PI / 2 + 0.008f;
		
		this->orientation.x = cos(this->pitch) * cos(this->yaw);
		this->orientation.y = sin(this->pitch);
		this->orientation.z = cos(this->pitch) * sin(this->yaw);
		this->orientation = X::Math::Vector3::normalize(orientation);
	}
	void Camera::rotateLeft() {
		this->yaw -= this->rotationSpeed;
	
		this->orientation.x = cos(this->pitch) * cos(this->yaw);
		this->orientation.z = cos(this->pitch) * sin(this->yaw);
		this->orientation = X::Math::Vector3::normalize(orientation);
	}
	void Camera::rotateRight() {
		this->yaw += this->rotationSpeed;
	
		this->orientation.x = cos(this->pitch) * cos(this->yaw);
		this->orientation.z = cos(this->pitch) * sin(this->yaw);
		this->orientation = X::Math::Vector3::normalize(orientation);
	}
	void Camera::rotateUp() {
		this->pitch += this->rotationSpeed;
	
		if (this->pitch > X::Math::PI / 2 - 0.008f)	this->pitch = X::Math::PI / 2 - 0.008f;
		else if (this->pitch < -X::Math::PI / 2 + 0.008f) this->pitch = -X::Math::PI / 2 + 0.008f;
	
		this->orientation.x = cos(this->pitch) * cos(this->yaw);
		this->orientation.y = sin(this->pitch);
		this->orientation.z = cos(this->pitch) * sin(this->yaw);
		this->orientation = X::Math::Vector3::normalize(orientation);
	}
	void Camera::rotateDown() {
		this->pitch -= this->rotationSpeed;
	
		if (this->pitch > X::Math::PI / 2 - 0.008f)	this->pitch = X::Math::PI / 2 - 0.008f;
		else if (this->pitch < -X::Math::PI / 2 + 0.008f) this->pitch = -X::Math::PI / 2 + 0.008f;
	
		this->orientation.x = cos(this->pitch) * cos(this->yaw);
		this->orientation.y = sin(this->pitch);
		this->orientation.z = cos(this->pitch) * sin(this->yaw);
		this->orientation = X::Math::Vector3::normalize(orientation);
	}
	void Camera::rotate(const float& yaw, const float& pitch) {
		this->yaw += yaw;
		this->pitch -= pitch;
	
		if (this->pitch > X::Math::PI / 2)	this->pitch = X::Math::PI / 2;
		else if (this->pitch < -X::Math::PI / 2) this->pitch = -X::Math::PI / 2;
	
		this->orientation.x = cos(this->pitch) * cos(this->yaw);
		this->orientation.y = sin(this->pitch);
		this->orientation.z = cos(this->pitch) * sin(this->yaw);
		this->orientation = X::Math::Vector3::normalize(orientation);
	}
	
	
	void Camera::updateFreeCamera() {
		if (this->shouldToggleFreeCamera())
		{
			if (this->canToggleFree)
			{
				this->freeCamera = !this->freeCamera;
			}
		
			this->canToggleFree = false;
		}
		else	this->canToggleFree = true;
	}
	void Camera::update() {
		if (this->shouldRotateUp())		this->rotateUp();
		if (this->shouldRotateDown())	this->rotateDown();
		if (this->shouldMoveForward())	this->moveForward();
		if (this->shouldMoveBackward())	this->moveBackward();
		if (this->shouldMoveLeft())		this->moveLeft();
		if (this->shouldMoveRight())	this->moveRight();
		if (this->shouldMoveUp())		this->moveUp();
		if (this->shouldMoveDown())		this->moveDown();

		if (this->shouldRotateLeft())	this->rotateLeft();
		if (this->shouldRotateRight())	this->rotateRight();
	
	}
	
	void Camera::use() {
	
	}
	
	X::Math::Matrix4 Camera::getViewMatrix() {
		return X::Math::view(this->posistion, this->orientation, this->up);
	}
}}