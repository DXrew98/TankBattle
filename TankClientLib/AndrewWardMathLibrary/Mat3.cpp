#include "Mat3.h"
#include "Vec3.h"

andMath::vec3 andMath::mat3::operator[](unsigned idx) const { return c[idx]; }

andMath::vec3 & andMath::mat3::operator[](unsigned idx) { return c[idx]; }

andMath::mat3 andMath::mat3::identity()
{
	mat3 n;
	n.c[0] = { 1, 0, 0 };
	n.c[1] = { 0, 1, 0 };
	n.c[2] = { 0, 0, 1 };
	return n;
}

andMath::mat3 andMath::transpose(const mat3 & a)
{
	mat3 n;
	n.c[0] = { a.mm[0][0], a.mm[1][0], a.mm[2][0] };
	n.c[1] = { a.mm[0][1], a.mm[1][1], a.mm[2][1] };
	n.c[2] = { a.mm[0][2], a.mm[1][2], a.mm[2][2] };
	return n;
}
andMath::mat3 andMath::inverse(const mat3 & a)
{

	//lots of help form jacob
	mat3 n;
	//mat3 mC = {  1, -1, 1, -1, 1, -1, 1, -1, 1  };

	n.c[0] = {  a.mm[1][1] * a.mm[2][2] - a.mm[2][1] * a.mm[1][2], a.mm[2][1] * a.mm[0][2] - a.mm[0][1] * a.mm[2][2], a.mm[0][1] * a.mm[1][2] - a.mm[1][1] * a.mm[0][2] };
	n.c[1] = {  a.mm[2][0] * a.mm[1][2] - a.mm[1][0] * a.mm[2][2], a.mm[0][0] * a.mm[2][2] - a.mm[2][0] * a.mm[0][2], a.mm[1][0] * a.mm[0][2] - a.mm[0][0] * a.mm[1][2] };
	n.c[2] = {  a.mm[1][0] * a.mm[2][1] - a.mm[2][0] * a.mm[1][1], a.mm[2][0] * a.mm[0][1] - a.mm[0][0] * a.mm[2][1], a.mm[0][0] * a.mm[1][1] - a.mm[1][0] * a.mm[0][1] };

	//n *= mC;


	return n = (n * (1 / determinant(a)));
}

// detA= a11a22a33 + a21a32a13
//      +a31a12a23 - a11a32a23
//      -a31a22a13 - a21a12a33

float andMath::determinant(const mat3 & a)
{
	float n =  a.mm[0][0]*a.mm[1][1]*a.mm[2][2] + a.mm[0][1]*a.mm[1][2]*a.mm[2][0]
		     + a.mm[0][2]*a.mm[1][0]*a.mm[2][1] - a.mm[0][0]*a.mm[1][2]*a.mm[2][1]
			 - a.mm[0][2]*a.mm[1][1]*a.mm[2][0] - a.mm[0][1]*a.mm[1][0]*a.mm[2][2];


	//float n = (a.m[0] * (a.m[4] * a.m[8] - a.m[5] * a.m[7]))
	//		- (a.m[1] * (a.m[3] * a.m[8] - a.m[5] * a.m[6]))
	//		+ (a.m[2] * (a.m[3] * a.m[7] - a.m[4] * a.m[6]));
	return n; 
}

andMath::mat3 andMath::rotate(float a)
{
	mat3 n = n.identity();
	a *= DEGtoRAD;
	n.c[0] = { cosf(a), sinf(a), 0 };
	n.c[1] = { -sinf(a), cosf(a), 0 };
	return n;
}
andMath::mat3 andMath::translate(const vec2 &a)
{
	mat3 n = n.identity();
	n.mm[2][0] = a.x;
	n.mm[2][1] = a.y;
	return n;
}
andMath::mat3 andMath::scale(const vec2 scale)
{
	mat3 n = n.identity();
	n.mm[0][0] = scale.x;
	n.mm[1][1] = scale.y;
	return n;
}

andMath::mat3 andMath::operator+(const mat3 & lhs, const mat3 & rhs)
{
	mat3 n;
	n.c[0] = lhs.c[0] + rhs.c[0];
	n.c[1] = lhs.c[1] + rhs.c[1];
	n.c[2] = lhs.c[2] + rhs.c[2];
	return n;
}
andMath::mat3 andMath::operator+=(mat3 & lhs, const mat3 & rhs)
{
	lhs.c[0] += rhs.c[0];
	lhs.c[1] += rhs.c[1];
	lhs.c[2] += rhs.c[2];
	return lhs;
}
andMath::mat3 andMath::operator-(const mat3 & lhs, const mat3 & rhs)
{
	mat3 n;
	n.c[0] = lhs.c[0] - rhs.c[0];
	n.c[1] = lhs.c[1] - rhs.c[1];
	n.c[2] = lhs.c[2] - rhs.c[2];
	return n;
}
andMath::mat3 andMath::operator-=(mat3 & lhs, const mat3 & rhs)
{
	lhs.c[0] -= rhs.c[0];
	lhs.c[1] -= rhs.c[1];
	lhs.c[2] -= rhs.c[2];
	return lhs;
}

andMath::mat3 andMath::operator*(const mat3 & lhs, const mat3 & rhs)
{
	mat3 n, t = transpose(lhs);
	n.c[0] = { dot(t.c[0], rhs.c[0]), dot(t.c[1], rhs.c[0]), dot(t.c[2], rhs.c[0]) };
	n.c[1] = { dot(t.c[0], rhs.c[1]), dot(t.c[1], rhs.c[1]), dot(t.c[2], rhs.c[1]) };
	n.c[2] = { dot(t.c[0], rhs.c[2]), dot(t.c[1], rhs.c[2]), dot(t.c[2], rhs.c[2]) };
	return n;
}
andMath::vec3 andMath::operator*(const mat3 & lhs, const vec3 & rhs)
{
	mat3 t = transpose(lhs);
	vec3 n;

	n.x = dot(t.c[0], rhs);
	n.y = dot(t.c[1], rhs);
	n.z = dot(t.c[2], rhs);

	return n;
}
andMath::mat3 andMath::operator*(const mat3 & lhs, float rhs)
{
	mat3 n;
	n.c[0] = lhs.c[0] * rhs;
	n.c[1] = lhs.c[1] * rhs;
	n.c[2] = lhs.c[2] * rhs;
	return n;
}

andMath::mat3 andMath::operator*=(mat3 & lhs, const mat3 & rhs)
{
	lhs = lhs * rhs;
	return lhs;
}
andMath::mat3 andMath::operator*=(mat3 & lhs, float rhs)
{
	lhs.c[0] *= rhs;
	lhs.c[1] *= rhs;
	lhs.c[2] *= rhs;
	return lhs;
}

bool andMath::operator==(const mat3 & a, const mat3 & b)
{
	return (a.c[0] == b.c[0] && a.c[1] == b.c[1] && a.c[2] == b.c[2])? true : false;
}
bool andMath::operator!=(const mat3 & a, const mat3 & b)
{
	return (a.c[0] != b.c[0] && a.c[1] != b.c[1] && a.c[2] != b.c[2]) ? true : false;
}