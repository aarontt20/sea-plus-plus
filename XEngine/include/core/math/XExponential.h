
//==================================================================================\\
//FILE NAME:			XExponential.cpp											\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#ifndef X_EXPONENTIAL_H
#define X_EXPONENTIAL_H

#include <cmath>

namespace X {	namespace Math {

	template <typename T> T pow(const T& base, const T& exponent);

	template <typename T> T root(const T& degree, const T& radicand);
	template <typename T> T sqrt(const T& radicand);
	template <typename T> T cbrt(const T& radicand);

	template <typename T> T exp(const T& x);
	template <typename T> T log(const T& x);
	template <typename T> T exp2(const T& x);
	template <typename T> T log2(const T& x);
}}

#include "../src/core/math/XExponential.inl"

#endif // !X_EXPONENTIAL_H
