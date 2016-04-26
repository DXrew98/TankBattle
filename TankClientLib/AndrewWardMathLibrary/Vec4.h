#pragma once
#include <cfloat>
#include <cmath>

#define PI 3.141592654;

//FLT_EPSILON
namespace andMath {
struct vec4 {
		union {
			float v[4];
			struct { float x, y, z, w; };
			struct { float r, g, b, a; };
		};
		float mag()		const;
		vec4 normal()	const;
		void normalize();
		vec4 operator-()const;
	};
	//binary operations 
	float dot(const vec4 &lhs, const vec4 &rhs);

	vec4 lerp(const vec4 &lhs, const vec4 &rhs, float t);
	vec4 reflect(const vec4 &lhs, const vec4 &norm);

	vec4 operator+  (const vec4 &lhs, const vec4 &rhs);
	vec4 operator+= (vec4 &lhs, const vec4 &rhs);
	vec4 operator-  (const vec4 &lhs, const vec4 &rhs);
	vec4 operator-= (vec4 &lhs, const vec4 &rhs);

	vec4 operator*  (const vec4 &lhs, float rhs);
	vec4 operator*  (float rhs, const vec4 &lhs);
	vec4 operator*= (vec4 &lhs, float rhs);
	vec4 operator*= (float rhs, vec4 &lhs);

	vec4 operator/  (const vec4 &lhs, float rhs);
	vec4 operator/  (float rhs, const vec4 &lhs);
	vec4 operator/= (vec4 &lhs, float rhs);
	vec4 operator/= (float rhs, vec4 &lhs);

	bool operator== (const vec4 &lhs, const vec4 &rhs);
	bool operator!= (const vec4 &lhs, const vec4 &rhs);

	bool operator<  (const vec4 &lhs, const vec4 &rhs);
	bool operator<= (const vec4 &lhs, const vec4 &rhs);

	bool operator>  (const vec4 &lhs, const vec4 &rhs);
	bool operator>= (const vec4 &lhs, const vec4 &rhs);
}