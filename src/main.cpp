#include <iostream>
#include "triangle.h"
#include "ImageIO.h"

int main(void)
{
	AABBox test = AABBox(vec3f(2.0f, 2.0f), vec3f(7.0f, 4.0f));
	Ray r = Ray(vec3f(), vec3f(0.5,0.5,0.5));
	Triangle t = Triangle(vec3f(0,-1000, 3), vec3f(-1000,1000,3), vec3f(1000,1000,3));
	float fet = 5;
	bool bee = t.intersection(r, fet);
	std::cout << bee << "t:" << t.normal.x << std::endl;
	std::vector<int> tesese = std::vector<int>();
	ImageIO i = ImageIO();
	for(int y = 0; y < i.getHeight(); y++)
	{
		for(int x = 0; x < i.getWidth(); x++)
		{
			if(x == 25 && y == 0)
				i.setPixel(x,y,&vec3f(0.0));
			else
				i.setPixel(x,y,&vec3f(1.0));
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