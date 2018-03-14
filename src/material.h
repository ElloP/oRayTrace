#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "ray.h"
#include "intersectable.h"

#ifndef PI
#define PI 3.141592653589793238
#endif

enum MaterialType {DIFFUSE}; 

class Material 
{
public:
	vec3f getColor() const;
	vec3f getEmission() const;
	MaterialType getType() const;

	Ray getReflectionRay(const Ray &r, Hit &h) const;
private:
	vec3f color;
	vec3f emission;

	MaterialType type;
};
#endif