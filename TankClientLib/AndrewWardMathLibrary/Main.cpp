#include <cassert>
#include <iostream>
#include "VMMath.h"


using andMath::vec2;

void vec2Tests() {
	//new vectors to test with
	andMath::vec2 a{ 5, 1 };
	andMath::vec2 b{ 2, 12 };
	andMath::vec2 c;
	float d = 2; //used for multi and div tests and float tests
	float d2;

	//vectors for bool tests
	andMath::vec2 e{ 1, 1 };
	andMath::vec2 f{ 1, 1 };
	andMath::vec2 h{ 10, 0 };
	andMath::vec2 i{ 0, 0 };

	//vector for mag test 
	andMath::vec2 g{ 2, 2};

	assert(fabs(sqrt(2) - e.mag()) < FLT_EPSILON);

	//perpendicular test
	//reseting c
	c = { 0,0 };
	andMath::vec2 perResult = { 1, -5 };
	c = a.perp();
	assert(c == perResult);

	//normal tests
	//reseting c
	c = { 0,0 };
	andMath::vec2 norm1Result = { (2 / sqrtf(8)), (2 / sqrtf(8)) };
	c = g.normal();
	assert(c == norm1Result);

	//normalizing a vector
	andMath::vec2 norm2Result = { (2 / sqrtf(8)), (2 / sqrtf(8)) };
	g.normalize();
	assert(g == norm2Result);

	//sign flip
	c = { 0,0 };
	andMath::vec2 flipResult = { -5, -1 };
	c = a.operator-();
	assert(c == flipResult);

	//dot product
	d2 = 0;
	float dotResult = 22;
	d2 = dot(a, b);
	assert(d2 == dotResult);

	//lerp
	float t = .5;
	c = { 0,0 };
	andMath::vec2 lerpResult = { 5, 0 };
	c = lerp(i, h, t);
	assert(c == lerpResult);

	//projection
	c = { 0,0 };
	andMath::vec2 proResult = { sqrtf(2), sqrtf(2) };
	c = project(e, f);
 	assert(c == proResult);

	//Operators
	//+
	andMath::vec2 pResult = { 7, 13 };
    c = a + b;
	assert(c == pResult);

	//+=
	andMath::vec2 pEResult = { 9, 25 };
	c += b;
	assert(c == pEResult);
	
	//reseting c
	c = { 0,0 };
	//-
	andMath::vec2 miResult = { 3, -11 };
	c = a - b;
	assert(c == miResult);

	//-=
	andMath::vec2 miEResult = { 1, -23 };
	c -= b;
	assert(c == miEResult);

	//reseting c
	c = { 0,0 };
	//*
	andMath::vec2 tResult = { 10, 2 };
	c = a * d;
	assert(c == tResult);

	//*=
	andMath::vec2 tEResult = { 20, 4 };
	c *= d;
	assert(c == tEResult);

	//reseting c
	c = { 0,0 };
	//*
	andMath::vec2 dResult = { 2.5, .5 };
	c = a / d;
	assert(c == dResult);

	//*=
	andMath::vec2 dEResult = { 1.25, .25 };
	c /= d;
	assert(c == dEResult);

	//bool tests
	assert(e == f);
	assert(e != a);
	assert(e < b);
	assert(e <= a);
	assert(b > a);
	assert(a >= e);


}

void vec3Tests() {
	//new vectors to test with
	andMath::vec3 a{ 5, 1, 3 };
	andMath::vec3 b{ 2, 12, 3 };
	andMath::vec3 c;
	float d = 2; //used for multi and div tests and float tests
	float d2;

	//vectors for bool tests
	andMath::vec3 e{ 1, 1, 1 };
	andMath::vec3 f{ 1, 1, 1 };
	andMath::vec3 h{ 10, 0, 2 };
	andMath::vec3 i{ 0, 0, 1 };

	//vector for mag test 
	andMath::vec3 g{ 2, 2, 2 };

	assert(fabs(sqrt(3) - e.mag()) < FLT_EPSILON);


	//normal tests
	//reseting c
	c = { 0, 0, 0 };
	andMath::vec3 norm1Result = { (2 / sqrtf(12)), (2 / sqrtf(12)), (2 / sqrtf(12)) };
	c = g.normal();
	assert(c == norm1Result);

	//normalizing a vector
	andMath::vec3 norm2Result = { (2 / sqrtf(12)), (2 / sqrtf(12)), (2 / sqrtf(12)) };
	g.normalize();
	assert(g == norm2Result);

	//sign flip
	c = { 0, 0, 0 };
	andMath::vec3 flipResult = { -5, -1, -3 };
	c = a.operator-();
	assert(c == flipResult);

	//dot product
	d2 = 0;
	float dotResult = 31;
	d2 = dot(a, b);
	assert(d2 == dotResult);

	//lerp
	float t = .5;
	c = { 0, 0, 0 };
	andMath::vec3 lerpResult = { 5, 0, 1.5 };
	c = lerp(i, h, t);
	assert(c == lerpResult);

	//Operators
	//+
	andMath::vec3 pResult = { 7, 13, 6 };
	c = a + b;
	assert(c == pResult);

	//+=
	andMath::vec3 pEResult = { 9, 25, 9 };
	c += b;
	assert(c == pEResult);

	//reseting c
	c = { 0, 0, 0 };
	//-
	andMath::vec3 miResult = { 3, -11, 0 };
	c = a - b;
	assert(c == miResult);

	//-=
	andMath::vec3 miEResult = { 1, -23, -3 };
	c -= b;
	assert(c == miEResult);

	//reseting c
	c = { 0, 0, 0 };
	//*
	andMath::vec3 tResult = { 10, 2, 6 };
	c = a * d;
	assert(c == tResult);

	//*=
	andMath::vec3 tEResult = { 20, 4, 12 };
	c *= d;
	assert(c == tEResult);

	//reseting c
	c = { 0, 0, 0 };
	//*
	andMath::vec3 dResult = { 2.5, .5, 1.5 };
	c = a / d;
	assert(c == dResult);

	//*=
	andMath::vec3 dEResult = { 1.25, .25, .75 };
	c /= d;
	assert(c == dEResult);

	//bool tests
	assert(e == f);
	assert(h != a);
	assert(e < b);
	assert(e <= a);
	assert(b > a);
	assert(a >= e);

}

void vec4Tests() {
	//new vectors to test with
	andMath::vec4 a{ 5, 1, 3, 2 };
	andMath::vec4 b{ 2, 12, 3, 4 };
	andMath::vec4 c;
	float d = 2; //used for multi and div tests and float tests
	float d2;

	//vectors for bool tests
	andMath::vec4 e{ 1, 1, 1, 1 };
	andMath::vec4 f{ 1, 1, 1, 1 };
	andMath::vec4 h{ 10, 0, 2, 0 };
	andMath::vec4 i{ 0, 0, 1, 0 };

	//vector for mag test 
	andMath::vec4 g{ 2, 2, 2, 2 };

	assert(fabs(sqrt(4) - e.mag()) < FLT_EPSILON);


	//normal tests
	//reseting c
	c = { 0, 0, 0, 0 };
	andMath::vec4 norm1Result = { (2 / sqrtf(16)), (2 / sqrtf(16)), (2 / sqrtf(16)), (2 / sqrtf(16)) };
	c = g.normal();
	assert(c == norm1Result);

	//normalizing a vector
	andMath::vec4 norm2Result = { (2 / sqrtf(16)), (2 / sqrtf(16)), (2 / sqrtf(16)), (2 / sqrtf(16)) };
	g.normalize();
	assert(g == norm2Result);

	//sign flip
	c = { 0, 0, 0 };
	andMath::vec4 flipResult = { -5, -1, -3, -2 };
	c = a.operator-();
	assert(c == flipResult);

	//dot product
	d2 = 0;
	float dotResult = 39;
	d2 = dot(a, b);
	assert(d2 == dotResult);

	//lerp
	float t = .5;
	c = { 0, 0, 0 };
	andMath::vec4 lerpResult = { 5, 0, 1.5, 0 };
	c = lerp(i, h, t);
	assert(c == lerpResult);

	//Operators
	//+
	andMath::vec4 pResult = { 7, 13, 6, 6 };
	c = a + b;
	assert(c == pResult);

	//+=
	andMath::vec4 pEResult = { 9, 25, 9, 10 };
	c += b;
	assert(c == pEResult);

	//reseting c
	c = { 0, 0, 0, 0 };
	//-
	andMath::vec4 miResult = { 3, -11, 0, -2 };
	c = a - b;
	assert(c == miResult);

	//-=
	andMath::vec4 miEResult = { 1, -23, -3, -6 };
	c -= b;
	assert(c == miEResult);

	//reseting c
	c = { 0, 0, 0, 0 };
	//*
	andMath::vec4 tResult = { 10, 2, 6, 4 };
	c = a * d;
	assert(c == tResult);

	//*=
	andMath::vec4 tEResult = { 20, 4, 12, 8 };
	c *= d;
	assert(c == tEResult);

	//reseting c
	c = { 0, 0, 0 };
	//*
	andMath::vec4 dResult = { 2.5, .5, 1.5, 1 };
	c = a / d;
	assert(c == dResult);

	//*=
	andMath::vec4 dEResult = { 1.25, .25, .75, .5 };
	c /= d;
	assert(c == dEResult);

	//bool tests
	assert(e == f);
	assert(h != a);
	assert(e < b);
	assert(e <= a);
	assert(b > a);
	assert(a >= e);

}

void mat3Tests() {

	andMath::mat3 a = { 1, 1, 1,
						1, 1, 1,
						1, 1, 1 };
	andMath::mat3 b = { 2, 2, 2,
						2, 2, 2,
						2, 2, 2 };

	a = a.identity();
	b = b.identity();

	assert(a == b);

	a = { 1, 2, 3,
		  4, 5, 6,
		  7, 8, 9 };
	b = { 1, 4, 7,
		  2, 5, 8,
		  3, 6, 9 };

	a = andMath::transpose(a);
	assert(a == b);

	a = { 2, 2, 3,
		  4, 5, 6,
		  7, 8, 9 };
	b = { 1, 4, 7,
		  2, 5, 8,
		  3, 6, 9 };

	assert(a * andMath::mat3::identity() == a);

	assert(fabs(andMath::determinant(b)) < FLT_EPSILON);

	andMath::mat3 inverseReturn = (a * andMath::inverse(a));
	assert(inverseReturn == a.identity());


	a = { 1, 1, 1,
		1, 1, 1,
		1, 1, 1 };
	b = { 2, 2, 2,
		2, 2, 2,
		2, 2, 2 };
	andMath::mat3 d = { 1, 1, 1,
						1, 1, 1,
						1, 1, 1 };
	a = a + a;
	assert(a == b);
	a = a - d;
	assert(a == d);
	d += b;
	a = a * a;
	assert(a == d);
	a = { 1, 1, 1,
		1, 1, 1,
		1, 1, 1 };
	a *= a;
	assert(a == d);
	a = { 1, 1, 1,
		  1, 1, 1,
		  1, 1, 1 };

	d = { 1, 1, 1,
		  1, 1, 1,
		  1, 1, 1 };

	a += d;
	assert(a == b);
	a -= d;
	assert(a == d);


	a = a * 2;
	assert(a == b);

	d *= 2;
	assert(d == b);

	a = { 1, 0, 0,
		  0, 1, 0,
		  1, 0, 1 };
	b = { 0, 1, 0,
		  -1, 0, 0,
		  1, 0, 1 };
	a *= andMath::rotate(90);
	assert(a == b);

	// starting position
	andMath::vec3 start = { 1, 1, 1 };
	andMath::vec2 v = { 1, 1 };
	andMath::mat3 translationMatrix = andMath::translate(v);
	andMath::vec3 end = { 2, 2, 1 };


	a = { 1, 0, 1,
		  0, 1, 1,
		  0, 0, 1 };
	b = { 1, 0, 1,
		  0, 1, 1,
		  0, 0, 1 };
	a *= andMath::translate(v);
	assert(translationMatrix * start == end);

	a = { 2, 0, 0,
		  0, 1, 0,
		  0, 0, 1 };
	v = { 2, 1 };
	andMath::vec3 end2 = { 2, 1, 1 };
	andMath::mat3 scaleMatrix = andMath::scale(v);
	assert(scaleMatrix * start == end2);


}

void mat4Tests() {
	andMath::mat4 a = { 1, 1, 1, 1,
						1, 1, 1, 1,
						1, 1, 1, 1, 
						1, 1, 1, 1};
	andMath::mat4 b = { 1, 1, 1, 1,
						1, 1, 1, 1,
						1, 1, 1, 1,
						1, 1, 1, 1 };
	andMath::mat4 c = { 2, 2, 2, 2,
						2, 2, 2, 2,
						2, 2, 2, 2,
						2, 2, 2, 2 };
	andMath::mat4 d;
	andMath::mat4 e = { 16, 16, 16, 16,
						16, 16, 16, 16,
						16, 16, 16, 16,
						16, 16, 16, 16 };

	andMath::mat4 f = {  1,  2,  3,  4,
						 5,  6,  7,  8,
						 9, 10, 11, 12,
						13, 14, 15, 16 };

	andMath::mat4 g = { 1,  5,  9, 13,
						2,  6, 10, 14,
						3,  7, 11, 15,
					    4,  8, 12, 16 };

	
	assert(a == b);
	assert(a != c);

	d = a + b;
	assert(d == c);
	d = d - b;
	assert(d == b);
	d += a;
	assert(d == c);
	d -= b;
	assert(d == b);

	f = andMath::transpose(f);
	assert(f == g);

	d = c * c;
	assert(d == e);
	d = c;
	d *= c;
	assert(d == e);

	andMath::vec4 vA = { 2, 2, 2, 2 };
	andMath::vec4 vB;
	andMath::vec4 vC = { 16, 16, 16, 16 };
	d = c;
	vB = d * vA;
	assert(vB == vC);
	vB = vA;

	d = a;
	d = d * 2;
	assert(d == c);
	d = a;
	d *= 2;
	assert(d == c);


	andMath::mat4 h = { 2,  2,  3,  4,
						4,  3,  2,  2,
						7,  8,  9,  0,
						1,  2,  3,  4 };
	assert(fabs(andMath::determinant(f)) < FLT_EPSILON);
	assert(fabs(andMath::determinant(h) - 56.0f) < FLT_EPSILON);

			      h = { 1, 1, 1, 0,
						0, 3, 1, 2,
						2, 3, 1, 0,
						1, 0, 2, 1 };

	andMath::mat4 inverseReturn = andMath::inverse(h);
	inverseReturn = inverseReturn * h;
	assert(inverseReturn == h.identity());

}

int main() {
	vec2Tests();
	vec3Tests();
	vec4Tests();
	mat3Tests();
	mat4Tests();



	system("pause");
	return 0;
}