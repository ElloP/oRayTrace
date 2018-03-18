#include "scene.h"
#include <random>
#include <iostream>

Scene::Scene(int _traceDepth) : traceDepth(_traceDepth)
{}

Hit Scene::intersect(const Ray &ray)
{
	Hit hit = Hit();
	Hit temp = Hit();
	for(Intersectable *i : sceneObjects)
	{
		if(i->intersection(ray, temp) && (hit.distance == 0 || temp.distance < hit.distance))
		{
			hit.distance = temp.distance;
			hit.point = ray.origin + ray.direction * hit.distance;
			hit.material = temp.material;
			hit.normal = temp.normal;
			hit.hit = temp.hit;
		}
	}
	return hit;
}

vec3f Scene::trace(const Ray &ray, int depth)
{
	Hit intersection = intersect(ray);
	if(intersection.hit && depth <= traceDepth)
	{
		Ray reflected;
		vec3f color = intersection.material.getColor();
		if(intersection.material.reflectedRay(ray, intersection.point, intersection.normal, reflected))
		{
			return color * trace(reflected, depth + 1);
		}
		else 
		{
			return vec3f();
		}
	}
	else
	{
		float t = 0.5 * (ray.direction.y + 1);
		return vec3f(1.0,1.0,1.0);
	}
}

void Scene::addObjectToScene(Intersectable* intersectable) 
{ 
	sceneObjects.push_back(intersectable);
}