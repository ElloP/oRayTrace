#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "vector.h"
#include "ray.h"

class Triangle {
public:
	union 
	{
		struct 
		{
			vec3f v0, v1, v2;	  //triangle vertices
		};
		vec3f vertices[3];
	};
	vec3f e1, e2, normal; //triangle edges and normal

	Triangle(vec3f _v0, vec3f _v1, vec3f _v2) : v0(_v0), v1(_v1), v2(_v2)
	{
		setEdges();
	}

	Triangle(vec3f _vertices[3]) : v0(_vertices[0]), v1(_vertices[1]), v2(_vertices[2])
	{
		setEdges();
	}

	inline void setEdges() 
	{
		e1 = v1 - v0;
		e2 = v2 - v0;
	}

	//intersection testing using the Möller-trumbore algorithm
	bool intersect(Ray &ray, float &t) 
	{
		const float epsilon = 0.0000001;

		vec3f h = cross(ray.direction, e2);
		float a = dot(e1,h);

		if(a > -epsilon && a < epsilon)
			return false;

		float f = 1/a;
		vec3f s = ray.origin - v0;
		float u = f * dot(s,h);

		if(u < 0 || u > 1) //outside of triangle
			return false;

		vec3f q = cross(s,e1);
		float v = f * dot(ray.direction, q);

		if(v < 0 || u + v > 1) //outside of triangle
			return false;

		float tTemp = f * dot(e2,q);

		if(tTemp > epsilon)
		{
			//TODO: might wanna return intersection point
			t = tTemp;
			return true;
		}

		return false;
	}

};

#endif //!TRIANGLE_H_