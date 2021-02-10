
//==================================================================================\\
//FILE NAME:			XExponential.cpp											\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#include "core/math/XExponential.h"
#include <cassert>


namespace X {	namespace Math {

	template <> float pow(const float& base, const float& exponent) {
		return std::powf(base, exponent);
	}
	template <> double pow(const double& base, const double& exponent) {
		return std::pow(base, exponent);
	}
	template <> long double pow(const long double& base, const long double& exponent) {
		return std::powl(base, exponent);
	}


	template <> float root(const float& degree, const float& radicand) {
		return std::powf(radicand, 1.0f / degree);
	}
	template <> double root(const double& degree, const double& radicand) {
		return std::pow(radicand, 1.0 / degree);
	}
	template <> long double root(const long double& degree, const long double& radicand) {
		return std::powl(radicand, 1.0l / degree);
	}
}}
