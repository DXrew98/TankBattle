#pragma once
#include "Shapes.h"
#include "Vec2.h"


//infor needed for collisions
struct CollisionData{
	bool	inOverlap;
	float	penetrationDepth;
	andMath::vec2	collisionNormal;
	andMath::vec2	pointOfContact;
};

//distance formuals
float pointPlaneDistance(const Circle &circle,	const Plane   &plane);
float rayPlaneDistance	(const Ray    &ray,		const Plane   &plane);

//basic tests 
CollisionData iTest(const AABB		 &rectA,	const AABB     &rectb);
CollisionData iTest(const AABB		 &rect,		const Circle   &circle);
inline CollisionData iTest(const Circle		 &circle, const AABB   &rect) {
	return iTest(rect, circle);
}
CollisionData iTest(const AABB		 &rect,		const Ray      &ray);
CollisionData iTest(const AABB		 &rect,		const Plane    &plane);

CollisionData iTest(const Circle	 &circleA,	const Circle   &circleB);
CollisionData iTest(const Circle	 &circle,	const Ray      &ray);
CollisionData iTest(const Circle	 &circleA,	const Plane    &plane);

CollisionData iTest(const Ray		 &ray,		const Plane	   &plane);

CollisionData iTest(const ConvexHull &chullA, const ConvexHull &chullB);
CollisionData iTest(const ConvexHull &chull,  const Circle     &circle);
CollisionData iTest(const ConvexHull &chull,  const Ray        &ray);
CollisionData iTest(const ConvexHull &chull,  const Plane      &plane);
CollisionData iTest(const ConvexHull &chull,  const AABB       &rect);