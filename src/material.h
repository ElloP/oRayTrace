#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "ray.h"

#ifndef PI
#define PI 3.141592653589793238
#endif

enum MaterialType {DIFFUSE}; 

class Material 
{
public:
	Material(vec3f _color = vec3f(1.0), vec3f _emission = vec3f(1.0));

	vec3f getColor() const;
	vec3f getEmission() const;
	//MaterialType getType() const;

	bool reflectedRay(const Ray &ray, const vec3f &point, const vec3f &normal, Ray &result) const;
private:
	vec3f color;
	vec3f emission;

	MaterialType type;
};
#endif