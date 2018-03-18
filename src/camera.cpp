#include "camera.h"

Camera::Camera(vec3f _position, vec3f target, int _width, int _height) 
	: 
	position(_position),
	width(_width),
	height(_height)
{
	aspectRatio = width / height;
	xSpacing = (2.0 * aspectRatio) / width;
	ySpacing = 2.0 / height;
	
	direction = (target - position).normalize();
	right = cross(vec3f(0,0,1.0), -direction).normalize();
	up = cross(direction, right).normalize();
}

Ray Camera::getRay(int x, int y, bool jitter)
{
	float xJitter = 0.0;
	float yJitter = 0.0;

	if(jitter)
	{
		xJitter = randomf(1,0) * xSpacing - xSpacing / 2.0;
		yJitter = randomf(1,0) * ySpacing - ySpacing / 2.0;
	}

	vec3f pixel = position + direction * 2.0;
	pixel = right * aspectRatio + right * ((x * 2 * aspectRatio) * 1/ (float) width) + xJitter;
	pixel = pixel + up - up * ((y * 2.0) * 1/(float) height + yJitter);
	
	return Ray(position, pixel-position);
}
