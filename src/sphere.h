#ifndef SPHERE_H_
#define SPHERE_H_

#include "BVH\aabbox.h"

class Sphere : public Intersectable 
{
public:
	vec3f position;
	float radius;

	Sphere(vec3f _position = vec3f(0.0,0.0,0.0), float _radius = 1.0f) : position(_position), radius(_radius)
	{}

	bool intersection(Ray &ray, float &t)
	{
		//not sure about this
		float a = dot(ray.direction, ray.direction);
		float b = 2 * dot(ray.direction, ray.origin);
		float c = dot(ray.origin, ray.origin) - radius * radius;

		float t0, t1;

		if(!solveQuadratic(a,b,c,t0,t1))
			return false;

		if(t0 < 0)
		{
			//use the positive t
			t0 = t1;
			if(t0 < 0)
				return false; //both ts are negative
		}

		t = t0;
		return true;
	}

	AABBox getBoundingBox()
	{
		vec3f minCorner = vec3f
		(
			position.x - radius,
			position.y - radius,
			position.z - radius
		);

		vec3f maxCorner = vec3f
		(
			position.x + radius,
			position.y + radius,
			position.z + radius
		);

		return AABBox(minCorner, maxCorner);
	}

private:
	bool solveQuadratic(const float &a, const float &b, const float &c, float &t0, float &t1)
	{
		float discr = b * b - 4 * a * c;
		if(discr < 0) 
			return false;
		else if(discr == 0) 
			t0 = t1 = -0.5 * b / a;
		else
		{
			float q = (b > 0) ?
				-0.5 * (b + sqrt(discr)) :
				-0.5 * (b - sqrt(discr));

			t0 = q / a;
			t1 = c / q;
		}

		if(t0 > t1)
			std::swap(t0,t1);

		return true;
	}
};

#endif