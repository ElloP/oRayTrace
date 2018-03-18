#include "material.h"
#include <random>
#define _XOPEN_SOURCE
#include <stdlib.h>
#include <iostream>

Material::Material(vec3f _color, vec3f _emission) : color(_color)
{}

vec3f Material::getColor() const 
{
	return color;
}

vec3f random_in_unit_sphere() {
    vec3f p;
    do {
		
        p = vec3f(randomf(2,-1),randomf(2,-1),randomf(2,-1)) * 2.0 - vec3f(1,1,1);
    } while (p.length() * p.length() >= 1.0);
    return p;
}

vec3f Material::getEmission() const 
{
	return emission;
}

bool Material::reflectedRay(const Ray &ray, const vec3f &point, const vec3f &normal, Ray &result) const
{
	vec3f target = point + normal + random_in_unit_sphere();
	result = Ray(point, target - point);
	return true;
}