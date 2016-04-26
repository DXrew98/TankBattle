#include "Vec4.h"

#define FLT_EPSILON 0.00001

float andMath::vec4::mag()		const { return sqrtf(x * x + y * y + z * z + w * w); }
andMath::vec4 andMath::vec4::normal()	const {
	vec4 c;
	float m = mag();
	c.x = x / m;
	c.y = y / m;
	c.z = z / m;
	c.w = w / m;
	return c;
}
void andMath::vec4::normalize() {
	float m = mag();
	x /= m;
	y /= m;
	z /= m;
	w /= m;
}
andMath::vec4 andMath::vec4::operator-()const {
	vec4 c;
	c.x = x * -1;
	c.y = y * -1;
	c.z = z * -1;
	c.w = w * -1;
	return  c;
}

float andMath::dot(const vec4 &lhs, const vec4 &rhs) { return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w); }

andMath::vec4 andMath::lerp(const vec4 &lhs, const vec4 &rhs, float t) { return lhs * t + rhs * (1 - t); }// add clamp betwwen 0-1
andMath::vec4 andMath::reflect(const vec4 &lhs, const vec4 &norm) { return 2 * (dot(lhs, norm)) * norm - lhs; }

andMath::vec4 andMath::operator+  (const vec4 &lhs, const vec4 &rhs) {
	vec4 c;
	c.x = lhs.x + rhs.x;
	c.y = lhs.y + rhs.y;
	c.z = lhs.z + rhs.z;
	c.w = lhs.w + rhs.w;
	return  c;
}
andMath::vec4 andMath::operator+= (vec4 &lhs, const vec4 &rhs)
{
	return lhs = lhs + rhs;
}
andMath::vec4 andMath::operator-  (const vec4 &lhs, const vec4 &rhs) {
	vec4 c;
	c.x = lhs.x - rhs.x;
	c.y = lhs.y - rhs.y;
	c.z = lhs.z - rhs.z;
	c.w = lhs.w - rhs.w;
	return  c;
}
andMath::vec4 andMath::operator-= (vec4 &lhs, const vec4 &rhs) {
	return lhs = lhs - rhs;
}

andMath::vec4 andMath::operator*  (const vec4 &lhs, float rhs) {
	vec4 c;
	c.x = lhs.x * rhs;
	c.y = lhs.y * rhs;
	c.z = lhs.z * rhs;
	c.w = lhs.w * rhs;
	return  c;
}
andMath::vec4 andMath::operator*  (float rhs, const vec4 &lhs) {
	vec4 c;
	c.x = lhs.x * rhs;
	c.y = lhs.y * rhs;
	c.z = lhs.z * rhs;
	c.w = lhs.w * rhs;
	return  c;
}
andMath::vec4 andMath::operator*= (vec4 &lhs, float rhs) {
	return lhs = lhs * rhs;
}
andMath::vec4 andMath::operator*= (float rhs, vec4 &lhs) {
	return lhs = lhs * rhs;
}

andMath::vec4 andMath::operator/  (const vec4 &lhs, float rhs) {
	vec4 c;
	c.x = lhs.x / rhs;
	c.y = lhs.y / rhs;
	c.z = lhs.z / rhs;
	c.w = lhs.w / rhs;
	return  c;
}
andMath::vec4 andMath::operator/  (float rhs, const vec4 &lhs) {
	vec4 c;
	c.x = lhs.x / rhs;
	c.y = lhs.y / rhs;
	c.z = lhs.z / rhs;
	c.w = lhs.w / rhs;
	return  c;
}
andMath::vec4 andMath::operator/= (vec4 &lhs, float rhs) {
	return lhs = lhs / rhs;
}
andMath::vec4 andMath::operator/= (float rhs, vec4 &lhs) {
	return lhs = lhs / rhs;
}

bool andMath::operator== (const vec4 &lhs, const vec4 &rhs) { return (fabs(lhs.x - rhs.x) < FLT_EPSILON && fabs(lhs.y - rhs.y) < FLT_EPSILON 
																&& fabs(lhs.z - rhs.z) < FLT_EPSILON && fabs(lhs.w - rhs.w) < FLT_EPSILON); }
bool andMath::operator!= (const vec4 &lhs, const vec4 &rhs) { return !(fabs(lhs.x - rhs.x) < FLT_EPSILON) && !(fabs(lhs.y - rhs.y) < FLT_EPSILON)
																&& !(fabs(lhs.z - rhs.z) < FLT_EPSILON) && !(fabs(lhs.w - rhs.w) < FLT_EPSILON); }

bool andMath::operator<  (const vec4 &lhs, const vec4 &rhs) { return lhs.mag() < rhs.mag(); }
bool andMath::operator<= (const vec4 &lhs, const vec4 &rhs) { return lhs.mag() < rhs.mag() || fabs(lhs.mag() - rhs.mag()) < FLT_EPSILON; }

bool andMath::operator>  (const vec4 &lhs, const vec4 &rhs) { return lhs.mag() > rhs.mag(); }
bool andMath::operator>= (const vec4 &lhs, const vec4 &rhs) { return lhs.mag() > rhs.mag() || fabs(lhs.mag() - rhs.mag()) < FLT_EPSILON; }