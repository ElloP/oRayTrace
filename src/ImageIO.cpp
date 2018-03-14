#include "ImageIO.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../libs/stb_image_write.h"
#include <iostream>

void ImageIO::setPixel(int x, int y, vec3f *color)
{
	assert(x <= width && y <= height);

	pixelBuffer[x + y * width] = color;
}

void ImageIO::writeToImage(char *path)
{
	unsigned char* byteBuffer = new unsigned char[width * height * 3];

	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			//const int flippedY = height - y - 1;
			const int index = y * width + x;
			byteBuffer[3 * index + 0] = toBytePixel(pixelBuffer[index]->r);
			byteBuffer[3 * index + 1] = toBytePixel(pixelBuffer[index]->g);
			byteBuffer[3 * index + 2] = toBytePixel(pixelBuffer[index]->b);

		}
	}

	/*
	for(auto &pixel : pixelBuffer)
	{
		intBuffer.push_back(toIntPixel(pixel->r));
		intBuffer.push_back(toIntPixel(pixel->g));
		intBuffer.push_back(toIntPixel(pixel->b));
	}*/
	stbi_write_png(path, width, height, 3, byteBuffer, width * 3);
	delete[] byteBuffer;
}