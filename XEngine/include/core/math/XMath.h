
//==================================================================================\\
//FILE NAME:			XMath.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#ifndef X_MATH_H
#define X_MATH_H


#include "XConstants.h"
#include "XCommon.h"
#include "XExponential.h"
#include "XTrigonometric.h"
#include "XVector.h"
#include "XMatrix.h"
#include "XTransform.h"


namespace X {	namespace Math {
	//Vector types

	using Vector2b = Vector2t<bool>;
	using Vector2s = Vector2t<short int>;
	using Vector2i = Vector2t<int>;
	using Vector2u = Vector2t<unsigned int>;
	using Vector2l = Vector2t<long int>;
	using Vector2f = Vector2t<float>;
	using Vector2d = Vector2t<double>;

	using Vector3b = Vector3t<bool>;
	using Vector3s = Vector3t<short int>;
	using Vector3i = Vector3t<int>;
	using Vector3u = Vector3t<unsigned int>;
	using Vector3l = Vector3t<long int>;
	using Vector3f = Vector3t<float>;
	using Vector3d = Vector3t<double>;

	using Vector4b = Vector4t<bool>;
	using Vector4s = Vector4t<short int>;
	using Vector4i = Vector4t<int>;
	using Vector4u = Vector4t<unsigned int>;
	using Vector4l = Vector4t<long int>;
	using Vector4f = Vector4t<float>;
	using Vector4d = Vector4t<double>;

	using Vector2 = Vector2f;
	using Vector3 = Vector3f;
	using Vector4 = Vector4f;


	//Matrix types

	using Matrix2x2i = Matrix2x2t<int>;
	using Matrix2x2l = Matrix2x2t<long int>;
	using Matrix2x2f = Matrix2x2t<float>;
	using Matrix2x2d = Matrix2x2t<double>;

	using Matrix2x3i = Matrix2x3t<int>;
	using Matrix2x3l = Matrix2x3t<long int>;
	using Matrix2x3f = Matrix2x3t<float>;
	using Matrix2x3d = Matrix2x3t<double>;

	using Matrix2x4i = Matrix2x4t<int>;
	using Matrix2x4l = Matrix2x4t<long int>;
	using Matrix2x4f = Matrix2x4t<float>;
	using Matrix2x4d = Matrix2x4t<double>;

	using Matrix3x2i = Matrix3x2t<int>;
	using Matrix3x2l = Matrix3x2t<long int>;
	using Matrix3x2f = Matrix3x2t<float>;
	using Matrix3x2d = Matrix3x2t<double>;

	using Matrix3x3i = Matrix3x3t<int>;
	using Matrix3x3l = Matrix3x3t<long int>;
	using Matrix3x3f = Matrix3x3t<float>;
	using Matrix3x3d = Matrix3x3t<double>;

	using Matrix3x4i = Matrix3x4t<int>;
	using Matrix3x4l = Matrix3x4t<long int>;
	using Matrix3x4f = Matrix3x4t<float>;
	using Matrix3x4d = Matrix3x4t<double>;

	using Matrix4x2i = Matrix4x2t<int>;
	using Matrix4x2l = Matrix4x2t<long int>;
	using Matrix4x2f = Matrix4x2t<float>;
	using Matrix4x2d = Matrix4x2t<double>;

	using Matrix4x3i = Matrix4x3t<int>;
	using Matrix4x3l = Matrix4x3t<long int>;
	using Matrix4x3f = Matrix4x3t<float>;
	using Matrix4x3d = Matrix4x3t<double>;

	using Matrix4x4i = Matrix4x4t<int>;
	using Matrix4x4l = Matrix4x4t<long int>;
	using Matrix4x4f = Matrix4x4t<float>;
	using Matrix4x4d = Matrix4x4t<double>;

	using Matrix2x2 = Matrix2x2f;
	using Matrix2x3 = Matrix2x3f;
	using Matrix2x4 = Matrix2x4f;
	using Matrix3x2 = Matrix3x2f;
	using Matrix3x3 = Matrix3x3f;
	using Matrix3x4 = Matrix3x4f;
	using Matrix4x2 = Matrix4x2f;
	using Matrix4x3 = Matrix4x3f;
	using Matrix4x4 = Matrix4x4f;

	using Matrix2i = Matrix2x2i;
	using Matrix2l = Matrix2x2l;
	using Matrix2f = Matrix2x2f;
	using Matrix2d = Matrix2x2d;

	using Matrix3i = Matrix3x3i;
	using Matrix3l = Matrix3x3l;
	using Matrix3f = Matrix3x3f;
	using Matrix3d = Matrix3x3d;

	using Matrix4i = Matrix4x4i;
	using Matrix4l = Matrix4x4l;
	using Matrix4f = Matrix4x4f;
	using Matrix4d = Matrix4x4d;

	using Matrix2 = Matrix2f;
	using Matrix3 = Matrix3f;
	using Matrix4 = Matrix4f;
}}

#endif // !X_MATH
