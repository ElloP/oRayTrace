#include "material.h"
#include <random>

vec3f Material::getColor() const 
{
	return color;
}

vec3f Material::getEmission() const 
{
	return emission;
}

Ray Material::getReflectionRay(const Ray &ray, Hit &hit) const
{
	//if(type == DIFFUSE)
	//{
		vec3f n1 = dot(hit.normal, (ray.direction)) < 0 ? hit.normal : hit.normal * -1;
		float r1 = 2 * PI * rand(), r2 = rand(), r2s = sqrt(r2);
		vec3f w = n1;
		vec3f u = cross((fabs(w.x) > 0.1 ? vec3f(0,1) : vec3f(1.0)), w).normalize();
		vec3f v = cross(w, u);
		vec3f d = (u * cos(r1) * r2s + v * sin(r1) * r2s + w * sqrt(1-r2)).normalize();
		//TODO: this might break
		return Ray(ray.origin + ray.direction * hit.distance, d);
	//}
}