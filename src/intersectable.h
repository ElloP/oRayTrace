#ifndef INTERSECTABLE_H_
#define INTERSECTABLE_H_

#include "ray.h"
#include "material.h"

struct Hit 
{
	Hit(float _distance = 0, vec3f _point = vec3f(), vec3f _normal = vec3f(), bool _hit = false, Material _material = Material()) 
		: 
		distance(_distance), 
		point(_point), 
		normal(_normal),
		hit(_hit),
		material(_material)
	{}

	float distance;
	vec3f point;
	vec3f normal;
	bool hit;
	Material material;
};

class Intersectable
{
public:
	virtual bool intersection(const Ray &ray, Hit &t) = 0;
};

#endif