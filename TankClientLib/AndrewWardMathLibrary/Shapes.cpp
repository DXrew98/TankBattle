#include "Shapes.h"
#include <cmath>
#include <vector>

//ConvexHull operator*(const mat3 & matrix, const ConvexHull & shape)	{ return matrix * shape; }

Ray operator*(const mat3 & matrix, const Ray & ray){

	vec3 dir = vec3{ray.dir.x, ray.dir.y, 0} * ray.len;
	vec3 pos{ ray.pos.x, ray.pos.y, 1 };

	return{ (matrix * pos).xy, (matrix * dir).xy.normal(), dir.mag() };
}

Plane operator*(const mat3 & matrix, const Plane & plane){

	vec3 nor{ plane.normal.x, plane.normal.y, 0 };
	vec3 pos{ plane.pos.x,	  plane.pos.y,	  1 };

	return{ (matrix * pos).xy, (matrix * nor).xy };
}

Circle operator*(const mat3 & matrix, const Circle & circle){ 

	Circle temp;
	temp.pos = (matrix * vec3{ circle.pos.x, circle.pos.y, 1 }).xy;

	vec3 xRad{ circle.radius, 0, 0 };
	vec3 yRad{ 0, circle.radius, 0 };

	temp.radius = fmaxf((matrix*xRad).mag(), (matrix*yRad).mag());

	return temp;
}

AABB operator*(const mat3 & matrix, const AABB & AABB){ 

	vec2 aMin = AABB.min();
	vec2 aMax = AABB.max();

	vec2 mMin = matrix[2].xy;
	vec2 mMax = matrix[2].xy;

	float s, f;

	for (unsigned i = 0; i < 2; ++i)
		for (unsigned j = 0; j < 2; ++j) {

			s = aMin[j] * matrix[j][i];
			f = aMax[j] * matrix[j][i];

			if (s < f) std::swap(s, f);
			mMin[i] += s;
			mMax[i] += f;
		}

	return{ (mMin + mMax) / 2, (mMin - mMax) / 2 };
}
 