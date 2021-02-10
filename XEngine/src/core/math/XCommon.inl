
//==================================================================================\\
//FILE NAME:			XCommon.inl													\\
//PROJECT:				XEngine														\\
//CREATED BY:			Aaron Toms													\\
//DATE CREATED:			03/14/2017													\\
//LAST MODIIFED:		04/01/2017													\\
//				 ©Copyright 2017, Aaron Toms. All Rights Reserved.					\\
//==================================================================================\\


#include "core/math/XCommon.h"


namespace X {	namespace Math {

	template <typename T>		T		abs(const T& x) {
		T abs = (x < 0) ? -x : x;

		return abs;
	}

	template <typename T>		T		max(const T& x, const T& y) {
		T max = (x == y) ? x : (x < y) ? y : x;

		return max;
	}
	template <typename T>		T		min(const T& x, const T& y) {
		T min = (x == y) ? x : (x < y) ? x : y;

		return min;
	}

	template <typename T>		short int		sign(const T& x) {
		short int sign = (x == 0) ? x : (x < 0) ? -1 : 1;

		return sign;
	}

	template <typename T>		T		round(const T& x) {
		T round = (x > 0) ? (x - static_cast<long long int>(x) < 0.5f) ? static_cast<long long int>(x) : static_cast<long long int>(x) + 1 : (x < 0) ? (x - static_cast<long long int>(x) > -0.5f) ? static_cast<long long int>(x) : static_cast<long long int>(x) - 1 : x;

		return round;
	}
	template <typename T>		T		floor(const T& x) {
		T floor = (x == static_cast<long long int>(x)) ? x : (x > 0) ? static_cast<long long int>(x) : static_cast<long long int>(x) - 1;

		return floor;
	}
	template <typename T>		T		ceiling(const T& x) {
		T ceil = (x == static_cast<long long int>(x)) ? x : (x > 0) ? static_cast<long long int>(x) + 1 : static_cast<long long int>(x);

		return ceil;
	}
	template <typename T>		T		truncate(const T& x) {
		T trunc = static_cast<long long int>(x);

		return trunc;
	}

	template <typename T>		long double		radians(const T& angle) {
		return angle*(TAU / 360);
	}
	template <typename T>		long double		degrees(const T& angle) {
		return angle*(360 / TAU);
	}

	template <typename T>		long double		normalizeRad(const T& angle) {
		long double norm = angle - (long long int)(angle / TAU) * TAU;

		if (norm >= 0) return norm;
		else return TAU + norm;
	}
	template <typename T>		long double		normalizeDeg(const T& angle) {
		long double norm = angle - (long long int)(angle / 360) * 360;

		if (norm >= 0) return norm;
		else return 360 + norm;
	}
}}
