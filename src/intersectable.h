#ifndef INTERSECTABLE_H_
#define INTERSECTABLE_H_

#include "ray.h"

struct Hit 
{
	float distance;
	vec3f point;
	vec3f normal;
};

class Intersectable
{
public:
	virtual bool intersection(Ray &ray, float &t) = 0;
};

#endif