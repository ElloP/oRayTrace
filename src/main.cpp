#include "vector.h"
#include <iostream>
#include "aabbox.h"
#include "triangle.h"

int main(void)
{
	AABBox test = AABBox(vec3f(2.0f, 2.0f), vec3f(7.0f, 4.0f));
	Ray r = Ray(vec3f(), vec3f(0.5,0.5,0.5));
	Triangle t = Triangle(vec3f(0,-1000, 3), vec3f(-1000,1000,3), vec3f(1000,1000,3));
	float fet = 5;
	bool bee = t.intersect(r, fet);
	std::cout << bee << "t:" << fet << std::endl;
	//x = x.normalize();
	//AABBox y = AABBox(x,x);
	//x.coords[2] = 5.0f;
	//std::cout << test.intersection(r);
	system("pause");
	return 0;
}