#include "vmmath.h"



andMath::mat4 andMath::mat4::identity()
{
	mat4 n;
	n.c[0] = { 1, 0, 0, 0 };
	n.c[1] = { 0, 1, 0, 0 };
	n.c[2] = { 0, 0, 1, 0 };
	n.c[3] = { 0, 0, 0, 1 };
	return n;
}

void andMath::mat4::setBLock2x2(int row, int col, mat2 a)
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			mm[i + col][j + row] = a.mm[i][j];
}
andMath::mat2 andMath::mat4::getBlock2x2(int row, int col) const
{
	
	mat2 n;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			n.mm[i][j] = mm[i + col][j + row];
	return n;
}

andMath::mat4 andMath::mat4::mat3to4(const float * m, float z)
{
	return{

		m[0], m[1], 0, m[2],
		m[3], m[4], 0, m[5],
		  0,    0,  0,   0,
		m[6], m[7], z, m[8]
	};
}

andMath::mat4 andMath::transpose(const mat4 & a)
{
	mat4 n;
	n.c[0] = vec4{ a.mm[0][0], a.mm[1][0], a.mm[2][0], a.mm[3][0] };
	n.c[1] = vec4{ a.mm[0][1], a.mm[1][1], a.mm[2][1], a.mm[3][1] };
	n.c[2] = vec4{ a.mm[0][2], a.mm[1][2], a.mm[2][2], a.mm[3][2] };
	n.c[3] = vec4{ a.mm[0][3], a.mm[1][3], a.mm[2][3], a.mm[3][3] };
	return n;
}
andMath::mat4 andMath::inverse(const mat4 & a)
{
	mat2 A = a.getBlock2x2(0, 0); //andMath::getBlock2x2(a.mm[0][0], a.mm[0][0]);
	mat2 B = a.getBlock2x2(0, 2); //andMath::getBlock2x2(a.mm[0][0], a.mm[0][2]);
	mat2 C = a.getBlock2x2(2, 0); //andMath::getBlock2x2(a.mm[2][0], a.mm[0][0]);
	mat2 D = a.getBlock2x2(2, 2); //andMath::getBlock2x2(a.mm[2][2], a.mm[2][2]);

	mat2 ai = andMath::inverse(A);
	mat2 ca = C * ai;
	mat2 ab = ai * B;

	mat2 dcab = andMath::inverse((D - ca * B));

	mat2 nA = ai + ab *		  dcab		 * ca;
	mat2 nB =	  (ab * -1) * dcab;
	mat2 nC =				 (dcab * -1) * ca;
	mat2 nD =				  dcab;

	mat4 n;

	n.setBLock2x2(0, 0, nA);
	n.setBLock2x2(0, 2, nB);
	n.setBLock2x2(2, 0, nC);
	n.setBLock2x2(2, 2, nD);

	return n;
}

float andMath::determinant(const mat4 & a)
{
	float n =	a.mm[0][0] * a.mm[1][1] * a.mm[2][2] * a.mm[3][3] + a.mm[0][0] * a.mm[1][2] * a.mm[2][3] * a.mm[3][1] + a.mm[0][0] * a.mm[1][3] * a.mm[2][1] * a.mm[3][2] +
				a.mm[0][1] * a.mm[1][0] * a.mm[2][3] * a.mm[3][2] + a.mm[0][1] * a.mm[1][2] * a.mm[2][0] * a.mm[3][3] + a.mm[0][1] * a.mm[1][3] * a.mm[2][2] * a.mm[3][0] +
				a.mm[0][2] * a.mm[1][0] * a.mm[2][1] * a.mm[3][3] + a.mm[0][2] * a.mm[1][1] * a.mm[2][3] * a.mm[3][0] + a.mm[0][2] * a.mm[1][3] * a.mm[2][0] * a.mm[3][1] +
				a.mm[0][3] * a.mm[1][0] * a.mm[2][2] * a.mm[3][1] + a.mm[0][3] * a.mm[1][1] * a.mm[2][0] * a.mm[3][2] + a.mm[0][3] * a.mm[1][2] * a.mm[2][1] * a.mm[3][0] -
				//-
				a.mm[0][0] * a.mm[1][1] * a.mm[2][3] * a.mm[3][2] - a.mm[0][0] * a.mm[1][2] * a.mm[2][1] * a.mm[3][3] - a.mm[0][0] * a.mm[1][3] * a.mm[2][2] * a.mm[3][1] -
				a.mm[0][1] * a.mm[1][0] * a.mm[2][2] * a.mm[3][3] - a.mm[0][1] * a.mm[1][2] * a.mm[2][3] * a.mm[3][0] - a.mm[0][1] * a.mm[1][3] * a.mm[2][0] * a.mm[3][2] -
				a.mm[0][2] * a.mm[1][0] * a.mm[2][3] * a.mm[3][1] - a.mm[0][2] * a.mm[1][1] * a.mm[2][0] * a.mm[3][3] - a.mm[0][2] * a.mm[1][3] * a.mm[2][1] * a.mm[3][0] -
				a.mm[0][3] * a.mm[1][0] * a.mm[2][1] * a.mm[3][2] - a.mm[0][3] * a.mm[1][1] * a.mm[2][2] * a.mm[3][0] - a.mm[0][3] * a.mm[1][2] * a.mm[2][0] * a.mm[3][1];
	return n;
}

andMath::mat4 andMath::rotate(const vec3 &normalizedVec3, float angle)
{
	vec3 m = normalizedVec3;
	float cos = cosf(angle);
	float cosp = 1.0f - cos;
	float sin = sinf(angle);
	
	mat4 n = { cos + m.x * m.x * cosp, m.y * m.x * cosp + m.z * sin, m.z * m.x * cosp - m.y * sin, 0, //first col

			   m.x * m.y * cosp - m.z * sin, cos + m.y * m.y * cosp, m.z * m.y * cosp + m.x * sin, 0, //second col

			   m.x * m.z * cosp + m.y * sin, m.y * m.z * cosp - m.x * sin, cos + m.z * m.z * cosp, 0, //third col

			   0, 0, 0, 1 };																		  //fourth col
	return n;
}
andMath::mat4 andMath::translate(const vec3 &translation)
{
	mat4 n = n.identity();
	n.mm[3][0] = translation.x;
	n.mm[3][1] = translation.y;
	n.mm[3][2] = translation.z;
	return n;
}
andMath::mat4 andMath::scale(const vec3 &scale)
{
	mat4 n = n.identity();
	n.mm[0][0] = scale.x;
	n.mm[1][1] = scale.y;
	n.mm[2][2] = scale.z;
	return mat4();
}

andMath::mat4 andMath::operator+(const mat4 & lhs, const mat4 & rhs)
{
	mat4 n;
	n.c[0] = lhs.c[0] + rhs.c[0];
	n.c[1] = lhs.c[1] + rhs.c[1];
	n.c[2] = lhs.c[2] + rhs.c[2];
	n.c[3] = lhs.c[3] + rhs.c[3];
	return n;
}
andMath::mat4 andMath::operator+=(mat4 & lhs, const mat4 & rhs)
{
	lhs.c[0] += rhs.c[0];
	lhs.c[1] += rhs.c[1];
	lhs.c[2] += rhs.c[2];
	lhs.c[3] += rhs.c[3];
	return lhs;
}
andMath::mat4 andMath::operator-(const mat4 & lhs, const mat4 & rhs)
{
	mat4 n;
	n.c[0] = lhs.c[0] - rhs.c[0];
	n.c[1] = lhs.c[1] - rhs.c[1];
	n.c[2] = lhs.c[2] - rhs.c[2];
	n.c[3] = lhs.c[3] - rhs.c[3];
	return n;
}
andMath::mat4 andMath::operator-=(mat4 & lhs, const mat4 & rhs)
{
	lhs.c[0] -= rhs.c[0];
	lhs.c[1] -= rhs.c[1];
	lhs.c[2] -= rhs.c[2];
	lhs.c[3] -= rhs.c[3];
	return lhs;
}

andMath::mat4 andMath::operator*(const mat4 & lhs, const mat4 & rhs)
{
	mat4 n, t = transpose(lhs);
	n.c[0] = { dot(t.c[0], rhs.c[0]), dot(t.c[1], rhs.c[0]), dot(t.c[2], rhs.c[0]),  dot(t.c[3], rhs.c[0]) };
	n.c[1] = { dot(t.c[0], rhs.c[1]), dot(t.c[1], rhs.c[1]), dot(t.c[2], rhs.c[1]),  dot(t.c[3], rhs.c[1]) };
	n.c[2] = { dot(t.c[0], rhs.c[2]), dot(t.c[1], rhs.c[2]), dot(t.c[2], rhs.c[2]),  dot(t.c[3], rhs.c[2]) };
	n.c[3] = { dot(t.c[0], rhs.c[3]), dot(t.c[1], rhs.c[3]), dot(t.c[2], rhs.c[3]),  dot(t.c[3], rhs.c[3]) };
	return n;
}
andMath::vec4 andMath::operator*(const mat4 & lhs, const vec4 & rhs)
{
	mat4 t = transpose(lhs);
	vec4 n;

	n.x = dot(t.c[0], rhs);
	n.y = dot(t.c[1], rhs);
	n.z = dot(t.c[2], rhs);
	n.w = dot(t.c[3], rhs);

	return n;
}
andMath::mat4 andMath::operator*(const mat4 & lhs, float rhs)
{
	mat4 n;
	n.c[0] = lhs.c[0] * rhs;
	n.c[1] = lhs.c[1] * rhs;
	n.c[2] = lhs.c[2] * rhs;
	n.c[3] = lhs.c[3] * rhs;
	return n;
}

andMath::mat4 andMath::operator*=(mat4 & lhs, const mat4 & rhs)
{
	lhs = lhs * rhs;
	return lhs;
}
andMath::mat4 andMath::operator*=(mat4 & lhs, float rhs)
{
	lhs.c[0] *= rhs;
	lhs.c[1] *= rhs;
	lhs.c[2] *= rhs;
	lhs.c[3] *= rhs;
	return lhs;
}

bool andMath::operator==(const mat4 & a, const mat4 & b)
{
	return (a.c[0] == b.c[0] && a.c[1] == b.c[1] && a.c[2] == b.c[2] && a.c[3] == b.c[3]) ? true : false;
}
bool andMath::operator!=(const mat4 & a, const mat4 & b)
{
	return (a.c[0] != b.c[0] && a.c[1] != b.c[1] && a.c[2] != b.c[2] && a.c[3] != b.c[3]) ? true : false;
}

andMath::mat4 andMath::ortho(float left, float right, float bottom, float top, float near, float far)
{
	//based of off work done in glmatrix library
	//http://glmatrix.net/docs/2.2.0/symbols/src/gl-matrix_src_gl-matrix_mat4.js.html

	mat4 nM = mat4::identity();

	float l = left, r = right, b = bottom, t = top, n = near, f = far;
	float lr = 1 / (l - r),
		  bt = 1 / (b - t),
		  nf = 1 / (n - f);

	//anything not listed here is 0
	nM.m[0]  = -2 * lr;
	nM.m[5]  = -2 * bt;
	nM.m[10] =  2 * nf;
	nM.m[12] = (l + r) * lr;
	nM.m[13] = (t + b) * bt;
	nM.m[14] = (n + f) * nf;

	return nM;
}

andMath::mat4 andMath::frustum(float left, float right, float bottom, float top, float near, float far)
{
	//based of off work done in glmatrix library
	//http://glmatrix.net/docs/2.2.0/symbols/src/gl-matrix_src_gl-matrix_mat4.js.html

	mat4 nM = mat4::identity();

	float l = left, r = right, b = bottom, t = top, n = near, f = far;
	float rl = 1 / (r - l),
		  tb = 1 / (t - b),
		  nf = 1 / (n - f);

	//anything not listed here is 0
	nM.m[0]  = (n * 2) * rl;
	nM.m[5]  = (n * 2) * tb;
	nM.m[8]  = (r + l) * rl;
	nM.m[9]  = (t + b) * tb;
	nM.m[10] = (f + n) * nf;
	nM.m[11] = -1;
	nM.m[14] = (f * n * 2) * nf;

	return nM;
}

andMath::mat4 andMath::perspective(float fov, float aspect, float near, float far)
{
	//based of off work done in glmatrix library
	//http://glmatrix.net/docs/2.2.0/symbols/src/gl-matrix_src_gl-matrix_mat4.js.html

	mat4 nM = mat4::identity();

	float fo = fov, a = aspect, n = near, fa = far;
	float f = 1 / tanf(fo / 2);
	float nf = 1 / (n - fa);

	//anything not listed here is 0
	nM.m[0]  = f / a;
	nM.m[5]  = f;
	nM.m[10] = (fa + n) * nf;
	nM.m[11] = -1;
	nM.m[14] = (2 * fa * n) * nf;

	return nM;
}



