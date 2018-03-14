#ifndef AABBOX_H_
#define AABBOX_H_

#include "../intersectable.h"
#include <algorithm>

class AABBox : public Intersectable {
public:
	vec3f bottomLeft, topRight;

	AABBox(vec3f _bottomLeft = vec3f(), vec3f _topRight = vec3f()) : bottomLeft(_bottomLeft), topRight(_topRight) {};

	bool intersection(const Ray &ray, Hit &hit) 
	{
		float t1 = (bottomLeft.x - ray.origin.x) * ray.inverseDir.x;
		float t2 = (bottomLeft.y - ray.origin.y) * ray.inverseDir.y;

		float tmin = std::max(t1, t2);

		t2 = (bottomLeft.z - ray.origin.z) * ray.inverseDir.z;

		tmin = std::max(tmin, t2);

		t1 = (topRight.x - ray.origin.x) * ray.inverseDir.x;
		t2 = (topRight.y - ray.origin.y) * ray.inverseDir.y;

		float tmax = std::min(t1, t2);

		t2 = (topRight.z - ray.origin.z) * ray.inverseDir.z;

		tmax = std::min(tmax, t2);

		//AABBoxes have no normal or material
		hit.distance = tmin;
		hit.point = ray.origin + ray.direction * hit.distance;

		return tmin <= tmax;
	}
};

#endif // !AABBOX_H_
