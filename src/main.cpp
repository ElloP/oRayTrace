#include <iostream>
#include "triangle.h"
#include "ImageIO.h"
#include "renderer.h"
#include "scene.h"
#include "sphere.h"
#include "material.h"

int main(void)
{
	AABBox test = AABBox(vec3f(2.0f, 2.0f), vec3f(7.0f, 4.0f));
	Ray r = Ray(vec3f(), vec3f(0.5,0.5,0.5));
	Triangle t = Triangle(vec3f(0,-1000, 3), vec3f(-1000,1000,3), vec3f(1000,1000,3));
	float fet = 5;
	std::vector<int> tesese = std::vector<int>();

	Material mat = Material(vec3f(1.0,0.0,0.0), vec3f(1.0));
	Material mat2 = Material(vec3f(0.0,0.0,1.0), vec3f(1.0));

	Scene scene = Scene();
	scene.addObjectToScene(&Sphere(vec3f(1.0,0.0,5.0), 0.5f, mat));
	scene.addObjectToScene(&Sphere(vec3f(3.0,0.0,4.0), 0.5f, mat2));

	Renderer renderer = Renderer(&scene);

	ImageIO i = ImageIO();
	for(int y = 0; y < i.getHeight(); y++)
	{
		for(int x = 0; x < i.getWidth(); x++)
		{
			vec3f color = renderer.samplePixel(x,y);
			//std::cout << "x:" << color.x << "y:" << color.y << "z:" << color.z << std::endl;
			i.setPixel(x,y, &color);
		}
	}
	
	i.writeToImage("examples/test.png");
	//x = x.normalize();
	//AABBox y = AABBox(x,x);
	//x.coords[2] = 5.0f;
	//std::cout << test.intersection(r);
	system("pause");
	return 0;
}