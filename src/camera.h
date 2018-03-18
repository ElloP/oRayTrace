#ifndef CAMERA_H_
#define CAMERA_H_

#include "ray.h"

static vec3f worldUp = vec3f(0.0,1.0,0.0);

class Camera
{
public:
	Camera(vec3f position = vec3f(), vec3f target = vec3f(0,0,1), int _width = 640, int _height = 480);

	Ray getRay(int x, int y, bool jitter = true);

	inline int getWidth() const { return width; }
	inline int getHeight() const { return height; }
private:
	int height;
	int width;

	float aspectRatio;
	float xSpacing;
	float ySpacing;

	vec3f position;
	vec3f direction;
	vec3f right;
	vec3f up;
};

#endif