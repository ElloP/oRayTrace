#include "renderer.h"
#include <iostream>

Renderer::Renderer(Scene *_scene, int _width, int _height) : scene(_scene), width(_width), height(_height)
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

	float offsetX = 0.5;
	float offsetY = 0.5;


	direction.x = (x + offsetX) / w * 2.0f - 1.0f;
	direction.y = (y + offsetY) / h * 2.0f - 1.0f;
	direction.z = 1.0f;
	float ratio = w / h;
	direction.x *= ratio;

	direction = direction.normalize();
	return Ray(vec3f(0.0), direction);
}