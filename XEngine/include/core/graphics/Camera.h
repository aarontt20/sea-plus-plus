
//==================================================================================\\
//FILE NAME:			Camera.h													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			04/02/2017													\\
//LAST MODIIFED:		04/05/2017													\\
//		  ©Copyright 2017, Aaron Toms & Peter Stein. All Rights Reserved.			\\
//==================================================================================\\

#ifndef CAMERA_H
#define CAMERA_H

#include "core\input\XInput.h"
#include "core\math\XMath.h"
#include <vector>

namespace X {	namespace Graphics {
	class Camera {
	protected:
		X::Math::Vector3 posistion, orientation, up;
		float pitch, yaw;

		bool canToggleFree;
		bool freeCamera;

		float movementSpeed;
		float rotationSpeed;

		std::vector<X::Input::Key> linkedMovementKeys[6];
		std::vector<X::Input::Key> linkedRotationKeys[4];
		std::vector<X::Input::Key> linkedFreeCameraKeys;
		std::vector<X::Input::Key> linkedToggleFreeCameraKeys;

	public:
		Camera();
		Camera(const X::Math::Vector3& posistion);
		Camera(const X::Math::Vector3& posistion, const X::Math::Vector3& orientation);
		Camera(const X::Math::Vector3& posistion, const X::Math::Vector3& orientation, const X::Math::Vector3& up);

		X::Math::Vector3 getPosistion() const;
		X::Math::Vector3 getOrientation() const;
		X::Math::Vector3 getUpVector() const;
		bool isFree() const;
		float getMovementSpeed() const;
		float getRoationSpeed() const;

		std::vector<X::Input::Key> getLinkedMoveForwardKeys() const;
		std::vector<X::Input::Key> getLinkedMoveBackwardKeys() const;
		std::vector<X::Input::Key> getLinkedMoveLeftKeys() const;
		std::vector<X::Input::Key> getLinkedMoveRightKeys() const;
		std::vector<X::Input::Key> getLinkedMoveUpKeys() const;
		std::vector<X::Input::Key> getLinkedMoveDownKeys() const;
		
		std::vector<X::Input::Key> getLinkedRotateLeftKeys() const;
		std::vector<X::Input::Key> getLinkedRotateRightKeys() const;
		std::vector<X::Input::Key> getLinkedRotateUpKeys() const;
		std::vector<X::Input::Key> getLinkedRotateDownKeys() const;
		
		std::vector<X::Input::Key> getLinkedFreeCameraKeys() const;
		std::vector<X::Input::Key> getLinkedToggleFreeCameraKeys() const;


		bool shouldMoveForward();
		bool shouldMoveBackward();
		bool shouldMoveLeft();
		bool shouldMoveRight();
		bool shouldMoveUp();
		bool shouldMoveDown();

		bool shouldRotateLeft();
		bool shouldRotateRight();
		bool shouldRotateUp();
		bool shouldRotateDown();

		bool shouldToggleFreeCamera();
		bool shouldFreeCamera();


		void setPosistion(const X::Math::Vector3& posistion);
		void setOrientation(const X::Math::Vector3& orientation);
		void setUpVector(const X::Math::Vector3& upVector);
		void setFreeCamera(const bool& isFree);
		void setMovementSpeed(const float& speed);
		void setRotationSpeed(const float& speed);

		void linkMoveForwardKey(const X::Input::Key& key);
		void linkMoveBackwardKey(const X::Input::Key& key);
		void linkMoveLeftKey(const X::Input::Key& key);
		void linkMoveRightKey(const X::Input::Key& key);
		void linkMoveUpKey(const X::Input::Key& key);
		void linkMoveDownKey(const X::Input::Key& key);

		void linkRotateLeftKey(const X::Input::Key& key);
		void linkRotateRightKey(const X::Input::Key& key);
		void linkRotateUpKey(const X::Input::Key& key);
		void linkRotateDownKey(const X::Input::Key& key);

		void linkFreeCameraKey(const X::Input::Key& key);
		void linkToggleFreeCameraKey(const X::Input::Key& key);

		void delinkMoveForwardKey(const X::Input::Key& key);
		void delinkMoveBackwardKey(const X::Input::Key& key);
		void delinkMoveLeftKey(const X::Input::Key& key);
		void delinkMoveRightKey(const X::Input::Key& key);
		void delinkMoveUpKey(const X::Input::Key& key);
		void delinkMoveDownKey(const X::Input::Key& key);

		void delinkRotateLeftKey(const X::Input::Key& key);
		void delinkRotateRightKey(const X::Input::Key& key);
		void delinkRotateUpKey(const X::Input::Key& key);
		void delinkRotateDownKey(const X::Input::Key& key);

		void delinkFreeCameraKey(const X::Input::Key& key);
		void delinkToggleFreeCameraKey(const X::Input::Key& key);

		void delinkAllMoveForwardKeys();
		void delinkAllMoveBackwardKeys();
		void delinkAllMoveLeftKeys();
		void delinkAllMoveRightKeys();
		void delinkAllMoveUpKeys();
		void delinkAllMoveDownKeys();

		void delinkAllRotateLeftKeys();
		void delinkAllRotateRightKeys();
		void delinkAllRotateUpKeys();
		void delinkAllRotateDownKeys();

		void delinkAllFreeCameraKeys();
		void delinkAllToggleFreeCameraKeys();


		void moveForward();
		void moveBackward();
		void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
		void moveForward(const float& dist);
		void moveBackward(const float& dist);
		void moveLeft(const float& dist);
		void moveRight(const float& dist);
		void moveUp(const float& dist);
		void moveDown(const float& dist);

		void rotate();
		void rotateLeft();
		void rotateRight();
		void rotateUp();
		void rotateDown();
		void rotate(const float& yaw, const float& pitch);

		void updateFreeCamera();
		void update();

		void use();

		X::Math::Matrix4 getViewMatrix();
	};
}}

#endif // !CAMERA_H