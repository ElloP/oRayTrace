#ifndef RENDERER_H_
#define RENDERER_H_

#include "scene.h"
#include "camera.h"

class Renderer
{
public:
	Renderer(Scene *_scene, Camera* _camera, int _width = 640, int _height = 480);
	vec3f samplePixel(int x, int y, int samples = 4);

private:
	Camera* camera;
	Scene *scene;
	int width, height;
	Ray getPrimaryRay(int pixelX, int pixelY);
};

#endif