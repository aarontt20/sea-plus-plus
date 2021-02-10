
//==================================================================================\\
//FILE NAME:			XTransform.inl												\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#include "core/math/XTransform.h"
#include "core/math/XTrigonometric.h"

namespace X {	namespace Math {

	//3D transformations
	template <typename T>	Matrix4x4t<T>	translate(const Matrix4x4t<T>& mat4x4, const Vector3t<T>& vec3) {
		Matrix4x4t<T> translate;

		translate[3][0] = vec3.x;
		translate[3][1] = vec3.y;
		translate[3][2] = vec3.z;

		return translate * mat4x4;
	}
	template <typename T>	Matrix4x4t<T>	scale(const Matrix4x4t<T>& mat4x4, const Vector3t<T>& vec3) {
		Matrix4x4t<T> scale;

		scale[0][0] = vec3.x;
		scale[1][1] = vec3.y;
		scale[2][2] = vec3.z;

		return scale * mat4x4;
	}
	template <typename T>	Matrix4x4t<T>	rotate(const Matrix4x4t<T>& mat4x4, const long double& angle, const Vector3t<T>& axis) {
		Matrix4x4t<T> rotation;

		T c = cos(angle);
		T s = sin(angle);

		Vector3 vec3 = Vector3::normalize(axis);

		rotation[0][0] = (1 - c) * vec3.x * vec3.x + c;
		rotation[0][1] = (1 - c) * vec3.x * vec3.y + vec3.z * s;
		rotation[0][2] = (1 - c) * vec3.z * vec3.x - vec3.y * s;
		rotation[1][0] = (1 - c) * vec3.x * vec3.y - vec3.z * s;
		rotation[1][1] = (1 - c) * vec3.y * vec3.y + c;
		rotation[1][2] = (1 - c) * vec3.y * vec3.z + vec3.x * s;
		rotation[2][0] = (1 - c) * vec3.z * vec3.x + vec3.y * s;
		rotation[2][1] = (1 - c) * vec3.y * vec3.z - vec3.x * s;
		rotation[2][2] = (1 - c) * vec3.z * vec3.z + c;

		return rotation * mat4x4;
	}

	template <typename T>	Matrix4x4t<T>	rotateFromPoint(const Matrix4x4t<T>& mat4x4, const Vector3t<T>& point , const long double& angle, const Vector3t<T>& axis) {
		Matrix4x4t<T> rotation = mat4x4;
		
		rotation = translate(rotation, -point);
		rotation = rotate(rotation, angle, axis);
		rotation = translate(rotation, point);

		return rotation;
	}

	template <typename T>	Vector3t<T>		eulerAngles(const Matrix4x4t<T> &mat4x4) {

		double x = atan2(static_cast<double>(mat4x4[2][1]), static_cast<double>(mat4x4[2][2]));
		double c2 = X::Math::sqrt(X::Math::pow(static_cast<double>(mat4x4[0][0]), 2.0) + X::Math::pow(static_cast<double>(mat4x4[1][0]), 2.0));
		double y = atan2(static_cast<double>(-mat4x4[2][0]), c2);
		double s1 = X::Math::sin(x);
		double c1 = X::Math::cos(x);
		double z = atan2(s1 * mat4x4[2][0] - c1 * mat4x4[0][1], c1 * mat4x4[1][1] - s1 * mat4x4[1][2]);
		
		return Vector3t<T>(x, y, z);
	}

	//Projections
	template <typename T>	Matrix4x4t<T>	perspective(const T& fovAngle, const T& aspectRatio, const T& near, const T& far) {
		Matrix4x4t<T> perspective;

		T d = 1 / (tan(fovAngle / 2));

		perspective[0][0] = d / aspectRatio;
		perspective[1][1] = d;
		perspective[2][2] = (near + far) / (near - far);
		perspective[2][3] = -1;
		perspective[3][2] = (2 * near * far) / (near - far);
		perspective[3][3] = 0;

		return perspective;
	}
	template <typename T>	Matrix4x4t<T>	perspectiveOblique(const T& left, const T& right, const T& bottom, const T& top, const T& near, const T& far) {
		Matrix4x4t<T> perspective;

		perspective[0][0] = (2 * near) / (right - left);
		perspective[1][1] = (2 * near) / (top - bottom);
		perspective[2][0] = (right + left) / (right - left);
		perspective[2][1] = (top + bottom) / (top - bottom);
		perspective[2][2] = (near + far) / (near - far);;
		perspective[2][3] = -1;
		perspective[3][2] = (2 * near * far) / (near - far);
		perspective[3][3] = 0;

		return perspective;
	}
	template <typename T>	Matrix4x4t<T>	perspectiveOrtho(const T& left, const T& right, const T& bottom, const T& top, const T& near, const T& far) {
		Matrix4x4t<T> perspective;

		perspective[0][0] = 2 / (right - left);
		perspective[1][1] = 2 / (top - bottom);
		perspective[2][2] = -2 / (far - near);
		perspective[3][0] = -((right + left) / (right - left));
		perspective[3][1] = -((top + bottom) / (top - bottom));
		perspective[3][2] = -((far + near) / (far - near));

		return perspective;
	}

	template <typename T>	Vector3t<T>		unProject(const Vector3t<T>& win, const Matrix4x4t<T>& mod, const Matrix4x4t<T>& proj, const Vector4t<T>& viewport) {
		Matrix4x4t<T> inv = Matrix4x4t<T>::inverse(proj * mod);

		Vector4t<T> v(win, 1.0);

		v.x = (v.x - (viewport.x)) / (viewport.z);
		v.y = (v.y - (viewport.y)) / (viewport.w);

		v = v * static_cast<T>(2.0) - static_cast<T>(1.0);

		Vector4t<T> unProj = (inv * v);
		unProj /= unProj.w;

		return Vector3t<T>(unProj);
	}

	//View
	template <typename T>	Matrix4x4t<T>	view(const Vector3t<T>& posistion, const Vector3t<T>& target, const Vector3t<T>& up) {
		Matrix4x4t<T> view;

		Vector3t<T> z = -(target / static_cast<float>(Vector3t<T>::magnitude(target)));
		Vector3t<T> x = Vector3t<T>::cross(target, up) / static_cast<float>(Vector3t<T>::magnitude(Vector3t<T>::cross(target, up)));
		Vector3t<T> y = Vector3t<T>::cross(z, x);

		view = Matrix4x4t<T>(Vector4t<T>(x, 0), Vector4t<T>(y, 0), Vector4t<T>(z, 0), Vector4t<T>(posistion, 1));

		view = Matrix4x4t<T>::inverse(view);

		return view;
	}
}}
