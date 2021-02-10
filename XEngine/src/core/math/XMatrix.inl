
//==================================================================================\\
//FILE NAME:			XMatrix.inl													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#include "core/math/XMatrix.h"
#include <cassert>

namespace X {	namespace Math {

	//Matrix2x2 Struct Definitions

	template <typename T>									Matrix2x2t<T>::Matrix2x2t() :
		data{ Vector2t<T>(1, 0), Vector2t<T>(0, 1) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Matrix2x2t<T>& mat2x2) :
		data{ Vector2t<T>(mat2x2[0]), Vector2t<T>(mat2x2[1]) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const T& scalar) :
		data{ Vector2t<T>(scalar, 0), Vector2t<T>(0, scalar) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Vector2t<T>& col0, const Vector2t<T>& col1) :
		data{ Vector2t<T>(col0), Vector2t<T>(col1) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(
		const T& x0, const T& x1,
		const T& y0, const T& y1) :
		data{ Vector2t<T>(x0, y0), Vector2t<T>(x1, y1) } {	}
	template <typename T>		template <typename Ta>		Matrix2x2t<T>::Matrix2x2t(const Matrix2x2t<Ta>& mat2x2) :
		data{ Vector2t<T>(mat2x2[0]), Vector2t<T>(mat2x2[1]) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Matrix2x3t<T>& mat2x3) :
		data{ Vector2t<T>(mat2x3[0]), Vector2t<T>(mat2x3[1]) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Matrix2x4t<T>& mat2x4) :
		data{ Vector2t<T>(mat2x4[0]), Vector2t<T>(mat2x4[1]) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Matrix3x2t<T>& mat3x2) :
		data{ Vector2t<T>(mat3x2[0]), Vector2t<T>(mat3x2[1]) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Matrix3x3t<T>& mat3x3) :
		data{ Vector2t<T>(mat3x3[0]), Vector2t<T>(mat3x3[1]) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Matrix3x4t<T>& mat3x4) :
		data{ Vector2t<T>(mat3x4[0]), Vector2t<T>(mat3x4[1]) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Matrix4x2t<T>& mat4x2) :
		data{ Vector2t<T>(mat4x2[0]), Vector2t<T>(mat4x2[1]) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Matrix4x3t<T>& mat4x3) :
		data{ Vector2t<T>(mat4x3[0]), Vector2t<T>(mat4x3[1]) } {	}
	template <typename T>									Matrix2x2t<T>::Matrix2x2t(const Matrix4x4t<T>& mat4x4) :
		data{ Vector2t<T>(mat4x4[0]), Vector2t<T>(mat4x4[1]) } {	}
	template <typename T>		Vector2t<T>&			Matrix2x2t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 2);
		return this->data[index];
	}
	template <typename T>		const Vector2t<T>&		Matrix2x2t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 2);
		return this->data[index];
	}
	template <typename T>		Matrix2x2t<T>&			Matrix2x2t<T>::operator +=(const T& scalar) {
		this->data[0] += scalar;
		this->data[1] += scalar;

		return *this;
	}
	template <typename T>		Matrix2x2t<T>&			Matrix2x2t<T>::operator -=(const T& scalar) {
		this->data[0] -= scalar;
		this->data[1] -= scalar;

		return *this;
	}
	template <typename T>		Matrix2x2t<T>&			Matrix2x2t<T>::operator *=(const T& scalar) {
		this->data[0] *= scalar;
		this->data[1] *= scalar;

		return *this;
	}
	template <typename T>		Matrix2x2t<T>&			Matrix2x2t<T>::operator /=(const T& scalar) {
		this->data[0] /= scalar;
		this->data[1] /= scalar;

		return *this;
	}
	template <typename T>		Matrix2x2t<T>&			Matrix2x2t<T>::operator +=(const Matrix2x2t<T>& mat2x2) {
		this->data[0] += mat2x2[0];
		this->data[1] += mat2x2[1];

		return *this;
	}
	template <typename T>		Matrix2x2t<T>&			Matrix2x2t<T>::operator -=(const Matrix2x2t<T>& mat2x2) {
		this->data[0] -= mat2x2[0];
		this->data[1] -= mat2x2[1];

		return *this;
	}
	template <typename T>		Matrix2x2t<T>&			Matrix2x2t<T>::operator *=(const Matrix2x2t<T>& mat2x2) {
		T x0 = this->data[0][0] * mat2x2[0][0] + this->data[1][0] * mat2x2[0][1], y0 = this->data[0][1] * mat2x2[0][0] + this->data[1][1] * mat2x2[0][1];
		T x1 = this->data[0][0] * mat2x2[1][0] + this->data[1][0] * mat2x2[1][1], y1 = this->data[0][1] * mat2x2[1][0] + this->data[1][1] * mat2x2[1][1];

		this->data[0] = Vector2t<T>(x0, y0);
		this->data[1] = Vector2t<T>(x1, y1);

		return *this;
	}
	template <typename T>		Matrix2x2t<T>&			Matrix2x2t<T>::operator /=(const Matrix2x2t<T>& mat2x2) {
		this *= inverse(mat2x2);

		return *this;
	}
	template <typename T> template<typename Ta>		Matrix2x2t<Ta>			Matrix2x2t<T>::transpose(const Matrix2x2t<Ta>& mat2x2) {
		Matrix2x2t<Ta> transposition(
			mat2x2[0][0], mat2x2[0][1],
			mat2x2[1][0], mat2x2[1][1]
		);

		return transposition;
	}
	template <typename T> template<typename Ta>		Ta						Matrix2x2t<T>::determinant(const Matrix2x2t<Ta>& mat2x2) {
		Ta det = mat2x2[0][0] * mat2x2[1][1] - mat2x2[1][0] * mat2x2[0][1];

		return det;
	}
	template <typename T> template<typename Ta>		Matrix2x2t<float>		Matrix2x2t<T>::inverse(const Matrix2x2t<Ta>& mat2x2) {
		assert(Matrix2x2t<Ta>::determinant(mat2x2) != 0);

		Matrix2x2t<float> Matrix2x2t<Ta>::inverse = Matrix2x2t<Ta>(mat2x2[1][1], -(mat2x2[1][0]), -(mat2x2[0][1]), mat2x2[0][0]) * (1 / Matrix2x2t<Ta>::determinant(mat2x2));

		return inverse;
	}
	template <typename T> template <typename Ta>		Matrix2x2t<Ta>		Matrix2x2t<T>::elementMultiplication(const Matrix2x2t<Ta>& mat2x2l, const Matrix2x2t<Ta>& mat2x2r) {
		Matrix2x2t<Ta> prod(
			mat2x2l[0][0] * mat2x2r[0][0], mat2x2l[1][0] * mat2x2r[1][0],
			mat2x2l[0][1] * mat2x2r[0][1], mat2x2l[1][1] * mat2x2r[1][1]
		);

		return prod;
	}
	template <typename T> template <typename Ta>		Matrix2x2t<Ta>		Matrix2x2t<T>::elementDivision(const Matrix2x2t<Ta>& mat2x2l, const Matrix2x2t<Ta>& mat2x2r) {
		Matrix2x2t<Ta> quot(
			mat2x2l[0][0] / mat2x2r[0][0], mat2x2l[1][0] / mat2x2r[1][0],
			mat2x2l[0][1] / mat2x2r[0][1], mat2x2l[1][1] / mat2x2r[1][1]
		);

		return quot;
	}

	//Matrix2x3 Struct Definitions

	template <typename T>									Matrix2x3t<T>::Matrix2x3t() :
		data{ Vector2t<T>(1, 0), Vector2t<T>(0, 1) , Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Matrix2x3t<T>& mat2x3) :
		data{ Vector2t<T>(mat2x3[0]), Vector2t<T>(mat2x3[1]), Vector2t<T>(mat2x3[2]) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const T& scalar) :
		data{ Vector2t<T>(scalar, 0), Vector2t<T>(0, scalar), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Vector2t<T>& col0, const Vector2t<T>& col1, const Vector2t<T>& col2) :
		data{ Vector2t<T>(col0), Vector2t<T>(col1), Vector2t<T>(col2) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(
		const T& x0, const T& x1, const T& x2,
		const T& y0, const T& y1, const T& y2) :
		data{ Vector2t<T>(x0, y0), Vector2t<T>(x1, y1), Vector2t<T>(x2, y2) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Matrix2x2t<T>& mat2x2) :
		data{ Vector2t<T>(mat2x2[0]), Vector2t<T>(mat2x2[1]), Vector2t<T>(0, 0) } {	}
	template <typename T>		template <typename Ta>		Matrix2x3t<T>::Matrix2x3t(const Matrix2x3t<Ta>& mat2x3) :
		data{ Vector2t<T>(mat2x3[0]), Vector2t<T>(mat2x3[1]), Vector2t<T>(mat2x3[2]) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Matrix2x4t<T>& mat2x4) :
		data{ Vector2t<T>(mat2x4[0]), Vector2t<T>(mat2x4[1]), Vector2t<T>(mat2x4[2]) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Matrix3x2t<T>& mat3x2) :
		data{ Vector2t<T>(mat3x2[0]), Vector2t<T>(mat3x2[1]), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Matrix3x3t<T>& mat3x3) :
		data{ Vector2t<T>(mat3x3[0]), Vector2t<T>(mat3x3[1]), Vector2t<T>(mat3x3[2]) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Matrix3x4t<T>& mat3x4) :
		data{ Vector2t<T>(mat3x4[0]), Vector2t<T>(mat3x4[1]), Vector2t<T>(mat3x4[2]) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Matrix4x2t<T>& mat4x2) :
		data{ Vector2t<T>(mat4x2[0]), Vector2t<T>(mat4x2[1]), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Matrix4x3t<T>& mat4x3) :
		data{ Vector2t<T>(mat4x3[0]), Vector2t<T>(mat4x3[1]), Vector2t<T>(mat4x3[2]) } {	}
	template <typename T>									Matrix2x3t<T>::Matrix2x3t(const Matrix4x4t<T>& mat4x4) :
		data{ Vector2t<T>(mat4x4[0]), Vector2t<T>(mat4x4[1]), Vector2t<T>(mat4x4[2]) } {	}
	template <typename T>		Vector2t<T>&			Matrix2x3t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 3);
		return this->data[index];
	}
	template <typename T>		const Vector2t<T>&		Matrix2x3t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 3);
		return this->data[index];
	}
	template <typename T>		Matrix2x3t<T>&			Matrix2x3t<T>::operator +=(const T& scalar) {
		this->data[0] += scalar;
		this->data[1] += scalar;
		this->data[2] += scalar;

		return *this;
	}
	template <typename T>		Matrix2x3t<T>&			Matrix2x3t<T>::operator -=(const T& scalar) {
		this->data[0] -= scalar;
		this->data[1] -= scalar;
		this->data[2] -= scalar;

		return *this;
	}
	template <typename T>		Matrix2x3t<T>&			Matrix2x3t<T>::operator *=(const T& scalar) {
		this->data[0] *= scalar;
		this->data[1] *= scalar;
		this->data[2] *= scalar;

		return *this;
	}
	template <typename T>		Matrix2x3t<T>&			Matrix2x3t<T>::operator /=(const T& scalar) {
		this->data[0] /= scalar;
		this->data[1] /= scalar;
		this->data[2] /= scalar;

		return *this;
	}
	template <typename T>		Matrix2x3t<T>&			Matrix2x3t<T>::operator +=(const Matrix2x3t<T>& mat2x3) {
		this->data[0] += mat2x3[0];
		this->data[1] += mat2x3[1];
		this->data[2] += mat2x3[2];

		return *this;
	}
	template <typename T>		Matrix2x3t<T>&			Matrix2x3t<T>::operator -=(const Matrix2x3t<T>& mat2x3) {
		this->data[0] -= mat2x3[0];
		this->data[1] -= mat2x3[1];
		this->data[2] -= mat2x3[2];

		return *this;
	}
	template <typename T>		Matrix2x3t<T>&			Matrix2x3t<T>::operator *=(const Matrix3x3t<T>& mat3x3) {
		T x0 = this->data[0][0] * mat3x3[0][0] + this->data[1][0] * mat3x3[0][1] + this->data[2][0] * mat3x3[0][2], y0 = this->data[0][1] * mat3x3[0][0] + this->data[1][1] * mat3x3[0][1] + this->data[2][1] * mat3x3[0][2];
		T x1 = this->data[0][0] * mat3x3[1][0] + this->data[1][0] * mat3x3[1][1] + this->data[2][0] * mat3x3[1][2], y1 = this->data[0][1] * mat3x3[1][0] + this->data[1][1] * mat3x3[1][1] + this->data[2][1] * mat3x3[1][2];
		T x2 = this->data[0][0] * mat3x3[2][0] + this->data[1][0] * mat3x3[2][1] + this->data[2][0] * mat3x3[2][2], y2 = this->data[0][1] * mat3x3[2][0] + this->data[1][1] * mat3x3[2][1] + this->data[2][1] * mat3x3[2][2];

		this->data[0] = Vector2t<T>(x0, y0);
		this->data[1] = Vector2t<T>(x1, y1);
		this->data[2] = Vector2t<T>(x2, y2);

		return *this;
	}
	template <typename T>		Matrix2x3t<T>&			Matrix2x3t<T>::operator /=(const Matrix3x3t<T>& mat3x3) {
		this *= inverse(mat3x3);

		return *this;
	}
	template <typename T> template<typename Ta>		Matrix3x2t<Ta>		Matrix2x3t<T>::transpose(const Matrix2x3t<Ta>& mat2x3) {
		Matrix3x2t<Ta> transposition(
			mat2x3[0][0], mat2x3[0][1],
			mat2x3[1][0], mat2x3[1][1],
			mat2x3[2][0], mat2x3[2][1]
		);

		return transposition;
	}
	template <typename T>  template <typename Ta>		Matrix2x3t<Ta>		Matrix2x3t<T>::elementMultiplication(const Matrix2x3t<Ta>& mat2x3l, const Matrix2x3t<Ta>& mat2x3r) {
		Matrix2x3t<Ta> prod(
			mat2x3l[0][0] * mat2x3r[0][0], mat2x3l[1][0] * mat2x3r[1][0], mat2x3l[2][0] * mat2x3r[2][0],
			mat2x3l[0][1] * mat2x3r[0][1], mat2x3l[1][1] * mat2x3r[1][1], mat2x3l[2][1] * mat2x3r[2][1]
		);

		return prod;
	}
	template <typename T>  template <typename Ta>		Matrix2x3t<Ta>		Matrix2x3t<T>::elementDivision(const Matrix2x3t<Ta>& mat2x3l, const Matrix2x3t<Ta>& mat2x3r) {
		Matrix2x3t<Ta> quot(
			mat2x3l[0][0] / mat2x3r[0][0], mat2x3l[1][0] / mat2x3r[1][0], mat2x3l[2][0] / mat2x3r[2][0],
			mat2x3l[0][1] / mat2x3r[0][1], mat2x3l[1][1] / mat2x3r[1][1], mat2x3l[2][1] / mat2x3r[2][1]
		);

		return quot;
	}

	//Matrix2x4 Struct Definitions

	template <typename T>									Matrix2x4t<T>::Matrix2x4t() :
		data{ Vector2t<T>(1, 0), Vector2t<T>(0, 1), Vector2t<T>(0, 0), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Matrix2x4t<T>& mat2x4) :
		data{ Vector2t<T>(mat2x4[0]), Vector2t<T>(mat2x4[1]), Vector2t<T>(mat2x4[2]), Vector2t<T>(mat2x4[3]) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const T& scalar) :
		data{ Vector2t<T>(scalar, 0), Vector2t<T>(0, scalar), Vector2t<T>(0, 0), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Vector2t<T>& col0, const Vector2t<T>& col1, const Vector2t<T>& col2, const Vector2t<T>& col3) :
		data{ Vector2t<T>(col0), Vector2t<T>(col1), Vector2t<T>(col2), Vector2t<T>(col3) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(
		const T& x0, const T& x1, const T& x2, const T& x3,
		const T& y0, const T& y1, const T& y2, const T& y3) :
		data{ Vector2t<T>(x0, y0), Vector2t<T>(x1, y1), Vector2t<T>(x2, y2), Vector2t<T>(x3, y3) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Matrix2x2t<T>& mat2x2) :
		data{ Vector2t<T>(mat2x2[0]), Vector2t<T>(mat2x2[1]), Vector2t<T>(0, 0), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Matrix2x3t<T>& mat2x3) :
		data{ Vector2t<T>(mat2x3[0]), Vector2t<T>(mat2x3[1]), Vector2t<T>(mat2x3[2]), Vector2t<T>(0, 0) } {	}
	template <typename T>		template <typename Ta>		Matrix2x4t<T>::Matrix2x4t(const Matrix2x4t<Ta>& mat2x4) :
		data{ Vector2t<T>(mat2x4[0]), Vector2t<T>(mat2x4[1]), Vector2t<T>(mat2x4[2]), Vector2t<T>(mat2x4[3]) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Matrix3x2t<T>& mat3x2) :
		data{ Vector2t<T>(mat3x2[0]), Vector2t<T>(mat3x2[1]), Vector2t<T>(0, 0), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Matrix3x3t<T>& mat3x3) :
		data{ Vector2t<T>(mat3x3[0]), Vector2t<T>(mat3x3[1]), Vector2t<T>(mat3x3[2]), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Matrix3x4t<T>& mat3x4) :
		data{ Vector2t<T>(mat3x4[0]), Vector2t<T>(mat3x4[1]), Vector2t<T>(mat3x4[2]), Vector2t<T>(mat3x4[3]) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Matrix4x2t<T>& mat4x2) :
		data{ Vector2t<T>(mat4x2[0]), Vector2t<T>(mat4x2[1]), Vector2t<T>(0, 0), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Matrix4x3t<T>& mat4x3) :
		data{ Vector2t<T>(mat4x3[0]), Vector2t<T>(mat4x3[1]), Vector2t<T>(mat4x3[2]), Vector2t<T>(0, 0) } {	}
	template <typename T>									Matrix2x4t<T>::Matrix2x4t(const Matrix4x4t<T>& mat4x4) :
		data{ Vector2t<T>(mat4x4[0]), Vector2t<T>(mat4x4[1]), Vector2t<T>(mat4x4[2]), Vector2t<T>(mat4x4[3]) } {	}
	template <typename T>		Vector2t<T>&			Matrix2x4t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 4);
		return this->data[index];
	}
	template <typename T>		const Vector2t<T>&		Matrix2x4t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 4);
		return this->data[index];
	}
	template <typename T>		Matrix2x4t<T>&			Matrix2x4t<T>::operator +=(const T& scalar) {
		this->data[0] += scalar;
		this->data[1] += scalar;
		this->data[2] += scalar;
		this->data[3] += scalar;

		return *this;
	}
	template <typename T>		Matrix2x4t<T>&			Matrix2x4t<T>::operator -=(const T& scalar) {
		this->data[0] -= scalar;
		this->data[1] -= scalar;
		this->data[2] -= scalar;
		this->data[3] -= scalar;

		return *this;
	}
	template <typename T>		Matrix2x4t<T>&			Matrix2x4t<T>::operator *=(const T& scalar) {
		this->data[0] *= scalar;
		this->data[1] *= scalar;
		this->data[2] *= scalar;
		this->data[3] *= scalar;

		return *this;
	}
	template <typename T>		Matrix2x4t<T>&			Matrix2x4t<T>::operator /=(const T& scalar) {
		this->data[0] /= scalar;
		this->data[1] /= scalar;
		this->data[2] /= scalar;
		this->data[3] /= scalar;

		return *this;
	}
	template <typename T>		Matrix2x4t<T>&			Matrix2x4t<T>::operator +=(const Matrix2x4t<T>& mat2x4) {
		this->data[0] += mat2x4[0];
		this->data[1] += mat2x4[1];
		this->data[2] += mat2x4[2];
		this->data[3] += mat2x4[3];

		return *this;
	}
	template <typename T>		Matrix2x4t<T>&			Matrix2x4t<T>::operator -=(const Matrix2x4t<T>& mat2x4) {
		this->data[0] -= mat2x4[0];
		this->data[1] -= mat2x4[1];
		this->data[2] -= mat2x4[2];
		this->data[3] -= mat2x4[3];

		return *this;
	}
	template <typename T>		Matrix2x4t<T>&			Matrix2x4t<T>::operator *=(const Matrix4x4t<T>& mat4x4) {
		T x0 = this->data[0][0] * mat4x4[0][0] + this->data[1][0] * mat4x4[0][1] + this->data[2][0] * mat4x4[0][2] + this->data[3][0] * mat4x4[0][3], y0 = this->data[0][1] * mat4x4[0][0] + this->data[1][1] * mat4x4[0][1] + this->data[2][1] * mat4x4[0][2] + this->data[3][1] * mat4x4[0][3];
		T x1 = this->data[0][0] * mat4x4[1][0] + this->data[1][0] * mat4x4[1][1] + this->data[2][0] * mat4x4[1][2] + this->data[3][0] * mat4x4[1][3], y1 = this->data[0][1] * mat4x4[1][0] + this->data[1][1] * mat4x4[1][1] + this->data[2][1] * mat4x4[1][2] + this->data[3][1] * mat4x4[1][3];
		T x2 = this->data[0][0] * mat4x4[2][0] + this->data[1][0] * mat4x4[2][1] + this->data[2][0] * mat4x4[2][2] + this->data[3][0] * mat4x4[2][3], y2 = this->data[0][1] * mat4x4[2][0] + this->data[1][1] * mat4x4[2][1] + this->data[2][1] * mat4x4[2][2] + this->data[3][1] * mat4x4[2][3];
		T x3 = this->data[0][0] * mat4x4[3][0] + this->data[1][0] * mat4x4[3][1] + this->data[2][0] * mat4x4[3][2] + this->data[3][0] * mat4x4[3][3], y3 = this->data[0][1] * mat4x4[3][0] + this->data[1][1] * mat4x4[3][1] + this->data[2][1] * mat4x4[3][2] + this->data[3][1] * mat4x4[3][3];

		this->data[0] = Vector2t<T>(x0, y0);
		this->data[1] = Vector2t<T>(x1, y1);
		this->data[2] = Vector2t<T>(x2, y2);
		this->data[3] = Vector2t<T>(x3, y3);

		return *this;
	}
	template <typename T>		Matrix2x4t<T>&			Matrix2x4t<T>::operator /=(const Matrix4x4t<T>& mat4x4) {
		this *= inverse(mat4x4);

		return *this;
	}
	template <typename T> template <typename Ta>	Matrix4x2t<Ta>		Matrix2x4t<T>::transpose(const Matrix2x4t<Ta>& mat2x4) {
		Matrix4x2t<Ta> transposition(
			mat2x4[0][0], mat2x4[0][1],
			mat2x4[1][0], mat2x4[1][1],
			mat2x4[2][0], mat2x4[2][1],
			mat2x4[3][0], mat2x4[3][1]
		);
	}
	template <typename T>  template <typename Ta>		Matrix2x4t<Ta>		Matrix2x4t<T>::elementMultiplication(const Matrix2x4t<Ta>& mat2x4l, const Matrix2x4t<Ta>& mat2x4r) {
		Matrix2x4t<Ta> prod(
			mat2x4l[0][0] * mat2x4r[0][0], mat2x4l[1][0] * mat2x4r[1][0], mat2x4l[2][0] * mat2x4r[2][0], mat2x4l[3][0] * mat2x4r[3][0],
			mat2x4l[0][1] * mat2x4r[0][1], mat2x4l[1][1] * mat2x4r[1][1], mat2x4l[2][1] * mat2x4r[2][1], mat2x4l[3][1] * mat2x4r[3][1]
		);

		return prod;
	}
	template <typename T>  template <typename Ta>		Matrix2x4t<Ta>		Matrix2x4t<T>::elementDivision(const Matrix2x4t<Ta>& mat2x4l, const Matrix2x4t<Ta>& mat2x4r) {
		Matrix2x4t<Ta> quot(
			mat2x4l[0][0] / mat2x4r[0][0], mat2x4l[1][0] / mat2x4r[1][0], mat2x4l[2][0] / mat2x4r[2][0], mat2x4l[3][0] / mat2x4r[3][0],
			mat2x4l[0][1] / mat2x4r[0][1], mat2x4l[1][1] / mat2x4r[1][1], mat2x4l[2][1] / mat2x4r[2][1], mat2x4l[3][1] / mat2x4r[3][1]
		);

		return quot;
	}

	//Matrix3x2 Struct Definitions

	template <typename T>									Matrix3x2t<T>::Matrix3x2t() :
		data{ Vector3t<T>(1, 0, 0), Vector3t<T>(0, 1, 0) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Matrix3x2t<T>& mat3x2) :
		data{ Vector3t<T>(mat3x2[0]), Vector3t<T>(mat3x2[1]) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const T& scalar) :
		data{ Vector3t<T>(scalar, 0, 0), Vector3t<T>(0, scalar, 0) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Vector3t<T>& col0, const Vector3t<T>& col1) :
		data{ Vector3t<T>(col0), Vector3t<T>(col1) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(
		const T& x0, const T& x1,
		const T& y0, const T& y1,
		const T& z0, const T& z1) :
		data{ Vector3t<T>(x0, y0, z0), Vector3t<T>(x1, y1, z1) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Matrix2x2t<T>& mat2x2) :
		data{ Vector3t<T>(mat2x2[0], 0), Vector3t<T>(mat2x2[1], 0) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Matrix2x3t<T>& mat2x3) :
		data{ Vector3t<T>(mat2x3[0], 0), Vector3t<T>(mat2x3[1], 0) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Matrix2x4t<T>& mat2x4) :
		data{ Vector3t<T>(mat2x4[0], 0), Vector3t<T>(mat2x4[1], 0) } {	}
	template <typename T>		template <typename Ta>		Matrix3x2t<T>::Matrix3x2t(const Matrix3x2t<Ta>& mat3x2) :
		data{ Vector3t<T>(mat3x2[0]), Vector3t<T>(mat3x2[1]) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Matrix3x3t<T>& mat3x3) :
		data{ Vector3t<T>(mat3x3[0]), Vector3t<T>(mat3x3[1]) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Matrix3x4t<T>& mat3x4) :
		data{ Vector3t<T>(mat3x4[0]), Vector3t<T>(mat3x4[1]) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Matrix4x2t<T>& mat4x2) :
		data{ Vector3t<T>(mat4x2[0]), Vector3t<T>(mat4x2[1]) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Matrix4x3t<T>& mat4x3) :
		data{ Vector3t<T>(mat4x3[0]), Vector3t<T>(mat4x3[1]) } {	}
	template <typename T>									Matrix3x2t<T>::Matrix3x2t(const Matrix4x4t<T>& mat4x4) :
		data{ Vector3t<T>(mat4x4[0]), Vector3t<T>(mat4x4[1]) } {	}
	template <typename T>		Vector3t<T>&			Matrix3x2t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 2);
		return this->data[index];
	}
	template <typename T>		const Vector3t<T>&		Matrix3x2t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 2);
		return this->data[index];
	}
	template <typename T>		Matrix3x2t<T>&			Matrix3x2t<T>::operator +=(const T& scalar) {
		this->data[0] += scalar;
		this->data[1] += scalar;

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x2t<T>::operator -=(const T& scalar) {
		this->data[0] -= scalar;
		this->data[1] -= scalar;

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x2t<T>::operator *=(const T& scalar) {
		this->data[0] *= scalar;
		this->data[1] *= scalar;

		return *this;
	}
	template <typename T>		Matrix3x2t<T>&			Matrix3x2t<T>::operator /=(const T& scalar) {
		this->data[0] /= scalar;
		this->data[1] /= scalar;

		return *this;
	}
	template <typename T>		Matrix3x2t<T>&			Matrix3x2t<T>::operator +=(const Matrix3x2t<T>& mat3x2) {
		this->data[0] += mat3x2[0];
		this->data[1] += mat3x2[1];

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x2t<T>::operator -=(const Matrix2x3t<T>& mat3x2) {
		this->data[0] -= mat3x2[0];
		this->data[1] -= mat3x2[1];

		return *this;
	}
	template <typename T>		Matrix3x2t<T>&			Matrix3x2t<T>::operator *=(const Matrix2x2t<T>& mat2x2) {
		T x0 = this->data[0][0] * mat2x2[0][0] + this->data[1][0] * mat2x2[0][1], y0 = this->data[0][1] * mat2x2[0][0] + this->data[1][1] * mat2x2[0][1], z0 = this->data[0][2] * mat2x2[0][0] + this->data[1][2] * mat2x2[0][1];
		T x1 = this->data[0][0] * mat2x2[1][0] + this->data[1][0] * mat2x2[1][1], y1 = this->data[0][1] * mat2x2[1][0] + this->data[1][1] * mat2x2[1][1], z1 = this->data[0][2] * mat2x2[1][0] + this->data[1][2] * mat2x2[1][1];

		this->data[0] = Vector3t<T>(x0, y0, z0);
		this->data[1] = Vector3t<T>(x1, y1, z1);

		return *this;
	}
	template <typename T>		Matrix3x2t<T>&			Matrix3x2t<T>::operator /=(const Matrix2x2t<T>& mat2x2) {
		this *= inverse(mat2x2);

		return *this;
	}
	template <typename T> template <typename Ta>	Matrix2x3t<Ta>		Matrix3x2t<T>::transpose(const Matrix3x2t<Ta>& mat3x2) {
		Matrix2x3t<Ta> transposition(
			mat3x2[0][0], mat3x2[0][1], mat3x2[0][2],
			mat3x2[1][0], mat3x2[1][1], mat3x2[1][2]
		);

		return transposition;
	}
	template <typename T>  template <typename Ta>		Matrix3x2t<Ta>		Matrix3x2t<T>::elementMultiplication(const Matrix3x2t<Ta>& mat3x2l, const Matrix3x2t<Ta>& mat3x2r) {
		Matrix3x2t<Ta> prod(
			mat3x2l[0][0] * mat3x2r[0][0], mat3x2l[1][0] * mat3x2r[1][0],
			mat3x2l[0][1] * mat3x2r[0][1], mat3x2l[1][1] * mat3x2r[1][1],
			mat3x2l[0][2] * mat3x2r[0][2], mat3x2l[1][2] * mat3x2r[1][2]
		);

		return prod;
	}
	template <typename T>  template <typename Ta>		Matrix3x2t<Ta>		Matrix3x2t<T>::elementDivision(const Matrix3x2t<Ta>& mat3x2l, const Matrix3x2t<Ta>& mat3x2r) {
		Matrix3x2t<Ta> quot(
			mat3x2l[0][0] / mat3x2r[0][0], mat3x2l[1][0] / mat3x2r[1][0],
			mat3x2l[0][1] / mat3x2r[0][1], mat3x2l[1][1] / mat3x2r[1][1],
			mat3x2l[0][2] / mat3x2r[0][2], mat3x2l[1][2] / mat3x2r[1][2]
		);

		return quot;
	}

	//Matrix3x3 Struct Definitions

	template <typename T>									Matrix3x3t<T>::Matrix3x3t() :
		data{ Vector3t<T>(1, 0, 0), Vector3t<T>(0, 1, 0), Vector3t<T>(0, 0, 1) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Matrix3x3t<T>& mat3x3) :
		data{ Vector3t<T>(mat3x3[0]), Vector3t<T>(mat3x3[1]), Vector3t<T>(mat3x3[2]) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const T& scalar) :
		data{ Vector3t<T>(scalar, 0, 0), Vector3t<T>(0, scalar, 0), Vector3t<T>(0, 0, scalar) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Vector3t<T>& col0, const Vector3t<T>& col1, const Vector3t<T>& col2) :
		data{ Vector3t<T>(co0), Vector3t<T>(col1), Vector3t<T>(col2) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(
		const T& x0, const T& x1, const T& x2,
		const T& y0, const T& y1, const T& y2,
		const T& z0, const T& z1, const T& z2) :
		data{ Vector3t<T>(x0, y0, z0), Vector3t<T>(x1, y1, z1), Vector3t<T>(x2, y2, z2) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Matrix2x2t<T>& mat2x2) :
		data{ Vector3t<T>(mat2x2[0], 0), Vector3t<T>(mat2x2[1], 0), Vector3t<T>(0, 0, 1) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Matrix2x3t<T>& mat2x3) :
		data{ Vector3t<T>(mat2x3[0], 0), Vector3t<T>(mat2x3[1], 0), Vector3t<T>(mat2x3[2], 1) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Matrix2x4t<T>& mat2x4) :
		data{ Vector3t<T>(mat2x4[0], 0), Vector3t<T>(mat2x4[1], 0), Vector3t<T>(mat2x4[2], 1) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Matrix3x2t<T>& mat3x2) :
		data{ Vector3t<T>(mat3x2[0]), Vector3t<T>(mat3x2[1]), Vector3t<T>(0, 0, 1) } {	}
	template <typename T>		template <typename Ta>		Matrix3x3t<T>::Matrix3x3t(const Matrix3x3t<Ta>& mat3x3) :
		data{ Vector3t<T>(mat3x3[0]), Vector3t<T>(mat3x3[1]), Vector3t<T>(mat3x3[2]) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Matrix3x4t<T>& mat3x4) :
		data{ Vector3t<T>(mat3x4[0]), Vector3t<T>(mat3x4[1]), Vector3t<T>(mat3x4[2]) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Matrix4x2t<T>& mat4x2) :
		data{ Vector3t<T>(mat4x2[0]), Vector3t<T>(mat4x2[1]), Vector3t<T>(0, 0, 1) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Matrix4x3t<T>& mat4x3) :
		data{ Vector3t<T>(mat4x3[0]), Vector3t<T>(mat4x3[1]), Vector3t<T>(mat4x3[2]) } {	}
	template <typename T>									Matrix3x3t<T>::Matrix3x3t(const Matrix4x4t<T>& mat4x4) :
		data{ Vector3t<T>(mat4x4[0]), Vector3t<T>(mat4x4[1]), Vector3t<T>(mat4x4[2]) } {	}
	template <typename T>		Vector3t<T>&			Matrix3x3t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 3);
		return this->data[index];
	}
	template <typename T>		const Vector3t<T>&		Matrix3x3t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 3);
		return this->data[index];
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x3t<T>::operator +=(const T& scalar) {
		this->data[0] += scalar;
		this->data[1] += scalar;
		this->data[2] += scalar;

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x3t<T>::operator -=(const T& scalar) {
		this->data[0] -= scalar;
		this->data[1] -= scalar;
		this->data[2] -= scalar;

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x3t<T>::operator *=(const T& scalar) {
		this->data[0] *= scalar;
		this->data[1] *= scalar;
		this->data[2] *= scalar;

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x3t<T>::operator /=(const T& scalar) {
		this->data[0] /= scalar;
		this->data[1] /= scalar;
		this->data[2] /= scalar;

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x3t<T>::operator +=(const Matrix3x3t<T>& mat3x3) {
		this->data[0] += mat3x3[0];
		this->data[1] += mat3x3[1];
		this->data[2] += mat3x3[2];

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x3t<T>::operator -=(const Matrix3x3t<T>& mat3x3) {
		this->data[0] -= mat3x3[0];
		this->data[1] -= mat3x3[1];
		this->data[2] -= mat3x3[2];

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x3t<T>::operator *=(const Matrix3x3t<T>& mat3x3) {
		T x0 = this->data[0][0] * mat3x3[0][0] + this->data[1][0] * mat3x3[0][1] + this->data[2][0] * mat3x3[0][2], y0 = this->data[0][0] * mat3x3[1][0] + this->data[1][0] * mat3x3[1][1] + this->data[2][0] * mat3x3[1][2], z0 = this->data[0][0] * mat3x3[2][0] + this->data[1][0] * mat3x3[2][1] + this->data[2][0] * mat3x3[2][2];
		T x1 = this->data[0][1] * mat3x3[0][0] + this->data[1][1] * mat3x3[0][1] + this->data[2][1] * mat3x3[0][2], y1 = this->data[0][1] * mat3x3[1][0] + this->data[1][1] * mat3x3[1][1] + this->data[2][1] * mat3x3[1][2], z1 = this->data[0][1] * mat3x3[2][0] + this->data[1][1] * mat3x3[2][1] + this->data[2][1] * mat3x3[2][2];
		T x2 = this->data[0][2] * mat3x3[0][0] + this->data[1][2] * mat3x3[0][1] + this->data[2][2] * mat3x3[0][2], y2 = this->data[0][2] * mat3x3[1][0] + this->data[1][2] * mat3x3[1][1] + this->data[2][2] * mat3x3[1][2], z2 = this->data[0][2] * mat3x3[2][0] + this->data[1][2] * mat3x3[2][1] + this->data[2][2] * mat3x3[2][2];

		this->data[0] = Vector3t<T>(x0, y0, z0);
		this->data[1] = Vector3t<T>(x1, y1, z1);
		this->data[2] = Vector3t<T>(x2, y2, z2);

		return *this;
	}
	template <typename T>		Matrix3x3t<T>&			Matrix3x3t<T>::operator /=(const Matrix3x3t<T>& mat3x3) {
		this *= inverse(mat3x3);

		return *this;
	}
	template <typename T> template <typename Ta>	Matrix3x3t<Ta>			Matrix3x3t<T>::transpose(const Matrix3x3t<Ta>& mat3x3) {
		Matrix3x3t<Ta> transposition(
			mat3x3[0][0], mat3x3[0][1], mat3x3[0][2],
			mat3x3[1][0], mat3x3[1][1], mat3x3[1][2],
			mat3x3[2][0], mat3x3[2][1], mat3x3[2][2]
		);

		return transposition;
	}
	template <typename T> template <typename Ta>	Ta						Matrix3x3t<T>::determinant(const Matrix3x3t<Ta>& mat3x3) {
		Ta det =
			mat3x3[0][0] * (mat3x3[1][1] * mat3x3[2][2] - mat3x3[2][1] * mat3x3[1][2]) -
			mat3x3[1][0] * (mat3x3[0][1] * mat3x3[2][2] - mat3x3[2][1] * mat3x3[0][2]) +
			mat3x3[2][0] * (mat3x3[0][1] * mat3x3[1][2] - mat3x3[1][1] * mat3x3[0][2]);

		return det;
	}
	template <typename T> template <typename Ta>	Matrix3x3t<float>		Matrix3x3t<T>::inverse(const Matrix3x3t<Ta>& mat3x3) {
		assert(Matrix3x3t<Ta>::determinant(mat3x3) != 0);

		Matrix3x3t<float> inverse = Matrix3x3t<Ta>::transpose(Matrix3x3t<Ta>(
			Matrix2x2t<Ta>::determinant(Matrix2x2t<Ta>(mat3x3[1][1], mat3x3[2][1], mat3x3[1][2], mat3x3[2][2])), -Matrix2x2t<Ta>::determinant(Matrix2x2t<Ta>(mat3x3[0][1], mat3x3[2][1], mat3x3[0][2], mat3x3[2][2])), Matrix2x2t<Ta>::determinant(Matrix2x2t<Ta>(mat3x3[0][1], mat3x3[1][1], mat3x3[0][2], mat3x3[1][2])),
			-Matrix2x2t<Ta>::determinant(Matrix2x2t<Ta>(mat3x3[1][0], mat3x3[2][0], mat3x3[1][2], mat3x3[2][2])), Matrix2x2t<Ta>::determinant(Matrix2x2t<Ta>(mat3x3[0][0], mat3x3[2][0], mat3x3[0][2], mat3x3[2][2])), -Matrix2x2t<Ta>::determinant(Matrix2x2t<Ta>(mat3x3[0][0], mat3x3[1][0], mat3x3[0][2], mat3x3[1][2])),
			Matrix2x2t<Ta>::determinant(Matrix2x2t<Ta>(mat3x3[1][0], mat3x3[2][0], mat3x3[1][1], mat3x3[2][1])), -Matrix2x2t<Ta>::determinant(Matrix2x2t<Ta>(mat3x3[0][0], mat3x3[2][0], mat3x3[0][1], mat3x3[2][1])), Matrix2x2t<Ta>::determinant(Matrix2x2t<Ta>(mat3x3[0][0], mat3x3[1][0], mat3x3[0][1], mat3x3[1][1]))
			)) * (1 / Matrix3x3t<Ta>::determinant(mat3x3));

		return inverse;
	}
	template <typename T>  template <typename Ta>		Matrix3x3t<Ta>		Matrix3x3t<T>::elementMultiplication(const Matrix3x3t<Ta>& mat3x3l, const Matrix3x3t<Ta>& mat3x3r) {
		Matrix3x3t<Ta> prod(
			mat3x3l[0][0] * mat3x3r[0][0], mat3x3l[1][0] * mat3x3r[1][0], mat3x3l[2][0] * mat3x3r[2][0],
			mat3x3l[0][1] * mat3x3r[0][1], mat3x3l[1][1] * mat3x3r[1][1], mat3x3l[2][1] * mat3x3r[2][1],
			mat3x3l[0][2] * mat3x3r[0][2], mat3x3l[1][2] * mat3x3r[1][2], mat3x3l[2][2] * mat3x3r[2][2]
		);

		return prod;
	}
	template <typename T>  template <typename Ta>		Matrix3x3t<Ta>		Matrix3x3t<T>::elementDivision(const Matrix3x3t<Ta>& mat3x3l, const Matrix3x3t<Ta>& mat3x3r) {
		Matrix3x3t<Ta> quot(
			mat3x3l[0][0] / mat3x3r[0][0], mat3x3l[1][0] / mat3x3r[1][0], mat3x3l[2][0] / mat3x3r[2][0],
			mat3x3l[0][1] / mat3x3r[0][1], mat3x3l[1][1] / mat3x3r[1][1], mat3x3l[2][1] / mat3x3r[2][1],
			mat3x3l[0][2] / mat3x3r[0][2], mat3x3l[1][2] / mat3x3r[1][2], mat3x3l[2][2] / mat3x3r[2][2]
		);

		return quot;
	}

	//Matrix3x4 Struct Definitions

	template <typename T>									Matrix3x4t<T>::Matrix3x4t() :
		data{ Vector3t<T>(1, 0, 0), Vector3t<T>(0, 1, 0), Vector3t<T>(0, 0, 1), Vector3t<T>(0, 0, 0) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Matrix3x4t<T>& mat3x4) :
		data{ Vector3t<T>(mat3x4[0]), Vector3t<T>(mat3x4[1]), Vector3t<T>(mat3x4[2]), Vector3t<T>(mat3x4[3]) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const T& scalar) :
		data{ Vector3t<T>(scalar, 0, 0), Vector3t<T>(0, scalar, 0), Vector3t<T>(0, 0, scalar), Vector3t<T>(0, 0, 0) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Vector3t<T>& col0, const Vector3t<T>& col1, const Vector3t<T>& col2, const Vector3t<T>& col3) :
		data{ Vector3t<T>(col0), Vector3t<T>(col1), Vector3t<T>(col2), Vector3t<T>(col3) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(
		const T& x0, const T& x1, const T& x2, const T& x3,
		const T& y0, const T& y1, const T& y2, const T& y3,
		const T& z0, const T& z1, const T& z2, const T& z3) :
		data{ Vector3t<T>(x0, y0, z0), Vector3t<T>(x1, y1, z1), Vector3t<T>(x2, y2, z2), Vector3t<T>(x3, y3, z3) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Matrix2x2t<T>& mat2x2) :
		data{ Vector3t<T>(mat2x2[0], 0), Vector3t<T>(mat2x2[1], 0), Vector3t<T>(0, 0, 1), Vector3t<T>(0, 0, 0) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Matrix2x3t<T>& mat2x3) :
		data{ Vector3t<T>(mat2x3[0], 0), Vector3t<T>(mat2x3[1], 0), Vector3t<T>(mat2x3[2], 1), Vector3t<T>(0, 0, 0) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Matrix2x4t<T>& mat2x4) :
		data{ Vector3t<T>(mat2x4[0], 0), Vector3t<T>(mat2x4[1], 0), Vector3t<T>(mat2x4[2], 1), Vector3t<T>(mat2x4[3], 0) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Matrix3x2t<T>& mat3x2) :
		data{ Vector3t<T>(mat3x2[0]), Vector3t<T>(mat3x2[1]), Vector3t<T>(0, 0, 1), Vector3t<T>(0, 0, 0) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Matrix3x3t<T>& mat3x3) :
		data{ Vector3t<T>(mat3x3[0]), Vector3t<T>(mat3x3[1]), Vector3t<T>(mat3x3[2]), Vector3t<T>(0, 0, 0) } {	}
	template <typename T>		template <typename Ta>		Matrix3x4t<T>::Matrix3x4t(const Matrix3x4t<Ta>& mat3x4) :
		data{ Vector3t<T>(mat3x4[0]), Vector3t<T>(mat3x4[1]), Vector3t<T>(mat3x4[2]), Vector3t<T>(mat3x4[3]) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Matrix4x2t<T>& mat4x2) :
		data{ Vector3t<T>(mat4x2[0]), Vector3t<T>(mat4x2[1]), Vector3t<T>(0, 0, 1), Vector3t<T>(0, 0, 0) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Matrix4x3t<T>& mat4x3) :
		data{ Vector3t<T>(mat4x3[0]), Vector3t<T>(mat4x3[1]), Vector3t<T>(mat4x3[2]), Vector3t<T>(0, 0, 0) } {	}
	template <typename T>									Matrix3x4t<T>::Matrix3x4t(const Matrix4x4t<T>& mat4x4) :
		data{ Vector3t<T>(mat4x4[0]), Vector3t<T>(mat4x4[1]), Vector3t<T>(mat4x4[2]), Vector3t<T>(mat4x4[3]) } {	}
	template <typename T>		Vector3t<T>&			Matrix3x4t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 4);
		return this->data[index];
	}
	template <typename T>		const Vector3t<T>&		Matrix3x4t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 4);
		return this->data[index];
	}
	template <typename T>		Matrix3x4t<T>&			Matrix3x4t<T>::operator +=(const T& scalar) {
		this->data[0] += scalar;
		this->data[1] += scalar;
		this->data[2] += scalar;
		this->data[3] += scalar;

		return *this;
	}
	template <typename T>		Matrix3x4t<T>&			Matrix3x4t<T>::operator -=(const T& scalar) {
		this->data[0] -= scalar;
		this->data[1] -= scalar;
		this->data[2] -= scalar;
		this->data[3] -= scalar;

		return *this;
	}
	template <typename T>		Matrix3x4t<T>&			Matrix3x4t<T>::operator *=(const T& scalar) {
		this->data[0] *= scalar;
		this->data[1] *= scalar;
		this->data[2] *= scalar;
		this->data[3] *= scalar;

		return *this;
	}
	template <typename T>		Matrix3x4t<T>&			Matrix3x4t<T>::operator /=(const T& scalar) {
		this->data[0] /= scalar;
		this->data[1] /= scalar;
		this->data[2] /= scalar;
		this->data[3] /= scalar;

		return *this;
	}
	template <typename T>		Matrix3x4t<T>&			Matrix3x4t<T>::operator +=(const Matrix3x4t<T>& mat3x4) {
		this->data[0] += mat3x4[0];
		this->data[1] += mat3x4[1];
		this->data[2] += mat3x4[2];
		this->data[3] += mat3x4[3];

		return *this;
	}
	template <typename T>		Matrix3x4t<T>&			Matrix3x4t<T>::operator -=(const Matrix3x4t<T>& mat3x4) {
		this->data[0] -= mat3x4[0];
		this->data[1] -= mat3x4[1];
		this->data[2] -= mat3x4[2];
		this->data[3] -= mat3x4[3];

		return *this;
	}
	template <typename T>		Matrix3x4t<T>&			Matrix3x4t<T>::operator *=(const Matrix4x4t<T>& mat4x4) {
		T x0 = this->data[0][0] * mat4x4[0][0] + this->data[1][0] * mat4x4[0][1] + this->data[2][0] * mat4x4[0][2] + this->data[3][0] * mat4x4[0][3], y0 = this->data[0][1] * mat4x4[0][0] + this->data[1][1] * mat4x4[0][1] + this->data[2][1] * mat4x4[0][2] + this->data[3][1] * mat4x4[0][3], z0 = this->data[0][2] * mat4x4[0][0] + this->data[1][2] * mat4x4[0][1] + this->data[2][2] * mat4x4[0][2] + this->data[3][2] * mat4x4[0][3];
		T x1 = this->data[0][0] * mat4x4[1][0] + this->data[1][0] * mat4x4[1][1] + this->data[2][0] * mat4x4[1][2] + this->data[3][0] * mat4x4[1][3], y1 = this->data[0][1] * mat4x4[1][0] + this->data[1][1] * mat4x4[1][1] + this->data[2][1] * mat4x4[1][2] + this->data[3][1] * mat4x4[1][3], z1 = this->data[0][2] * mat4x4[1][0] + this->data[1][2] * mat4x4[1][1] + this->data[2][2] * mat4x4[1][2] + this->data[3][2] * mat4x4[1][3];
		T x2 = this->data[0][0] * mat4x4[2][0] + this->data[1][0] * mat4x4[2][1] + this->data[2][0] * mat4x4[2][2] + this->data[3][0] * mat4x4[2][3], y2 = this->data[0][1] * mat4x4[2][0] + this->data[1][1] * mat4x4[2][1] + this->data[2][1] * mat4x4[2][2] + this->data[3][1] * mat4x4[2][3], z2 = this->data[0][2] * mat4x4[2][0] + this->data[1][2] * mat4x4[2][1] + this->data[2][2] * mat4x4[2][2] + this->data[3][2] * mat4x4[2][3];
		T x3 = this->data[0][0] * mat4x4[3][0] + this->data[1][0] * mat4x4[3][1] + this->data[2][0] * mat4x4[3][2] + this->data[3][0] * mat4x4[3][3], y3 = this->data[0][1] * mat4x4[3][0] + this->data[1][1] * mat4x4[3][1] + this->data[2][1] * mat4x4[3][2] + this->data[3][1] * mat4x4[3][3], z3 = this->data[0][2] * mat4x4[3][0] + this->data[1][2] * mat4x4[3][1] + this->data[2][2] * mat4x4[3][2] + this->data[3][2] * mat4x4[3][3];

		this->data[0] = Vector3t<T>(x0, y0, z0);
		this->data[1] = Vector3t<T>(x1, y1, z1);
		this->data[2] = Vector3t<T>(x2, y2, z2);
		this->data[3] = Vector3t<T>(x3, y3, z3);

		return *this;
	}
	template <typename T>		Matrix3x4t<T>&			Matrix3x4t<T>::operator /=(const Matrix4x4t<T>& mat4x4) {
		this *= inverse(mat4x4);

		return *this;
	}
	template <typename T> template <typename Ta>	Matrix4x3t<Ta>		Matrix3x4t<T>::transpose(const Matrix3x4t<Ta>& mat3x4) {
		Matrix4x3t<Ta> transposition(
			mat3x4[0][0], mat3x4[0][1], mat3x4[0][2],
			mat3x4[1][0], mat3x4[1][1], mat3x4[1][2],
			mat3x4[2][0], mat3x4[2][1], mat3x4[2][2],
			mat3x4[3][0], mat3x4[3][1], mat3x4[3][2]
		);

		return
	}
	template <typename T>  template <typename Ta>		Matrix3x4t<Ta>		Matrix3x4t<T>::elementMultiplication(const Matrix3x4t<Ta>& mat3x4l, const Matrix3x4t<Ta>& mat3x4r) {
		Matrix3x4t<Ta> prod(
			mat3x4l[0][0] * mat3x4r[0][0], mat3x4l[1][0] * mat3x4r[1][0], mat3x4l[2][0] * mat3x4r[2][0], mat3x4l[3][0] * mat3x4r[3][0],
			mat3x4l[0][1] * mat3x4r[0][1], mat3x4l[1][1] * mat3x4r[1][1], mat3x4l[2][1] * mat3x4r[2][1], mat3x4l[3][1] * mat3x4r[3][1],
			mat3x4l[0][2] * mat3x4r[0][2], mat3x4l[1][2] * mat3x4r[1][2], mat3x4l[2][2] * mat3x4r[2][2], mat3x4l[3][2] * mat3x4r[3][2]
		);

		return prod;
	}
	template <typename T>  template <typename Ta>		Matrix3x4t<Ta>		Matrix3x4t<T>::elementDivision(const Matrix3x4t<Ta>& mat3x4l, const Matrix3x4t<Ta>& mat3x4r) {
		Matrix3x4t<Ta> quot(
			mat3x4l[0][0] / mat3x4r[0][0], mat3x4l[1][0] / mat3x4r[1][0], mat3x4l[2][0] / mat3x4r[2][0], mat3x4l[3][0] / mat3x4r[3][0],
			mat3x4l[0][1] / mat3x4r[0][1], mat3x4l[1][1] / mat3x4r[1][1], mat3x4l[2][1] / mat3x4r[2][1], mat3x4l[3][1] / mat3x4r[3][1],
			mat3x4l[0][2] / mat3x4r[0][2], mat3x4l[1][2] / mat3x4r[1][2], mat3x4l[2][2] / mat3x4r[2][2], mat3x4l[3][2] / mat3x4r[3][2]
		);

		return quot;
	}

	//Matrix4x2 Struct Definitions

	template <typename T>									Matrix4x2t<T>::Matrix4x2t() :
		data{ Vector4t<T>(1, 0, 0, 0), Vector4t<T>(0, 1, 0, 0) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Matrix4x2t<T>& mat4x2) :
		data{ Vector4t<T>(mat4x2[0]), Vector4t<T>(mat4x2[1]) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const T& scalar) :
		data{ Vector4t<T>(scalar, 0, 0, 0), Vector4t<T>(0, scalar, 0, 0) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Vector4t<T>& col0, const Vector4t<T>& col1) :
		data{ Vector4t<T>(col0), Vector4t<T>(col1) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(
		const T& x0, const T& x1,
		const T& y0, const T& y1,
		const T& z0, const T& z1,
		const T& w0, const T& w1) :
		data{ Vector4t<T>(x0, y0, z0, w0), Vector4t<T>(x1, y1, z1, w1) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Matrix2x2t<T>& mat2x2) :
		data{ Vector4t<T>(mat2x2[0], 0, 0), Vector4t<T>(mat2x2[1], 0, 0) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Matrix2x3t<T>& mat2x3) :
		data{ Vector4t<T>(mat2x3[0], 0, 0), Vector4t<T>(mat2x3[1], 0, 0) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Matrix2x4t<T>& mat2x4) :
		data{ Vector4t<T>(mat2x4[0], 0, 0), Vector4t<T>(mat2x4[1], 0, 0) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Matrix3x2t<T>& mat3x2) :
		data{ Vector4t<T>(mat3x2[0], 0), Vector4t<T>(mat3x2[1], 0) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Matrix3x3t<T>& mat3x3) :
		data{ Vector4t<T>(mat3x3[0], 0), Vector4t<T>(mat3x3[1], 0) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Matrix3x4t<T>& mat3x4) :
		data{ Vector4t<T>(mat3x4[0], 0), Vector4t<T>(mat3x4[1], 0) } {	}
	template <typename T>		template <typename Ta>		Matrix4x2t<T>::Matrix4x2t(const Matrix4x2t<Ta>& mat4x2) :
		data{ Vector4t<T>(mat4x2[0]), Vector4t<T>(mat4x2[1]) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Matrix4x3t<T>& mat4x3) :
		data{ Vector4t<T>(mat4x3[0]), Vector4t<T>(mat4x3[1]) } {	}
	template <typename T>									Matrix4x2t<T>::Matrix4x2t(const Matrix4x4t<T>& mat4x4) :
		data{ Vector4t<T>(mat4x4[0]), Vector4t<T>(mat4x4[1]) } {	}
	template <typename T>		Vector4t<T>&			Matrix4x2t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 2);
		return this->data[index];
	}
	template <typename T>		const Vector4t<T>&		Matrix4x2t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 2);
		return this->data[index];
	}
	template <typename T>		Matrix4x2t<T>&			Matrix4x2t<T>::operator +=(const T& scalar) {
		this->data[0] += scalar;
		this->data[1] += scalar;

		return *this;
	}
	template <typename T>		Matrix4x2t<T>&			Matrix4x2t<T>::operator -=(const T& scalar) {
		this->data[0] -= scalar;
		this->data[1] -= scalar;

		return *this;
	}
	template <typename T>		Matrix4x2t<T>&			Matrix4x2t<T>::operator *=(const T& scalar) {
		this->data[0] *= scalar;
		this->data[1] *= scalar;

		return *this;
	}
	template <typename T>		Matrix4x2t<T>&			Matrix4x2t<T>::operator /=(const T& scalar) {
		this->data[0] /= scalar;
		this->data[1] /= scalar;

		return *this;
	}
	template <typename T>		Matrix4x2t<T>&			Matrix4x2t<T>::operator +=(const Matrix4x2t<T>& mat4x2) {
		this->data[0] += mat4x2[0];
		this->data[1] += mat4x2[1];

		return *this;
	}
	template <typename T>		Matrix4x2t<T>&			Matrix4x2t<T>::operator -=(const Matrix4x2t<T>& mat4x2) {
		this->data[0] -= mat4x2[0];
		this->data[1] -= mat4x2[1];

		return *this;
	}
	template <typename T>		Matrix4x2t<T>&			Matrix4x2t<T>::operator *=(const Matrix2x2t<T>& mat2x2) {
		T x0 = this->data[0][0] * mat2x2[0][0] + this->data[1][0] * mat2x2[0][1], y0 = this->data[0][1] * mat2x2[0][0] + this->data[1][1] * mat2x2[0][1], z0 = this->data[0][2] * mat2x2[0][0] + this->data[1][2] * mat2x2[0][1], w0 = this->data[0][3] * mat2x2[0][0] + this->data[1][3] * mat2x2[0][1];
		T x1 = this->data[0][0] * mat2x2[1][0] + this->data[1][0] * mat2x2[1][1], y1 = this->data[0][1] * mat2x2[1][0] + this->data[1][1] * mat2x2[1][1], z1 = this->data[0][2] * mat2x2[1][0] + this->data[1][2] * mat2x2[1][1], w1 = this->data[0][3] * mat2x2[1][0] + this->data[1][3] * mat2x2[1][1];

		this->data[0] = Vector4t<T>(x0, y0, z0, w0);
		this->data[1] = Vector4t<T>(x1, y1, z1, w1);

		return *this;
	}
	template <typename T>		Matrix4x2t<T>&			Matrix4x2t<T>::operator /=(const Matrix2x2t<T>& mat2x2) {
		this *= inverse(mat2x2);

		return *this;
	}
	template <typename T> template <typename Ta>	Matrix2x4t<Ta>		Matrix4x2t<T>::transpose(const Matrix4x2t<Ta>& mat4x2) {
		Matrix2x4t<Ta> transposition(
			mat4x2[0][0], mat4x2[0][1], mat4x2[0][2], mat4x2[0][3],
			mat4x2[1][0], mat4x2[1][1], mat4x2[1][2], mat4x2[1][3]
		);

		return transposition;
	}
	template <typename T>  template <typename Ta>		Matrix4x2t<Ta>		Matrix4x2t<T>::elementMultiplication(const Matrix4x2t<Ta>& mat4x2l, const Matrix4x2t<Ta>& mat4x2r) {
		Matrix4x2t<Ta> prod(
			mat4x2l[0][0] * mat4x2r[0][0], mat4x2l[1][0] * mat4x2r[1][0],
			mat4x2l[0][1] * mat4x2r[0][1], mat4x2l[1][1] * mat4x2r[1][1],
			mat4x2l[0][2] * mat4x2r[0][2], mat4x2l[1][2] * mat4x2r[1][2],
			mat4x2l[0][3] * mat4x2r[0][3], mat4x2l[1][3] * mat4x2r[1][3]
		);

		return prod;
	}
	template <typename T>  template <typename Ta>		Matrix4x2t<Ta>		Matrix4x2t<T>::elementDivision(const Matrix4x2t<Ta>& mat4x2l, const Matrix4x2t<Ta>& mat4x2r) {
		Matrix4x2t<Ta> quot(
			mat4x2l[0][0] / mat4x2r[0][0], mat4x2l[1][0] / mat4x2r[1][0],
			mat4x2l[0][1] / mat4x2r[0][1], mat4x2l[1][1] / mat4x2r[1][1],
			mat4x2l[0][2] / mat4x2r[0][2], mat4x2l[1][2] / mat4x2r[1][2],
			mat4x2l[0][3] / mat4x2r[0][3], mat4x2l[1][3] / mat4x2r[1][3]
		);

		return quot;
	}

	//Matrix4x3 Struct Definitions

	template <typename T>									Matrix4x3t<T>::Matrix4x3t() :
		data{ Vector4t<T>(1, 0, 0, 0), Vector4t<T>(0, 1, 0, 0), Vector4t<T>(0, 0, 1, 0) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Matrix4x3t<T>& mat4x3) :
		data{ Vector4t<T>(mat4x3[0]), Vector4t<T>(mat4x3[1]), Vector4t<T>(mat4x3[2]) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const T& scalar) :
		data{ Vector4t<T>(scalar, 0, 0, 0), Vector4t<T>(0, scalar, 0, 0), Vector4t<T>(0, 0, scalar, 0) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Vector4t<T>& col0, const Vector4t<T>& col1, const Vector4t<T>& col2) :
		data{ Vector4t<T>(col0), Vector4t<T>(col1), Vector4t<T>(col2) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(
		const T& x0, const T& x1, const T& x2,
		const T& y0, const T& y1, const T& y2,
		const T& z0, const T& z1, const T& z2,
		const T& w0, const T& w1, const T& w2) :
		data{ Vector4t<T>(x0, y0, z0, w0), Vector4t<T>(x1, y1, z1, w1), Vector4t<T>(x2, y2, z2, w2) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Matrix2x2t<T>& mat2x2) :
		data{ Vector4t<T>(mat2x2[0], 0, 0), Vector4t<T>(mat2x2[1], 0, 0), Vector4t<T>(0, 0, 1, 0) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Matrix2x3t<T>& mat2x3) :
		data{ Vector4t<T>(mat2x3[0], 0, 0), Vector4t<T>(mat2x3[1], 0, 0), Vector4t<T>(mat2x3[2], 1, 0) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Matrix2x4t<T>& mat2x4) :
		data{ Vector4t<T>(mat2x4[0], 0, 0), Vector4t<T>(mat2x4[1], 0, 0), Vector4t<T>(mat2x4[2], 1, 0) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Matrix3x2t<T>& mat3x2) :
		data{ Vector4t<T>(mat3x2[0], 0), Vector4t<T>(mat3x2[1], 0), Vector4t<T>(0, 0, 1, 0) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Matrix3x3t<T>& mat3x3) :
		data{ Vector4t<T>(mat3x3[0], 0), Vector4t<T>(mat3x3[1], 0), Vector4t<T>(mat3x3[2], 0) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Matrix3x4t<T>& mat3x4) :
		data{ Vector4t<T>(mat3x4[0], 0), Vector4t<T>(mat3x4[1], 0), Vector4t<T>(mat3x4[2], 0) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Matrix4x2t<T>& mat4x2) :
		data{ Vector4t<T>(mat4x2[0]), Vector4t<T>(mat4x2[1]), Vector4t<T>(0, 0, 1, 0) } {	}
	template <typename T>		template <typename Ta>		Matrix4x3t<T>::Matrix4x3t(const Matrix4x3t<Ta>& mat4x3) :
		data{ Vector4t<T>(mat4x3[0]), Vector4t<T>(mat4x3[1]), Vector4t<T>(mat4x3[2]) } {	}
	template <typename T>									Matrix4x3t<T>::Matrix4x3t(const Matrix4x4t<T>& mat4x4) :
		data{ Vector4t<T>(mat4x4[0]), Vector4t<T>(mat4x4[1]), Vector4t<T>(mat4x4[2]) } {	}
	template <typename T>		Vector4t<T>&			Matrix4x3t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 3);
		return this->data[index];
	}
	template <typename T>		const Vector4t<T>&		Matrix4x3t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 3);
		return this->data[index];
	}
	template <typename T>		Matrix4x3t<T>&			Matrix4x3t<T>::operator +=(const T& scalar) {
		this->data[0] += scalar;
		this->data[1] += scalar;
		this->data[2] += scalar;

		return *this;
	}
	template <typename T>		Matrix4x3t<T>&			Matrix4x3t<T>::operator -=(const T& scalar) {
		this->data[0] -= scalar;
		this->data[1] -= scalar;
		this->data[2] -= scalar;

		return *this;
	}
	template <typename T>		Matrix4x3t<T>&			Matrix4x3t<T>::operator *=(const T& scalar) {
		this->data[0] *= scalar;
		this->data[1] *= scalar;
		this->data[2] *= scalar;

		return *this;
	}
	template <typename T>		Matrix4x3t<T>&			Matrix4x3t<T>::operator /=(const T& scalar) {
		this->data[0] /= scalar;
		this->data[1] /= scalar;
		this->data[2] /= scalar;

		return *this;
	}
	template <typename T>		Matrix4x3t<T>&			Matrix4x3t<T>::operator +=(const Matrix4x3t<T>& mat4x3) {
		this->data[0] += mat4x3[0];
		this->data[1] += mat4x3[1];
		this->data[2] += mat4x3[2];

		return *this;
	}
	template <typename T>		Matrix4x3t<T>&			Matrix4x3t<T>::operator -=(const Matrix4x3t<T>& mat4x3) {
		this->data[0] -= mat4x3[0];
		this->data[1] -= mat4x3[1];
		this->data[2] -= mat4x3[2];

		return *this;
	}
	template <typename T>		Matrix4x3t<T>&			Matrix4x3t<T>::operator *=(const Matrix3x3t<T>& mat3x3) {
		T x0 = this->data[0][0] * mat3x3[0][0] + this->data[1][0] * mat3x3[0][1] + this->data[2][0] * mat3x3[0][2], y0 = this->data[0][1] * mat3x3[0][0] + this->data[1][1] * mat3x3[0][1] + this->data[2][1] * mat3x3[0][2], z0 = this->data[0][2] * mat3x3[0][0] + this->data[1][2] * mat3x3[0][1] + this->data[2][2] * mat3x3[0][2], w0 = this->data[0][3] * mat3x3[0][0] + this->data[1][3] * mat3x3[0][1] + this->data[2][3] * mat3x3[0][2];
		T x1 = this->data[0][0] * mat3x3[1][0] + this->data[1][0] * mat3x3[1][1] + this->data[2][0] * mat3x3[1][2], y1 = this->data[0][1] * mat3x3[1][0] + this->data[1][1] * mat3x3[1][1] + this->data[2][1] * mat3x3[1][2], z1 = this->data[0][2] * mat3x3[1][0] + this->data[1][2] * mat3x3[1][1] + this->data[2][2] * mat3x3[1][2], w1 = this->data[0][3] * mat3x3[1][0] + this->data[1][3] * mat3x3[1][1] + this->data[2][3] * mat3x3[1][2];
		T x2 = this->data[0][0] * mat3x3[2][0] + this->data[1][0] * mat3x3[2][1] + this->data[2][0] * mat3x3[2][2], y2 = this->data[0][1] * mat3x3[2][0] + this->data[1][1] * mat3x3[2][1] + this->data[2][1] * mat3x3[2][2], z2 = this->data[0][2] * mat3x3[2][0] + this->data[1][2] * mat3x3[2][1] + this->data[2][2] * mat3x3[2][2], w2 = this->data[0][3] * mat3x3[2][0] + this->data[1][3] * mat3x3[2][1] + this->data[2][3] * mat3x3[2][2];

		this->data[0] = Vector4t<T>(x0, y0, z0, w0);
		this->data[1] = Vector4t<T>(x1, y1, z1, w1);
		this->data[2] = Vector4t<T>(x2, y2, z2, w2);

		return *this;
	}
	template <typename T>		Matrix4x3t<T>&			Matrix4x3t<T>::operator /=(const Matrix3x3t<T>& mat3x3) {
		this *= inverse(mat3x3);

		return *this;
	}
	template <typename T> template <typename Ta>	Matrix3x4t<Ta>		Matrix4x3t<T>::transpose(const Matrix4x3t<Ta>& mat4x3) {
		Matrix3x4t<Ta> transposition(
			mat4x3[0][1], mat4x3[0][2], mat4x3[0][3], mat4x3[0][4],
			mat4x3[1][1], mat4x3[1][2], mat4x3[1][3], mat4x3[1][4],
			mat4x3[2][1], mat4x3[2][2], mat4x3[2][3], mat4x3[2][4]
		);

		return transposition;
	}
	template <typename T>  template <typename Ta>		Matrix4x3t<Ta>		Matrix4x3t<T>::elementMultiplication(const Matrix4x3t<Ta>& mat4x3l, const Matrix4x3t<Ta>& mat4x3r) {
		Matrix4x3t<Ta> prod(
			mat4x3l[0][0] * mat4x3r[0][0], mat4x3l[1][0] * mat4x3r[1][0], mat4x3l[2][0] * mat4x3r[2][0],
			mat4x3l[0][1] * mat4x3r[0][1], mat4x3l[1][1] * mat4x3r[1][1], mat4x3l[2][1] * mat4x3r[2][1],
			mat4x3l[0][2] * mat4x3r[0][2], mat4x3l[1][2] * mat4x3r[1][2], mat4x3l[2][2] * mat4x3r[2][2],
			mat4x3l[0][3] * mat4x3r[0][3], mat4x3l[1][3] * mat4x3r[1][3], mat4x3l[2][3] * mat4x3r[2][3]
		);

		return prod;
	}
	template <typename T>  template <typename Ta>		Matrix4x3t<Ta>		Matrix4x3t<T>::elementDivision(const Matrix4x3t<Ta>& mat4x3l, const Matrix4x3t<Ta>& mat4x3r) {
		Matrix4x3t<Ta> quot(
			mat4x3l[0][0] / mat4x3r[0][0], mat4x3l[1][0] / mat4x3r[1][0], mat4x3l[2][0] / mat4x3r[2][0],
			mat4x3l[0][1] / mat4x3r[0][1], mat4x3l[1][1] / mat4x3r[1][1], mat4x3l[2][1] / mat4x3r[2][1],
			mat4x3l[0][2] / mat4x3r[0][2], mat4x3l[1][2] / mat4x3r[1][2], mat4x3l[2][2] / mat4x3r[2][2],
			mat4x3l[0][3] / mat4x3r[0][3], mat4x3l[1][3] / mat4x3r[1][3], mat4x3l[2][3] / mat4x3r[2][3]
		);

		return quot;
	}

	//Matrix4x4 Struct Definitions

	template <typename T>									Matrix4x4t<T>::Matrix4x4t() :
		data{ Vector4t<T>(1, 0, 0, 0), Vector4t<T>(0, 1, 0, 0), Vector4t<T>(0, 0, 1, 0), Vector4t<T>(0, 0, 0, 1) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Matrix4x4t<T>& mat4x4) :
		data{ Vector4t<T>(mat4x4[0]), Vector4t<T>(mat4x4[1]), Vector4t<T>(mat4x4[2]), Vector4t<T>(mat4x4[3]) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const T& scalar) :
		data{ Vector4t<T>(scalar, 0, 0, 0), Vector4t<T>(0, scalar, 0, 0), Vector4t<T>(0, 0, scalar, 0), Vector4t<T>(0, 0, 0, scalar) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Vector4t<T>& col0, const Vector4t<T>& col1, const Vector4t<T>& col2, const Vector4t<T>& col3) :
		data{ Vector4t<T>(col0), Vector4t<T>(col1), Vector4t<T>(col2), Vector4t<T>(col3) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(
		const T& x0, const T& x1, const T& x2, const T& x3,
		const T& y0, const T& y1, const T& y2, const T& y3,
		const T& z0, const T& z1, const T& z2, const T& z3,
		const T& w0, const T& w1, const T& w2, const T& w3) :
		data{ Vector4t<T>(x0, y0, z0, w0), Vector4t<T>(x1, y1, z1, w1), Vector4t<T>(x2, y2, z2, w2), Vector4t<T>(x3, y3, z3, w3) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Matrix2x2t<T>& mat2x2) :
		data{ Vector4t<T>(mat2x2[0], 0, 0), Vector4t<T>(mat2x2[1], 0, 0), Vector4t<T>(0, 0, 1, 0), Vector4t<T>(0, 0, 0, 1) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Matrix2x3t<T>& mat2x3) :
		data{ Vector4t<T>(mat2x3[0], 0, 0), Vector4t<T>(mat2x3[1], 0, 0), Vector4t<T>(mat2x3[2], 1, 0), Vector4t<T>(0, 0, 0, 1) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Matrix2x4t<T>& mat2x4) :
		data{ Vector4t<T>(mat2x4[0], 0, 0), Vector4t<T>(mat2x4[1], 0, 0), Vector4t<T>(mat2x4[2], 1, 0), Vector4t<T>(mat2x4[3], 0, 1) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Matrix3x2t<T>& mat3x2) :
		data{ Vector4t<T>(mat3x2[0], 0), Vector4t<T>(mat3x2[1], 0), Vector4t<T>(0, 0, 1, 0), Vector4t<T>(0, 0, 0, 1) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Matrix3x3t<T>& mat3x3) :
		data{ Vector4t<T>(mat3x3[0], 0), Vector4t<T>(mat3x3[1], 0), Vector4t<T>(mat3x3[2], 0), Vector4t<T>(0, 0, 0, 1) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Matrix3x4t<T>& mat3x4) :
		data{ Vector4t<T>(mat3x4[0], 0), Vector4t<T>(mat3x4[1], 0), Vector4t<T>(mat3x4[2], 0), Vector4t<T>(mat3x4[3], 1) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Matrix4x2t<T>& mat4x2) :
		data{ Vector4t<T>(mat4x2[0]), Vector4t<T>(mat4x2[1]), Vector4t<T>(0, 0, 1, 0), Vector4t<T>(0, 0, 0, 1) } {	}
	template <typename T>									Matrix4x4t<T>::Matrix4x4t(const Matrix4x3t<T>& mat4x3) :
		data{ Vector4t<T>(mat4x3[0]), Vector4t<T>(mat4x3[1]), Vector4t<T>(mat4x3[2]), Vector4t<T>(0, 0, 0, 1) } {	}
	template <typename T>		template <typename Ta>		Matrix4x4t<T>::Matrix4x4t(const Matrix4x4t<Ta>& mat4x4) :
		data{ Vector4t<T>(mat4x4[0]), Vector4t<T>(mat4x4[1]), Vector4t<T>(mat4x4[2]), Vector4t<T>(mat4x4[3]) } {	}
	template <typename T>		Vector4t<T>&			Matrix4x4t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 4);
		return this->data[index];
	}
	template <typename T>		const Vector4t<T>&		Matrix4x4t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 4);
		return this->data[index];
	}
	template <typename T>		Matrix4x4t<T>&			Matrix4x4t<T>::operator +=(const T& scalar) {
		this->data[0] += scalar;
		this->data[1] += scalar;
		this->data[2] += scalar;
		this->data[3] += scalar;

		return *this;
	}
	template <typename T>		Matrix4x4t<T>&			Matrix4x4t<T>::operator -=(const T& scalar) {
		this->data[0] -= scalar;
		this->data[1] -= scalar;
		this->data[2] -= scalar;
		this->data[3] -= scalar;

		return *this;
	}
	template <typename T>		Matrix4x4t<T>&			Matrix4x4t<T>::operator *=(const T& scalar) {
		this->data[0] *= scalar;
		this->data[1] *= scalar;
		this->data[2] *= scalar;
		this->data[3] *= scalar;

		return *this;
	}
	template <typename T>		Matrix4x4t<T>&			Matrix4x4t<T>::operator /=(const T& scalar) {
		this->data[0] /= scalar;
		this->data[1] /= scalar;
		this->data[2] /= scalar;
		this->data[3] /= scalar;

		return *this;
	}
	template <typename T>		Matrix4x4t<T>&			Matrix4x4t<T>::operator +=(const Matrix4x4t<T>& mat4x4) {
		this->data[0] += mat4x4[0];
		this->data[1] += mat4x4[1];
		this->data[2] += mat4x4[2];
		this->data[3] += mat4x4[3];

		return *this;
	}
	template <typename T>		Matrix4x4t<T>&			Matrix4x4t<T>::operator -=(const Matrix4x4t<T>& mat4x4) {
		this->data[0] -= mat4x4[0];
		this->data[1] -= mat4x4[1];
		this->data[2] -= mat4x4[2];
		this->data[3] -= mat4x4[3];

		return *this;
	}
	template <typename T>		Matrix4x4t<T>&			Matrix4x4t<T>::operator *=(const Matrix4x4t<T>& mat4x4) {
		T x0 = this->data[0][0] * mat4x4[0][0] + this->data[1][0] * mat4x4[0][1] + this->data[2][0] * mat4x4[0][2] + this->data[3][0] * mat4x4[0][3], y0 = this->data[0][1] * mat4x4[0][0] + this->data[1][1] * mat4x4[0][1] + this->data[2][1] * mat4x4[0][2] + this->data[3][1] * mat4x4[0][3], z0 = this->data[0][2] * mat4x4[0][0] + this->data[1][2] * mat4x4[0][1] + this->data[2][2] * mat4x4[0][2] + this->data[3][2] * mat4x4[0][3], w0 = this->data[0][3] * mat4x4[0][0] + this->data[1][3] * mat4x4[0][1] + this->data[2][3] * mat4x4[0][2] + this->data[3][3] * mat4x4[0][3];
		T x1 = this->data[0][0] * mat4x4[1][0] + this->data[1][0] * mat4x4[1][1] + this->data[2][0] * mat4x4[1][2] + this->data[3][0] * mat4x4[1][3], y1 = this->data[0][1] * mat4x4[1][0] + this->data[1][1] * mat4x4[1][1] + this->data[2][1] * mat4x4[1][2] + this->data[3][1] * mat4x4[1][3], z1 = this->data[0][2] * mat4x4[1][0] + this->data[1][2] * mat4x4[1][1] + this->data[2][2] * mat4x4[1][2] + this->data[3][2] * mat4x4[1][3], w1 = this->data[0][3] * mat4x4[1][0] + this->data[1][3] * mat4x4[1][1] + this->data[2][3] * mat4x4[1][2] + this->data[3][3] * mat4x4[1][3];
		T x2 = this->data[0][0] * mat4x4[2][0] + this->data[1][0] * mat4x4[2][1] + this->data[2][0] * mat4x4[2][2] + this->data[3][0] * mat4x4[2][3], y2 = this->data[0][1] * mat4x4[2][0] + this->data[1][1] * mat4x4[2][1] + this->data[2][1] * mat4x4[2][2] + this->data[3][1] * mat4x4[2][3], z2 = this->data[0][2] * mat4x4[2][0] + this->data[1][2] * mat4x4[2][1] + this->data[2][2] * mat4x4[2][2] + this->data[3][2] * mat4x4[2][3], w2 = this->data[0][3] * mat4x4[2][0] + this->data[1][3] * mat4x4[2][1] + this->data[2][3] * mat4x4[2][2] + this->data[3][3] * mat4x4[2][3];
		T x3 = this->data[0][0] * mat4x4[3][0] + this->data[1][0] * mat4x4[3][1] + this->data[2][0] * mat4x4[3][2] + this->data[3][0] * mat4x4[3][3], y3 = this->data[0][1] * mat4x4[3][0] + this->data[1][1] * mat4x4[3][1] + this->data[2][1] * mat4x4[3][2] + this->data[3][1] * mat4x4[3][3], z3 = this->data[0][2] * mat4x4[3][0] + this->data[1][2] * mat4x4[3][1] + this->data[2][2] * mat4x4[3][2] + this->data[3][2] * mat4x4[3][3], w3 = this->data[0][3] * mat4x4[3][0] + this->data[1][3] * mat4x4[3][1] + this->data[2][3] * mat4x4[3][2] + this->data[3][3] * mat4x4[3][3];

		this->data[0] = Vector4t<T>(x0, y0, z0, w0);
		this->data[1] = Vector4t<T>(x1, y1, z1, w1);
		this->data[2] = Vector4t<T>(x2, y2, z2, w2);
		this->data[3] = Vector4t<T>(x3, y3, z3, w3);

		return *this;
	}
	template <typename T>		Matrix4x4t<T>&			Matrix4x4t<T>::operator /=(const Matrix4x4t<T>& mat4x4) {
		this *= inverse(mat4x4);

		return *this;
	}
	template <typename T> template <typename Ta>	Matrix4x4t<Ta>			Matrix4x4t<T>::transpose(const Matrix4x4t<Ta>& mat4x4) {
		Matrix4x4t<Ta> transposition(
			mat4x4[0][0], mat4x4[0][1], mat4x4[0][2], mat4x4[0][3],
			mat4x4[1][0], mat4x4[1][1], mat4x4[1][2], mat4x4[1][3],
			mat4x4[2][0], mat4x4[2][1], mat4x4[2][2], mat4x4[2][3],
			mat4x4[3][0], mat4x4[3][1], mat4x4[3][2], mat4x4[3][3]
		);

		return transposition;
	}
	template <typename T> template <typename Ta>	Ta						Matrix4x4t<T>::determinant(const Matrix4x4t<Ta>& mat4x4) {
		Ta det =
			mat4x4[0][0] * (mat4x4[1][1] * (mat4x4[2][2] * mat4x4[3][3] - mat4x4[3][2] * mat4x4[2][3]) - mat4x4[2][1] * (mat4x4[1][2] * mat4x4[3][3] - mat4x4[3][2] * mat4x4[1][3]) + mat4x4[3][1] * (mat4x4[1][2] * mat4x4[2][3] - mat4x4[2][2] * mat4x4[1][3])) -
			mat4x4[1][0] * (mat4x4[0][1] * (mat4x4[2][2] * mat4x4[3][3] - mat4x4[3][2] * mat4x4[2][3]) - mat4x4[2][1] * (mat4x4[0][2] * mat4x4[3][3] - mat4x4[3][2] * mat4x4[0][3]) + mat4x4[3][1] * (mat4x4[0][2] * mat4x4[2][3] - mat4x4[2][2] * mat4x4[0][3])) +
			mat4x4[2][0] * (mat4x4[0][1] * (mat4x4[1][2] * mat4x4[3][3] - mat4x4[3][2] * mat4x4[1][3]) - mat4x4[1][1] * (mat4x4[0][2] * mat4x4[3][3] - mat4x4[3][2] * mat4x4[0][3]) + mat4x4[3][1] * (mat4x4[0][2] * mat4x4[1][3] - mat4x4[1][2] * mat4x4[0][3])) -
			mat4x4[3][0] * (mat4x4[0][1] * (mat4x4[1][2] * mat4x4[2][3] - mat4x4[2][2] * mat4x4[1][3]) - mat4x4[1][1] * (mat4x4[0][2] * mat4x4[2][3] - mat4x4[2][2] * mat4x4[0][3]) + mat4x4[2][1] * (mat4x4[0][2] * mat4x4[1][3] - mat4x4[1][2] * mat4x4[0][3]));
		;

		return det;
	}
	template <typename T> template <typename Ta>	Matrix4x4t<float>		Matrix4x4t<T>::inverse(const Matrix4x4t<Ta>& mat4x4) {
		assert(Matrix4x4t<Ta>::determinant(mat4x4) != 0);

		Matrix4x4t<float> inverse = Matrix4x4t<T>::transpose(Matrix4x4t<Ta>(
			Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[1][1], mat4x4[2][1], mat4x4[3][1], mat4x4[1][2], mat4x4[2][2], mat4x4[3][2], mat4x4[1][3], mat4x4[2][3], mat4x4[3][3])), -Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][1], mat4x4[2][1], mat4x4[3][1], mat4x4[0][2], mat4x4[2][2], mat4x4[3][2], mat4x4[0][3], mat4x4[2][3], mat4x4[3][3])), Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][1], mat4x4[1][1], mat4x4[3][1], mat4x4[0][2], mat4x4[1][2], mat4x4[3][2], mat4x4[0][3], mat4x4[1][3], mat4x4[3][3])), -Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][1], mat4x4[1][1], mat4x4[2][1], mat4x4[0][2], mat4x4[1][2], mat4x4[2][2], mat4x4[0][3], mat4x4[1][3], mat4x4[2][3])),
			-Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[1][0], mat4x4[2][0], mat4x4[3][0], mat4x4[1][2], mat4x4[2][2], mat4x4[3][2], mat4x4[1][3], mat4x4[2][3], mat4x4[3][3])), Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][0], mat4x4[2][0], mat4x4[3][0], mat4x4[0][2], mat4x4[2][2], mat4x4[3][2], mat4x4[0][3], mat4x4[2][3], mat4x4[3][3])), -Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][0], mat4x4[1][0], mat4x4[3][0], mat4x4[0][2], mat4x4[1][2], mat4x4[3][2], mat4x4[0][3], mat4x4[1][3], mat4x4[3][3])), Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][0], mat4x4[1][0], mat4x4[2][0], mat4x4[0][2], mat4x4[1][2], mat4x4[2][2], mat4x4[0][3], mat4x4[1][3], mat4x4[2][3])),
			Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[1][0], mat4x4[2][0], mat4x4[3][0], mat4x4[1][1], mat4x4[2][1], mat4x4[3][1], mat4x4[1][3], mat4x4[2][3], mat4x4[3][3])), -Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][0], mat4x4[2][0], mat4x4[3][0], mat4x4[0][1], mat4x4[2][1], mat4x4[3][1], mat4x4[0][3], mat4x4[2][3], mat4x4[3][3])), Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][0], mat4x4[1][0], mat4x4[3][0], mat4x4[0][1], mat4x4[1][1], mat4x4[3][1], mat4x4[0][3], mat4x4[1][3], mat4x4[3][3])), -Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][0], mat4x4[1][0], mat4x4[2][0], mat4x4[0][1], mat4x4[1][1], mat4x4[2][1], mat4x4[0][3], mat4x4[1][3], mat4x4[2][3])),
			-Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[1][0], mat4x4[2][0], mat4x4[3][0], mat4x4[1][1], mat4x4[2][1], mat4x4[3][1], mat4x4[1][2], mat4x4[2][2], mat4x4[3][2])), Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][0], mat4x4[2][0], mat4x4[3][0], mat4x4[0][1], mat4x4[2][1], mat4x4[3][1], mat4x4[0][2], mat4x4[2][2], mat4x4[3][2])), -Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][0], mat4x4[1][0], mat4x4[3][0], mat4x4[0][1], mat4x4[1][1], mat4x4[3][1], mat4x4[0][2], mat4x4[1][2], mat4x4[3][2])), Matrix3x3t<Ta>::determinant(Matrix3x3t<Ta>(mat4x4[0][0], mat4x4[1][0], mat4x4[2][0], mat4x4[0][1], mat4x4[1][1], mat4x4[2][1], mat4x4[0][2], mat4x4[1][2], mat4x4[2][2]))
			)) * (1 / Matrix4x4t<Ta>::determinant(mat4x4));

		return inverse;
	}
	template <typename T>  template <typename Ta>		Matrix4x4t<Ta>		Matrix4x4t<T>::elementMultiplication(const Matrix4x4t<Ta>& mat4x4l, const Matrix4x4t<Ta>& mat4x4r) {
		Matrix4x4t<Ta> prod(
			mat4x4l[0][0] * mat4x4r[0][0], mat4x4l[1][0] * mat4x4r[1][0], mat4x4l[2][0] * mat4x4r[2][0], mat4x4l[3][0] * mat4x4r[3][0],
			mat4x4l[0][1] * mat4x4r[0][1], mat4x4l[1][1] * mat4x4r[1][1], mat4x4l[2][1] * mat4x4r[2][1], mat4x4l[3][1] * mat4x4r[3][1],
			mat4x4l[0][2] * mat4x4r[0][2], mat4x4l[1][2] * mat4x4r[1][2], mat4x4l[2][2] * mat4x4r[2][2], mat4x4l[3][2] * mat4x4r[3][2],
			mat4x4l[0][3] * mat4x4r[0][3], mat4x4l[1][3] * mat4x4r[1][3], mat4x4l[2][3] * mat4x4r[2][3], mat4x4l[3][3] * mat4x4r[3][3]
		);

		return prod;
	}
	template <typename T>  template <typename Ta>		Matrix4x4t<Ta>		Matrix4x4t<T>::elementDivision(const Matrix4x4t<Ta>& mat4x4l, const Matrix4x4t<Ta>& mat4x4r) {
		Matrix4x4t<Ta> quot(
			mat4x4l[0][0] / mat4x4r[0][0], mat4x4l[1][0] / mat4x4r[1][0], mat4x4l[2][0] / mat4x4r[2][0], mat4x4l[3][0] / mat4x4r[3][0],
			mat4x4l[0][1] / mat4x4r[0][1], mat4x4l[1][1] / mat4x4r[1][1], mat4x4l[2][1] / mat4x4r[2][1], mat4x4l[3][1] / mat4x4r[3][1],
			mat4x4l[0][2] / mat4x4r[0][2], mat4x4l[1][2] / mat4x4r[1][2], mat4x4l[2][2] / mat4x4r[2][2], mat4x4l[3][2] / mat4x4r[3][2],
			mat4x4l[0][3] / mat4x4r[0][3], mat4x4l[1][3] / mat4x4r[1][3], mat4x4l[2][3] / mat4x4r[2][3], mat4x4l[3][3] / mat4x4r[3][3]
		);

		return quot;
	}


	//Matrix2x2 Arithmitic Operators

	template <typename T>		Matrix2x2t<T>		operator -(const Matrix2x2t<T>& mat2x2) {
		Matrix2x2t<T> negative = mat2x2;

		negative[0] = -negative[0];
		negative[1] = -negative[1];

		return negative;
	}
	template <typename T>		Matrix2x2t<T>		operator +(const Matrix2x2t<T>& mat2x2, const T& scalar) {
		Matrix2x2t<T> sum = mat2x2;

		sum[0] += scalar;
		sum[1] += scalar;

		return sum;
	}
	template <typename T>		Matrix2x2t<T>		operator -(const Matrix2x2t<T>& mat2x2, const T& scalar) {
		Matrix2x2t<T> diff = mat2x2;

		diff[0] -= scalar;
		diff[1] -= scalar;

		return diff;
	}
	template <typename T>		Matrix2x2t<T>		operator *(const Matrix2x2t<T>& mat2x2, const T& scalar) {
		Matrix2x2t<T> prod = mat2x2;

		prod[0] *= scalar;
		prod[1] *= scalar;

		return prod;
	}
	template <typename T>		Matrix2x2t<T>		operator /(const Matrix2x2t<T>& mat2x2, const T& scalar) {
		Matrix2x2t<T> quot = mat2x2;

		quot[0] /= scalar;
		quot[1] /= scalar;

		return quot;
	}
	template <typename T>		Matrix2x2t<T>		operator +(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r) {
		Matrix2x2t<T> sum = mat2x2l;

		sum[0] += mat2x2r[0];
		sum[1] += mat2x2r[1];

		return sum;
	}
	template <typename T>		Matrix2x2t<T>		operator -(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r) {
		Matrix2x2t<T> diff = mat2x2l;

		diff[0] -= mat2x2r[0];
		diff[1] -= mat2x2r[1];

		return diff;
	}
	template <typename T>		Vector2t<T>			operator *(const Matrix2x2t<T>& mat2x2, const Vector2t<T>& vec2) {
		Vector2t<T> prod(
			mat2x2[0][0] * vec2[0] + mat2x2[1][0] * vec2[1],
			mat2x2[0][1] * vec2[0] + mat2x2[1][1] * vec2[1]);

		return prod;
	}
	template <typename T>		Matrix2x2t<T>		operator *(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r) {
		Matrix2x2t<T> prod(
			mat2x2l[0][0] * mat2x2r[0][0] + mat2x2l[1][0] * mat2x2r[0][1], mat2x2l[0][0] * mat2x2r[1][0] + mat2x2l[1][0] * mat2x2r[1][1],
			mat2x2l[0][1] * mat2x2r[0][0] + mat2x2l[1][1] * mat2x2r[0][1], mat2x2l[0][1] * mat2x2r[1][0] + mat2x2l[1][1] * mat2x2r[1][1]);

		return prod;
	}
	template <typename T>		Matrix2x3t<T>		operator *(const Matrix2x2t<T>& mat2x2, const Matrix2x3t<T>& mat2x3) {
		Matrix2x3t<T> prod(
			mat2x2[0][0] * mat2x3[0][0] + mat2x2[1][0] * mat2x3[0][1], mat2x2[0][0] * mat2x3[1][0] + mat2x2[1][0] * mat2x3[1][1], mat2x2[0][0] * mat2x3[2][0] + mat2x2[1][0] * mat2x3[2][1],
			mat2x2[0][1] * mat2x3[0][0] + mat2x2[1][1] * mat2x3[0][1], mat2x2[0][1] * mat2x3[1][0] + mat2x2[1][1] * mat2x3[1][1], mat2x2[0][1] * mat2x3[2][0] + mat2x2[1][1] * mat2x3[2][1]);

		return prod;
	}
	template <typename T>		Matrix2x4t<T>		operator *(const Matrix2x2t<T>& mat2x2, const Matrix2x4t<T>& mat2x4) {
		Matrix2x4t<T> prod(
			mat2x2[0][0] * mat2x4[0][0] + mat2x2[1][0] * mat2x4[0][1], mat2x2[0][0] * mat2x4[1][0] + mat2x2[1][0] * mat2x4[1][1], mat2x2[0][0] * mat2x4[2][0] + mat2x2[1][0] * mat2x4[2][1], mat2x2[0][0] * mat2x4[3][0] + mat2x2[1][0] * mat2x4[3][1],
			mat2x2[0][1] * mat2x4[0][0] + mat2x2[1][1] * mat2x4[0][1], mat2x2[0][1] * mat2x4[1][0] + mat2x2[1][1] * mat2x4[1][1], mat2x2[0][1] * mat2x4[2][0] + mat2x2[1][1] * mat2x4[2][1], mat2x2[0][1] * mat2x4[3][0] + mat2x2[1][1] * mat2x4[3][1]);

		return prod;
	}
	template <typename T>		Matrix2x2t<T>		operator /(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r) {
		Matrix2x2t<T> quot = mat2x2l * inverse(mat2x2r);

		return quot;
	}

	//Matrix2x3 Arithmitic Operators

	template <typename T>		Matrix2x3t<T>		operator -(const Matrix2x3t<T>& mat2x3) {
		Matrix2x3t<T> negative = mat2x3;

		negative[0] = -negative[0];
		negative[1] = -negative[1];
		negative[2] = -negative[2];

		return negative;
	}
	template <typename T>		Matrix2x3t<T>		operator +(const Matrix2x3t<T>& mat2x3, const T& scalar) {
		Matrix2x3t<T> sum = mat2x3;

		sum[0] += scalar;
		sum[1] += scalar;
		sum[2] += scalar;

		return sum;
	}
	template <typename T>		Matrix2x3t<T>		operator -(const Matrix2x3t<T>& mat2x3, const T& scalar) {
		Matrix2x3t<T> diff = mat2x3;

		diff[0] -= scalar;
		diff[1] -= scalar;
		diff[2] -= scalar;

		return diff;
	}
	template <typename T>		Matrix2x3t<T>		operator *(const Matrix2x3t<T>& mat2x3, const T& scalar) {
		Matrix2x3t<T> prod = mat2x3;

		prod[0] *= scalar;
		prod[1] *= scalar;
		prod[2] *= scalar;

		return prod;
	}
	template <typename T>		Matrix2x3t<T>		operator /(const Matrix2x3t<T>& mat2x3, const T& scalar) {
		Matrix2x3t<T> quot = mat2x3;

		quot[0] /= scalar;
		quot[1] /= scalar;
		quot[2] /= scalar;

		return quot;
	}
	template <typename T>		Matrix2x3t<T>		operator +(const Matrix2x3t<T>& mat2x3l, const Matrix2x3t<T>& mat2x3r) {
		Matrix2x3t<T> sum = mat2x3l;

		sum[0] += mat2x3r[0];
		sum[1] += mat2x3r[1];
		sum[2] += mat2x3r[2];

		return sum;
	}
	template <typename T>		Matrix2x3t<T>		operator -(const Matrix2x3t<T>& mat2x3l, const Matrix2x3t<T>& mat2x3r) {
		Matrix2x3t<T> diff = mat2x3l;

		diff[0] -= mat2x3r[0];
		diff[1] -= mat2x3r[1];
		diff[2] -= mat2x3r[2];

		return diff;
	}
	template <typename T>		Vector2t<T>			operator *(const Matrix2x3t<T>& mat2x3, const Vector3t<T>& vec3) {
		Vector2t<T> prod(
			mat2x3[0][0] * vec3[0] + mat2x3[1][0] * vec3[1] + mat2x3[2][0] * vec3[2],
			mat2x3[0][1] * vec3[0] + mat2x3[1][1] * vec3[1] + mat2x3[2][1] * vec3[2]);

		return prod;
	}
	template <typename T>		Matrix2x2t<T>		operator *(const Matrix2x3t<T>& mat2x3, const Matrix3x2t<T>& mat3x2) {
		Matrix2x2t<T> prod(
			mat2x3[0][0] * mat3x2[0][0] + mat2x3[1][0] * mat3x2[0][1] + mat2x3[2][0] * mat3x2[0][2], mat2x3[0][0] * mat3x2[1][0] + mat2x3[1][0] * mat3x2[1][1] + mat2x3[2][0] * mat3x2[1][2],
			mat2x3[0][1] * mat3x2[0][0] + mat2x3[1][1] * mat3x2[0][1] + mat2x3[2][1] * mat3x2[0][2], mat2x3[0][1] * mat3x2[1][0] + mat2x3[1][1] * mat3x2[1][1] + mat2x3[2][1] * mat3x2[1][2]
		);

		return prod;
	}
	template <typename T>		Matrix2x3t<T>		operator *(const Matrix2x3t<T>& mat2x3, const Matrix3x3t<T>& mat3x3) {
		Matrix2x3t<T> prod(
			mat2x3[0][0] * mat3x3[0][0] + mat2x3[1][0] * mat3x3[0][1] + mat2x3[2][0] * mat3x3[0][2], mat2x3[0][0] * mat3x3[1][0] + mat2x3[1][0] * mat3x3[1][1] + mat2x3[2][0] * mat3x3[1][2], mat2x3[0][0] * mat3x3[2][0] + mat2x3[1][0] * mat3x3[2][1] + mat2x3[2][0] * mat3x3[2][2],
			mat2x3[0][1] * mat3x3[0][0] + mat2x3[1][1] * mat3x3[0][1] + mat2x3[2][1] * mat3x3[0][2], mat2x3[0][1] * mat3x3[1][0] + mat2x3[1][1] * mat3x3[1][1] + mat2x3[2][1] * mat3x3[1][2], mat2x3[0][1] * mat3x3[2][0] + mat2x3[1][1] * mat3x3[2][1] + mat2x3[2][1] * mat3x3[2][2]
		);

		return prod;
	}
	template <typename T>		Matrix2x4t<T>		operator *(const Matrix2x3t<T>& mat2x3, const Matrix3x4t<T>& mat3x4) {
		Matrix2x4t<T> prod(
			mat2x3[0][0] * mat3x4[0][0] + mat2x3[1][0] * mat3x4[0][1] + mat2x3[2][0] * mat3x4[0][2], mat2x3[0][0] * mat3x4[1][0] + mat2x3[1][0] * mat3x4[1][1] + mat2x3[2][0] * mat3x4[1][2], mat2x3[0][0] * mat3x4[2][0] + mat2x3[1][0] * mat3x4[2][1] + mat2x3[2][0] * mat3x4[2][2], mat2x3[0][0] * mat3x4[3][0] + mat2x3[1][0] * mat3x4[3][1] + mat2x3[2][0] * mat3x4[3][2],
			mat2x3[0][1] * mat3x4[0][0] + mat2x3[1][1] * mat3x4[0][1] + mat2x3[2][1] * mat3x4[0][2], mat2x3[0][1] * mat3x4[1][0] + mat2x3[1][1] * mat3x4[1][1] + mat2x3[2][1] * mat3x4[1][2], mat2x3[0][1] * mat3x4[2][0] + mat2x3[1][1] * mat3x4[2][1] + mat2x3[2][1] * mat3x4[2][2], mat2x3[0][1] * mat3x4[3][0] + mat2x3[1][1] * mat3x4[3][1] + mat2x3[2][1] * mat3x4[3][2]
		);

		return prod;
	}
	template <typename T>		Matrix2x3t<T>		operator /(const Matrix2x3t<T>& mat2x3, const Matrix3x3t<T>& mat3x3) {
		Matrix2x3t<T> quot = mat2x3 * inverse(mat3x3);

		return quot;
	}

	//Matrix2x4 Arithmitic Operators

	template <typename T>		Matrix2x4t<T>		operator -(const Matrix2x4t<T>& mat2x4) {
		Matrix2x4t<T> negative = mat2x4;

		negative[0] = -negative[0];
		negative[1] = -negative[1];
		negative[2] = -negative[2];
		negative[3] = -negative[3];

		return negative;
	}
	template <typename T>		Matrix2x4t<T>		operator +(const Matrix2x4t<T>& mat2x4, const T& scalar) {
		Matrix2x4t<T> sum = mat2x4;

		sum[0] += scalar;
		sum[1] += scalar;
		sum[2] += scalar;
		sum[3] += scalar;

		return sum;
	}
	template <typename T>		Matrix2x4t<T>		operator -(const Matrix2x4t<T>& mat2x4, const T& scalar) {
		Matrix2x4t<T> diff = mat2x4;

		diff[0] -= scalar;
		diff[1] -= scalar;
		diff[2] -= scalar;
		diff[3] -= scalar;

		return diff;
	}
	template <typename T>		Matrix2x4t<T>		operator *(const Matrix2x4t<T>& mat2x4, const T& scalar) {
		Matrix2x4t<T> prod = mat2x4;

		prod[0] *= scalar;
		prod[1] *= scalar;
		prod[2] *= scalar;
		prod[3] *= scalar;

		return prod;
	}
	template <typename T>		Matrix2x4t<T>		operator /(const Matrix2x4t<T>& mat2x4, const T& scalar) {
		Matrix2x4t<T> quot = mat2x4;

		quot[0] /= scalar;
		quot[1] /= scalar;
		quot[2] /= scalar;
		quot[3] /= scalar;

		return quot;
	}
	template <typename T>		Matrix2x4t<T>		operator +(const Matrix2x4t<T>& mat2x4l, const Matrix2x4t<T>& mat2x4r) {
		Matrix2x4t<T> sum = mat2x4l;

		sum[0] += mat2x4r[0];
		sum[1] += mat2x4r[1];
		sum[2] += mat2x4r[2];
		sum[3] += mat2x4r[3];

		return sum;
	}
	template <typename T>		Matrix2x4t<T>		operator -(const Matrix2x4t<T>& mat2x4l, const Matrix2x4t<T>& mat2x4r) {
		Matrix2x4t<T> diff = mat2x4l;

		diff[0] -= mat2x4r[0];
		diff[1] -= mat2x4r[1];
		diff[2] -= mat2x4r[2];
		diff[3] -= mat2x4r[3];

		return diff;
	}
	template <typename T>		Vector2t<T>			operator *(const Matrix2x4t<T>& mat2x4, const Vector4t<T>& vec4) {
		Vector2t<T> prod(
			mat2x4[0][0] * vec4[0] + mat2x4[1][0] * vec4[1] + mat2x4[2][0] * vec4[2] + mat2x4[3][0] * vec4[3],
			mat2x4[0][1] * vec4[0] + mat2x4[1][1] * vec4[1] + mat2x4[2][1] * vec4[2] + mat2x4[3][1] * vec4[3]
		);

		return prod;
	}
	template <typename T>		Matrix2x2t<T>		operator *(const Matrix2x4t<T>& mat2x4, const Matrix4x2t<T>& mat4x2) {
		Matrix2x2t<T> prod(
			mat2x4[0][0] * mat4x2[0][0] + mat2x4[1][0] * mat4x2[0][1] + mat2x4[2][0] * mat4x2[0][2] + mat2x4[3][0] * mat4x2[0][3], mat2x4[0][0] * mat4x2[1][0] + mat2x4[1][0] * mat4x2[1][1] + mat2x4[2][0] * mat4x2[1][2] + mat2x4[3][0] * mat4x2[1][3],
			mat2x4[0][1] * mat4x2[0][0] + mat2x4[1][1] * mat4x2[0][1] + mat2x4[2][1] * mat4x2[0][2] + mat2x4[3][1] * mat4x2[0][3], mat2x4[0][1] * mat4x2[1][0] + mat2x4[1][1] * mat4x2[1][1] + mat2x4[2][1] * mat4x2[1][2] + mat2x4[3][1] * mat4x2[1][3]
		);

		return prod;
	}
	template <typename T>		Matrix2x3t<T>		operator *(const Matrix2x4t<T>& mat2x4, const Matrix4x3t<T>& mat4x3) {
		Matrix2x3t<T> prod(
			mat2x4[0][0] * mat4x3[0][0] + mat2x4[1][0] * mat4x3[0][1] + mat2x4[2][0] * mat4x3[0][2] + mat2x4[3][0] * mat4x3[0][3], mat2x4[0][0] * mat4x3[1][0] + mat2x4[1][0] * mat4x3[1][1] + mat2x4[2][0] * mat4x3[1][2] + mat2x4[3][0] * mat4x3[1][3], mat2x4[0][0] * mat4x3[2][0] + mat2x4[1][0] * mat4x3[2][1] + mat2x4[2][0] * mat4x3[2][2] + mat2x4[3][0] * mat4x3[2][3],
			mat2x4[0][1] * mat4x3[0][0] + mat2x4[1][1] * mat4x3[0][1] + mat2x4[2][1] * mat4x3[0][2] + mat2x4[3][1] * mat4x3[0][3], mat2x4[0][1] * mat4x3[1][0] + mat2x4[1][1] * mat4x3[1][1] + mat2x4[2][1] * mat4x3[1][2] + mat2x4[3][1] * mat4x3[1][3], mat2x4[0][1] * mat4x3[2][0] + mat2x4[1][1] * mat4x3[2][1] + mat2x4[2][1] * mat4x3[2][2] + mat2x4[3][1] * mat4x3[2][3]
		);

		return prod;
	}
	template <typename T>		Matrix2x4t<T>		operator *(const Matrix2x4t<T>& mat2x4, const Matrix4x4t<T>& mat4x4) {
		Matrix2x4t<T> prod(
			mat2x4[0][0] * mat4x4[0][0] + mat2x4[1][0] * mat4x4[0][1] + mat2x4[2][0] * mat4x4[0][2] + mat2x4[3][0] * mat4x4[0][3], mat2x4[0][0] * mat4x4[1][0] + mat2x4[1][0] * mat4x4[1][1] + mat2x4[2][0] * mat4x4[1][2] + mat2x4[3][0] * mat4x4[1][3], mat2x4[0][0] * mat4x4[2][0] + mat2x4[1][0] * mat4x4[2][1] + mat2x4[2][0] * mat4x4[2][2] + mat2x4[3][0] * mat4x4[2][3], mat2x4[0][0] * mat4x4[3][0] + mat2x4[1][0] * mat4x4[3][1] + mat2x4[2][0] * mat4x4[3][2] + mat2x4[3][0] * mat4x4[3][3],
			mat2x4[0][1] * mat4x4[0][0] + mat2x4[1][1] * mat4x4[0][1] + mat2x4[2][1] * mat4x4[0][2] + mat2x4[3][1] * mat4x4[0][3], mat2x4[0][1] * mat4x4[1][0] + mat2x4[1][1] * mat4x4[1][1] + mat2x4[2][1] * mat4x4[1][2] + mat2x4[3][1] * mat4x4[1][3], mat2x4[0][1] * mat4x4[2][0] + mat2x4[1][1] * mat4x4[2][1] + mat2x4[2][1] * mat4x4[2][2] + mat2x4[3][1] * mat4x4[2][3], mat2x4[0][1] * mat4x4[3][0] + mat2x4[1][1] * mat4x4[3][1] + mat2x4[2][1] * mat4x4[3][2] + mat2x4[3][1] * mat4x4[3][3]
		);

		return prod;
	}
	template <typename T>		Matrix2x4t<T>		operator /(const Matrix2x4t<T>& mat2x4, const Matrix4x4t<T>& mat4x4) {
		Matrix2x4t<T> quot = mat2x4 * inverse(mat4x4);

		return quot;
	}

	//Matrix3x2 Arithmitic Operators

	template <typename T>		Matrix3x2t<T>		operator -(const Matrix3x2t<T>& mat3x2) {
		Matrix3x2t<T> negative = mat3x2;

		negative[0] = -negative[0];
		negative[1] = -negative[1];

		return negative;
	}
	template <typename T>		Matrix3x2t<T>		operator +(const Matrix3x2t<T>& mat3x2, const T& scalar) {
		Matrix3x2t<T> sum = mat3x2;

		sum[0] += scalar;
		sum[1] += scalar;

		return sum;
	}
	template <typename T>		Matrix3x2t<T>		operator -(const Matrix3x2t<T>& mat3x2, const T& scalar) {
		Matrix3x2t<T> diff = mat3x2;

		diff[0] -= scalar;
		diff[1] -= scalar;

		return diff;
	}
	template <typename T>		Matrix3x2t<T>		operator *(const Matrix3x2t<T>& mat3x2, const T& scalar) {
		Matrix3x2t<T> prod = mat3x2;

		prod[0] *= scalar;
		prod[1] *= scalar;

		return prod;
	}
	template <typename T>		Matrix3x2t<T>		operator /(const Matrix3x2t<T>& mat3x2, const T& scalar) {
		Matrix3x2t<T> quot = mat3x2;

		quot[0] /= scalar;
		quot[1] /= scalar;

		return
	}
	template <typename T>		Matrix3x2t<T>		operator +(const Matrix3x2t<T>& mat3x2l, const Matrix3x2t<T>& mat3x2r) {
		Matrix3x2t<T> sum = mat3x2l;

		sum[0] += mat3x2r[0];
		sum[1] += mat3x2r[1];

		return sum;
	}
	template <typename T>		Matrix3x2t<T>		operator -(const Matrix3x2t<T>& mat3x2l, const Matrix3x2t<T>& mat3x2r) {
		Matrix3x2t<T> diff = mat3x2l;

		diff[0] -= mat3x2r[0];
		diff[0] -= mat3x2r[1];

		return diff;
	}
	template <typename T>		Vector3t<T>			operator *(const Matrix3x2t<T>& mat3x2, const Vector2t<T>& vec2) {
		Vector3t<T> prod(
			mat3x2[0][0] * vec2[0] + mat3x2[1][0] * vec2[1],
			mat3x2[0][1] * vec2[0] + mat3x2[1][1] * vec2[1],
			mat3x2[0][2] * vec2[0] + mat3x2[1][2] * vec2[1]
		);

		return prod;
	}
	template <typename T>		Matrix3x2t<T>		operator *(const Matrix3x2t<T>& mat3x2, const Matrix2x2t<T>& mat2x2) {
		Matrix3x2t<T> prod(
			mat3x2[0][0] * mat2x2[0][0] + mat3x2[1][0] * mat2x2[0][1], mat3x2[0][0] * mat2x2[1][0] + mat3x2[1][0] * mat2x2[1][1],
			mat3x2[0][1] * mat2x2[0][0] + mat3x2[1][1] * mat2x2[0][1], mat3x2[0][1] * mat2x2[1][0] + mat3x2[1][1] * mat2x2[1][1],
			mat3x2[0][2] * mat2x2[0][0] + mat3x2[1][2] * mat2x2[0][1], mat3x2[0][2] * mat2x2[1][0] + mat3x2[1][2] * mat2x2[1][1]
		);

		return prod;
	}
	template <typename T>		Matrix3x3t<T>		operator *(const Matrix3x2t<T>& mat3x2, const Matrix2x3t<T>& mat2x3) {
		Matrix3x3t<T> prod(
			mat3x2[0][0] * mat2x3[0][0] + mat3x2[1][0] * mat2x3[0][1], mat3x2[0][0] * mat2x3[1][0] + mat3x2[1][0] * mat2x3[1][1], mat3x2[0][0] * mat2x3[2][0] + mat3x2[1][0] * mat2x3[2][1],
			mat3x2[0][1] * mat2x3[0][0] + mat3x2[1][1] * mat2x3[0][1], mat3x2[0][1] * mat2x3[1][0] + mat3x2[1][1] * mat2x3[1][1], mat3x2[0][1] * mat2x3[2][0] + mat3x2[1][1] * mat2x3[2][1],
			mat3x2[0][2] * mat2x3[0][0] + mat3x2[1][2] * mat2x3[0][1], mat3x2[0][2] * mat2x3[1][0] + mat3x2[1][2] * mat2x3[1][1], mat3x2[0][2] * mat2x3[2][0] + mat3x2[1][2] * mat2x3[2][1]
		);

		return prod;
	}
	template <typename T>		Matrix3x4t<T>		operator *(const Matrix3x2t<T>& mat3x2, const Matrix2x4t<T>& mat2x4) {
		Matrix3x4t<T> prod(
			mat3x2[0][0] * mat2x4[0][0] + mat3x2[1][0] * mat2x4[0][1], mat3x2[0][0] * mat2x4[1][0] + mat3x2[1][0] * mat2x4[1][1], mat3x2[0][0] * mat2x4[2][0] + mat3x2[1][0] * mat2x4[2][1], mat3x2[0][0] * mat2x4[3][0] + mat3x2[1][0] * mat2x4[3][1],
			mat3x2[0][1] * mat2x4[0][0] + mat3x2[1][1] * mat2x4[0][1], mat3x2[0][1] * mat2x4[1][0] + mat3x2[1][1] * mat2x4[1][1], mat3x2[0][1] * mat2x4[2][0] + mat3x2[1][1] * mat2x4[2][1], mat3x2[0][1] * mat2x4[3][0] + mat3x2[1][1] * mat2x4[3][1],
			mat3x2[0][2] * mat2x4[0][0] + mat3x2[1][2] * mat2x4[0][1], mat3x2[0][2] * mat2x4[1][0] + mat3x2[1][2] * mat2x4[1][1], mat3x2[0][2] * mat2x4[2][0] + mat3x2[1][2] * mat2x4[2][1], mat3x2[0][2] * mat2x4[3][0] + mat3x2[1][2] * mat2x4[3][1]
		);

		return prod;
	}
	template <typename T>		Matrix3x2t<T>		operator /(const Matrix3x2t<T>& mat3x2, const Matrix2x2t<T> mat2x2) {
		Matrix3x2t<T> quot = mat3x2 * inverse(mat2x2);

		return quot;
	}
	
	//Matrix3x3 Arithmitic Operators

	template <typename T>		Matrix3x3t<T>		operator -(const Matrix3x3t<T>& mat3x3) {
		Matrix3x3t<T> negative = mat3x3;

		negative[0] = -negative[0];
		negative[1] = -negative[1];
		negative[2] = -negative[2];

		return negative;
	}
	template <typename T>		Matrix3x3t<T>		operator +(const Matrix3x3t<T>& mat3x3, const T& scalar) {
		Matrix3x3t<T> sum = mat2x3;

		sum[0] += scalar;
		sum[1] += scalar;
		sum[2] += scalar;

		return sum;
	}
	template <typename T>		Matrix3x3t<T>		operator -(const Matrix3x3t<T>& mat3x3, const T& scalar) {
		Matrix3x3t<T> diff = mat2x3;

		diff[0] -= scalar;
		diff[1] -= scalar;
		diff[2] -= scalar;

		return diff;
	}
	template <typename T>		Matrix3x3t<T>		operator *(const Matrix3x3t<T>& mat3x3, const T& scalar) {
		Matrix3x3t<T> prod = mat3x3;

		prod[0] *= scalar;
		prod[1] *= scalar;
		prod[2] *= scalar;

		return prod;
	}
	template <typename T>		Matrix3x3t<T>		operator /(const Matrix3x3t<T>& mat3x3, const T& scalar) {
		Matrix3x3t<T> quot = mat3x3;

		quot[0] /= scalar;
		quot[1] /= scalar;
		quot[2] /= scalar;

		return quot;
	}
	template <typename T>		Matrix3x3t<T>		operator +(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r) {
		Matrix3x3t<T> sum = mat3x3l;

		sum[0] += mat3x3r[0];
		sum[1] += mat3x3r[1];
		sum[2] += mat3x3r[2];

		return sum;
	}
	template <typename T>		Matrix3x3t<T>		operator -(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r) {
		Matrix3x3t<T> diff = mat3x3l;

		diff[0] -= mat3x3r[0];
		diff[1] -= mat3x3r[1];
		diff[2] -= mat3x3r[2];

		return diff;
	}
	template <typename T>		Vector3t<T>			operator *(const Matrix3x3t<T>& mat3x3, const Vector3t<T>& vec3) {
		Vector3t<T> prod(
			mat3x3[0][0] * vec3[0] + mat3x3[1][0] * vec3[1] + mat3x3[2][0] * vec3[2],
			mat3x3[0][1] * vec3[0] + mat3x3[1][1] * vec3[1] + mat3x3[2][1] * vec3[2],
			mat3x3[0][2] * vec3[0] + mat3x3[1][2] * vec3[1] + mat3x3[2][2] * vec3[2]
		);

		return prod;
	}
	template <typename T>		Matrix3x2t<T>		operator *(const Matrix3x3t<T>& mat3x3, const Matrix3x2t<T>& mat3x2) {
		Matrix3x2t<T> prod(
			mat3x3[0][0] * mat3x2[0][0] + mat3x3[1][0] * mat3x2[0][1] + mat3x3[2][0] * mat3x2[0][2], mat3x3[0][0] * mat3x2[1][0] + mat3x3[1][0] * mat3x2[1][1] + mat3x3[2][0] * mat3x2[1][2],
			mat3x3[0][1] * mat3x2[0][0] + mat3x3[1][1] * mat3x2[0][1] + mat3x3[2][1] * mat3x2[0][2], mat3x3[0][1] * mat3x2[1][0] + mat3x3[1][1] * mat3x2[1][1] + mat3x3[2][1] * mat3x2[1][2],
			mat3x3[0][2] * mat3x2[0][0] + mat3x3[1][2] * mat3x2[0][1] + mat3x3[2][2] * mat3x2[0][2], mat3x3[0][2] * mat3x2[1][0] + mat3x3[1][2] * mat3x2[1][1] + mat3x3[2][2] * mat3x2[1][2]
		);

		return prod;
	}
	template <typename T>		Matrix3x3t<T>		operator *(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r) {
		Matrix3x3t<T> prod(
			mat3x3l[0][0] * mat3x3r[0][0] + mat3x3l[1][0] * mat3x3r[0][1] + mat3x3l[2][0] * mat3x3r[0][2], mat3x3l[0][0] * mat3x3r[1][0] + mat3x3l[1][0] * mat3x3r[1][1] + mat3x3l[2][0] * mat3x3r[1][2], mat3x3l[0][0] * mat3x3r[2][0] + mat3x3l[1][0] * mat3x3r[2][1] + mat3x3l[2][0] * mat3x3r[2][2],
			mat3x3l[0][1] * mat3x3r[0][0] + mat3x3l[1][1] * mat3x3r[0][1] + mat3x3l[2][1] * mat3x3r[0][2], mat3x3l[0][1] * mat3x3r[1][0] + mat3x3l[1][1] * mat3x3r[1][1] + mat3x3l[2][1] * mat3x3r[1][2], mat3x3l[0][1] * mat3x3r[2][0] + mat3x3l[1][1] * mat3x3r[2][1] + mat3x3l[2][1] * mat3x3r[2][2],
			mat3x3l[0][2] * mat3x3r[0][0] + mat3x3l[1][2] * mat3x3r[0][1] + mat3x3l[2][2] * mat3x3r[0][2], mat3x3l[0][2] * mat3x3r[1][0] + mat3x3l[1][2] * mat3x3r[1][1] + mat3x3l[2][2] * mat3x3r[1][2], mat3x3l[0][2] * mat3x3r[2][0] + mat3x3l[1][2] * mat3x3r[2][1] + mat3x3l[2][2] * mat3x3r[2][2]
		);

		return prod;
	}
	template <typename T>		Matrix3x4t<T>		operator *(const Matrix3x3t<T>& mat3x3, const Matrix3x4t<T>& mat3x4) {
		Matrix3x4t<T> prod(
			mat3x3[0][0] * mat3x4[0][0] + mat3x3[1][0] * mat3x4[0][1] + mat3x3[2][0] * mat3x4[0][2], mat3x3[0][0] * mat3x4[1][0] + mat3x3[1][0] * mat3x4[1][1] + mat3x3[2][0] * mat3x4[1][2], mat3x3[0][0] * mat3x4[2][0] + mat3x3[1][0] * mat3x4[2][1] + mat3x3[2][0] * mat3x4[2][2], mat3x3[0][0] * mat3x4[3][0] + mat3x3[1][0] * mat3x4[3][1] + mat3x3[2][0] * mat3x4[3][2],
			mat3x3[0][1] * mat3x4[0][0] + mat3x3[1][1] * mat3x4[0][1] + mat3x3[2][1] * mat3x4[0][2], mat3x3[0][1] * mat3x4[1][0] + mat3x3[1][1] * mat3x4[1][1] + mat3x3[2][1] * mat3x4[1][2], mat3x3[0][1] * mat3x4[2][0] + mat3x3[1][1] * mat3x4[2][1] + mat3x3[2][1] * mat3x4[2][2], mat3x3[0][1] * mat3x4[3][0] + mat3x3[1][1] * mat3x4[3][1] + mat3x3[2][1] * mat3x4[3][2],
			mat3x3[0][2] * mat3x4[0][0] + mat3x3[1][2] * mat3x4[0][1] + mat3x3[2][2] * mat3x4[0][2], mat3x3[0][2] * mat3x4[1][0] + mat3x3[1][2] * mat3x4[1][1] + mat3x3[2][2] * mat3x4[1][2], mat3x3[0][2] * mat3x4[2][0] + mat3x3[1][2] * mat3x4[2][1] + mat3x3[2][2] * mat3x4[2][2], mat3x3[0][2] * mat3x4[3][0] + mat3x3[1][2] * mat3x4[3][1] + mat3x3[2][2] * mat3x4[3][2]
		);

		return prod;
	}
	template <typename T>		Matrix3x3t<T>		operator /(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r) {
		Matrix3x3t<T> quot = mat3x3l * inverse(mat3x3r);

		return quot;
	}

	//Matrix3x4 Arithmitic Operators

	template <typename T>		Matrix3x4t<T>		operator -(const Matrix3x4t<T>& mat3x4) {
		Matrix3x4t<T> negative = mat3x4;

		negative[0] = -negative[0];
		negative[1] = -negative[1];
		negative[2] = -negative[2];
		negative[3] = -negative[3];

		return negative;
	}
	template <typename T>		Matrix3x4t<T>		operator +(const Matrix3x4t<T>& mat3x4, const T& scalar) {
		Matrix3x4t<T> sum = mat3x4;

		sum[0] += scalar;
		sum[1] += scalar;
		sum[2] += scalar;
		sum[3] += scalar;

		return sum;
	}
	template <typename T>		Matrix3x4t<T>		operator -(const Matrix3x4t<T>& mat3x4, const T& scalar) {
		Matrix3x4t<T> diff = mat3x4;

		diff[0] -= scalar;
		diff[1] -= scalar;
		diff[2] -= scalar;
		diff[3] -= scalar;

		return diff;
	}
	template <typename T>		Matrix3x4t<T>		operator *(const Matrix3x4t<T>& mat3x4, const T& scalar) {
		Matrix3x4t<T> prod = mat3x4;

		prod[0] *= scalar;
		prod[1] *= scalar;
		prod[2] *= scalar;
		prod[3] *= scalar;

		return prod;
	}
	template <typename T>		Matrix3x4t<T>		operator /(const Matrix3x4t<T>& mat3x4, const T& scalar) {
		Matrix3x4t<T> quot = mat3x4;

		quot[0] /= scalar;
		quot[1] /= scalar;
		quot[2] /= scalar;
		quot[3] /= scalar;

		return quot;
	}
	template <typename T>		Matrix3x4t<T>		operator +(const Matrix3x4t<T>& mat3x4l, const Matrix3x4t<T>& mat3x4r) {
		Matrix3x4t<T> sum = mat3x4l;

		sum[0] += mat3x4r[0];
		sum[1] += mat3x4r[1];
		sum[2] += mat3x4r[2];
		sum[3] += mat3x4r[3];

		return sum;
	}
	template <typename T>		Matrix3x4t<T>		operator -(const Matrix3x4t<T>& mat3x4l, const Matrix3x4t<T>& mat3x4r) {
		Matrix3x4t<T> diff = mat3x4l;

		diff[0] -= mat3x4r[0];
		diff[1] -= mat3x4r[1];
		diff[2] -= mat3x4r[2];
		diff[3] -= mat3x4r[3];

		return diff;
	}
	template <typename T>		Vector3t<T>			operator *(const Matrix3x4t<T>& mat3x4, const Vector4t<T>& vec4) {
		Vector3t<T> prod(
			mat3x4[0][0] * vec4[0] + mat3x4[1][0] * vec4[1] + mat3x4[2][0] * vec4[2] + mat3x4[3][0] * vec4[3],
			mat3x4[0][1] * vec4[0] + mat3x4[1][1] * vec4[1] + mat3x4[2][1] * vec4[2] + mat3x4[3][1] * vec4[3],
			mat3x4[0][2] * vec4[0] + mat3x4[1][2] * vec4[1] + mat3x4[2][2] * vec4[2] + mat3x4[3][2] * vec4[3]
		);

		return prod;
	}
	template <typename T>		Matrix3x2t<T>		operator *(const Matrix3x4t<T>& mat3x4, const Matrix4x2t<T>& mat4x2) {
		Matrix3x2t<T> prod(
			mat3x4[0][0] * mat4x2[0][0] + mat3x4[1][0] * mat4x2[0][1] + mat3x4[2][0] * mat4x2[0][2] + mat3x4[3][0] * mat4x2[0][3], mat3x4[0][0] * mat4x2[1][0] + mat3x4[1][0] * mat4x2[1][1] + mat3x4[2][0] * mat4x2[1][2] + mat3x4[3][0] * mat4x2[1][3],
			mat3x4[0][1] * mat4x2[0][0] + mat3x4[1][1] * mat4x2[0][1] + mat3x4[2][1] * mat4x2[0][2] + mat3x4[3][1] * mat4x2[0][3], mat3x4[0][1] * mat4x2[1][0] + mat3x4[1][1] * mat4x2[1][1] + mat3x4[2][1] * mat4x2[1][2] + mat3x4[3][1] * mat4x2[1][3],
			mat3x4[0][2] * mat4x2[0][0] + mat3x4[1][2] * mat4x2[0][1] + mat3x4[2][2] * mat4x2[0][2] + mat3x4[3][2] * mat4x2[0][3], mat3x4[0][2] * mat4x2[1][0] + mat3x4[1][2] * mat4x2[1][1] + mat3x4[2][2] * mat4x2[1][2] + mat3x4[3][2] * mat4x2[1][3]
		);

		return prod;
	}
	template <typename T>		Matrix3x3t<T>		operator *(const Matrix3x4t<T>& mat3x4, const Matrix4x3t<T>& mat4x3) {
		Matrix3x3t<T> prod(
			mat3x4[0][0] * mat4x3[0][0] + mat3x4[1][0] * mat4x3[0][1] + mat3x4[2][0] * mat4x3[0][2] + mat3x4[3][0] * mat4x3[0][3], mat3x4[0][0] * mat4x3[1][0] + mat3x4[1][0] * mat4x3[1][1] + mat3x4[2][0] * mat4x3[1][2] + mat3x4[3][0] * mat4x3[1][3], mat3x4[0][0] * mat4x3[2][0] + mat3x4[1][0] * mat4x3[2][1] + mat3x4[2][0] * mat4x3[2][2] + mat3x4[3][0] * mat4x3[2][3],
			mat3x4[0][1] * mat4x3[0][0] + mat3x4[1][1] * mat4x3[0][1] + mat3x4[2][1] * mat4x3[0][2] + mat3x4[3][1] * mat4x3[0][3], mat3x4[0][1] * mat4x3[1][0] + mat3x4[1][1] * mat4x3[1][1] + mat3x4[2][1] * mat4x3[1][2] + mat3x4[3][1] * mat4x3[1][3], mat3x4[0][1] * mat4x3[2][0] + mat3x4[1][1] * mat4x3[2][1] + mat3x4[2][1] * mat4x3[2][2] + mat3x4[3][1] * mat4x3[2][3],
			mat3x4[0][2] * mat4x3[0][0] + mat3x4[1][2] * mat4x3[0][1] + mat3x4[2][2] * mat4x3[0][2] + mat3x4[3][2] * mat4x3[0][3], mat3x4[0][2] * mat4x3[1][0] + mat3x4[1][2] * mat4x3[1][1] + mat3x4[2][2] * mat4x3[1][2] + mat3x4[3][2] * mat4x3[1][3], mat3x4[0][2] * mat4x3[2][0] + mat3x4[1][2] * mat4x3[2][1] + mat3x4[2][2] * mat4x3[2][2] + mat3x4[3][2] * mat4x3[2][3]
		);

		return prod;
	}
	template <typename T>		Matrix3x4t<T>		operator *(const Matrix3x4t<T>& mat3x4, const Matrix4x4t<T>& mat4x4) {
		Matrix3x4t<T> prod(
			mat3x4[0][0] * mat4x4[0][0] + mat3x4[1][0] * mat4x4[0][1] + mat3x4[2][0] * mat4x4[0][2] + mat3x4[3][0] * mat4x4[0][3], mat3x4[0][0] * mat4x4[1][0] + mat3x4[1][0] * mat4x4[1][1] + mat3x4[2][0] * mat4x4[1][2] + mat3x4[3][0] * mat4x4[1][3], mat3x4[0][0] * mat4x4[2][0] + mat3x4[1][0] * mat4x4[2][1] + mat3x4[2][0] * mat4x4[2][2] + mat3x4[3][0] * mat4x4[2][3], mat3x4[0][0] * mat4x4[3][0] + mat3x4[1][0] * mat4x4[3][1] + mat3x4[2][0] * mat4x4[3][2] + mat3x4[3][0] * mat4x4[3][3],
			mat3x4[0][1] * mat4x4[0][0] + mat3x4[1][1] * mat4x4[0][1] + mat3x4[2][1] * mat4x4[0][2] + mat3x4[3][1] * mat4x4[0][3], mat3x4[0][1] * mat4x4[1][0] + mat3x4[1][1] * mat4x4[1][1] + mat3x4[2][1] * mat4x4[1][2] + mat3x4[3][1] * mat4x4[1][3], mat3x4[0][1] * mat4x4[2][0] + mat3x4[1][1] * mat4x4[2][1] + mat3x4[2][1] * mat4x4[2][2] + mat3x4[3][1] * mat4x4[2][3], mat3x4[0][1] * mat4x4[3][0] + mat3x4[1][1] * mat4x4[3][1] + mat3x4[2][1] * mat4x4[3][2] + mat3x4[3][1] * mat4x4[3][3],
			mat3x4[0][2] * mat4x4[0][0] + mat3x4[1][2] * mat4x4[0][1] + mat3x4[2][2] * mat4x4[0][2] + mat3x4[3][2] * mat4x4[0][3], mat3x4[0][2] * mat4x4[1][0] + mat3x4[1][2] * mat4x4[1][1] + mat3x4[2][2] * mat4x4[1][2] + mat3x4[3][2] * mat4x4[1][3], mat3x4[0][2] * mat4x4[2][0] + mat3x4[1][2] * mat4x4[2][1] + mat3x4[2][2] * mat4x4[2][2] + mat3x4[3][2] * mat4x4[2][3], mat3x4[0][2] * mat4x4[3][0] + mat3x4[1][2] * mat4x4[3][1] + mat3x4[2][2] * mat4x4[3][2] + mat3x4[3][2] * mat4x4[3][3]
		);

		return prod;
	}
	template <typename T>		Matrix3x4t<T>		operator /(const Matrix3x4t<T>& mat3x4, const Matrix4x4t<T>& mat4x4) {
		Matrix3x4t<T> quot = mat3x4 * inverse(mat4x4);

		return quot;
	}

	//Matrix4x2 Arithmitic Operators

	template <typename T>		Matrix4x2t<T>		operator -(const Matrix4x2t<T>& mat4x2) {
		Matrix4x2t<T> negative = mat4x2;

		negative[0] = -negative[0];
		negative[1] = -negative[1];

		return negative;
	}
	template <typename T>		Matrix4x2t<T>		operator +(const Matrix4x2t<T>& mat4x2, const T& scalar) {
		Matrix4x2t<T> sum = mat4x2;

		sum[0] += scalar;
		sum[1] += scalar;

		return sum;
	}
	template <typename T>		Matrix4x2t<T>		operator -(const Matrix4x2t<T>& mat4x2, const T& scalar) {
		Matrix4x2t<T> diff = mat4x2;

		diff[0] -= scalar;
		diff[1] -= scalar;

		return diff;
	}
	template <typename T>		Matrix4x2t<T>		operator *(const Matrix4x2t<T>& mat4x2, const T& scalar) {
		Matrix4x2t<T> prod = mat4x2;

		prod[0] *= scalar;
		prod[1] *= scalar;

		return prod;
	}
	template <typename T>		Matrix4x2t<T>		operator /(const Matrix4x2t<T>& mat4x2, const T& scalar) {
		Matrix4x2t<T> quot = mat4x2;

		quot[0] /= scalar;
		quot[1] /= scalar;

		return quot;
	}
	template <typename T>		Matrix4x2t<T>		operator +(const Matrix4x2t<T>& mat4x2l, const Matrix4x2t<T>& mat4x2r) {
		Matrix4x2t<T> sum = mat4x2l;

		sum[0] += mat4x2r[0];
		sum[1] += mat4x2r[1];

		return sum;
	}
	template <typename T>		Matrix4x2t<T>		operator -(const Matrix4x2t<T>& mat4x2l, const Matrix4x2t<T>& mat4x2r) {
		Matrix4x2t<T> diff = mat4x2l;

		diff[0] -= mat4x2r[0];
		diff[1] -= mat4x2r[1];

		return diff;
	}
	template <typename T>		Vector4t<T>			operator *(const Matrix4x2t<T>& mat4x2, const Vector2t<T>& vec2) {
		Vector4t<T> prod(
			mat4x2[0][0] * vec2[0] + mat4x2[1][0] * vec2[1],
			mat4x2[0][1] * vec2[0] + mat4x2[1][1] * vec2[1],
			mat4x2[0][2] * vec2[0] + mat4x2[1][2] * vec2[1],
			mat4x2[0][3] * vec2[0] + mat4x2[1][3] * vec2[1]
		);

		return prod;
	}
	template <typename T>		Matrix4x2t<T>		operator *(const Matrix4x2t<T>& mat4x2, const Matrix2x2t<T>& mat2x2) {
		Matrix4x2t<T> prod(
			mat4x2[0][0] * mat2x2[0][0] + mat4x2[1][0] * mat2x2[0][1], mat4x2[0][0] * mat2x2[1][0] + mat4x2[1][0] * mat2x2[1][1],
			mat4x2[0][1] * mat2x2[0][0] + mat4x2[1][1] * mat2x2[0][1], mat4x2[0][1] * mat2x2[1][0] + mat4x2[1][1] * mat2x2[1][1],
			mat4x2[0][2] * mat2x2[0][0] + mat4x2[1][2] * mat2x2[0][1], mat4x2[0][2] * mat2x2[1][0] + mat4x2[1][2] * mat2x2[1][1],
			mat4x2[0][3] * mat2x2[0][0] + mat4x2[1][3] * mat2x2[0][1], mat4x2[0][3] * mat2x2[1][0] + mat4x2[1][3] * mat2x2[1][1]
		);

		return prod;
	}
	template <typename T>		Matrix4x3t<T>		operator *(const Matrix4x2t<T>& mat4x2, const Matrix2x3t<T>& mat2x3) {
		Matrix4x3t<T> prod(
			mat4x2[0][0] * mat2x3[0][0] + mat4x2[1][0] * mat2x3[0][1], mat4x2[0][0] * mat2x3[1][0] + mat4x2[1][0] * mat2x3[1][1], mat4x2[0][0] * mat2x3[2][0] + mat4x2[1][0] * mat2x3[2][1],
			mat4x2[0][1] * mat2x3[0][0] + mat4x2[1][1] * mat2x3[0][1], mat4x2[0][1] * mat2x3[1][0] + mat4x2[1][1] * mat2x3[1][1], mat4x2[0][1] * mat2x3[2][0] + mat4x2[1][1] * mat2x3[2][1],
			mat4x2[0][2] * mat2x3[0][0] + mat4x2[1][2] * mat2x3[0][1], mat4x2[0][2] * mat2x3[1][0] + mat4x2[1][2] * mat2x3[1][1], mat4x2[0][2] * mat2x3[2][0] + mat4x2[1][2] * mat2x3[2][1],
			mat4x2[0][3] * mat2x3[0][0] + mat4x2[1][3] * mat2x3[0][1], mat4x2[0][3] * mat2x3[1][0] + mat4x2[1][3] * mat2x3[1][1], mat4x2[0][3] * mat2x3[2][0] + mat4x2[1][3] * mat2x3[2][1]
		);

		return prod;
	}
	template <typename T>		Matrix4x4t<T>		operator *(const Matrix4x2t<T>& mat4x2, const Matrix2x4t<T>& mat2x4) {
		Matrix4x4t<T> prod(
			mat4x2[0][0] * mat2x4[0][0] + mat4x2[1][0] * mat2x4[0][1], mat4x2[0][0] * mat2x4[1][0] + mat4x2[1][0] * mat2x4[1][1], mat4x2[0][0] * mat2x4[2][0] + mat4x2[1][0] * mat2x4[2][1], mat4x2[0][0] * mat2x4[3][0] + mat4x2[1][0] * mat2x4[3][1],
			mat4x2[0][1] * mat2x4[0][0] + mat4x2[1][1] * mat2x4[0][1], mat4x2[0][1] * mat2x4[1][0] + mat4x2[1][1] * mat2x4[1][1], mat4x2[0][1] * mat2x4[2][0] + mat4x2[1][1] * mat2x4[2][1], mat4x2[0][1] * mat2x4[3][0] + mat4x2[1][1] * mat2x4[3][1],
			mat4x2[0][2] * mat2x4[0][0] + mat4x2[1][2] * mat2x4[0][1], mat4x2[0][2] * mat2x4[1][0] + mat4x2[1][2] * mat2x4[1][1], mat4x2[0][2] * mat2x4[2][0] + mat4x2[1][2] * mat2x4[2][1], mat4x2[0][2] * mat2x4[3][0] + mat4x2[1][2] * mat2x4[3][1],
			mat4x2[0][3] * mat2x4[0][0] + mat4x2[1][3] * mat2x4[0][1], mat4x2[0][3] * mat2x4[1][0] + mat4x2[1][3] * mat2x4[1][1], mat4x2[0][3] * mat2x4[2][0] + mat4x2[1][3] * mat2x4[2][1], mat4x2[0][3] * mat2x4[3][0] + mat4x2[1][3] * mat2x4[3][1]
		);

		return prod;
	}
	template <typename T>		Matrix4x2t<T>		operator /(const Matrix4x2t<T>& mat4x2, const Matrix2x2t<T>& mat2x2) {
		Matrix4x2t<T> quot = mat4x2 ** inverse(mat2x2);

		return quot;
	}
	
	//Matrix4x3 Arithmitic Operators

	template <typename T>		Matrix4x3t<T>		operator -(const Matrix4x3t<T>& mat4x3) {
		Matrix4x3t<T> negative = mat4x3;

		negative[0] = -negative[0];
		negative[1] = -negative[1];
		negative[2] = -negative[2];

		return negative;
	}
	template <typename T>		Matrix4x3t<T>		operator +(const Matrix4x3t<T>& mat4x3, const T& scalar) {
		Matrix4x3t<T> sum = mat4x3;

		sum[0] /= scalar;
		sum[1] /= scalar;
		sum[2] /= scalar;

		return sum;
	}
	template <typename T>		Matrix4x3t<T>		operator -(const Matrix4x3t<T>& mat4x3, const T& scalar) {
		Matrix4x3t<T> diff = mat4x3;

		diff[0] -= scalar;
		diff[1] -= scalar;
		diff[2] -= scalar;

		return diff;
	}
	template <typename T>		Matrix4x3t<T>		operator *(const Matrix4x3t<T>& mat4x3, const T& scalar) {
		Matrix4x3t<T> prod = mat4x3;

		prod[0] *= scalar;
		prod[1] *= scalar;
		prod[2] *= scalar;

		return prod;
	}
	template <typename T>		Matrix4x3t<T>		operator /(const Matrix4x3t<T>& mat4x3, const T& scalar) {
		Matrix4x3t<T> quot = mat4x3;

		quot[0] /= scalar;
		quot[1] /= scalar;
		quot[2] /= scalar;

		return quot;
	}
	template <typename T>		Matrix4x3t<T>		operator +(const Matrix4x3t<T>& mat4x3l, const Matrix4x3t<T>& mat4x3r) {
		Matrix4x3t<T> sum = mat4x3l;

		sum[0] += mat4x3r[0];
		sum[1] += mat4x3r[1];
		sum[2] += mat4x3r[2];

		return sum;
	}
	template <typename T>		Matrix4x3t<T>		operator -(const Matrix4x3t<T>& mat4x3l, const Matrix4x3t<T>& mat4x3r) {
		Matrix4x3t<T> diff = mat4x3l;

		diff[0] -= mat4x3r[0];
		diff[1] -= mat4x3r[1];
		diff[2] -= mat4x3r[2];

		return diff;
	}
	template <typename T>		Vector4t<T>			operator *(const Matrix4x3t<T>& mat4x3, const Vector3t<T>& vec3) {
		Vector4t<T> prod(
			mat4x3[0][0] * vec3[0] + mat4x3[1][0] * vec3[1] + mat4x3[2][0] * vec3[2],
			mat4x3[0][1] * vec3[0] + mat4x3[1][1] * vec3[1] + mat4x3[2][1] * vec3[2],
			mat4x3[0][2] * vec3[0] + mat4x3[1][2] * vec3[1] + mat4x3[2][2] * vec3[2],
			mat4x3[0][3] * vec3[0] + mat4x3[1][3] * vec3[1] + mat4x3[2][3] * vec3[2]
		);

		return prod;
	}
	template <typename T>		Matrix4x2t<T>		operator *(const Matrix4x3t<T>& mat4x3, const Matrix3x2t<T>& mat3x2) {
		Matrix4x2t<T> prod(
			mat4x3[0][0] * mat3x2[0][0] + mat4x3[1][0] * mat3x2[0][1] + mat4x3[2][0] * mat3x2[0][2], mat4x3[0][0] * mat3x2[1][0] + mat4x3[1][0] * mat3x2[1][1] + mat4x3[2][0] * mat3x2[1][2],
			mat4x3[0][1] * mat3x2[0][0] + mat4x3[1][1] * mat3x2[0][1] + mat4x3[2][1] * mat3x2[0][2], mat4x3[0][1] * mat3x2[1][0] + mat4x3[1][1] * mat3x2[1][1] + mat4x3[2][1] * mat3x2[1][2],
			mat4x3[0][2] * mat3x2[0][0] + mat4x3[1][2] * mat3x2[0][1] + mat4x3[2][2] * mat3x2[0][2], mat4x3[0][2] * mat3x2[1][0] + mat4x3[1][2] * mat3x2[1][1] + mat4x3[2][2] * mat3x2[1][2],
			mat4x3[0][3] * mat3x2[0][0] + mat4x3[1][3] * mat3x2[0][1] + mat4x3[2][3] * mat3x2[0][2], mat4x3[0][3] * mat3x2[1][0] + mat4x3[1][3] * mat3x2[1][1] + mat4x3[2][3] * mat3x2[1][2]
		);

		return prod;
	}
	template <typename T>		Matrix4x3t<T>		operator *(const Matrix4x3t<T>& mat4x3, const Matrix3x3t<T>& mat3x3) {
		Matrix4x3t<T> prod(
			mat4x3[0][0] * mat3x3[0][0] + mat4x3[1][0] * mat3x3[0][1] + mat4x3[2][0] * mat3x3[0][2], mat4x3[0][0] * mat3x3[1][0] + mat4x3[1][0] * mat3x3[1][1] + mat4x3[2][0] * mat3x3[1][2], mat4x3[0][0] * mat3x3[2][0] + mat4x3[1][0] * mat3x3[2][1] + mat4x3[2][0] * mat3x3[2][2],
			mat4x3[0][1] * mat3x3[0][0] + mat4x3[1][1] * mat3x3[0][1] + mat4x3[2][1] * mat3x3[0][2], mat4x3[0][1] * mat3x3[1][0] + mat4x3[1][1] * mat3x3[1][1] + mat4x3[2][1] * mat3x3[1][2], mat4x3[0][1] * mat3x3[2][0] + mat4x3[1][1] * mat3x3[2][1] + mat4x3[2][1] * mat3x3[2][2],
			mat4x3[0][2] * mat3x3[0][0] + mat4x3[1][2] * mat3x3[0][1] + mat4x3[2][2] * mat3x3[0][2], mat4x3[0][2] * mat3x3[1][0] + mat4x3[1][2] * mat3x3[1][1] + mat4x3[2][2] * mat3x3[1][2], mat4x3[0][2] * mat3x3[2][0] + mat4x3[1][2] * mat3x3[2][1] + mat4x3[2][2] * mat3x3[2][2],
			mat4x3[0][3] * mat3x3[0][0] + mat4x3[1][3] * mat3x3[0][1] + mat4x3[2][3] * mat3x3[0][2], mat4x3[0][3] * mat3x3[1][0] + mat4x3[1][3] * mat3x3[1][1] + mat4x3[2][3] * mat3x3[1][2], mat4x3[0][3] * mat3x3[2][0] + mat4x3[1][3] * mat3x3[2][1] + mat4x3[2][3] * mat3x3[2][2]
		);

		return prod;
	}
	template <typename T>		Matrix4x4t<T>		operator *(const Matrix4x3t<T>& mat4x3, const Matrix3x4t<T>& mat3x4) {
		Matrix4x4t<T> prod(
			mat4x3[0][0] * mat3x4[0][0] + mat4x3[1][0] * mat3x4[0][1] + mat4x3[2][0] * mat3x4[0][2], mat4x3[0][0] * mat3x4[1][0] + mat4x3[1][0] * mat3x4[1][1] + mat4x3[2][0] * mat3x4[1][2], mat4x3[0][0] * mat3x4[2][0] + mat4x3[1][0] * mat3x4[2][1] + mat4x3[2][0] * mat3x4[2][2], mat4x3[0][0] * mat3x4[3][0] + mat4x3[1][0] * mat3x4[3][1] + mat4x3[2][0] * mat3x4[3][2],
			mat4x3[0][1] * mat3x4[0][0] + mat4x3[1][1] * mat3x4[0][1] + mat4x3[2][1] * mat3x4[0][2], mat4x3[0][1] * mat3x4[1][0] + mat4x3[1][1] * mat3x4[1][1] + mat4x3[2][1] * mat3x4[1][2], mat4x3[0][1] * mat3x4[2][0] + mat4x3[1][1] * mat3x4[2][1] + mat4x3[2][1] * mat3x4[2][2], mat4x3[0][1] * mat3x4[3][0] + mat4x3[1][1] * mat3x4[3][1] + mat4x3[2][1] * mat3x4[3][2],
			mat4x3[0][2] * mat3x4[0][0] + mat4x3[1][2] * mat3x4[0][1] + mat4x3[2][2] * mat3x4[0][2], mat4x3[0][2] * mat3x4[1][0] + mat4x3[1][2] * mat3x4[1][1] + mat4x3[2][2] * mat3x4[1][2], mat4x3[0][2] * mat3x4[2][0] + mat4x3[1][2] * mat3x4[2][1] + mat4x3[2][2] * mat3x4[2][2], mat4x3[0][2] * mat3x4[3][0] + mat4x3[1][2] * mat3x4[3][1] + mat4x3[2][2] * mat3x4[3][2],
			mat4x3[0][3] * mat3x4[0][0] + mat4x3[1][3] * mat3x4[0][1] + mat4x3[2][3] * mat3x4[0][2], mat4x3[0][3] * mat3x4[1][0] + mat4x3[1][3] * mat3x4[1][1] + mat4x3[2][3] * mat3x4[1][2], mat4x3[0][3] * mat3x4[2][0] + mat4x3[1][3] * mat3x4[2][1] + mat4x3[2][3] * mat3x4[2][2], mat4x3[0][3] * mat3x4[3][0] + mat4x3[1][3] * mat3x4[3][1] + mat4x3[2][3] * mat3x4[3][2]
		);

		return prod;
	}
	template <typename T>		Matrix4x3t<T>		operator /(const Matrix4x3t<T>& mat4x3, const Matrix3x3t<T>& mat3x3) {
		Matrix4x3t<T> quot = mat4x3 * inverse(mat3x3);

		return quot;
	}

	//Matrix4x4 Arithmitic Operators

	template <typename T>		Matrix4x4t<T>		operator -(const Matrix4x4t<T>& mat4x4) {
		Matrix4x4t<T> negative = mat4x4;

		negative[0] = -negative[0];
		negative[1] = -negative[1];
		negative[2] = -negative[2];
		negative[3] = -negative[3];

		return negative;
	}
	template <typename T>		Matrix4x4t<T>		operator +(const Matrix4x4t<T>& mat4x4, const T& scalar) {
		Matrix4x4t<T> sum = mat4x4;

		sum[0] += scalar;
		sum[1] += scalar;
		sum[2] += scalar;
		sum[3] += scalar;

		return sum;
	}
	template <typename T>		Matrix4x4t<T>		operator -(const Matrix4x4t<T>& mat4x4, const T& scalar) {
		Matrix4x4t<T> diff = mat4x4;

		diff[0] -= scalar;
		diff[1] -= scalar;
		diff[2] -= scalar;
		diff[3] -= scalar;

		return diff;
	}
	template <typename T>		Matrix4x4t<T>		operator *(const Matrix4x4t<T>& mat4x4, const T& scalar) {
		Matrix4x4t<T> prod = mat4x4;

		prod[0] *= scalar;
		prod[1] *= scalar;
		prod[2] *= scalar;
		prod[3] *= scalar;

		return prod;
	}
	template <typename T>		Matrix4x4t<T>		operator /(const Matrix4x4t<T>& mat4x4, const T& scalar) {
		Matrix4x4t<T> quot = mat4x4;

		quot[0] /= scalar;
		quot[1] /= scalar;
		quot[2] /= scalar;
		quot[3] /= scalar;

		return quot;
	}
	template <typename T>		Matrix4x4t<T>		operator +(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r) {
		Matrix4x4t<T> sum = mat4x4l;

		sum[0] += mat4x4r[0];
		sum[1] += mat4x4r[1];
		sum[2] += mat4x4r[2];
		sum[3] += mat4x4r[3];

		return sum;
	}
	template <typename T>		Matrix4x4t<T>		operator -(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r) {
		Matrix4x4t<T> diff = mat4x4l;

		diff[0] += mat4x4r[0];
		diff[1] += mat4x4r[1];
		diff[2] += mat4x4r[2];
		diff[3] += mat4x4r[3];

		return diff;
	}
	template <typename T>		Vector4t<T>			operator *(const Matrix4x4t<T>& mat4x4, const Vector4t<T>& vec4) {
		Vector4t<T> prod(
			mat4x4[0][0] * vec4[0] + mat4x4[1][0] * vec4[1] + mat4x4[2][0] * vec4[2] + mat4x4[3][0] * vec4[3],
			mat4x4[0][1] * vec4[0] + mat4x4[1][1] * vec4[1] + mat4x4[2][1] * vec4[2] + mat4x4[3][1] * vec4[3],
			mat4x4[0][2] * vec4[0] + mat4x4[1][2] * vec4[1] + mat4x4[2][2] * vec4[2] + mat4x4[3][2] * vec4[3],
			mat4x4[0][3] * vec4[0] + mat4x4[1][3] * vec4[1] + mat4x4[2][3] * vec4[2] + mat4x4[3][3] * vec4[3]
		);

		return prod;
	}
	template <typename T>		Matrix4x2t<T>		operator *(const Matrix4x4t<T>& mat4x4, const Matrix4x2t<T>& mat4x2) {
		Matrix4x2t<T> prod(
			mat4x4[0][0] * mat4x2[0][0] + mat4x4[1][0] * mat4x2[0][1] + mat4x4[2][0] * mat4x2[0][2] + mat4x4[3][0] * mat4x2[0][3], mat4x4[0][0] * mat4x2[1][0] + mat4x4[1][0] * mat4x2[1][1] + mat4x4[2][0] * mat4x2[1][2] + mat4x4[3][0] * mat4x2[1][3],
			mat4x4[0][1] * mat4x2[0][0] + mat4x4[1][1] * mat4x2[0][1] + mat4x4[2][1] * mat4x2[0][2] + mat4x4[3][1] * mat4x2[0][3], mat4x4[0][1] * mat4x2[1][0] + mat4x4[1][1] * mat4x2[1][1] + mat4x4[2][1] * mat4x2[1][2] + mat4x4[3][1] * mat4x2[1][3],
			mat4x4[0][2] * mat4x2[0][0] + mat4x4[1][2] * mat4x2[0][1] + mat4x4[2][2] * mat4x2[0][2] + mat4x4[3][2] * mat4x2[0][3], mat4x4[0][2] * mat4x2[1][0] + mat4x4[1][2] * mat4x2[1][1] + mat4x4[2][2] * mat4x2[1][2] + mat4x4[3][2] * mat4x2[1][3],
			mat4x4[0][3] * mat4x2[0][0] + mat4x4[1][3] * mat4x2[0][1] + mat4x4[2][3] * mat4x2[0][2] + mat4x4[3][3] * mat4x2[0][3], mat4x4[0][3] * mat4x2[1][0] + mat4x4[1][3] * mat4x2[1][1] + mat4x4[2][3] * mat4x2[1][2] + mat4x4[3][3] * mat4x2[1][3]
		);

		return prod;
	}
	template <typename T>		Matrix4x3t<T>		operator *(const Matrix4x4t<T>& mat4x4, const Matrix4x3t<T>& mat4x3) {
		Matrix4x3t<T> prod(
			mat4x4[0][0] * mat4x3[0][0] + mat4x4[1][0] * mat4x3[0][1] + mat4x4[2][0] * mat4x3[0][2] + mat4x4[3][0] * mat4x3[0][3], mat4x4[0][0] * mat4x3[1][0] + mat4x4[1][0] * mat4x3[1][1] + mat4x4[2][0] * mat4x3[1][2] + mat4x4[3][0] * mat4x3[1][3], mat4x4[0][0] * mat4x3[2][0] + mat4x4[1][0] * mat4x3[2][1] + mat4x4[2][0] * mat4x3[2][2] + mat4x4[3][0] * mat4x3[2][3],
			mat4x4[0][1] * mat4x3[0][0] + mat4x4[1][1] * mat4x3[0][1] + mat4x4[2][1] * mat4x3[0][2] + mat4x4[3][1] * mat4x3[0][3], mat4x4[0][1] * mat4x3[1][0] + mat4x4[1][1] * mat4x3[1][1] + mat4x4[2][1] * mat4x3[1][2] + mat4x4[3][1] * mat4x3[1][3], mat4x4[0][1] * mat4x3[2][0] + mat4x4[1][1] * mat4x3[2][1] + mat4x4[2][1] * mat4x3[2][2] + mat4x4[3][1] * mat4x3[2][3],
			mat4x4[0][2] * mat4x3[0][0] + mat4x4[1][2] * mat4x3[0][1] + mat4x4[2][2] * mat4x3[0][2] + mat4x4[3][2] * mat4x3[0][3], mat4x4[0][2] * mat4x3[1][0] + mat4x4[1][2] * mat4x3[1][1] + mat4x4[2][2] * mat4x3[1][2] + mat4x4[3][2] * mat4x3[1][3], mat4x4[0][2] * mat4x3[2][0] + mat4x4[1][2] * mat4x3[2][1] + mat4x4[2][2] * mat4x3[2][2] + mat4x4[3][2] * mat4x3[2][3],
			mat4x4[0][3] * mat4x3[0][0] + mat4x4[1][3] * mat4x3[0][1] + mat4x4[2][3] * mat4x3[0][2] + mat4x4[3][3] * mat4x3[0][3], mat4x4[0][3] * mat4x3[1][0] + mat4x4[1][3] * mat4x3[1][1] + mat4x4[2][3] * mat4x3[1][2] + mat4x4[3][3] * mat4x3[1][3], mat4x4[0][3] * mat4x3[2][0] + mat4x4[1][3] * mat4x3[2][1] + mat4x4[2][3] * mat4x3[2][2] + mat4x4[3][3] * mat4x3[2][3]
		);

		return prod;
	}
	template <typename T>		Matrix4x4t<T>		operator *(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r) {
		Matrix4x4t<T> prod(
			mat4x4l[0][0] * mat4x4r[0][0] + mat4x4l[1][0] * mat4x4r[0][1] + mat4x4l[2][0] * mat4x4r[0][2] + mat4x4l[3][0] * mat4x4r[0][3], mat4x4l[0][0] * mat4x4r[1][0] + mat4x4l[1][0] * mat4x4r[1][1] + mat4x4l[2][0] * mat4x4r[1][2] + mat4x4l[3][0] * mat4x4r[1][3], mat4x4l[0][0] * mat4x4r[2][0] + mat4x4l[1][0] * mat4x4r[2][1] + mat4x4l[2][0] * mat4x4r[2][2] + mat4x4l[3][0] * mat4x4r[2][3], mat4x4l[0][0] * mat4x4r[3][0] + mat4x4l[1][0] * mat4x4r[3][1] + mat4x4l[2][0] * mat4x4r[3][2] + mat4x4l[3][0] * mat4x4r[3][3],
			mat4x4l[0][1] * mat4x4r[0][0] + mat4x4l[1][1] * mat4x4r[0][1] + mat4x4l[2][1] * mat4x4r[0][2] + mat4x4l[3][1] * mat4x4r[0][3], mat4x4l[0][1] * mat4x4r[1][0] + mat4x4l[1][1] * mat4x4r[1][1] + mat4x4l[2][1] * mat4x4r[1][2] + mat4x4l[3][1] * mat4x4r[1][3], mat4x4l[0][1] * mat4x4r[2][0] + mat4x4l[1][1] * mat4x4r[2][1] + mat4x4l[2][1] * mat4x4r[2][2] + mat4x4l[3][1] * mat4x4r[2][3], mat4x4l[0][1] * mat4x4r[3][0] + mat4x4l[1][1] * mat4x4r[3][1] + mat4x4l[2][1] * mat4x4r[3][2] + mat4x4l[3][1] * mat4x4r[3][3],
			mat4x4l[0][2] * mat4x4r[0][0] + mat4x4l[1][2] * mat4x4r[0][1] + mat4x4l[2][2] * mat4x4r[0][2] + mat4x4l[3][2] * mat4x4r[0][3], mat4x4l[0][2] * mat4x4r[1][0] + mat4x4l[1][2] * mat4x4r[1][1] + mat4x4l[2][2] * mat4x4r[1][2] + mat4x4l[3][2] * mat4x4r[1][3], mat4x4l[0][2] * mat4x4r[2][0] + mat4x4l[1][2] * mat4x4r[2][1] + mat4x4l[2][2] * mat4x4r[2][2] + mat4x4l[3][2] * mat4x4r[2][3], mat4x4l[0][2] * mat4x4r[3][0] + mat4x4l[1][2] * mat4x4r[3][1] + mat4x4l[2][2] * mat4x4r[3][2] + mat4x4l[3][2] * mat4x4r[3][3],
			mat4x4l[0][3] * mat4x4r[0][0] + mat4x4l[1][3] * mat4x4r[0][1] + mat4x4l[2][3] * mat4x4r[0][2] + mat4x4l[3][3] * mat4x4r[0][3], mat4x4l[0][3] * mat4x4r[1][0] + mat4x4l[1][3] * mat4x4r[1][1] + mat4x4l[2][3] * mat4x4r[1][2] + mat4x4l[3][3] * mat4x4r[1][3], mat4x4l[0][3] * mat4x4r[2][0] + mat4x4l[1][3] * mat4x4r[2][1] + mat4x4l[2][3] * mat4x4r[2][2] + mat4x4l[3][3] * mat4x4r[2][3], mat4x4l[0][3] * mat4x4r[3][0] + mat4x4l[1][3] * mat4x4r[3][1] + mat4x4l[2][3] * mat4x4r[3][2] + mat4x4l[3][3] * mat4x4r[3][3]
		);

		return prod;
	}
	template <typename T>		Matrix4x4t<T>		operator /(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r) {
		Matrix4x4t<T> quot = mat4x4l * inverse(mat4x4r);

		return quot;
	}
}}
