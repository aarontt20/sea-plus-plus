
//==================================================================================\\
//FILE NAME:			XTransform.cpp												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#ifndef X_TRANSFORM_H
#define X_TRANSFORM_H


#include "XVector.h"
#include "XMatrix.h"


namespace X {	namespace Math {

	//3D transformations

	template <typename T>	Matrix4x4t<T>	translate(const Matrix4x4t<T>& mat4x4, const Vector3t<T>& vec3);
	template <typename T>	Matrix4x4t<T>	scale(const Matrix4x4t<T>& mat4x4, const Vector3t<T>& vec3);
	template <typename T>	Matrix4x4t<T>	rotate(const Matrix4x4t<T>& mat4x4, const long double& angle, const Vector3t<T>& vec3);

	//Projections

	template <typename T>	Matrix4x4t<T>	perspective(const T& fovAngle, const T& aspectRatio, const T& near, const T& far);
	template <typename T>	Matrix4x4t<T>	perspectiveOblique(const T& left, const T& right, const T& bottom, const T& top, const T& near, const T& far);
	template <typename T>	Matrix4x4t<T>	perspectiveOrtho(const T& left, const T& right, const T& bottom, const T& top, const T& near, const T& far);

	template <typename T>	Vector3t<T>		unProject(const Vector3t<T>& win, const Matrix4x4t<T>& mod, const Matrix4x4t<T>& proj, const Vector4t<T>& viewport);

	//View

	template <typename T>	Matrix4x4t<T>	view(const Vector3t<T>& posistion, const Vector3t<T>& target, const Vector3t<T>& up);
}}

#include "..\src\core\math\XTransform.inl"

#endif // !X_TRANSFORM_H
