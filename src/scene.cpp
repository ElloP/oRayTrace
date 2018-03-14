#include "scene.h"

void Scene::addObjectToScene(Intersectable* intersectable) 
{ 
	sceneObjects.push_back(intersectable);
}