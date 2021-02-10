
//==================================================================================\\
//FILE NAME:			XTrigonometric.inl											\\
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

	template <typename T>		T		sin(const T& angle) {
		assert(std::is_floating_point<T>() && "The function(sin(angle)) only accepts floating point values");

		return 0;
	}
	template <typename T>		T		cos(const T& angle) {
		assert(std::is_floating_point<T>() && "The function(cos(angle)) only accepts floating point values");

		return 0;
	}
	template <typename T>		T		tan(const T& angle) {
		assert(std::is_floating_point<T>() && "The function(tan(angle)) only accepts floating point values");

		return 0;
	}

	template <typename T>		T		csc(const T& angle) {
		assert(std::is_floating_point<T>() && "The function(csc(angle)) only accepts floating point values");

		return 0;
	}
	template <typename T>		T		sec(const T& angle) {
		assert(std::is_floating_point<T>() && "The function(sec(angle)) only accepts floating point values");

		return 0;
	}
	template <typename T>		T		cot(const T& angle) {
		assert(std::is_floating_point<T>() && "The function(cot(angle)) only accepts floating point values");

		return 0;
	}

	template <typename T>		T		arcsin(const T& x) {
		assert(std::is_floating_point<T>() && "The function(arcsin(x)) only accepts floating point values");

		return 0;
	}
	template <typename T>		T		arccos(const T& x) {
		assert(std::is_floating_point<T>() && "The function(arccos(x)) only accepts floating point values");

		return 0;
	}
	template <typename T>		T		arctan(const T& x) {
		assert(std::is_floating_point<T>() && "The function(arctan(x)) only accepts floating point values");

		return 0;
	}


	template <>		float		sin(const float& angle);
	template <>		float		cos(const float& angle);
	template <>		float		tan(const float& angle);

	template <>		float		csc(const float& angle);
	template <>		float		sec(const float& angle);
	template <>		float		cot(const float& angle);

	template <>		float		arcsin(const float& x);
	template <>		float		arccos(const float& x);
	template <>		float		arctan(const float& x);


	template <>		double		sin(const double& angle);
	template <>		double		cos(const double& angle);
	template <>		double		tan(const double& angle);

	template <>		double		csc(const double& angle);
	template <>		double		sec(const double& angle);
	template <>		double		cot(const double& angle);

	template <>		double		arcsin(const double& x);
	template <>		double		arccos(const double& x);
	template <>		double		arctan(const double& x);


	template <>		long double		sin(const long double& angle);
	template <>		long double		cos(const long double& angle);
	template <>		long double		tan(const long double& angle);

	template <>		long double		csc(const long double& angle);
	template <>		long double		sec(const long double& angle);
	template <>		long double		cot(const long double& angle);

	template <>		long double		arcsin(const long double& x);
	template <>		long double		arccos(const long double& x);
	template <>		long double		arctan(const long double& x);



	template <typename T>		T		sinh(const T& x) {
		assert(std::is_floating_point<T>() && "The function(sinh(x)) only accepts floating point numbers");

		return 0;
	}
	template <typename T>		T		cosh(const T& x) {
		assert(std::is_floating_point<T>() && "The function(cosh(x)) only accepts floating point numbers");

		return 0;
	}
	template <typename T>		T		tanh(const T& x) {
		assert(std::is_floating_point<T>() && "The function(tanh(x)) only accepts floating point numbers");

		return 0;
	}

	template <typename T>		T		csch(const T& x) {
		assert(std::is_floating_point<T>() && "The function(csch(x)) only accepts floating point numbers");

		return 0;
	}
	template <typename T>		T		sech(const T& x) {
		assert(std::is_floating_point<T>() && "The function(sech(x)) only accepts floating point numbers");

		return 0;
	}
	template <typename T>		T		coth(const T& x) {
		assert(std::is_floating_point<T>() && "The function(coth(x)) only accepts floating point numbers");

		return 0;
	}

	template <typename T>		T		arcsinh(const T& x) {
		assert(std::is_floating_point<T>() && "The function(arcsinh(x)) only accepts floating point numbers");

		return 0;
	}
	template <typename T>		T		arccosh(const T& x) {
		assert(std::is_floating_point<T>() && "The function(arccosh(x)) only accepts floating point numbers");

		return 0;
	}
	template <typename T>		T		arctanh(const T& x) {
		assert(std::is_floating_point<T>() && "The function(arctanh(x)) only accepts floating point numbers");

		return 0;
	}


	template <>		float		sinh(const float& x);
	template <>		float		cosh(const float& x);
	template <>		float		tanh(const float& x);

	template <>		float		csch(const float& x);
	template <>		float		sech(const float& x);
	template <>		float		coth(const float& x);

	template <>		float		arcsinh(const float& x);
	template <>		float		arccosh(const float& x);
	template <>		float		arctanh(const float& x);


	template <>		double		sinh(const double& x);
	template <>		double		cosh(const double& x);
	template <>		double		tanh(const double& x);

	template <>		double		csch(const double& x);
	template <>		double		sech(const double& x);
	template <>		double		coth(const double& x);

	template <>		double		arcsinh(const double& x);
	template <>		double		arccosh(const double& x);
	template <>		double		arctanh(const double& x);


	template <>		long double		sinh(const long double& x);
	template <>		long double		cosh(const long double& x);
	template <>		long double		tanh(const long double& x);

	template <>		long double		csch(const long double& x);
	template <>		long double		sech(const long double& x);
	template <>		long double		coth(const long double& x);

	template <>		long double		arcsinh(const long double& x);
	template <>		long double		arccosh(const long double& x);
	template <>		long double		arctanh(const long double& x);
}}
