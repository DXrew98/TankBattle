#pragma once
#include "Vec2.h"
#include <cfloat>
#include <cmath>

#define DEGtoRAD PI / 180.0f

namespace andMath {
	/*__declspec(align(32))*/ struct mat2 {
		union {
			vec2 c[2];
			struct { float m[4]; };
			struct { float mm[2][2]; };
		};
		static mat2 identity();
	};


	mat2 transpose(const mat2 &a);
	mat2 inverse(const mat2 &a);

	float determinant(const mat2 &a);

	mat2 operator+	(const mat2 &lhs, const mat2 &rhs);
	mat2 operator+=	(mat2 &lhs, const mat2 &rhs);
	mat2 operator-	(const mat2 &lhs, const mat2 &rhs);
	mat2 operator-=	(mat2 &lhs, const mat2 &rhs);

	mat2 operator*	(const mat2 &lhs, const mat2 &rhs); //mat
	vec2 operator*	(const mat2 &lhs, const vec2 &rhs); //vec
	mat2 operator*	(const mat2 &lhs, float rhs);		//scalar

	mat2 operator*=	(mat2 &lhs, const mat2 &rhs);
	mat2 operator*=	(mat2 &lhs, float rhs);

	bool operator == (const mat2 &a, const mat2 &b);
	bool operator != (const mat2 &a, const mat2 &b);
}