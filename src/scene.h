#ifndef SCENE_H_
#define SCENE_H_

#include "intersectable.h"
#include <vector>

class Scene 
{
public:
	void addObjectToScene(Intersectable* intersectable);

private:
	std::vector<Intersectable*> sceneObjects;
};

#endif