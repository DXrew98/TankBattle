#pragma once
#include "Mat2.h"
#include "vec4.h"
#include "mat3.h"

namespace andMath {
struct mat4 {
		union {
			vec4 c[4];
			float m[16];
			float mm[4][4];
			struct {
				union { vec4 c1; vec3 rht; };
				union { vec4 c2; vec3 up;  };
				union { vec4 c3; vec3 fwd; };
				union { vec4 c4; vec3 pos; };
			};
		};
		static mat4 identity();
		void setBLock2x2(int row, int col, mat2 a);
		mat2 getBlock2x2(int row, int col) const;
		static mat4 mat3to4(const float *m, float z);
	};	

	

	mat4 transpose(const mat4 &a);
	mat4 inverse(const mat4 &a);

	float determinant(const mat4 &a);

	mat4 rotate(const vec3 &a, float b);
	mat4 translate(const vec3 &a);
	mat4 scale(const vec3 &a);

	mat4 operator+	(const mat4 &lhs, const mat4 &rhs);
	mat4 operator+=	(mat4 &lhs, const mat4 &rhs);
	mat4 operator-	(const mat4 &lhs, const mat4 &rhs);
	mat4 operator-=	(mat4 &lhs, const mat4 &rhs);

	mat4 operator*	(const mat4 &lhs, const mat4 &rhs); //mat
	vec4 operator*	(const mat4 &lhs, const vec4 &rhs); //vec
	mat4 operator*	(const mat4 &lhs, float rhs);		//scalar

	mat4 operator*=	(mat4 &lhs, const mat4 &rhs);
	mat4 operator*=	(mat4 &lhs, float rhs);

	bool operator == (const mat4 &a, const mat4 &b);
	bool operator != (const mat4 &a, const mat4 &b);

	mat4 ortho(float left, float right, float bottom, float top, float near, float far);
	mat4 frustum(float left, float right, float bottom, float top, float near, float far);
	mat4 perspective(float fov, float aspect, float near, float far);
}