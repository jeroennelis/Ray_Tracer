#include "image.h"
#include "GL/glew.h"
#include "Window.h"
#include <algorithm>


Image::Image(int width, int height)
	: width(width), height(height)
{
	data = new RGBColor[width * height];
}

Image::~Image()
{
	delete[] data;
}

int Image::getWidth() const
{
	return width;
}

int Image::getHeight() const
{
	return height;
}

RGBColor* Image::getPixel(int x, int y)
{
	return data + (x + y * width);
}

void Image::setPixel(int x, int y, RGBColor & color)
{
	data[y + x * width] = color;
}

void Image::saveImage(std::string filename) const
{

	unsigned char* imgData = new unsigned char[4 * width * height];

	int newY = height - 1;
	for (int y = 0; y < height; y++, newY--)
	{
		for (int x = 0; x < width; x++)
		{
			RGBColor curColor = data[x + y * width];

			imgData[4 * (x + y * width) + 0] = 255;
			imgData[4 * (x + y * width) + 1] =
			(unsigned char)(curColor.b * 255.0f);
			imgData[4 * (x + y * width) + 2] =
			(unsigned char)(curColor.g * 255.0f);
			imgData[4 * (x + y * width) + 3] =
			(unsigned char)(curColor.r * 255.0f);
		}
		glDrawPixels(300, y, GL_ABGR_EXT, GL_UNSIGNED_BYTE, imgData);
		Window::Update();
	}

	

	glDrawPixels(300, 300, GL_ABGR_EXT, GL_UNSIGNED_BYTE, imgData);

	std::reverse(imgData, (unsigned char *)(imgData + 300 * 300 * 4));

	/*Encode the image*/
	unsigned error = lodepng_encode32_file(filename.c_str(), imgData, width, height);

	/*if there's an error, display it*/
	if (error) printf("error %u: %s\n", error, lodepng_error_text(error));

	delete[] imgData;
}
