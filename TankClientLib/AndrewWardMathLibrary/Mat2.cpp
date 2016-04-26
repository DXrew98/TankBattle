#include "Mat2.h"
#include "Vec2.h"

andMath::mat2 andMath::mat2::identity()
{
	mat2 n;
	n.c[0] = { 1, 0};
	n.c[1] = { 0, 1};
	return n;
}

andMath::mat2 andMath::transpose(const mat2 & a)
{
	mat2 n;
	n.c[0] = { a.mm[0][0], a.mm[1][0]};
	n.c[1] = { a.mm[0][1], a.mm[1][1]};
	return n;
}
andMath::mat2 andMath::inverse(const mat2 & a)
{
	mat2 n;

	n.c[0] = {  a.mm[1][1], -a.mm[0][1] }; // A, C
	n.c[1] = { -a.mm[1][0],  a.mm[0][0] }; // B, D

	return n = (n * (1 / determinant(a)));
}

float andMath::determinant(const mat2 & a)
{
	float n = a.mm[0][0] * a.mm[1][1] - a.mm[0][1] * a.mm[1][0];
	return n;
}

andMath::mat2 andMath::operator+(const mat2 & lhs, const mat2 & rhs)
{
	mat2 n;
	n.c[0] = lhs.c[0] + rhs.c[0];
	n.c[1] = lhs.c[1] + rhs.c[1];
	return n;;
}
andMath::mat2 andMath::operator+=(mat2 & lhs, const mat2 & rhs)
{
	lhs.c[0] += rhs.c[0];
	lhs.c[1] += rhs.c[1];
	return lhs;
}
andMath::mat2 andMath::operator-(const mat2 & lhs, const mat2 & rhs)
{
	mat2 n;
	n.c[0] = lhs.c[0] - rhs.c[0];
	n.c[1] = lhs.c[1] - rhs.c[1];
	return n;
}
andMath::mat2 andMath::operator-=(mat2 & lhs, const mat2 & rhs)
{
	lhs.c[0] -= rhs.c[0];
	lhs.c[1] -= rhs.c[1];
	return lhs;
}

andMath::mat2 andMath::operator*(const mat2 & lhs, const mat2 & rhs)
{
	mat2 n, t = transpose(lhs);
	n.c[0] = { dot(t.c[0], rhs.c[0]), dot(t.c[1], rhs.c[0])};
	n.c[1] = { dot(t.c[0], rhs.c[1]), dot(t.c[1], rhs.c[1])};
	return n;
}
andMath::vec2 andMath::operator*(const mat2 & lhs, const vec2 & rhs)
{
	mat2 t = transpose(lhs);
	vec2 n;

	n.x = dot(t.c[0], rhs);
	n.y = dot(t.c[1], rhs);

	return n;
}
andMath::mat2 andMath::operator*(const mat2 & lhs, float rhs)
{
	mat2 n;
	n.c[0] = lhs.c[0] * rhs;
	n.c[1] = lhs.c[1] * rhs;
	return n;
}

andMath::mat2 andMath::operator*=(mat2 & lhs, const mat2 & rhs)
{
	lhs = lhs * rhs;
	return lhs;
}
andMath::mat2 andMath::operator*=(mat2 & lhs, float rhs)
{
	lhs.c[0] *= rhs;
	lhs.c[1] *= rhs;
	lhs.c[2] *= rhs;
	return lhs;
}

bool andMath::operator==(const mat2 & a, const mat2 & b)
{
	return (a.c[0] == b.c[0] && a.c[1] == b.c[1] && a.c[2] == b.c[2]) ? true : false;
}

bool andMath::operator!=(const mat2 & a, const mat2 & b)
{
	return (a.c[0] != b.c[0] && a.c[1] != b.c[1] && a.c[2] != b.c[2]) ? true : false;
}
