
//==================================================================================\\
//FILE NAME:			XTrigonometric.cpp											\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#include "core/math/XTrigonometric.h"
#include <cmath>
#include <cassert>
#include <climits>


namespace X {	namespace Math {

	template<>	float		sin<float>(const float& angle) {
		return std::sinf(angle);
	}
	template<>	float		cos<float>(const float& angle) {
		return std::cosf(angle);
	}
	template<>	float		tan<float>(const float& angle) {
		return std::tanf(angle);
	}

	template<>	float		csc(const float& angle) {
		return 1.0f / std::sinf(angle);
	}
	template<>	float		sec(const float& angle) {
		return 1.0f / std::cosf(angle);
	}
	template<>	float		cot(const float& angle) {
		return 1.0f / std::tanf(angle);
	}

	template<>	float		arcsin(const float& x) {
		return std::asinf(x);
	}
	template<>	float		arccos(const float& x) {
		return std::acosf(x);
	}
	template<>	float		arctan(const float& x) {
		return std::atanf(x);
	}


	template<>	double		sin(const double& angle) {
		return std::sin(angle);
	}
	template<>	double		cos(const double& angle) {
		return std::cos(angle);
	}
	template<>	double		tan(const double& angle) {
		return std::tan(angle);
	}

	template<>	double		csc(const double& angle) {
		return 1.0f / std::sin(angle);
	}
	template<>	double		sec(const double& angle) {
		return 1.0f / std::cos(angle);
	}
	template<>	double		cot(const double& angle) {
		return 1.0f / std::tan(angle);
	}

	template<>	double		arcsin(const double& x) {
		return std::asin(x);
	}
	template<>	double		arccos(const double& x) {
		return std::acos(x);
	}
	template<>	double		arctan(const double& x) {
		return std::atan(x);
	}


	template<>	long double		sin(const long double& angle) {
		return std::sinl(angle);
	}
	template<>	long double		cos(const long double& angle) {
		return std::cosl(angle);
	}
	template<>	long double		tan(const long double& angle) {
		return std::tanl(angle);
	}

	template<>	long double		csc(const long double& angle) {
		return 1.0f / std::sinl(angle);
	}
	template<>	long double		sec(const long double& angle) {
		return 1.0f / std::cosl(angle);
	}
	template<>	long double		cot(const long double& angle) {
		return 1.0f / std::tanl(angle);
	}

	template<>	long double		arcsin(const long double& x) {
		return std::asinl(x);
	}
	template<>	long double		arccos(const long double& x) {
		return std::acosl(x);
	}
	template<>	long double		arctan(const long double& x) {
		return std::atanl(x);
	}


	template<>	float		sinh(const float& x) {
		return std::sinhf(x);
	}
	template<>	float		cosh(const float& x) {
		return std::coshf(x);
	}
	template<>	float		tanh(const float& x) {
		return std::tanhf(x);
	}

	template<>	float		csch(const float& x) {
		return 1 / std::sinhf(x);
	}
	template<>	float		sech(const float& x) {
		return 1 / std::coshf(x);
	}
	template<>	float		coth(const float& x) {
		return 1 / std::tanhf(x);
	}

	template<>	float		arcsinh(const float& x) {
		return std::asinhf(x);
	}
	template<>	float		arccosh(const float& x) {
		return std::acoshf(x);
	}
	template<>	float		arctanh(const float& x) {
		return std::atanhf(x);
	}


	template<>	double		sinh(const double& x) {
		return std::sinh(x);
	}
	template<>	double		cosh(const double& x) {
		return std::cosh(x);
	}
	template<>	double		tanh(const double& x) {
		return std::tanh(x);
	}

	template<>	double		csch(const double& x) {
		return 1 / std::sinh(x);
	}
	template<>	double		sech(const double& x) {
		return 1 / std::cosh(x);
	}
	template<>	double		coth(const double& x) {
		return 1 / std::tanh(x);
	}

	template<>	double		arcsinh(const double& x) {
		return std::asinh(x);
	}
	template<>	double		arccosh(const double& x) {
		return std::acosh(x);
	}
	template<>	double		arctanh(const double& x) {
		return std::atanh(x);
	}


	template<>	long double		sinh(const long double& x) {
		return std::sinhl(x);
	}
	template<>	long double		cosh(const long double& x) {
		return std::coshl(x);
	}
	template<>	long double		tanh(const long double& x) {
		return std::tanhl(x);
	}

	template<>	long double		csch(const long double& x) {
		return 1 / std::sinhl(x);
	}
	template<>	long double		sech(const long double& x) {
		return 1 / std::coshl(x);
	}
	template<>	long double		coth(const long double& x) {
		return 1 / std::tanhl(x);
	}

	template<>	long double		arcsinh(const long double& x) {
		return std::asinhl(x);
	}
	template<>	long double		arccosh(const long double& x) {
		return std::acoshl(x);
	}
	template<>	long double		arctanh(const long double& x) {
		return std::atanhl(x);
	}
}}
