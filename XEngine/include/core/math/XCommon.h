
//==================================================================================\\
//FILE NAME:			XCommon.cpp													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#ifndef X_COMMON_H
#define X_COMMON_H




namespace X {	namespace Math {

	template <typename T>		T		abs(const T& x);

	template <typename T>		T		max(const T& x, const T& y);
	template <typename T>		T		min(const T& x, const T& y);

	template <typename T>		short int		sign(const T& x);

	template <typename T>		T		round(const T& x);
	template <typename T>		T		floor(const T& x);
	template <typename T>		T		ceiling(const T& x);
	template <typename T>		T		truncate(const T& x);

	template <typename T>		long double		radians(const T& angle);
	template <typename T>		long double		degrees(const T& angle);

	template <typename T>		long double		normalizeRad(const T& angle);
	template <typename T>		long double		normalizeDeg(const T& angle);
}}

#include "../src/core/math/XCommon.inl"

#endif // !X_COMMON_H
