#pragma once
#include "Vec2.h"
#include "Vec3.h"
#include <cfloat>
#include <cmath>

#define PI 3.141592654f
#define DEGtoRAD PI / 180.0f

namespace andMath {
	/*__declspec(align(32))*/ struct mat3{
		union{
			vec3 c[3];
			struct { float m[9]; };
			struct { float mm[3][3]; };
			struct {
				union { vec3 c1; vec2 rht; };
				union { vec3 c2; vec2 up; };
				union { vec3 c3; vec2 pos; };
			};
		};
		vec3  operator[](unsigned idx) const;
		vec3 &operator[](unsigned idx);
		static mat3 identity();
	};

	mat3 transpose	(const mat3 &a);
	mat3 inverse	(const mat3 &a);

	float determinant(const mat3 &a);

	mat3 rotate		(float a);
	mat3 translate	(const vec2 &a);
	mat3 scale		(const vec2 scale);

	mat3 operator+	(const mat3 &lhs, const mat3 &rhs);
	mat3 operator+=	(mat3 &lhs, const mat3 &rhs);
	mat3 operator-	(const mat3 &lhs, const mat3 &rhs);
	mat3 operator-=	(mat3 &lhs, const mat3 &rhs);

	mat3 operator*	(const mat3 &lhs, const mat3 &rhs); //mat
	vec3 operator*	(const mat3 &lhs, const vec3 &rhs); //vec
	mat3 operator*	(const mat3 &lhs, float rhs);		//scalar

	mat3 operator*=	(mat3 &lhs, const mat3 &rhs);
	mat3 operator*=	(mat3 &lhs, float rhs);

	bool operator == (const mat3 &a, const mat3 &b);
	bool operator != (const mat3 &a, const mat3 &b);
}