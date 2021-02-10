
//==================================================================================\\
//FILE NAME:			XTrigonometric.cpp											\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#ifndef X_TRIGONOMETRIC_H
#define X_TRIGONOMETRIC_H




namespace X {	namespace Math {

	template <typename T> T sin(const T& angle);
	template <typename T> T cos(const T& angle);
	template <typename T> T tan(const T& angle);

	template <typename T> T csc(const T& angle);
	template <typename T> T sec(const T& angle);
	template <typename T> T cot(const T& angle);

	template <typename T> T arcsin(const T& x);
	template <typename T> T arccos(const T& x);
	template <typename T> T arctan(const T& x);


	template <typename T> T sinh(const T& x);
	template <typename T> T cosh(const T& x);
	template <typename T> T tanh(const T& x);

	template <typename T> T csch(const T& x);
	template <typename T> T sech(const T& x);
	template <typename T> T coth(const T& x);

	template <typename T> T arcsinh(const T& x);
	template <typename T> T arccosh(const T& x);
	template <typename T> T arctanh(const T& x);
}}

#include "../src/core/math/XTrigonometric.inl"

#endif // !1
