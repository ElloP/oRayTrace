#ifndef RAY_H_
#define RAY_H_

#include "vector.h"

struct Ray {
	vec3f origin, direction, inverseDir;

	Ray(const vec3f &_origin, const vec3f &_direction) : origin(_origin), direction(_direction)
	{
		direction = direction.normalize();
		inverseDir = vec3f(1.0f / direction.x, 1.0f / direction.y, 1.0f / direction.z);
	};
};

#endif // !RAY_H_