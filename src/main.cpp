#include <iostream>
#include "triangle.h"
#include "ImageIO.h"
#include "renderer.h"
#include "scene.h"
#include "sphere.h"
#include "material.h"
#include "camera.h"

int main(void)
{
	Material mat = Material(vec3f(0.7,0.4,0.2), vec3f(1.0));
	Material white = Material(vec3f(1.0,1.0,1.0), vec3f(1.0));
	Material blue = Material(vec3f(0.0,0.0,1.0), vec3f(1.0));
	Material red = Material(vec3f(1.0,0.0,0.0), vec3f(1.0));

	Triangle floor1 = Triangle(vec3f(-3,-2, -4), vec3f(-3,-2,4), vec3f(3,-2,-4), white);
	Triangle floor2 = Triangle(vec3f(3,-2,4), vec3f(3,-2,-4), vec3f(-3,-2,4), white);

	Triangle roof1 = Triangle(vec3f(-3,2, -4), vec3f(-3,2,4), vec3f(3,2,-4), white);
	Triangle roof2 = Triangle(vec3f(3,2,4), vec3f(3,2,-4), vec3f(-3,2,4), white);

	Triangle rightWall1 = Triangle(vec3f(3,-2, 4), vec3f(3,2,4), vec3f(3,-2, -4), red);
	Triangle rightWall2 = Triangle(vec3f(3, 2, -4), vec3f(3,2,4), vec3f(3,-2,-4), red);

	Triangle leftWall1 = Triangle(vec3f(-3,-2, 4), vec3f(-3,-2, -4), vec3f(-3,2,4), blue);
	Triangle leftWall2 = Triangle(vec3f(-3, 2, -4), vec3f(-3,-2,-4), vec3f(-3,2,4), blue);

	Triangle backWall1 = Triangle(vec3f(-3, -2, 4), vec3f(3,-2,4), vec3f(3,2,4),mat);
	Triangle backWall2 = Triangle(vec3f(-3, 2, 4), vec3f(3,2,4), vec3f(-3,-2,4),mat);

	//leftWall1.flipNormal();
	//leftWall2.flipNormal();
	backWall1.flipNormal();
	roof1.flipNormal();
	roof2.flipNormal();

	Sphere sp = Sphere(vec3f(0,-0.5,2), 0.8f, white);

	Scene scene = Scene(8);
	scene.addObjectToScene(&floor1);
	scene.addObjectToScene(&floor2);
	scene.addObjectToScene(&rightWall1);
	scene.addObjectToScene(&rightWall2);
	scene.addObjectToScene(&backWall1);
	scene.addObjectToScene(&backWall2);
	scene.addObjectToScene(&leftWall1);
	scene.addObjectToScene(&leftWall2);
	//scene.addObjectToScene(&roof1);
	//scene.addObjectToScene(&roof2);
	scene.addObjectToScene(&sp);
	//scene.addObjectToScene(&Sphere(vec3f(1.0,0.0,5.0), 0.5f, mat));
	//scene.addObjectToScene(&Sphere(vec3f(3.0,0.0,4.0), 0.5f, mat2));

	Camera camera = Camera();

	Renderer renderer = Renderer(&scene, &camera);

	ImageIO i = ImageIO();
	int nx = 200;
	int ny = 100;
	for(int x = 0; x < i.getWidth(); x++)
	{
		for(int y = 0; y < i.getHeight(); y++)
		{
			vec3f color = renderer.samplePixel(x,y,4);
			i.setPixel(x,y, color);
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