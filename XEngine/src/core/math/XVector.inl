
//==================================================================================\\
//FILE NAME:			XVector.inl													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#include "core\math\XVector.h"
#include <cassert> 


namespace X {	namespace Math {
	//Vector2t Struct Definitions:

	template <typename T>														Vector2t<T>::Vector2t()
		: x(0), y(0) {	}
	template <typename T>														Vector2t<T>::Vector2t(const Vector2t<T>& vec2)
		: x(vec2.x), y(vec2.y) {	}
	template <typename T>												Vector2t<T>::Vector2t(const T& scalar)
		: x(scalar), y(scalar) {	}
	template <typename T>												Vector2t<T>::Vector2t(const T& x, const T & y)
		: x(x), y(y) {	}
	template <typename T> template <typename Ta>						Vector2t<T>::Vector2t(const Ta& scalar)
		: x(static_cast<T>(scalar)), y(static_cast<T>(scalar)) {	}
	template <typename T> template <typename Ta, typename Tb>			Vector2t<T>::Vector2t(const Ta& x, const Tb& y)
		: x(static_cast<T>(x)), y(static_cast<T>(y)) {	}
	template <typename T> template <typename Ta>						Vector2t<T>::Vector2t(const Vector2t<Ta>& vec2)
		: x(static_cast<T>(vec2.x)), y(static_cast<T>(vec2.y)) {	}
	template <typename T> template <typename Ta>						Vector2t<T>::Vector2t(const Vector3t<Ta>& vec3)
		: x(static_cast<T>(vec3.x)), y(static_cast<T>(vec3.y)) {	}
	template <typename T> template <typename Ta>						Vector2t<T>::Vector2t(const Vector4t<Ta>& vec4)
		: x(static_cast<T>(vec4.x)), y(static_cast<T>(vec4.y)) {	}

	template <typename T>	T&			Vector2t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 2);
		return (&this->x)[index];
	}
	template <typename T>	const T&	Vector2t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 2);
		return (&this->x)[index];
	}

	template <typename T>								Vector2t<T>&	Vector2t<T>::operator =(const Vector2t<T>& vec2) {
		this->x = vec2.x;
		this->y = vec2.y;

		return *this;
	}
	template <typename T> template <typename Ta>		Vector2t<T>&	Vector2t<T>::operator =(const Vector2t<Ta>& vec2) {
		this->x = static_cast<T>(vec2.x);
		this->y = static_cast<T>(vec2.y);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector2t<T>&	Vector2t<T>::operator +=(const Ta& scalar) {
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector2t<T>&	Vector2t<T>::operator -=(const Ta& scalar) {
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector2t<T>&	Vector2t<T>::operator *=(const Ta& scalar) {
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector2t<T>&	Vector2t<T>::operator /=(const Ta& scalar) {
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);

		return *this;
	}
	template <typename T>								Vector2t<T>&	Vector2t<T>::operator ++() {
		this->x++;
		this->y++;

		return *this;
	}
	template <typename T>								Vector2t<T>&	Vector2t<T>::operator --() {
		this->x--;
		this->y--;

		return *this;
	}
	template <typename T> template <typename Ta>		Vector2t<T>&	Vector2t<T>::operator +=(const Vector2t<Ta>& vec2) {
		this->x += static_cast<T>(vec2.x);
		this->y += static_cast<T>(vec2.y);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector2t<T>&	Vector2t<T>::operator -=(const Vector2t<Ta>& vec2) {
		this->x -= static_cast<T>(vec2.x);
		this->y -= static_cast<T>(vec2.y);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector2t<T>&	Vector2t<T>::operator *=(const Vector2t<Ta>& vec2) {
		this->x *= static_cast<T>(vec2.x);
		this->y *= static_cast<T>(vec2.y);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector2t<T>&	Vector2t<T>::operator /=(const Vector2t<Ta>& vec2) {
		this->x /= static_cast<T>(vec2.x);
		this->y /= static_cast<T>(vec2.y);

		return *this;
	}
	
	template <typename T> template <typename Ta>		long double			Vector2t<T>::magnitude(const Vector2t<Ta>& vec2) {
		long double mag = sqrt(pow(static_cast<long double>(vec2.x), 2.0l) + pow(static_cast<long double>(vec2.y), 2.0l));

		return mag;
	}
	template <typename T> template <typename Ta>		Ta					Vector2t<T>::dot(const Vector2t<Ta>& vec2a, const Vector2t<Ta>& vec2b) {
		Ta  dot = vec2a.x * vec2b.x + vec2a.y * vec2b.y;

		return dot;
	}
	template <typename T> template <typename Ta>		Vector2t<Ta>		Vector2t<T>::normalize(const Vector2t<Ta>& vec2) {
		Vector2t<Ta> norm;

		long double mag = magnitude(vec2);;

		norm.x = vec2.x / mag;
		norm.y = vec2.y / mag;

		return norm;
	}

	//Vector3t Struct Definitions:

	template <typename T>																	Vector3t<T>::Vector3t()
		: x(0), y(0), z(0) {	}
	template <typename T>																	Vector3t<T>::Vector3t(const Vector3t<T>& vec3)
		: x(vec3.x), y(vec3.y), z(vec3.z) {	}
	template <typename T>															Vector3t<T>::Vector3t(const T& scalar)
		: x(scalar), y(scalar), z(scalar) {	}
	template <typename T>															Vector3t<T>::Vector3t(const T& x, const T& y, const T& z)
		: x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)) {	}
	template <typename T> template <typename Ta>									Vector3t<T>::Vector3t(const Ta& scalar)
		: x(static_cast<T>(scalar)), y(static_cast<T>(scalar)), z(static_cast<T>(scalar)) {	}
	template <typename T> template <typename Ta, typename Tb, typename Tc>			Vector3t<T>::Vector3t(const Ta& x, const Tb& y, const Tc& z)
		: x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)) {	}
	template <typename T> template <typename Ta, typename Tb>						Vector3t<T>::Vector3t(const Vector2t<Ta>& vec2, const Tb& z)
		: x(static_cast<T>(vec2.x)), y(static_cast<T>(vec2.y)), z(static_cast<T>(z)) {	}
	template <typename T> template <typename Ta, typename Tb>						Vector3t<T>::Vector3t(const Ta& x, const Vector2t<Tb>& vec2)
		: x(static_cast<T>(x)), y(static_cast<T>(vec2.x)), z(static_cast<T>(vec2.y)) {	}
	template <typename T> template <typename Ta>									Vector3t<T>::Vector3t(const Vector3t<Ta>& vec3)
		: x(static_cast<T>(vec3.x)), y(static_cast<T>(vec3.y)), z(static_cast<T>(vec3.z)) {	}
	template <typename T> template <typename Ta>									Vector3t<T>::Vector3t(const Vector4t<Ta>& vec4)
		: x(static_cast<T>(vec4.x)), y(static_cast<T>(vec4.y)), z(static_cast<T>(vec4.z)) {	}

	template <typename T> T&			Vector3t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 3);
		return (&this->x)[index];
	}
	template <typename T> const T&		Vector3t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 3);
		return (&this->x)[index];
	}

	template <typename T>								Vector3t<T>&	Vector3t<T>::operator =(const Vector3t<T>& vec3) {
		this->x = vec3.x;
		this->y = vec3.y;
		this->z = vec3.z;

		return *this;
	}
	template <typename T> template <typename Ta>		Vector3t<T>&	Vector3t<T>::operator =(const Vector3t<Ta>& vec3) {
		this->x = static_cast<T>(vec3.x);
		this->y = static_cast<T>(vec3.y);
		this->z = static_cast<T>(vec3.z);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector3t<T>&	Vector3t<T>::operator +=(const Ta& scalar) {
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector3t<T>&	Vector3t<T>::operator -=(const Ta& scalar) {
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector3t<T>&	Vector3t<T>::operator *=(const Ta& scalar) {
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector3t<T>&	Vector3t<T>::operator /=(const Ta& scalar) {
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);

		return *this;
	}
	template <typename T>								Vector3t<T>&	Vector3t<T>::operator ++() {
		this->x++;
		this->y++;
		this->z++;

		return *this;
	}
	template <typename T>								Vector3t<T>&	Vector3t<T>::operator --() {
		this->x--;
		this->y--;
		this->z--;

		return *this;
	}
	template <typename T> template <typename Ta>		Vector3t<T>&	Vector3t<T>::operator +=(const Vector3t<Ta>& vec3) {
		this->x += static_cast<T>(vec3.x);
		this->y += static_cast<T>(vec3.y);
		this->z += static_cast<T>(vec3.z);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector3t<T>&	Vector3t<T>::operator -=(const Vector3t<Ta>& vec3) {
		this->x -= static_cast<T>(vec3.x);
		this->y -= static_cast<T>(vec3.y);
		this->z -= static_cast<T>(vec3.z);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector3t<T>&	Vector3t<T>::operator *=(const Vector3t<Ta>& vec3) {
		this->x *= static_cast<T>(vec3.x);
		this->y *= static_cast<T>(vec3.y);
		this->z *= static_cast<T>(vec3.z);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector3t<T>&	Vector3t<T>::operator /=(const Vector3t<Ta>& vec3) {
		this->x /= static_cast<T>(vec3.x);
		this->y /= static_cast<T>(vec3.y);
		this->z /= static_cast<T>(vec3.z);

		return *this;
	}

	template <typename T> template <typename Ta>		long double		Vector3t<T>::magnitude(const Vector3t<Ta>& vec3) {
		long double mag = sqrt(pow(static_cast<long double>(vec3.x), 2.0l) + pow(static_cast<long double>(vec3.y), 2.0l) + pow(static_cast<long double>(vec3.z), 2.0l));

		return mag;
	}
	template <typename T> template <typename Ta>		Ta				Vector3t<T>::dot(const Vector3t<Ta>& vec3a, const Vector3t<Ta>& vec3b) {
		Ta dot = vec3a.x * vec3b.x + vec3a.y * vec3b.y + vec3a.z * vec3b.z;

		return dot;
	}
	template <typename T> template <typename Ta>		Vector3t<Ta>	Vector3t<T>::cross(const Vector3t<Ta>& vec3a, const Vector3t<Ta>& vec3b) {
		Vector3t<Ta> cross(vec3a.y * vec3b.z - vec3a.z * vec3b.y, vec3a.z * vec3b.x - vec3a.x * vec3b.z, vec3a.x * vec3b.y - vec3a.y * vec3b.x);

		return cross;
	}
	template <typename T> template <typename Ta>		Vector3t<Ta>	Vector3t<T>::normalize(const Vector3t<Ta>& vec3) {
		Vector3t<Ta> norm;

		long double mag = magnitude(vec3);

		norm.x = vec3.x / mag;
		norm.y = vec3.y / mag;
		norm.z = vec3.z / mag;

		return norm;
	}

	//Vector4t Struct Definitions:

	template <typename T>																					Vector4t<T>::Vector4t()
		: x(0), y(0), z(0), w(0) {	}
	template <typename T>																					Vector4t<T>::Vector4t(const Vector4t<T>& vec4)
		: x(vec4.x), y(vec4.y), z(vec4.z), w(vec4.w) {	}
	template <typename T>																			Vector4t<T>::Vector4t(const T& scalar)
		: x(scalar), y(scalar), z(scalar), w(scalar) {	}
	template <typename T>																			Vector4t<T>::Vector4t(const T& x, const T& y, const T& z, const T& w)
		: x(x), y(y), z(z), w(w) {	}
	template <typename T> template <typename Ta>													Vector4t<T>::Vector4t(const Ta& scalar)
		: x(static_cast<T>(scalar)), y(static_cast<T>(scalar)), z(static_cast<T>(scalar)), w(static_cast<T>(scalar)) {	}
	template <typename T> template <typename Ta, typename Tb, typename Tc, typename Td>				Vector4t<T>::Vector4t(const Ta& x, const Tb& y, const Tc& z, const Td& w)
		: x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(z)), w(static_cast<T>(w)) {	}
	template <typename T> template <typename Ta, typename Tb, typename Tc>							Vector4t<T>::Vector4t(const Vector2t<Ta>& vec2, const Tb& z, const Tc& w)
		: x(static_cast<T>(vec2.x)), y(static_cast<T>(vec2.y)), z(static_cast<T>(z)), w(static_cast<T>(w)) {	}
	template <typename T> template <typename Ta, typename Tb, typename Tc>							Vector4t<T>::Vector4t(const Ta& x, const Vector2t<Tb>& vec2, const Tc& w)
		: x(static_cast<T>(x)), y(static_cast<T>(vec2.x)), z(static_cast<T>(vec2.y)), w(static_cast<T>(w)) {	}
	template <typename T> template <typename Ta, typename Tb, typename Tc>							Vector4t<T>::Vector4t(const Ta& x, const Tb& y, const Vector2t<Tc>& vec2)
		: x(static_cast<T>(x)), y(static_cast<T>(y)), z(static_cast<T>(vec2.x)), w(static_cast<T>(vec2.y)) {	}
	template <typename T> template <typename Ta, typename Tb>										Vector4t<T>::Vector4t(const Vector2t<Ta>& vec2a, const Vector2t<Tb>& vec2b)
		: x(static_cast<T>(vec2a.x)), y(static_cast<T>(vec2a.y)), z(static_cast<T>(vec2b.x)), w(static_cast<T>(vec2b.y)) {	}
	template <typename T> template <typename Ta, typename Tb>										Vector4t<T>::Vector4t(const Vector3t<Ta>& vec3, const Tb& w)
		: x(static_cast<T>(vec3.x)), y(static_cast<T>(vec3.y)), z(static_cast<T>(vec3.z)), w(static_cast<T>(w)) {	}
	template <typename T> template <typename Ta, typename Tb>										Vector4t<T>::Vector4t(const Ta& x, const Vector3t<Tb>& vec3)
		: x(static_cast<T>(x)), y(static_cast<T>(vec3.x)), z(static_cast<T>(vec3.y)), w(static_cast<T>(vec3.z)) {	}
	template <typename T> template <typename Ta>													Vector4t<T>::Vector4t(const Vector4t<Ta>& vec4)
		: x(static_cast<T>(vec4.x)), y(static_cast<T>(vec4.y)), z(static_cast<T>(vec4.z)), w(static_cast<T>(vec4.w)) {	}

	template <typename T> T&			Vector4t<T>::operator [](const unsigned short int& index) {
		assert(index >= 0 && index < 4);
		return (&this->x)[index];
	}
	template <typename T> const T&		Vector4t<T>::operator [](const unsigned short int& index) const {
		assert(index >= 0 && index < 4);
		return (&this->x)[index];
	}

	template <typename T>								Vector4t<T>& Vector4t<T>::operator =(const Vector4t<T>& vec4) {
		this->x = vec4.x;
		this->y = vec4.y;
		this->z = vec4.z;
		this->w = vec4.w;

		return *this;
	}
	template <typename T> template <typename Ta>		Vector4t<T>& Vector4t<T>::operator =(const Vector4t<Ta>& vec4) {
		this->x = static_cast<T>(vec4.x);
		this->y = static_cast<T>(vec4.y);
		this->z = static_cast<T>(vec4.z);
		this->w = static_cast<T>(vec4.w);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector4t<T>& Vector4t<T>::operator +=(const Ta& scalar) {
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		this->w += static_cast<T>(scalar);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector4t<T>& Vector4t<T>::operator -=(const Ta& scalar) {
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		this->w -= static_cast<T>(scalar);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector4t<T>& Vector4t<T>::operator *=(const Ta& scalar) {
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		this->w *= static_cast<T>(scalar);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector4t<T>& Vector4t<T>::operator /=(const Ta& scalar) {
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		this->w /= static_cast<T>(scalar);

		return *this;
	}
	template <typename T>								Vector4t<T>& Vector4t<T>::operator ++() {
		this->x++;
		this->y++;
		this->z++;
		this->w++;

		return *this;
	}
	template <typename T>								Vector4t<T>& Vector4t<T>::operator --() {
		this->x--;
		this->y--;
		this->z--;
		this->w--;

		return *this;
	}
	template <typename T> template <typename Ta>		Vector4t<T>& Vector4t<T>::operator +=(const Vector4t<Ta>& vec4) {
		this->x += static_cast<T>(vec4.x);
		this->y += static_cast<T>(vec4.y);
		this->z += static_cast<T>(vec4.z);
		this->w += static_cast<T>(vec4.w);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector4t<T>& Vector4t<T>::operator -=(const Vector4t<Ta>& vec4) {
		this->x -= static_cast<T>(vec4.x);
		this->y -= static_cast<T>(vec4.y);
		this->z -= static_cast<T>(vec4.z);
		this->w -= static_cast<T>(vec4.w);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector4t<T>& Vector4t<T>::operator *=(const Vector4t<Ta>& vec4) {
		this->x *= static_cast<T>(vec4.x);
		this->y *= static_cast<T>(vec4.y);
		this->z *= static_cast<T>(vec4.z);
		this->w *= static_cast<T>(vec4.w);

		return *this;
	}
	template <typename T> template <typename Ta>		Vector4t<T>& Vector4t<T>::operator /=(const Vector4t<Ta>& vec4) {
		this->x /= static_cast<T>(vec4.x);
		this->y /= static_cast<T>(vec4.y);
		this->z /= static_cast<T>(vec4.z);
		this->w /= static_cast<T>(vec4.w);

		return *this;
	}

	template <typename T> template <typename Ta>		long double		Vector4t<T>::magnitude(const Vector4t<Ta>& vec4) {
		long double mag = sqrt(pow(static_cast<long double>(vec4.x), 2.0l) + pow(static_cast<long double>(vec4.y), 2.0l) + pow(static_cast<long double>(vec4.z), 2.0l) + pow(static_cast<long double>(vec4.w), 2.0l));

		return mag;
	}
	template <typename T> template <typename Ta>		Ta				Vector4t<T>::dot(const Vector4t<Ta>& vec4a, const Vector4t<Ta>& vec4b) {
		Ta dot = vec4a.x * vec4b.x + vec4a.y * vec4b.y + vec4a.z * vec4b.z + vec4a.w * vec4b.w;

		return dot;
	}
	template <typename T> template <typename Ta>		Vector4t<Ta>	Vector4t<T>::normalize(const Vector4t<Ta>& vec4) {
		Vector4t<Ta> norm;

		long double mag = magnitude(vec4);

		norm.x = vec4.x / mag;
		norm.y = vec4.y / mag;
		norm.z = vec4.z / mag;
		norm.w = vec4.w / mag;

		return norm;
	}


	//Vector2t Arithmitc Operator Definitions:

	template <typename T>	Vector2t<T> operator -(const Vector2t<T>& vec2) {
		Vector2t<T> negative(-vec2.x, -vec2.y);

		return negative;
	}
	template <typename T>	Vector2t<T> operator +(const Vector2t<T>& vec2, const T& scalar) {
		Vector2t<T> sum(vec2.x + scalar, vec2.y + scalar);

		return sum;
	}
	template <typename T>	Vector2t<T> operator -(const Vector2t<T>& vec2, const T& scalar) {
		Vector2t<T> diff(vec2.x - scalar, vec2.y - scalar);

		return diff;
	}
	template <typename T>	Vector2t<T> operator *(const Vector2t<T>& vec2, const T& scalar) {
		Vector2t<T> prod(vec2.x * scalar, vec2.y * scalar);

		return prod;
	}
	template <typename T>	Vector2t<T> operator /(const Vector2t<T>& vec2, const T& scalar) {
		Vector2t<T> quot(vec2.x / scalar, vec2.y / scalar);

		return quot;
	}

	template <typename T>	Vector2t<T> operator +(const Vector2t<T>& vec2lhs, const Vector2t<T>& vec2rhs) {
		Vector2t<T> sum(vec2lhs.x + vec2rhs.x, vec2lhs.y + vec2rhs.y);

		return sum;
	}
	template <typename T>	Vector2t<T> operator -(const Vector2t<T>& vec2lhs, const Vector2t<T>& vec2rhs) {
		Vector2t<T> diff(vec2lhs.x - vec2rhs.x, vec2lhs.y - vec2rhs.y);

		return diff;
	}
	template <typename T>	Vector2t<T> operator *(const Vector2t<T>& vec2lhs, const Vector2t<T>& vec2rhs) {
		Vector2t<T> prod(vec2lhs.x * vec2rhs.x, vec2lhs.y * vec2rhs.y);

		return prod;
	}
	template <typename T>	Vector2t<T> operator /(const Vector2t<T>& vec2lhs, const Vector2t<T>& vec2rhs) {
		Vector2t<T> quot(vec2lhs.x / vec2rhs.x, vec2lhs.y / vec2rhs.y);

		return quot;
	}

	//Vector3t Aritmitic Operator Definitions:

	template <typename T>	Vector3t<T> operator -(const Vector3t<T>& vec3) {
		Vector3t<T> negative(-vec3.x, -vec3.y, -vec3.z);

		return negative;
	}
	template <typename T>	Vector3t<T> operator +(const Vector3t<T>& vec3, const T& scalar) {
		Vector3t<T> sum(vec3.x + scalar, vec3.y + scalar, vec3.z + scalar);

		return sum;
	}
	template <typename T>	Vector3t<T> operator -(const Vector3t<T>& vec3, const T& scalar) {
		Vector3t<T> diff(vec3.x - scalar, vec3.y - scalar, vec3.z - scalar);

		return diff;
	}
	template <typename T>	Vector3t<T> operator *(const Vector3t<T>& vec3, const T& scalar) {
		Vector3t<T> prod(vec3.x * scalar, vec3.y * scalar, vec3.z * scalar);

		return prod;
	}
	template <typename T>	Vector3t<T> operator /(const Vector3t<T>& vec3, const T& scalar) {
		Vector3t<T> quot(vec3.x / scalar, vec3.y / scalar, vec3.z / scalar);

		return quot;
	}

	template <typename T>	Vector3t<T> operator +(const Vector3t<T>& vec3lhs, const Vector3t<T>& vec3rhs) {
		Vector3t<T> sum(vec3lhs.x + vec3rhs.x, vec3lhs.y + vec3rhs.y, vec3lhs.z + vec3rhs.z);

		return sum;
	}
	template <typename T>	Vector3t<T> operator -(const Vector3t<T>& vec3lhs, const Vector3t<T>& vec3rhs) {
		Vector3t<T> diff(vec3lhs.x - vec3rhs.x, vec3lhs.y - vec3rhs.y, vec3lhs.z - vec3rhs.z);

		return diff;
	}
	template <typename T>	Vector3t<T> operator *(const Vector3t<T>& vec3lhs, const Vector3t<T>& vec3rhs) {
		Vector3t<T> prod(vec3lhs.x * vec3rhs.x, vec3lhs.y * vec3rhs.y, vec3lhs.z * vec3rhs.z);

		return prod;
	}
	template <typename T>	Vector3t<T> operator /(const Vector3t<T>& vec3lhs, const Vector3t<T>& vec3rhs) {
		Vector3t<T> quot(vec3lhs.x / vec3rhs.x, vec3lhs.y / vec3rhs.y, vec3lhs.z / vec3rhs.z);

		return quot;
	}

	//Vector4t Arithmitic Operator Definitions:

	template <typename T>	Vector4t<T> operator -(const Vector4t<T>& vec4) {
		Vector4t<T> negative(-vec4.x, -vec4.y, -vec4.z, -vec4.w);

		return negative;
	}
	template <typename T>	Vector4t<T> operator +(const Vector4t<T>& vec4, const T& scalar) {
		Vector4t<T> sum(vec4.x + scalar, vec4.y + scalar, vec4.z + scalar, vec4.w + scalar);

		return sum;
	}
	template <typename T>	Vector4t<T> operator -(const Vector4t<T>& vec4, const T& scalar) {
		Vector4t<T> diff(vec4.x - scalar, vec4.y - scalar, vec4.z - scalar, vec4.w - scalar);

		return diff;
	}
	template <typename T>	Vector4t<T> operator *(const Vector4t<T>& vec4, const T& scalar) {
		Vector4t<T> prod(vec4.x * scalar, vec4.y * scalar, vec4.z * scalar, vec4.w * scalar);

		return prod;
	}
	template <typename T>	Vector4t<T> operator /(const Vector4t<T>& vec4, const T& scalar) {
		Vector4t<T> quot(vec4.x / scalar, vec4.y / scalar, vec4.z / scalar, vec4.w / scalar);

		return quot;
	}

	template <typename T>	Vector4t<T> operator +(const Vector4t<T>& vec4lhs, const Vector4t<T>& vec4rhs) {
		Vector4t<T> sum(vec4lhs.x + vec4rhs.x, vec4lhs.y + vec4rhs.y, vec4lhs.z + vec4rhs.z, vec4lhs.w + vec4rhs.w);

		return sum;
	}
	template <typename T>	Vector4t<T> operator -(const Vector4t<T>& vec4lhs, const Vector4t<T>& vec4rhs) {
		Vector4t<T> diff(vec4lhs.x - vec4rhs.x, vec4lhs.y - vec4rhs.y, vec4lhs.z - vec4rhs.z, vec4lhs.w - vec4rhs.w);

		return diff;
	}
	template <typename T>	Vector4t<T> operator *(const Vector4t<T>& vec4lhs, const Vector4t<T>& vec4rhs) {
		Vector4t<T> prod(vec4lhs.x * vec4rhs.x, vec4lhs.y * vec4rhs.y, vec4lhs.z * vec4rhs.z, vec4lhs.w * vec4rhs.w);

		return prod;
	}
	template <typename T>	Vector4t<T> operator /(const Vector4t<T>& vec4lhs, const Vector4t<T>& vec4rhs) {
		Vector4t<T> quot(vec4lhs.x / vec4rhs.x, vec4lhs.y / vec4rhs.y, vec4lhs.z / vec4rhs.z, vec4lhs.w / vec4rhs.w);

		return quot;
	}
}}
