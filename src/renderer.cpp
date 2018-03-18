#include "renderer.h"
#include <iostream>

Renderer::Renderer(Scene *_scene, Camera* _camera, int _width, int _height) 
	: 
	scene(_scene), 
	camera(_camera), 
	width(_width), 
	height(_height)
{}

vec3f Renderer::samplePixel(int x, int y, int samples)
{
	float rayContrib = 1.f/samples;

	vec3f color = vec3f(0.0);

	for(int a = 0; a < samples; a++)
	{
		Ray ray = getPrimaryRay(x, y);
		color = color + scene->trace(ray);
		//std::cout << "x:" << color.x << "y:" << color.y << "z:" << color.z << std::endl;
	}
	return color * rayContrib;
}

Ray Renderer::getPrimaryRay(int pixelX, int pixelY)
{
	vec3f direction = vec3f();

	float x = (float) pixelX;
	float y = (float) pixelY;
	float w = (float) width;
	float h = (float) height;

	float ratio = w / h;

	float spacingX = (2.0 * ratio) / w;
	float spacingY = (2.0/h);

	float xJitter = randomf(1,0) * spacingX - spacingX / 2.0;
	float yJitter = randomf(1,0) * spacingY - spacingY / 2.0;

	direction.x = (x + xJitter) / w * 2.0f - 1.0f;
	direction.y = (y + yJitter) / h * 2.0f - 1.0f;
	direction.z = 1.0f;
	
	direction.x *= ratio;

	direction = direction.normalize();
	return Ray(vec3f(0.0), direction);
}