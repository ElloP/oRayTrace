#ifndef SCENE_H_
#define SCENE_H_

#include "intersectable.h"
#include <vector>

class Scene 
{
public:
	Scene(int _traceDepth = 4);
	void addObjectToScene(Intersectable* intersectable);
	Hit intersect(const Ray &ray);
	vec3f trace(const Ray &ray, int depth = 4);

private:
	int traceDepth;
	std::vector<Intersectable*> sceneObjects;
};

#endif