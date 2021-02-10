
//==================================================================================\\
//FILE NAME:			XVector.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#ifndef X_VECTOR_H
#define X_VECTOR_H

namespace X {	namespace Math {

	template <typename T> struct Vector2t;
	template <typename T> struct Vector3t;
	template <typename T> struct Vector4t;


	//Vector Struct Declerations:

	template <typename T> struct Vector2t {
		//Data
		union { T x, u, s; };
		union { T y, v, t; };


		//Implicit Constructors

		Vector2t();
		Vector2t(const Vector2t<T>& vec2);

		//Explicit Constructors

		explicit	Vector2t(const T& scalar);
		explicit	Vector2t(const T& x, const T & y);

		//Explicit Template Constucors

		template <typename Ta>					explicit	Vector2t(const Ta& scalar);
		template <typename Ta, typename Tb>		explicit	Vector2t(const Ta& x, const Tb& y);

		template <typename Ta>		explicit	Vector2t(const Vector2t<Ta>& vec2);
		template <typename Ta>		explicit	Vector2t(const Vector3t<Ta>& vec3);
		template <typename Ta>		explicit	Vector2t(const Vector4t<Ta>& vec4);


		//Data Access

		T& operator [](const unsigned short int& index);
		const T& operator [](const unsigned short int& index) const;


		//Arithmitic Operators

		Vector2t<T>& operator =(const Vector2t<T>& vec2);
		template <typename Ta>		Vector2t<T>& operator =(const Vector2t<Ta>& vec2);

		template <typename Ta>		Vector2t<T>& operator +=(const Ta& scalar);
		template <typename Ta>		Vector2t<T>& operator -=(const Ta& scalar);
		template <typename Ta>		Vector2t<T>& operator *=(const Ta& scalar);
		template <typename Ta>		Vector2t<T>& operator /=(const Ta& scalar);

		Vector2t<T>& operator ++();
		Vector2t<T>& operator --();

		template <typename Ta>		Vector2t<T>& operator +=(const Vector2t<Ta>& vec2);
		template <typename Ta>		Vector2t<T>& operator -=(const Vector2t<Ta>& vec2);
		template <typename Ta>		Vector2t<T>& operator *=(const Vector2t<Ta>& vec2);
		template <typename Ta>		Vector2t<T>& operator /=(const Vector2t<Ta>& vec2);


		//Vector Operations

		template <typename T>	static		long double			magnitude(const Vector2t<T>& vec2);
		template <typename T>	static		T					dot(const Vector2t<T>& vec2a, const Vector2t<T>& vec2b);
		template <typename T>	static		Vector2t<T>			normalize(const Vector2t<T>& vec2);
	};
	template <typename T> struct Vector3t {
		//Data

		union { T x, r, s; };
		union { T y, g, t; };
		union { T z, b, p; };

		//Implicit Constructors

		Vector3t();
		Vector3t(const Vector3t<T>& vec3);

		//Explicit Constructors

		explicit	Vector3t(const T& scalar);
		explicit	Vector3t(const T& x, const T& y, const T& z);

		//Explicit Template Constructors

		template <typename Ta>								explicit	Vector3t(const Ta& scalar);
		template <typename Ta, typename Tb, typename Tc>	explicit	Vector3t(const Ta& x, const Tb& y, const Tc& z);

		template <typename Ta, typename Tb>		explicit	Vector3t(const Vector2t<Ta>& vec2, const Tb& z);
		template <typename Ta, typename Tb>		explicit	Vector3t(const Ta& x, const Vector2t<Tb>& vec2);
		template <typename Ta>					explicit	Vector3t(const Vector3t<Ta>& vec3);
		template <typename Ta>					explicit	Vector3t(const Vector4t<Ta>& vec4);


		//Data Access

		T& operator [](const unsigned short int& index);
		const T& operator [](const unsigned short int& index) const;


		//Arithmitic Operators

		Vector3t<T>& operator =(const Vector3t<T>& vec3);
		template <typename Ta>		Vector3t<T>& operator =(const Vector3t<Ta>& vec3);

		template <typename Ta>		Vector3t<T>& operator +=(const Ta& scalar);
		template <typename Ta>		Vector3t<T>& operator -=(const Ta& scalar);
		template <typename Ta>		Vector3t<T>& operator *=(const Ta& scalar);
		template <typename Ta>		Vector3t<T>& operator /=(const Ta& scalar);

		Vector3t<T>& operator ++();
		Vector3t<T>& operator --();

		template <typename Ta>		Vector3t<T>& operator +=(const Vector3t<Ta>& vec3);
		template <typename Ta>		Vector3t<T>& operator -=(const Vector3t<Ta>& vec3);
		template <typename Ta>		Vector3t<T>& operator *=(const Vector3t<Ta>& vec3);
		template <typename Ta>		Vector3t<T>& operator /=(const Vector3t<Ta>& vec3);


		//Vector Operations

		template <typename T>	static		long double			magnitude(const Vector3t<T>& vec3);
		template <typename T>	static		T					dot(const Vector3t<T>& vec3a, const Vector3t<T>& vec3b);
		template <typename T>	static		Vector3t<T>			cross(const Vector3t<T>& vec3a, const Vector3t<T>& vec3b);
		template <typename T>	static		Vector3t<T>			normalize(const Vector3t<T>& vec3);
	};
	template <typename T> struct Vector4t {
		//Data

		union { T x, r; };
		union { T y, g; };
		union { T z, b; };
		union { T w, a; };


		//Implicit Constructors

		Vector4t();
		Vector4t(const Vector4t<T>& vec4);

		//Explicit Constructors

		explicit	Vector4t(const T& scalar);
		explicit	Vector4t(const T& x, const T& y, const T& z, const T& w);

		//Explicit Template Constructors

		template <typename Ta>												explicit	Vector4t(const Ta& scalar);
		template <typename Ta, typename Tb, typename Tc, typename Td>		explicit	Vector4t(const Ta& x, const Tb& y, const Tc& z, const Td& w);

		template <typename Ta, typename Tb, typename Tc>	explicit	Vector4t(const Vector2t<Ta>& vec2, const Tb& z, const Tc& w);
		template <typename Ta, typename Tb, typename Tc>	explicit	Vector4t(const Ta& x, const Vector2t<Tb>& vec2, const Tc& w);
		template <typename Ta, typename Tb, typename Tc>	explicit	Vector4t(const Ta& x, const Tb& y, const Vector2t<Tc>& vec2);
		template <typename Ta, typename Tb>					explicit	Vector4t(const Vector2t<Ta>& vec2a, const Vector2t<Tb>& vec2b);
		template <typename Ta, typename Tb>					explicit	Vector4t(const Vector3t<Ta>& vec3, const Tb& w);
		template <typename Ta, typename Tb>					explicit	Vector4t(const Ta& x, const Vector3t<Tb>& vec3);
		template <typename Ta>								explicit	Vector4t(const Vector4t<Ta>& vec4);


		//Data Access

		T& operator [](const unsigned short int& index);
		const T& operator [](const unsigned short int& index) const;


		//Arithmitic Operators

		Vector4t<T>& operator =(const Vector4t<T>& vec4);
		template <typename Ta>		Vector4t<T>& operator =(const Vector4t<Ta>& vec4);

		template <typename Ta>		Vector4t<T>& operator +=(const Ta& scalar);
		template <typename Ta>		Vector4t<T>& operator -=(const Ta& scalar);
		template <typename Ta>		Vector4t<T>& operator *=(const Ta& scalar);
		template <typename Ta>		Vector4t<T>& operator /=(const Ta& scalar);

		Vector4t<T> & operator ++();
		Vector4t<T> & operator --();

		template <typename Ta>		Vector4t<T>& operator +=(const Vector4t<Ta>& vec4);
		template <typename Ta>		Vector4t<T>& operator -=(const Vector4t<Ta>& vec4);
		template <typename Ta>		Vector4t<T>& operator *=(const Vector4t<Ta>& vec4);
		template <typename Ta>		Vector4t<T>& operator /=(const Vector4t<Ta>& vec4);


		//Vector Operations

		template <typename T>	static		long double			magnitude(const Vector4t<T>& vec4);
		template <typename T>	static		T					dot(const Vector4t<T>& vec4a, const Vector4t<T>& vec4b);
		template <typename T>	static		Vector4t<T>			normalize(const Vector4t<T>& vec4);
	};


	//Vector2 Arithmitc Operators

	template <typename T>	Vector2t<T> operator -(const Vector2t<T>& vec2);
	template <typename T>	Vector2t<T> operator +(const Vector2t<T>& vec2, const T& scalar);
	template <typename T>	Vector2t<T> operator -(const Vector2t<T>& vec2, const T& scalar);
	template <typename T>	Vector2t<T> operator *(const Vector2t<T>& vec2, const T& scalar);
	template <typename T>	Vector2t<T> operator /(const Vector2t<T>& vec2, const T& scalar);

	template <typename T>	Vector2t<T> operator +(const Vector2t<T>& vec2lhs, const Vector2t<T>& vec2rhs);
	template <typename T>	Vector2t<T> operator -(const Vector2t<T>& vec2lhs, const Vector2t<T>& vec2rhs);
	template <typename T>	Vector2t<T> operator *(const Vector2t<T>& vec2lhs, const Vector2t<T>& vec2rhs);
	template <typename T>	Vector2t<T> operator /(const Vector2t<T>& vec2lhs, const Vector2t<T>& vec2rhs);

	//Vector3 Aritmitic Operators

	template <typename T>	Vector3t<T> operator -(const Vector3t<T>& vec3);
	template <typename T>	Vector3t<T> operator +(const Vector3t<T>& vec3, const T& scalar);
	template <typename T>	Vector3t<T> operator -(const Vector3t<T>& vec3, const T& scalar);
	template <typename T>	Vector3t<T> operator *(const Vector3t<T>& vec3, const T& scalar);
	template <typename T>	Vector3t<T> operator /(const Vector3t<T>& vec3, const T& scalar);

	template <typename T>	Vector3t<T> operator +(const Vector3t<T>& vec3lhs, const Vector3t<T>& vec3rhs);
	template <typename T>	Vector3t<T> operator -(const Vector3t<T>& vec3lhs, const Vector3t<T>& vec3rhs);
	template <typename T>	Vector3t<T> operator *(const Vector3t<T>& vec3lhs, const Vector3t<T>& vec3rhs);
	template <typename T>	Vector3t<T> operator /(const Vector3t<T>& vec3lhs, const Vector3t<T>& vec3rhs);

	//Vector4 Arithmitic Operators

	template <typename T>	Vector4t<T> operator -(const Vector4t<T>& vec4);
	template <typename T>	Vector4t<T> operator +(const Vector4t<T>& vec4, const T& scalar);
	template <typename T>	Vector4t<T> operator -(const Vector4t<T>& vec4, const T& scalar);
	template <typename T>	Vector4t<T> operator *(const Vector4t<T>& vec4, const T& scalar);
	template <typename T>	Vector4t<T> operator /(const Vector4t<T>& vec4, const T& scalar);

	template <typename T>	Vector4t<T> operator +(const Vector4t<T>& vec4lhs, const Vector4t<T>& vec4rhs);
	template <typename T>	Vector4t<T> operator -(const Vector4t<T>& vec4lhs, const Vector4t<T>& vec4rhs);
	template <typename T>	Vector4t<T> operator *(const Vector4t<T>& vec4lhs, const Vector4t<T>& vec4rhs);
	template <typename T>	Vector4t<T> operator /(const Vector4t<T>& vec4lhs, const Vector4t<T>& vec4rhs);
}}

#include "../src/core/math/XVector.inl"

#endif // !X_VECTOR
