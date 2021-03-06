#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "BVH\aabbox.h"
#include "material.h"

class Triangle : public Intersectable 
{
public:
	vec3f v0, v1, v2; //triangle vertices
	vec3f e1, e2, normal; //triangle edges and normal
	Material material;

	Triangle() = default;

	Triangle(vec3f _v0, vec3f _v1, vec3f _v2, Material _material = Material()) : v0(_v0), v1(_v1), v2(_v2), material(_material)
	{
		setEdges();
	}

	Triangle(vec3f _vertices[3], Material _material = Material()) : v0(_vertices[0]), v1(_vertices[1]), v2(_vertices[2]), material(_material)
	{
		setEdges();
	}

	inline void setEdges() 
	{
		e1 = v1 - v0;
		e2 = v2 - v0;
		normal = cross(e1,e2).normalize();
	}

	inline void flipNormal() { normal = -normal; }

	//intersection testing using the M�ller-trumbore algorithm
	bool intersection(const Ray &ray, Hit &hit) 
	{
		const float epsilon = 0.0000001f;

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
			hit.distance = tTemp;
			hit.normal = normal;
			hit.material = material;
			hit.point = ray.origin + ray.direction * hit.distance;
			hit.hit = true;
			return true;
		}

		return false;
	}

	AABBox getBoundingBox() 
	{
		vec3f minCorner = vec3f
		(
			std::min(v0.x, std::min(v1.x, v2.x)),
			std::min(v0.y, std::min(v1.y, v2.y)),
			std::min(v0.z, std::min(v1.z, v2.z))
		);

		vec3f maxCorner = vec3f
		(
			std::max(v0.x, std::max(v1.x, v2.x)),
			std::max(v0.y, std::max(v1.y, v2.y)),
			std::max(v0.z, std::max(v1.z, v2.z))
		);

		return AABBox(minCorner, maxCorner);
	}

};

#endif //!TRIANGLE_H_