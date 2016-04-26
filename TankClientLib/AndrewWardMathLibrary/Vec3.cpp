#include "Vec3.h"

#define FLT_EPSILON 0.00001

float & andMath::vec3::operator[](unsigned idx) { return v[idx]; }

float andMath::vec3::operator[](unsigned idx) const { return v[idx]; }

// shoot a vector for a determined angle
float andMath::vec3::mag()		const { return sqrtf(x * x + y * y + z * z); }
andMath::vec3 andMath::vec3::normal()	const {
	vec3 c;
	float m = mag();
	c.x = x / m;
	c.y = y / m;
	c.z = z / m;
	return c;
}
void andMath::vec3::normalize() {
	float m = mag();
	x /= m;
	y /= m;
	z /= m;
}
andMath::vec3 andMath::vec3::operator-()const {
	vec3 c;
	c.x = x * -1;
	c.y = y * -1;
	c.z = z * -1;
	return  c;
}

float andMath::dot(const vec3 &lhs, const vec3 &rhs) { return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z); }
andMath::vec3 andMath::cross(const vec3 &lhs, const vec3 &rhs) { 
	vec3 c;
	c.x = (lhs.y * rhs.z) - (lhs.z * rhs.y);
	c.y = (lhs.z * rhs.x) - (lhs.x * rhs.z);
	c.z = (lhs.x * rhs.y) - (lhs.y * rhs.x);
	return c;
}

andMath::vec3 andMath::lerp(const vec3 &lhs, const vec3 &rhs, float t) { return lhs * t + rhs * (1 - t); }// add clamp betwwen 0-1
andMath::vec3 andMath::reflect(const vec3 &lhs, const vec3 &norm) { return 2 * (dot(lhs, norm)) * norm - lhs; }

andMath::vec3 andMath::operator+  (const vec3 &lhs, const vec3 &rhs) {
	vec3 c;
	c.x = lhs.x + rhs.x;
	c.y = lhs.y + rhs.y;
	c.z = lhs.z + rhs.z;
	return  c;
}
andMath::vec3 andMath::operator+= (vec3 &lhs, const vec3 &rhs)
{
	return lhs = lhs + rhs;
}
andMath::vec3 andMath::operator-  (const vec3 &lhs, const vec3 &rhs) {
	vec3 c;
	c.x = lhs.x - rhs.x;
	c.y = lhs.y - rhs.y;
	c.z = lhs.z - rhs.z;
	return  c;
}
andMath::vec3 andMath::operator-= (vec3 &lhs, const vec3 &rhs) {
	return lhs = lhs - rhs;
}

andMath::vec3 andMath::operator*  (const vec3 &lhs, float rhs) {
	vec3 c;
	c.x = lhs.x * rhs;
	c.y = lhs.y * rhs;
	c.z = lhs.z * rhs;
	return  c;
}
andMath::vec3 andMath::operator*  (float rhs, const vec3 &lhs) {
	vec3 c;
	c.x = lhs.x * rhs;
	c.y = lhs.y * rhs;
	c.z = lhs.z * rhs;
	return  c;
}
andMath::vec3 andMath::operator*= (vec3 &lhs, float rhs) {
	return lhs = lhs * rhs;
}
andMath::vec3 andMath::operator*= (float rhs, vec3 &lhs) {
	return lhs = lhs * rhs;
}

andMath::vec3 andMath::operator/  (const vec3 &lhs, float rhs) {
	vec3 c;
	c.x = lhs.x / rhs;
	c.y = lhs.y / rhs;
	c.z = lhs.z / rhs;
	return  c;
}
andMath::vec3 andMath::operator/  (float rhs, const vec3 &lhs) {
	vec3 c;
	c.x = lhs.x / rhs;
	c.y = lhs.y / rhs;
	c.z = lhs.z / rhs;
	return  c;
}
andMath::vec3 andMath::operator/= (vec3 &lhs, float rhs) {
	return lhs = lhs / rhs;
}
andMath::vec3 andMath::operator/= (float rhs, vec3 &lhs) { 
	return lhs = lhs / rhs; 
}

bool andMath::operator== (const vec3 &lhs, const vec3 &rhs) { return (fabs(lhs.x - rhs.x) < FLT_EPSILON && fabs(lhs.y - rhs.y) < FLT_EPSILON && fabs(lhs.z - rhs.z) < FLT_EPSILON); }
bool andMath::operator!= (const vec3 &lhs, const vec3 &rhs) { return !(fabs(lhs.x - rhs.x) < FLT_EPSILON) && !(fabs(lhs.y - rhs.y) < FLT_EPSILON) && !(fabs(lhs.z - rhs.z) < FLT_EPSILON); }

bool andMath::operator<  (const vec3 &lhs, const vec3 &rhs) { return lhs.mag() < rhs.mag(); }
bool andMath::operator<= (const vec3 &lhs, const vec3 &rhs) { return lhs.mag() < rhs.mag() || fabs(lhs.mag() - rhs.mag()) < FLT_EPSILON; }

bool andMath::operator>  (const vec3 &lhs, const vec3 &rhs) { return lhs.mag() > rhs.mag(); }
bool andMath::operator>= (const vec3 &lhs, const vec3 &rhs) { return lhs.mag() > rhs.mag() || fabs(lhs.mag() - rhs.mag()) < FLT_EPSILON; }

