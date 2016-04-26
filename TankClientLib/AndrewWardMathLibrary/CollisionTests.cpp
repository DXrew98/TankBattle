
#include "Shapes.h"
#include "CollisionTests.h"
#include "Vec2.h"
#include "Extra.h"
#include <iostream>

#define UP		{ 0,  1 }
#define DOWN	{ 0, -1 }
#define RIGHT	{ 1,  0 }
#define LEFT	{ -1, 0 }

float pointPlaneDistance(const Circle &circle, const Plane & plane)
{
	return (dot(plane.normal, (circle.pos - plane.pos)));
}
float rayPlaneDistance(const Ray & ray, const Plane & plane)
{
	return (dot(plane.normal, (ray.pos - plane.pos)) / -dot(plane.normal, ray.dir));
}

CollisionData iTest(const AABB & rectA, const AABB & rectB)
{
	CollisionData cd = { false, 0, 0, 0 };
	const float left	= rectB.max().x - rectA.min().x;
	const float right	= rectA.max().x - rectB.min().x;
	const float up		= rectB.max().y - rectA.min().y;
	const float down	= rectA.max().y - rectB.min().y;

	if (left > 0.0f && right  > 0.0f && up > 0.0f && down > 0.0f) cd.inOverlap = true;

	float collisionX = abs(left) < right ? left : right;
	float collisionY = abs( up ) < down ?  up   : down;
	cd.penetrationDepth = fminf(collisionX, collisionY);

	if (collisionX < collisionY) cd.collisionNormal = collisionX == right ? vec2 RIGHT : vec2 LEFT;
	else						 cd.collisionNormal = collisionY == up    ? vec2 UP    : vec2 DOWN;
	/*if (cd.inOverlap == true) std::cout << "hitAABB" << std::endl;*/
	return cd;
}
CollisionData iTest(const AABB & rect, const Circle & circle)
{

	CollisionData cd = { false, 0, 0, 0 };
	cd.pointOfContact = { clamp(circle.pos.x, rect.min().x, rect.max().x), clamp(circle.pos.y, rect.min().y, rect.max().y) };

	if (cd.pointOfContact == circle.pos) {
		float dX = (cd.pointOfContact.x - rect.min().x < rect.max().x - cd.pointOfContact.x) ? rect.min().x : rect.max().x;
		float dY = (cd.pointOfContact.y - rect.min().y < rect.max().y - cd.pointOfContact.y) ? rect.min().y : rect.max().y;

		if (abs(dX - cd.pointOfContact.x) < abs(dY - cd.pointOfContact.y)) cd.pointOfContact.x = dX;
		else															   cd.pointOfContact.y = dY;
	}

	float dist = (cd.pointOfContact - circle.pos).mag();//circle.pos.x - cd.pointOfContact.x + circle.pos.y - cd.pointOfContact.y;
	float radius =	circle.radius;

	cd.penetrationDepth = dist - radius;
	if (dist < radius) cd.inOverlap = true;
	/*if (cd.inOverlap == true)
	{
		std::cout << "hitAABB" << std::endl;
	}*/
	cd.collisionNormal = (circle.pos - cd.pointOfContact).normal();

	return cd;
}
CollisionData iTest(const AABB & rect, const Ray & ray)
{
	CollisionData cd = { false, 0, 0, 0 };
	
	// Min/Max along the X-Axis
	Plane s1p1  = Plane{ rect.max(), RIGHT	};
	Plane s1p2  = Plane{ rect.min(), LEFT	};
	float t11   = rayPlaneDistance(ray, s1p1); // Right
	float t12   = rayPlaneDistance(ray, s1p2); // Left
	float t1min = std::fminf(t11, t12);
	float t1max = std::fmaxf(t11, t12);
	vec2  n1    = (t11 < t12) ? vec2 RIGHT : vec2 LEFT;

	// Min/Max along the Y-Axis
	Plane s2p1  = Plane{ rect.max(), UP		};
	Plane s2p2  = Plane{ rect.min(), DOWN	};
	float t21   = rayPlaneDistance(ray, s2p1);
	float t22   = rayPlaneDistance(ray, s2p2);
	float t2min = std::fminf(t21, t22);
	float t2max = std::fmaxf(t21, t22);
	vec2  n2 = (t21 < t22) ? vec2 UP : vec2 DOWN;
	
	float tmin  = std::fmaxf(t2min, t1min);
	float tmax  = std::fminf(t2max, t1max);
	
	cd.penetrationDepth = ray.len - tmin;
	cd.inOverlap = cd.penetrationDepth >= 0 && tmin <= tmax && tmin > 0;
	cd.collisionNormal   = (t1min > t2min) ? n1 : n2;
	
	return cd;
}
CollisionData iTest(const AABB & rect, const Plane & plane)
{
	CollisionData cd = { false, 0, 0, 0 };

	vec2 localDis = rect.pos - plane.pos;
	float rectPlaneTest = rect.halfPoint.x * abs(dot(plane.normal, RIGHT)) + rect.halfPoint.y * abs(dot(plane.normal, UP));

	cd.penetrationDepth = rectPlaneTest - dot(plane.normal, localDis);
	if (dot(plane.normal, localDis) <= rectPlaneTest) cd.inOverlap = true;
	cd.collisionNormal = plane.normal;

	return cd;
}

CollisionData iTest(const Circle & circleA, const Circle & circleB)
{

	CollisionData cd = { false, 0, 0, 0 }; 
	float dist2 =	pow(circleB.pos.x - circleA.pos.x, 2) + pow(circleB.pos.y - circleA.pos.y, 2);
	float radius =	pow(circleB.radius + circleA.radius, 2);

	

	cd.penetrationDepth = circleB.radius + circleA.radius
							- (circleB.pos - circleA.pos).mag();
	if (dist2 < radius) cd.inOverlap = true;
	cd.collisionNormal = (circleB.pos - circleA.pos).normal();

	//if (cd.inOverlap == true) { std::cout << "Hit" << std::endl; }

	return cd;
}
CollisionData iTest(const Circle & circle, const Ray & ray) //still needs to be done
{
	CollisionData cd = { false, 0, 0, 0 };

	float crDis = dot(circle.pos, ray.pos);
	float clampedPoint = clamp(crDis, 0, ray.len);
	vec2 closestPoint = ray.pos + ray.dir * clampedPoint;

	float circleTest = dot((circle.pos - closestPoint), (circle.pos - closestPoint));

	cd.penetrationDepth = 0;
	if (circleTest <= circle.radius * circle.radius) cd.inOverlap = true;
	cd.collisionNormal = { 0, 0 };

	return cd;
}
CollisionData iTest(const Circle & circle, const Plane & plane)
{
	CollisionData cd = { false, 0, 0, 0 };
	float lhs = dot(plane.normal, (circle.pos - plane.pos));
	float rhs = circle.radius;
	
	cd.penetrationDepth = rhs - lhs;
	if (lhs <= rhs) { cd.inOverlap = true; }
	cd.collisionNormal = plane.normal;

	return cd;
}

CollisionData iTest(const Ray & ray, const Plane & plane)
{
	CollisionData cd = { false, 0, 0, 0 };

	vec2 rayLength = ray.len * ray.dir;
	vec2 localDis = ray.pos - plane.pos;
	float rayPlaneTest = (dot(plane.normal, localDis) / dot(plane.normal, rayLength) * -1);

	if (dot(plane.normal, rayLength) * -1 > 0) { return cd; }
	else if (rayPlaneTest >= 0 && rayPlaneTest <= ray.len) { 
		cd.penetrationDepth = ray.len - rayPlaneTest;
		cd.inOverlap = true; 
		cd.collisionNormal = ray.dir.normal() * -1;
	}
	return cd;
}

CollisionData iTest(const ConvexHull & chullA, const ConvexHull & chullB)
{
	return CollisionData();
}
CollisionData iTest(const ConvexHull & chull,  const Circle & circle)
{
	return CollisionData();
}
CollisionData iTest(const ConvexHull & chull,  const Ray & ray)
{
	return CollisionData();
}
CollisionData iTest(const ConvexHull & chull,  const Plane & plane)
{
	return CollisionData();
}
CollisionData iTest(const ConvexHull & chull,  const AABB & rect)
{
	return CollisionData();
}
