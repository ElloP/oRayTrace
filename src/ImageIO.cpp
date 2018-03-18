#include "ImageIO.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../libs/stb_image_write.h"

void ImageIO::setPixel(int x, int y, vec3f color)
{
	assert(0 <= x && x <= width && 0 <= y && y <= height);

	int index = 3 * (x + (height - y - 1) * width);
	pixelBuffer[index + 0] = toBytePixel(color.r);
	pixelBuffer[index + 1] = toBytePixel(color.g);
	pixelBuffer[index + 2] = toBytePixel(color.b);
}

void ImageIO::writeToImage(char *path)
{
	stbi_write_png(path, width, height, 3, pixelBuffer, width * 3);
	delete[] pixelBuffer;
}