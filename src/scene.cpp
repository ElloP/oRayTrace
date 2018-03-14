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
		}
	}
	return hit;
}

vec3f Scene::trace(const Ray &ray, int depth)
{
	Hit intersection = intersect(ray);

	//Possible bug, check if bool on hit struct is needed
	if(!intersection.distance)
		return vec3f();

	vec3f color = intersection.material.getColor();

	//calculate max reflection
	float p = color.x>color.y && color.x>color.z ? color.x : color.y>color.z ? color.y : color.z; 

	//use russian roulette termination
	float random = (float) rand() / (RAND_MAX);
	if(depth > traceDepth)
	{
		if(random < p * 0.9) 
		{
			color = color * (0.9 / p);
		}
		else
			return intersection.material.getEmission();
	}
	
	Ray reflectionRay = intersection.material.getReflectionRay(ray, intersection.point, intersection.normal);
	vec3f test = trace(reflectionRay, depth + 1);
	//std::cout << "x:" << test.x << "y:" << test.y << "z:" << test.z << std::endl;
	return color;
}

void Scene::addObjectToScene(Intersectable* intersectable) 
{ 
	sceneObjects.push_back(intersectable);
}