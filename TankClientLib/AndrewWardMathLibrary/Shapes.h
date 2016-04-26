#pragma once
#include "Vec2.h"
#include "Mat3.h"

using andMath::vec2;
using andMath::vec3;
using andMath::mat3;


//Base shape definitions 
struct ConvexHull { vec2 verts; };

struct Ray		{ vec2 pos, dir; float len; };
struct Plane	{ vec2 pos, normal; };
struct Circle	{ vec2 pos; float radius; };
struct AABB		{ vec2 pos, halfPoint; vec2 min() const, max() const;};

inline vec2 AABB::min() const { return pos - halfPoint; }
inline vec2 AABB::max() const { return pos + halfPoint; }

//Shape conversions to mat3s 
//ConvexHull	operator*(const mat3 &matrix, const ConvexHull &shape);

Ray			operator*(const mat3 &matrix, const Ray &ray);
Plane		operator*(const mat3 &matrix, const Plane &plane);
Circle		operator*(const mat3 &matrix, const Circle &cicle);
AABB		operator*(const mat3 &matrix, const AABB &AABB);
