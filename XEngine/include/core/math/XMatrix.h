
//==================================================================================\\
//FILE NAME:			XMatrix.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#ifndef X_MATRIX_H
#define X_MATRIX_H

#include "XVector.h"


namespace X {	namespace Math {

	template <typename T> struct Matrix2x2t;
	template <typename T> struct Matrix2x3t;
	template <typename T> struct Matrix2x4t;
	template <typename T> struct Matrix3x2t;
	template <typename T> struct Matrix3x3t;
	template <typename T> struct Matrix3x4t;
	template <typename T> struct Matrix4x2t;
	template <typename T> struct Matrix4x3t;
	template <typename T> struct Matrix4x4t;


	//Matrix Struct Declerations

	template <typename T> struct Matrix2x2t {
	private:
		//Data

		Vector2t<T> data[2];

	public:
		//Implicit Constructors

		Matrix2x2t();
		Matrix2x2t(const Matrix2x2t<T>& mat2x2);

		//Explicit Constructors

		explicit	Matrix2x2t(const T& scalar);
		explicit	Matrix2x2t(const Vector2t<T>& col0, const Vector2t<T>& col1);
		explicit	Matrix2x2t(
			const T& x0, const T& x1,
			const T& y0, const T& y1);
		//Explicit Conversion Constructors

		template <typename Ta>		explicit	Matrix2x2t(const Matrix2x2t<Ta>& mat2x2);
		explicit	Matrix2x2t(const Matrix2x3t<T>& mat2x3);
		explicit	Matrix2x2t(const Matrix2x4t<T>& mat2x4);
		explicit	Matrix2x2t(const Matrix3x2t<T>& mat3x2);
		explicit	Matrix2x2t(const Matrix3x3t<T>& mat3x3);
		explicit	Matrix2x2t(const Matrix3x4t<T>& mat3x4);
		explicit	Matrix2x2t(const Matrix4x2t<T>& mat4x2);
		explicit	Matrix2x2t(const Matrix4x3t<T>& mat4x3);
		explicit	Matrix2x2t(const Matrix4x4t<T>& mat4x4);

		//Data Access

		Vector2t<T>&			operator [](const unsigned short int& index);
		const Vector2t<T>&		operator [](const unsigned short int& index) const;

		//Arithmitic Operators

		Matrix2x2t<T>&		operator +=(const T& scalar);
		Matrix2x2t<T>&		operator -=(const T& scalar);
		Matrix2x2t<T>&		operator *=(const T& scalar);
		Matrix2x2t<T>&		operator /=(const T& scalar);
		Matrix2x2t<T>&		operator +=(const Matrix2x2t<T>& mat2x2);
		Matrix2x2t<T>&		operator -=(const Matrix2x2t<T>& mat2x2);
		Matrix2x2t<T>&		operator *=(const Matrix2x2t<T>& mat2x2);
		Matrix2x2t<T>&		operator /= (const Matrix2x2t<T>& mat2x2);

		//Matrix Operations

		template <typename T>		static		Matrix2x2t<T>			transpose(const Matrix2x2t<T>& mat2x2);
		template <typename T>		static		T						determinant(const Matrix2x2t<T>& mat2x2);
		template <typename T>		static		Matrix2x2t<float>		inverse(const Matrix2x2t<T>& mat2x2);
		template <typename T>		static		Matrix2x2t<T>			elementMultiplication(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r);
		template <typename T>		static		Matrix2x2t<T>			elementDivision(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r);
	};
	template <typename T> struct Matrix2x3t {
	private:
		//Data

		Vector2t<T> data[3];

	public:
		//Implicit Constructors

		Matrix2x3t();
		Matrix2x3t(const Matrix2x3t<T>& mat2x3);

		//Explicit Constructors

		explicit	Matrix2x3t(const T& scalar);
		explicit	Matrix2x3t(const Vector2t<T>& col0, const Vector2t<T>& col1, const Vector2t<T>& col2);
		explicit	Matrix2x3t(
			const T& x0, const T& x1, const T& x2,
			const T& y0, const T& y1, const T& y2);

		//Explicit Conversion Constructors

		explicit	Matrix2x3t(const Matrix2x2t<T>& mat2x2);
		template <typename Ta>		explicit	Matrix2x3t(const Matrix2x3t<Ta>& mat2x3);
		explicit	Matrix2x3t(const Matrix2x4t<T>& mat2x4);
		explicit	Matrix2x3t(const Matrix3x2t<T>& mat3x2);
		explicit	Matrix2x3t(const Matrix3x3t<T>& mat3x3);
		explicit	Matrix2x3t(const Matrix3x4t<T>& mat3x4);
		explicit	Matrix2x3t(const Matrix4x2t<T>& mat4x2);
		explicit	Matrix2x3t(const Matrix4x3t<T>& mat4x3);
		explicit	Matrix2x3t(const Matrix4x4t<T>& mat4x4);

		//Data Access

		Vector2t<T>&			operator [](const unsigned short int& index);
		const Vector2t<T>&		operator [](const unsigned short int& index) const;

		//Arithmitic Operators

		Matrix2x3t<T>&		operator +=(const T& scalar);
		Matrix2x3t<T>&		operator -=(const T& scalar);
		Matrix2x3t<T>&		operator *=(const T& scalar);
		Matrix2x3t<T>&		operator /=(const T& scalar);
		Matrix2x3t<T>&		operator +=(const Matrix2x3t<T>& mat2x3);
		Matrix2x3t<T>&		operator -=(const Matrix2x3t<T>& mat2x3);
		Matrix2x3t<T>&		operator *=(const Matrix3x3t<T>& mat3x3);
		Matrix2x3t<T>&		operator /=(const Matrix3x3t<T>& mat3x3);

		//Matrix Operations

		template <typename T>		static		Matrix3x2t<T>		transpose(const Matrix2x3t<T>& mat2x3);
		template <typename T>		static		Matrix2x3t<T>		elementMultiplication(const Matrix2x3t<T>& mat2x3l, const Matrix2x3t<T>& mat2x3r);
		template <typename T>		static		Matrix2x3t<T>		elementDivision(const Matrix2x3t<T>& mat2x3l, const Matrix2x3t<T>& mat2x3r);
	};
	template <typename T> struct Matrix2x4t {
	private:
		//Data

		Vector2t<T> data[4];

	public:
		//Implicit Constructors

		Matrix2x4t();
		Matrix2x4t(const Matrix2x4t<T>& mat2x4);

		//Explicit Constructors

		explicit	Matrix2x4t(const T& scalar);
		explicit	Matrix2x4t(const Vector2t<T>& col0, const Vector2t<T>& col1, const Vector2t<T>& col2, const Vector2t<T>& col3);
		explicit	Matrix2x4t(
			const T& x0, const T& x1, const T& x2, const T& x3,
			const T& y0, const T& y1, const T& y2, const T& y3);

		//Explicit Conversion Constructors

		explicit	Matrix2x4t(const Matrix2x2t<T>& mat2x2);
		explicit	Matrix2x4t(const Matrix2x3t<T>& mat2x3);
		template <typename Ta>		explicit	Matrix2x4t(const Matrix2x4t<Ta>& mat2x4);
		explicit	Matrix2x4t(const Matrix3x2t<T>& mat3x2);
		explicit	Matrix2x4t(const Matrix3x3t<T>& mat3x3);
		explicit	Matrix2x4t(const Matrix3x4t<T>& mat3x4);
		explicit	Matrix2x4t(const Matrix4x2t<T>& mat4x2);
		explicit	Matrix2x4t(const Matrix4x3t<T>& mat4x3);
		explicit	Matrix2x4t(const Matrix4x4t<T>& mat4x4);

		//Data Access

		Vector2t<T>&			operator [](const unsigned short int& index);
		const Vector2t<T>&		operator [](const unsigned short int& index) const;

		//Arithmitic Operators

		Matrix2x4t<T>&		operator +=(const T& scalar);
		Matrix2x4t<T>&		operator -=(const T& scalar);
		Matrix2x4t<T>&		operator *=(const T& scalar);
		Matrix2x4t<T>&		operator /=(const T& scalar);
		Matrix2x4t<T>&		operator +=(const Matrix2x4t<T>& mat2x4);
		Matrix2x4t<T>&		operator -=(const Matrix2x4t<T>& mat2x4);
		Matrix2x4t<T>&		operator *=(const Matrix4x4t<T>& mat4x4);
		Matrix2x4t<T>&		operator /=(const Matrix4x4t<T>& mat4x4);

		//Matrix Operations

		template <typename T>		static		Matrix4x2t<T>		transpose(const Matrix2x4t<T>& mat2x4);
		template <typename T>		static		Matrix2x4t<T>		elementMultiplication(const Matrix2x4t<T>& mat2x4l, const Matrix2x4t<T>& mat2x4r);
		template <typename T>		static		Matrix2x4t<T>		elementDivision(const Matrix2x4t<T>& mat2x4l, const Matrix2x4t<T>& mat2x4r);
	};
	template <typename T> struct Matrix3x2t {
	private:
		//Data

		Vector3t<T> data[2];

	public:
		//Implicit Constructors

		Matrix3x2t();
		Matrix3x2t(const Matrix3x2t<T>& mat3x2);

		//Explicit Constructors

		explicit	Matrix3x2t(const T& scalar);
		explicit	Matrix3x2t(const Vector3t<T>& col0, const Vector3t<T>& col1);
		explicit	Matrix3x2t(
			const T& x0, const T& x1,
			const T& y0, const T& y1,
			const T& z0, const T& z1);

		//Explicit Conversion Constructors

		explicit	Matrix3x2t(const Matrix2x2t<T>& mat2x2);
		explicit	Matrix3x2t(const Matrix2x3t<T>& mat2x3);
		explicit	Matrix3x2t(const Matrix2x4t<T>& mat2x4);
		template <typename Ta>		explicit	Matrix3x2t(const Matrix3x2t<Ta>& mat3x2);
		explicit	Matrix3x2t(const Matrix3x3t<T>& mat3x3);
		explicit	Matrix3x2t(const Matrix3x4t<T>& mat3x4);
		explicit	Matrix3x2t(const Matrix4x2t<T>& mat4x2);
		explicit	Matrix3x2t(const Matrix4x3t<T>& mat4x3);
		explicit	Matrix3x2t(const Matrix4x4t<T>& mat4x4);

		//Data Access

		Vector3t<T>&			operator [](const unsigned short int& index);
		const Vector3t<T>&		operator [](const unsigned short int& index) const;

		//Arithmitic Operators

		Matrix3x2t<T>&		operator +=(const T& scalar);
		Matrix3x3t<T>&		operator -=(const T& scalar);
		Matrix3x3t<T>&		operator *=(const T& scalar);
		Matrix3x2t<T>&		operator /=(const T& scalar);
		Matrix3x2t<T>&		operator +=(const Matrix3x2t<T>& mat3x2);
		Matrix3x3t<T>&		operator -=(const Matrix2x3t<T>& mat3x2);
		Matrix3x2t<T>&		operator *=(const Matrix2x2t<T>& mat2x2);
		Matrix3x2t<T>&		operator /=(const Matrix2x2t<T>& mat2x2);

		//Matrix Operations

		template <typename T>		static		Matrix2x3t<T>		transpose(const Matrix3x2t<T>& mat3x2);
		template <typename T>		static		Matrix3x2t<T>		elementMultiplication(const Matrix3x2t<T>& mat3x2l, const Matrix3x2t<T>& mat3x2r);
		template <typename T>		static		Matrix3x2t<T>		elementDivision(const Matrix3x2t<T>& mat3x2l, const Matrix3x2t<T>& mat3x2r);
	};
	template <typename T> struct Matrix3x3t {
	private:
		//Data

		Vector3t<T> data[3];

	public:
		//Implicit Constructors

		Matrix3x3t();
		Matrix3x3t(const Matrix3x3t<T>& mat3x3);

		//Explicit Constructors

		explicit	Matrix3x3t(const T& scalar);
		explicit	Matrix3x3t(const Vector3t<T>& col0, const Vector3t<T>& col1, const Vector3t<T>& col2);
		explicit	Matrix3x3t(
			const T& x0, const T& x1, const T& x2,
			const T& y0, const T& y1, const T& y2,
			const T& z0, const T& z1, const T& z2);

		//Explicit Conversion Constructors

		explicit	Matrix3x3t(const Matrix2x2t<T>& mat2x2);
		explicit	Matrix3x3t(const Matrix2x3t<T>& mat2x3);
		explicit	Matrix3x3t(const Matrix2x4t<T>& mat2x4);
		explicit	Matrix3x3t(const Matrix3x2t<T>& mat3x2);
		template <typename Ta>		explicit	Matrix3x3t(const Matrix3x3t<Ta>& mat3x3);
		explicit	Matrix3x3t(const Matrix3x4t<T>& mat3x4);
		explicit	Matrix3x3t(const Matrix4x2t<T>& mat4x2);
		explicit	Matrix3x3t(const Matrix4x3t<T>& mat4x3);
		explicit	Matrix3x3t(const Matrix4x4t<T>& mat4x4);

		//Data Access

		Vector3t<T>&			operator [](const unsigned short int& index);
		const Vector3t<T>&		operator [](const unsigned short int& index) const;

		//Arithmitic Operators

		Matrix3x3t<T>&		operator +=(const T& scalar);
		Matrix3x3t<T>&		operator -=(const T& scalar);
		Matrix3x3t<T>&		operator *=(const T& scalar);
		Matrix3x3t<T>&		operator /=(const T& scalar);
		Matrix3x3t<T>&		operator +=(const Matrix3x3t<T>& mat3x3);
		Matrix3x3t<T>&		operator -=(const Matrix3x3t<T>& mat3x3);
		Matrix3x3t<T>&		operator *=(const Matrix3x3t<T>& mat3x3);
		Matrix3x3t<T>&		operator /=(const Matrix3x3t<T>& mat3x3);

		//Matrix Operations

		template <typename T>		static		Matrix3x3t<T>			transpose(const Matrix3x3t<T>& mat3x3);
		template <typename T>		static		T						determinant(const Matrix3x3t<T>& mat3x3);
		template <typename T>		static		Matrix3x3t<float>		inverse(const Matrix3x3t<T>& mat3x3);
		template <typename T>		static		Matrix3x3t<T>			elementMultiplication(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r);
		template <typename T>		static		Matrix3x3t<T>			elementDivision(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r);
	};
	template <typename T> struct Matrix3x4t {
	private:
		//Data

		Vector3t<T> data[4];

	public:
		//Implicit Constructors

		Matrix3x4t();
		Matrix3x4t(const Matrix3x4t<T>& mat3x4);

		//Explicit Constructors

		explicit	Matrix3x4t(const T& scalar);
		explicit	Matrix3x4t(const Vector3t<T>& col0, const Vector3t<T>& col1, const Vector3t<T>& col2, const Vector3t<T>& col3);
		explicit	Matrix3x4t(
			const T& x0, const T& x1, const T& x2, const T& x3,
			const T& y0, const T& y1, const T& y2, const T& y3,
			const T& z0, const T& z1, const T& z2, const T& z3);

		//Explicit Conversion Constructors

		explicit	Matrix3x4t(const Matrix2x2t<T>& mat2x2);
		explicit	Matrix3x4t(const Matrix2x3t<T>& mat2x3);
		explicit	Matrix3x4t(const Matrix2x4t<T>& mat2x4);
		explicit	Matrix3x4t(const Matrix3x2t<T>& mat3x2);
		explicit	Matrix3x4t(const Matrix3x3t<T>& mat3x3);
		template <typename Ta>		explicit	Matrix3x4t(const Matrix3x4t<Ta>& mat3x4);
		explicit	Matrix3x4t(const Matrix4x2t<T>& mat4x2);
		explicit	Matrix3x4t(const Matrix4x3t<T>& mat4x3);
		explicit	Matrix3x4t(const Matrix4x4t<T>& mat4x4);

		//Data Access

		Vector3t<T>&			operator [](const unsigned short int& index);
		const Vector3t<T>&		operator [](const unsigned short int& index) const;

		//Arithmitic Operators

		Matrix3x4t<T>&		operator +=(const T& scalar);
		Matrix3x4t<T>&		operator -=(const T& scalar);
		Matrix3x4t<T>&		operator *=(const T& scalar);
		Matrix3x4t<T>&		operator /=(const T& scalar);
		Matrix3x4t<T>&		operator +=(const Matrix3x4t<T>& mat3x4);
		Matrix3x4t<T>&		operator -=(const Matrix3x4t<T>& mat3x4);
		Matrix3x4t<T>&		operator *=(const Matrix4x4t<T>& mat4x4);
		Matrix3x4t<T>&		operator /=(const Matrix4x4t<T>& mat4x4);

		//Matrix Operations

		template <typename T>		static		Matrix4x3t<T>		transpose(const Matrix3x4t<T>& mat3x4);
		template <typename T>		static		Matrix3x4t<T>		elementMultiplication(const Matrix3x4t<T>& mat3x4l, const Matrix3x4t<T>& mat3x4r);
		template <typename T>		static		Matrix3x4t<T>		elementDivision(const Matrix3x4t<T>& mat3x4l, const Matrix3x4t<T>& mat3x4r);
	};
	template <typename T> struct Matrix4x2t {
	private:
		//Data

		Vector4t<T> data[2];

	public:
		//Implicit Constructors

		Matrix4x2t();
		Matrix4x2t(const Matrix4x2t<T>& mat4x2);

		//Explicit Constructors

		explicit	Matrix4x2t(const T& scalar);
		explicit	Matrix4x2t(const Vector4t<T>& col0, const Vector4t<T>& col1);
		explicit	Matrix4x2t(
			const T& x0, const T& x1,
			const T& y0, const T& y1,
			const T& z0, const T& z1,
			const T& w0, const T& w1);

		//Explicit Conversion Constructors

		explicit	Matrix4x2t(const Matrix2x2t<T>& mat2x2);
		explicit	Matrix4x2t(const Matrix2x3t<T>& mat2x3);
		explicit	Matrix4x2t(const Matrix2x4t<T>& mat2x4);
		explicit	Matrix4x2t(const Matrix3x2t<T>& mat3x2);
		explicit	Matrix4x2t(const Matrix3x3t<T>& mat3x3);
		explicit	Matrix4x2t(const Matrix3x4t<T>& mat3x4);
		template <typename Ta>		explicit	Matrix4x2t(const Matrix4x2t<Ta>& mat4x2);
		explicit	Matrix4x2t(const Matrix4x3t<T>& mat4x3);
		explicit	Matrix4x2t(const Matrix4x4t<T>& mat4x4);

		//Data Access

		Vector4t<T>&			operator [](const unsigned short int& index);
		const Vector4t<T>&		operator [](const unsigned short int& index) const;

		//Arithmitic Operators

		Matrix4x2t<T>&		operator +=(const T& scalar);
		Matrix4x2t<T>&		operator -=(const T& scalar);
		Matrix4x2t<T>&		operator *=(const T& scalar);
		Matrix4x2t<T>&		operator /=(const T& scalar);
		Matrix4x2t<T>&		operator +=(const Matrix4x2t<T>& mat4x2);
		Matrix4x2t<T>&		operator -=(const Matrix4x2t<T>& mat4x2);
		Matrix4x2t<T>&		operator *=(const Matrix2x2t<T>& mat2x2);
		Matrix4x2t<T>&		operator /=(const Matrix2x2t<T>& mat2x2);

		//Matrix Operations

		template <typename T>		static		Matrix2x4t<T>		transpose(const Matrix4x2t<T>& mat4x2);
		template <typename T>		static		Matrix4x2t<T>		elementMultiplication(const Matrix4x2t<T>& mat4x2l, const Matrix4x2t<T>& mat4x2r);
		template <typename T>		static		Matrix4x2t<T>		elementDivision(const Matrix4x2t<T>& mat4x2l, const Matrix4x2t<T>& mat4x2r);
	};
	template <typename T> struct Matrix4x3t {
	private:
		//Data

		Vector4t<T> data[3];

	public:
		//Implicit Constructors

		Matrix4x3t();
		Matrix4x3t(const Matrix4x3t<T>& mat4x3);

		//Explicit Constructors

		explicit	Matrix4x3t(const T& scalar);
		explicit	Matrix4x3t(const Vector4t<T>& col0, const Vector4t<T>& col1, const Vector4t<T>& col2);
		explicit	Matrix4x3t(
			const T& x0, const T& x1, const T& x2,
			const T& y0, const T& y1, const T& y2,
			const T& z0, const T& z1, const T& z2,
			const T& w0, const T& w1, const T& w2);

		//Explicit Conversion Constructors

		explicit	Matrix4x3t(const Matrix2x2t<T>& mat2x2);
		explicit	Matrix4x3t(const Matrix2x3t<T>& mat2x3);
		explicit	Matrix4x3t(const Matrix2x4t<T>& mat2x4);
		explicit	Matrix4x3t(const Matrix3x2t<T>& mat3x2);
		explicit	Matrix4x3t(const Matrix3x3t<T>& mat3x3);
		explicit	Matrix4x3t(const Matrix3x4t<T>& mat3x4);
		explicit	Matrix4x3t(const Matrix4x2t<T>& mat4x2);
		template <typename Ta>		explicit	Matrix4x3t(const Matrix4x3t<Ta>& mat4x3);
		explicit	Matrix4x3t(const Matrix4x4t<T>& mat4x4);

		//Data Access

		Vector4t<T>&			operator [](const unsigned short int& index);
		const Vector4t<T>&		operator [](const unsigned short int& index) const;

		//Arithmitic Operators

		Matrix4x3t<T>&		operator +=(const T& scalar);
		Matrix4x3t<T>&		operator -=(const T& scalar);
		Matrix4x3t<T>&		operator *=(const T& scalar);
		Matrix4x3t<T>&		operator /=(const T& scalar);
		Matrix4x3t<T>&		operator +=(const Matrix4x3t<T>& mat4x3);
		Matrix4x3t<T>&		operator -=(const Matrix4x3t<T>& mat4x3);
		Matrix4x3t<T>&		operator *=(const Matrix3x3t<T>& mat3x3);
		Matrix4x3t<T>&		operator /=(const Matrix3x3t<T>& mat3x3);

		//Matrix Operations

		template <typename T>		static		Matrix3x4t<T>		transpose(const Matrix4x3t<T>& mat4x3);
		template <typename T>		static		Matrix4x3t<T>		elementMultiplication(const Matrix4x3t<T>& mat4x3l, const Matrix4x3t<T>& mat4x3r);
		template <typename T>		static		Matrix4x3t<T>		elementDivision(const Matrix4x3t<T>& mat4x3l, const Matrix4x3t<T>& mat4x3r);
	};
	template <typename T> struct Matrix4x4t {
	private:
		//Data

		Vector4t<T> data[4];

	public:
		//Implicit Constructors

		Matrix4x4t();
		Matrix4x4t(const Matrix4x4t<T>& mat4x4);

		//Explicit Constructors

		explicit	Matrix4x4t(const T& scalar);
		explicit	Matrix4x4t(const Vector4t<T>& col0, const Vector4t<T>& col1, const Vector4t<T>& col2, const Vector4t<T>& col3);
		explicit	Matrix4x4t(
			const T& x0, const T& x1, const T& x2, const T& x3,
			const T& y0, const T& y1, const T& y2, const T& y3,
			const T& z0, const T& z1, const T& z2, const T& z3,
			const T& w0, const T& w1, const T& w2, const T& w3);

		//Explicit Conversion Constructors

		explicit	Matrix4x4t(const Matrix2x2t<T>& mat2x2);
		explicit	Matrix4x4t(const Matrix2x3t<T>& mat2x3);
		explicit	Matrix4x4t(const Matrix2x4t<T>& mat2x4);
		explicit	Matrix4x4t(const Matrix3x2t<T>& mat3x2);
		explicit	Matrix4x4t(const Matrix3x3t<T>& mat3x3);
		explicit	Matrix4x4t(const Matrix3x4t<T>& mat3x4);
		explicit	Matrix4x4t(const Matrix4x2t<T>& mat4x2);
		explicit	Matrix4x4t(const Matrix4x3t<T>& mat4x3);
		template <typename Ta>		explicit	Matrix4x4t(const Matrix4x4t<Ta>& mat4x4);

		//Data Access

		Vector4t<T>&			operator [](const unsigned short int& index);
		const Vector4t<T>&		operator [](const unsigned short int& index) const;

		//Arithmitic Operators

		Matrix4x4t<T>&		operator +=(const T& scalar);
		Matrix4x4t<T>&		operator -=(const T& scalar);
		Matrix4x4t<T>&		operator *=(const T& scalar);
		Matrix4x4t<T>&		operator /=(const T& scalar);
		Matrix4x4t<T>&		operator +=(const Matrix4x4t<T>& mat4x4);
		Matrix4x4t<T>&		operator -=(const Matrix4x4t<T>& mat4x4);
		Matrix4x4t<T>&		operator *=(const Matrix4x4t<T>& mat4x4);
		Matrix4x4t<T>&		operator /=(const Matrix4x4t<T>& mat4x4);

		//Matrix Operations

		template <typename T>		static		Matrix4x4t<T>			transpose(const Matrix4x4t<T>& mat4x4);
		template <typename T>		static		T						determinant(const Matrix4x4t<T>& mat4x4);
		template <typename T>		static		Matrix4x4t<float>		inverse(const Matrix4x4t<T>& mat4x4);
		template <typename T>		static		Matrix4x4t<T>			elementMultiplication(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r);
		template <typename T>		static		Matrix4x4t<T>			elementDivision(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r);
	};


	//Matrix2x2 Arithmitic Operators

	template <typename T>		Matrix2x2t<T>		operator -(const Matrix2x2t<T>& mat2x2);
	template <typename T>		Matrix2x2t<T>		operator +(const Matrix2x2t<T>& mat2x2, const T& scalar);
	template <typename T>		Matrix2x2t<T>		operator -(const Matrix2x2t<T>& mat2x2, const T& scalar);
	template <typename T>		Matrix2x2t<T>		operator *(const Matrix2x2t<T>& mat2x2, const T& scalar);
	template <typename T>		Matrix2x2t<T>		operator /(const Matrix2x2t<T>& mat2x2, const T& scalar);
	template <typename T>		Matrix2x2t<T>		operator +(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r);
	template <typename T>		Matrix2x2t<T>		operator -(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r);
	template <typename T>		Vector2t<T>			operator *(const Matrix2x2t<T>& mat2x2, const Vector2t<T>& vec2);
	template <typename T>		Matrix2x2t<T>		operator *(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r);
	template <typename T>		Matrix2x3t<T>		operator *(const Matrix2x2t<T>& mat2x2, const Matrix2x3t<T>& mat2x3);
	template <typename T>		Matrix2x4t<T>		operator *(const Matrix2x2t<T>& mat2x2, const Matrix2x4t<T>& mat2x4);
	template <typename T>		Matrix2x2t<T>		operator /(const Matrix2x2t<T>& mat2x2l, const Matrix2x2t<T>& mat2x2r);

	//Matrix2x3 Arithmitic Operators

	template <typename T>		Matrix2x3t<T>		operator -(const Matrix2x3t<T>& mat2x3);
	template <typename T>		Matrix2x3t<T>		operator +(const Matrix2x3t<T>& mat2x3, const T& scalar);
	template <typename T>		Matrix2x3t<T>		operator -(const Matrix2x3t<T>& mat2x3, const T& scalar);
	template <typename T>		Matrix2x3t<T>		operator *(const Matrix2x3t<T>& mat2x3, const T& scalar);
	template <typename T>		Matrix2x3t<T>		operator /(const Matrix2x3t<T>& mat2x3, const T& scalar);
	template <typename T>		Matrix2x3t<T>		operator +(const Matrix2x3t<T>& mat2x3l, const Matrix2x3t<T>& mat2x3r);
	template <typename T>		Matrix2x3t<T>		operator -(const Matrix2x3t<T>& mat2x3l, const Matrix2x3t<T>& mat2x3r);
	template <typename T>		Vector2t<T>			operator *(const Matrix2x3t<T>& mat2x3, const Vector3t<T>& vec3);
	template <typename T>		Matrix2x2t<T>		operator *(const Matrix2x3t<T>& mat2x3, const Matrix3x2t<T>& mat3x2);
	template <typename T>		Matrix2x3t<T>		operator *(const Matrix2x3t<T>& mat2x3, const Matrix3x3t<T>& mat3x3);
	template <typename T>		Matrix2x4t<T>		operator *(const Matrix2x3t<T>& mat2x3, const Matrix3x4t<T>& mat3x4);
	template <typename T>		Matrix2x3t<T>		operator /(const Matrix2x3t<T>& mat2x3, const Matrix3x3t<T>& mat3x3);

	//Matrix2x4 Arithmitic Operators

	template <typename T>		Matrix2x4t<T>		operator -(const Matrix2x4t<T>& mat2x4);
	template <typename T>		Matrix2x4t<T>		operator +(const Matrix2x4t<T>& mat2x4, const T& scalar);
	template <typename T>		Matrix2x4t<T>		operator -(const Matrix2x4t<T>& mat2x4, const T& scalar);
	template <typename T>		Matrix2x4t<T>		operator *(const Matrix2x4t<T>& mat2x4, const T& scalar);
	template <typename T>		Matrix2x4t<T>		operator /(const Matrix2x4t<T>& mat2x4, const T& scalar);
	template <typename T>		Matrix2x4t<T>		operator +(const Matrix2x4t<T>& mat2x4l, const Matrix2x4t<T>& mat2x4r);
	template <typename T>		Matrix2x4t<T>		operator -(const Matrix2x4t<T>& mat2x4l, const Matrix2x4t<T>& mat2x4r);
	template <typename T>		Vector2t<T>			operator *(const Matrix2x4t<T>& mat2x4, const Vector4t<T>& vec4);
	template <typename T>		Matrix2x2t<T>		operator *(const Matrix2x4t<T>& mat2x4, const Matrix4x2t<T>& mat4x2);
	template <typename T>		Matrix2x3t<T>		operator *(const Matrix2x4t<T>& mat2x4, const Matrix4x3t<T>& mat4x3);
	template <typename T>		Matrix2x4t<T>		operator *(const Matrix2x4t<T>& mat2x4, const Matrix4x4t<T>& mat4x4);
	template <typename T>		Matrix2x4t<T>		operator /(const Matrix2x4t<T>& mat2x4, const Matrix4x4t<T>& mat4x4);

	//Matrix3x2 Arithmitic Operators

	template <typename T>		Matrix3x2t<T>		operator -(const Matrix3x2t<T>& mat3x2);
	template <typename T>		Matrix3x2t<T>		operator +(const Matrix3x2t<T>& mat3x2, const T& scalar);
	template <typename T>		Matrix3x2t<T>		operator -(const Matrix3x2t<T>& mat3x2, const T& scalar);
	template <typename T>		Matrix3x2t<T>		operator *(const Matrix3x2t<T>& mat3x2, const T& scalar);
	template <typename T>		Matrix3x2t<T>		operator /(const Matrix3x2t<T>& mat3x2, const T& scalar);
	template <typename T>		Matrix3x2t<T>		operator +(const Matrix3x2t<T>& mat3x2l, const Matrix3x2t<T>& mat3x2r);
	template <typename T>		Matrix3x2t<T>		operator -(const Matrix3x2t<T>& mat3x2l, const Matrix3x2t<T>& mat3x2r);
	template <typename T>		Vector3t<T>			operator *(const Matrix3x2t<T>& mat3x2, const Vector2t<T>& vec2);
	template <typename T>		Matrix3x2t<T>		operator *(const Matrix3x2t<T>& mat3x2, const Matrix2x2t<T>& mat2x2);
	template <typename T>		Matrix3x3t<T>		operator *(const Matrix3x2t<T>& mat3x2, const Matrix2x3t<T>& mat2x3);
	template <typename T>		Matrix3x4t<T>		operator *(const Matrix3x2t<T>& mat3x2, const Matrix2x4t<T>& mat2x4);
	template <typename T>		Matrix3x2t<T>		operator /(const Matrix3x2t<T>& mat3x2, const Matrix2x2t<T> mat2x2);

	//Matrix3x3 Arithmitic Operators

	template <typename T>		Matrix3x3t<T>		operator -(const Matrix3x3t<T>& mat3x3);
	template <typename T>		Matrix3x3t<T>		operator +(const Matrix3x3t<T>& mat3x3, const T& scalar);
	template <typename T>		Matrix3x3t<T>		operator -(const Matrix3x3t<T>& mat3x3, const T& scalar);
	template <typename T>		Matrix3x3t<T>		operator *(const Matrix3x3t<T>& mat3x3, const T& scalar);
	template <typename T>		Matrix3x3t<T>		operator /(const Matrix3x3t<T>& mat3x3, const T& scalar);
	template <typename T>		Matrix3x3t<T>		operator +(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r);
	template <typename T>		Matrix3x3t<T>		operator -(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r);
	template <typename T>		Vector3t<T>			operator *(const Matrix3x3t<T>& mat3x3, const Vector3t<T>& vec3);
	template <typename T>		Matrix3x2t<T>		operator *(const Matrix3x3t<T>& mat3x3, const Matrix3x2t<T>& mat3x2);
	template <typename T>		Matrix3x3t<T>		operator *(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r);
	template <typename T>		Matrix3x4t<T>		operator *(const Matrix3x3t<T>& mat3x3, const Matrix3x4t<T>& mat3x4);
	template <typename T>		Matrix3x3t<T>		operator /(const Matrix3x3t<T>& mat3x3l, const Matrix3x3t<T>& mat3x3r);

	//Matrix3x4 Arithmitic Operators

	template <typename T>		Matrix3x4t<T>		operator -(const Matrix3x4t<T>& mat3x4);
	template <typename T>		Matrix3x4t<T>		operator +(const Matrix3x4t<T>& mat3x4, const T& scalar);
	template <typename T>		Matrix3x4t<T>		operator -(const Matrix3x4t<T>& mat3x4, const T& scalar);
	template <typename T>		Matrix3x4t<T>		operator *(const Matrix3x4t<T>& mat3x4, const T& scalar);
	template <typename T>		Matrix3x4t<T>		operator /(const Matrix3x4t<T>& mat3x4, const T& scalar);
	template <typename T>		Matrix3x4t<T>		operator +(const Matrix3x4t<T>& mat3x4l, const Matrix3x4t<T>& mat3x4r);
	template <typename T>		Matrix3x4t<T>		operator -(const Matrix3x4t<T>& mat3x4l, const Matrix3x4t<T>& mat3x4r);
	template <typename T>		Vector3t<T>			operator *(const Matrix3x4t<T>& mat3x4, const Vector4t<T>& vec4);
	template <typename T>		Matrix3x2t<T>		operator *(const Matrix3x4t<T>& mat3x4, const Matrix4x2t<T>& mat4x2);
	template <typename T>		Matrix3x3t<T>		operator *(const Matrix3x4t<T>& mat3x4, const Matrix4x3t<T>& mat4x3);
	template <typename T>		Matrix3x4t<T>		operator *(const Matrix3x4t<T>& mat3x4, const Matrix4x4t<T>& mat4x4);
	template <typename T>		Matrix3x4t<T>		operator /(const Matrix3x4t<T>& mat3x4, const Matrix4x4t<T>& mat4x4);

	//Matrix4x2 Arithmitic Operators

	template <typename T>		Matrix4x2t<T>		operator -(const Matrix4x2t<T>& mat4x2);
	template <typename T>		Matrix4x2t<T>		operator +(const Matrix4x2t<T>& mat4x2, const T& scalar);
	template <typename T>		Matrix4x2t<T>		operator -(const Matrix4x2t<T>& mat4x2, const T& scalar);
	template <typename T>		Matrix4x2t<T>		operator *(const Matrix4x2t<T>& mat4x2, const T& scalar);
	template <typename T>		Matrix4x2t<T>		operator /(const Matrix4x2t<T>& mat4x2, const T& scalar);
	template <typename T>		Matrix4x2t<T>		operator +(const Matrix4x2t<T>& mat4x2l, const Matrix4x2t<T>& mat4x2r);
	template <typename T>		Matrix4x2t<T>		operator -(const Matrix4x2t<T>& mat4x2l, const Matrix4x2t<T>& mat4x2r);
	template <typename T>		Vector4t<T>			operator *(const Matrix4x2t<T>& mat4x2, const Vector2t<T>& vec2);
	template <typename T>		Matrix4x2t<T>		operator *(const Matrix4x2t<T>& mat4x2, const Matrix2x2t<T>& mat2x2);
	template <typename T>		Matrix4x3t<T>		operator *(const Matrix4x2t<T>& mat4x2, const Matrix2x3t<T>& mat2x3);
	template <typename T>		Matrix4x4t<T>		operator *(const Matrix4x2t<T>& mat4x2, const Matrix2x4t<T>& mat2x4);
	template <typename T>		Matrix4x2t<T>		operator /(const Matrix4x2t<T>& mat4x2, const Matrix2x2t<T>& mat2x2);

	//Matrix4x3 Arithmitic Operators

	template <typename T>		Matrix4x3t<T>		operator -(const Matrix4x3t<T>& mat4x3);
	template <typename T>		Matrix4x3t<T>		operator +(const Matrix4x3t<T>& mat4x3, const T& scalar);
	template <typename T>		Matrix4x3t<T>		operator -(const Matrix4x3t<T>& mat4x3, const T& scalar);
	template <typename T>		Matrix4x3t<T>		operator *(const Matrix4x3t<T>& mat4x3, const T& scalar);
	template <typename T>		Matrix4x3t<T>		operator /(const Matrix4x3t<T>& mat4x3, const T& scalar);
	template <typename T>		Matrix4x3t<T>		operator +(const Matrix4x3t<T>& mat4x3l, const Matrix4x3t<T>& mat4x3r);
	template <typename T>		Matrix4x3t<T>		operator -(const Matrix4x3t<T>& mat4x3l, const Matrix4x3t<T>& mat4x3r);
	template <typename T>		Vector4t<T>			operator *(const Matrix4x3t<T>& mat4x3, const Vector3t<T>& vec3);
	template <typename T>		Matrix4x2t<T>		operator *(const Matrix4x3t<T>& mat4x3, const Matrix3x2t<T>& mat3x2);
	template <typename T>		Matrix4x3t<T>		operator *(const Matrix4x3t<T>& mat4x3, const Matrix3x3t<T>& mat3x3);
	template <typename T>		Matrix4x4t<T>		operator *(const Matrix4x3t<T>& mat4x3, const Matrix3x4t<T>& mat3x4);
	template <typename T>		Matrix4x3t<T>		operator /(const Matrix4x3t<T>& mat4x3, const Matrix3x3t<T>& mat3x3);

	//Matrix4x4 Arithmitic Operators

	template <typename T>		Matrix4x4t<T>		operator -(const Matrix4x4t<T>& mat4x4);
	template <typename T>		Matrix4x4t<T>		operator +(const Matrix4x4t<T>& mat4x4, const T& scalar);
	template <typename T>		Matrix4x4t<T>		operator -(const Matrix4x4t<T>& mat4x4, const T& scalar);
	template <typename T>		Matrix4x4t<T>		operator *(const Matrix4x4t<T>& mat4x4, const T& scalar);
	template <typename T>		Matrix4x4t<T>		operator /(const Matrix4x4t<T>& mat4x4, const T& scalar);
	template <typename T>		Matrix4x4t<T>		operator +(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r);
	template <typename T>		Matrix4x4t<T>		operator -(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r);
	template <typename T>		Vector4t<T>			operator *(const Matrix4x4t<T>& mat4x4, const Vector4t<T>& vec4);
	template <typename T>		Matrix4x2t<T>		operator *(const Matrix4x4t<T>& mat4x4, const Matrix4x2t<T>& mat4x2);
	template <typename T>		Matrix4x3t<T>		operator *(const Matrix4x4t<T>& mat4x4, const Matrix4x3t<T>& mat4x3);
	template <typename T>		Matrix4x4t<T>		operator *(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r);
	template <typename T>		Matrix4x4t<T>		operator /(const Matrix4x4t<T>& mat4x4l, const Matrix4x4t<T>& mat4x4r);
}}

#include "../src/core/math/XMatrix.inl"

#endif // !X_MATRIX
