
//==================================================================================\\
//FILE NAME:			XExponential.inl											\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#include "core/math/XExponential.h"
#include <cassert>


namespace X {	namespace Math {

	template <typename T> T pow(const T& base, const T& exponent) {
		return static_cast<T>(std::powf(static_cast<float>(base), static_cast<float>(exponent)));
	}
	template <typename T> T root(const T& degree, const T& radicand) {
		return static_cast<T>(std::powf(static_cast<float>(radicand), 1.0f / (static_cast<float>(degree))));
	}

	template <typename T> T sqrt(const T& radicand) {
		return root(static_cast<T>(2.0), radicand);
	}

	template <typename T> T cbrt(const T& radicand) {
		return root(static_cast<T>(3.0), radicand);
	}


	template <> float pow(const float& base, const float& exponent);
	template <> double pow(const double& base, const double& exponent);
	template <> long double pow(const long double& base, const long double& exponent);


	template <> float root(const float& degree, const float& radicand);
	template <> double root(const double& degree, const double& radicand);
	template <> long double root(const long double& degree, const long double& radicand);
}}
