#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <fstream>

#include "Vendor/lodepng.h"
#include "Utilities/RGBColor.h"


class Image
{
protected:
	int width, height;
	RGBColor* data;
	unsigned char* imgData;

public:
	Image(int width, int height);

	virtual ~Image();
	
	int getWidth() const;
	int getHeight() const;

	RGBColor* getPixel(int x, int y);
	void setPixel(int x, int y, RGBColor& color);

	void saveImage(std::string filename) const;
};

#endif
