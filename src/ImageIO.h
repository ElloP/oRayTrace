#ifndef IMAGEIO_H_
#define IMAGEIO_H_

#include "vector.h"
#include <vector>

class ImageIO 
{
public:
	ImageIO(int _width = 640, int _height = 480) : width(_width), height(_height), pixelBuffer()
	{
		pixelBuffer.resize(width * height);
	}
	void writeToImage(char *path);
	void setPixel(int _width, int _height, vec3f *color);

	inline int getWidth() const { return width;}
	inline int getHeight() const { return height;}
private:

	std::vector<vec3f*> pixelBuffer;
	int width, height;

	inline float clamp(float x) { return x<0 ?  0 : x>1 ? 1.0 : x; }
	inline unsigned char toBytePixel(float x) { return unsigned char(clamp(x) * 255); }
};

#endif