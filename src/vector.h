#ifndef VECTOR_H_
#define VECTOR_H_

#include <math.h>

struct Vector3f
{
	union
	{
		struct
		{
			float x, y, z;
		};
		struct
		{
			float r, g, b;
		};
		float coords[3];
	};

	Vector3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) : x(_x), y(_y), z(_z) {};

	Vector3f operator+(const Vector3f &other) const { return Vector3f(x + other.x, y + other.y, z + other.z); }
	Vector3f operator-(const Vector3f &other) const { return Vector3f(x - other.x, y - other.y, z - other.z); }
	Vector3f operator*(const Vector3f &other) const { return Vector3f(x * other.x, y * other.y, z * other.z); }
	Vector3f operator*(float other) const { return Vector3f(x * other, y * other, z * other); }
	Vector3f operator/(float other) const { return Vector3f(x / other, y / other, z / other); }
	Vector3f& normalize() { return ((*this)/sqrt(x*x+y*y+z*z));}
};

struct Vector4f
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		float coords[4];
	};

	Vector4f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f, float _w = 0.0f) : x(_x), y(_y), z(_z),w(_w) {};

	Vector4f operator+(const Vector4f &other) { return Vector4f(x + other.x, y + other.y, z + other.z, w + other.w); }
	Vector4f operator-(const Vector4f &other) { return Vector4f(x - other.x, y - other.y, z - other.z, w - other.w); }
	Vector4f operator*(const Vector4f &other) { return Vector4f(x * other.x, y * other.y, z * other.z, w * other.w); }
	Vector4f operator*(float other) { return Vector4f(x * other, y * other, z * other, w * other); }
	Vector4f operator/(float other) { return Vector4f(x / other, y / other, z / other, w / other); }
	Vector4f& normalize() { return ((*this)/sqrt(x*x+y*y+z*z+w*w));}
};

typedef Vector3f vec3f;
typedef Vector4f vec4f;

static float dot(const vec3f &a, const vec3f &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

static vec3f cross(const vec3f &a, const vec3f &b)
{
	return vec3f((a.y * b.z - a.z * b.y), (a.z * b.x - a.x * b.z), (a.x * b.y - a.y * b.x));
}

static float dot(const vec4f &a, const vec4f &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

#endif // !VECTOR_H_